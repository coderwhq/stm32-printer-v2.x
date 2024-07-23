#include "MyTask.h"


void initialTestTaskFun(void const *argument) {
    for (;;) {
        osDelay(1);
    }
}

void waitPrintMsgTask(void const *argument) {
    osEvent event;
    for (;;) {
        event = osMessagePeek(rxDataQueueHandle, osWaitForever);
        if (event.status == osEventMessage) {
            xTaskNotifyGive(printTaskHandle);
        } else if (event.status == osEventTimeout) {
            // overtime
        } else {
            // error
        }
        osDelay(10);
    }
}

void printTask(void const *argument) {
    osEvent event;
    for (;;) {
        LED::ledOff();                          // 没有打印
        ulTaskNotifyTake(pdTRUE, osWaitForever);// 等待打印通知
        LED::ledOn();                           // 打印中

        event = osMessageGet(rxDataQueueHandle, osWaitForever);

        if (event.status == osEventMessage) {
            // success
            Serial::serialPrintf(SERIAL, (char *) "printing......\r\n");
            char *lineP = (char *) event.value.p;

            const uint8_t fontHeight = FONT_HEIGHT_SIZE_PX + 1;// 多了一行

            const uint8_t characterWidth = CHARACTER_WIDTH_SIZE_PX;
            const uint8_t characterWidthByteSize = CHARACTER_WIDTH_SIZE_PX / 8;
            const uint8_t characterByteSize = fontHeight * characterWidth / 8;// 一个汉字所占字节空间

            const uint8_t letterWidth = LETTER_WIDTH_SIZE_PX;
            const uint8_t letterWidthByteSize = LETTER_WIDTH_SIZE_PX / 8;
            const uint8_t letterByteSize = fontHeight * letterWidth / 8;// 一个Ascll所占字节空间

            uint8_t lineBitmap[DOT_LINE_SIZE] = {0};

            for (uint8_t i = 0; i < fontHeight; i++) {
                uint8_t currentIdx = 0;
                uint8_t offsetStoreIdx = 0;
                while (lineP[currentIdx] != '\0') {
                    uint8_t q, w;
                    uint32_t offsetAddress;
                    if (lineP[currentIdx] & 0x80) {
                        // then is character
                        q = lineP[currentIdx] - 0xA0;
                        w = lineP[currentIdx + 1] - 0xA0;
                        offsetAddress = (94 * (q - 1) + (w - 1)) * characterByteSize;
                        FontBitmap::readData(offsetAddress + (characterWidthByteSize * i), lineBitmap + offsetStoreIdx, characterWidthByteSize);
                        offsetStoreIdx += characterWidthByteSize;
                        currentIdx += 2;
                    } else {
                        // then is letter
                        q = lineP[currentIdx];
                        offsetAddress = 0x1078D0L + (q - 0x20) * letterByteSize;
                        FontBitmap::readData(offsetAddress + (letterWidthByteSize * i), lineBitmap + offsetStoreIdx, letterWidthByteSize);
                        offsetStoreIdx += letterWidthByteSize;
                        currentIdx += 1;
                    }
                }
                memcpy(Printer::dotLine, lineBitmap, DOT_LINE_SIZE);
                Printer::printerPrintDotLine();
                memset(lineBitmap, 0x00, sizeof((char *) lineBitmap));
            }
            Printer::printerPrintLineSpace();
        } else if (event.status == osEventTimeout) {
            // overtime
        } else {
            // error
        }
        osDelay(10);
    }
}

void printPicTask(void const *argument) {
    for (;;) {
        LED::ledOff();// 没有打印
        ulTaskNotifyTake(pdTRUE, osWaitForever);
        LED::ledOn();// 打印中
    }
}

void rollPaperTask(void const *argument) {
    for (;;) {
        ulTaskNotifyTake(pdTRUE, osWaitForever);
        //        serial.serialPrintf("滚纸中…… \r\n");
        for (uint8_t i = 0; i < 8; i++) {
            Printer::printerPrintSegment();
        }
        osDelay(10);
    }
}
#include "Serial.h"

char Serial::rxBuffer[LINE_MAX_BYTE + 1];
char Serial::aRxBuffer;

uint8_t Serial::currentIdx = 0;
uint8_t Serial::storedByteCount = 0;
uint8_t Serial::restLineByte = LINE_MAX_BYTE - Serial::storedByteCount;
uint8_t Serial::characterFlag = 0;

void Serial::serialSendString(UART_HandleTypeDef *huart, const char *str) {
    HAL_UART_Transmit(huart, reinterpret_cast<const uint8_t *>(str), strlen(str), HAL_MAX_DELAY);
}

void Serial::serialPrintf(UART_HandleTypeDef *huart, char *format, ...) {
    char String[strlen(format) + 5];
    va_list arg;
    va_start(arg, format);
    vsprintf(String, format, arg);
    va_end(arg);
    serialSendString(huart, String);
}

void Serial::handleRxCplt(UART_HandleTypeDef *huart) {
    //    static char lineBuffer[LINE_MAX_BYTE + 1];
    if (huart->Instance == USART2) {
        if (aRxBuffer != '\n') {
            if (aRxBuffer != '\r') {// 不能将 '\r' 录入打印字符中
                processBuffer();
                rxBuffer[currentIdx++] = aRxBuffer;
            }
        } else {
            putLineBuffer();
        }
        HAL_UART_Receive_IT(huart, (uint8_t *) &aRxBuffer, 1);
    }
}

void Serial::processBuffer() {
    if (aRxBuffer & 0x80) {
        // then is character
        if (restLineByte < CHARACTER_BYTE_WIDTH) {
            // then send to queue, rest byte not enough for character
            if (characterFlag != 1) {
                putLineBuffer();
            }
        }
        storedByteCount += CHARACTER_BYTE_WIDTH / RX_CHARACTER_BYTE_WIDTH;
        restLineByte = LINE_MAX_BYTE - storedByteCount;
        characterFlag += 1;
        characterFlag %= 2;
    } else {
        // then is letter
        if (restLineByte < LETTER_BYTE_WIDTH) {
            // then send to queue, rest byte not enough for letter
            putLineBuffer();
        }
        storedByteCount += LETTER_BYTE_WIDTH / RX_LETTER_BYTE_WIDTH;
        restLineByte = LINE_MAX_BYTE - storedByteCount;
    }
}

void Serial::putLineBuffer() {
    rxBuffer[currentIdx] = '\0';
    char *linePointer = static_cast<char *>(malloc(currentIdx + 1));
    if (linePointer != NULL) {
        strcpy(linePointer, rxBuffer);
        if (osMessagePut(rxDataQueueHandle, (uint32_t) linePointer, 0) != osOK) {
            free(linePointer);
        }
    }
    //    memset(rxBuffer, 0x00, sizeof(rxBuffer));
    currentIdx = 0;
    storedByteCount = 0;
    restLineByte = LINE_MAX_BYTE - storedByteCount;
}

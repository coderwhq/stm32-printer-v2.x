#include "Printer.h"

uint8_t Printer::dotLine[DOT_LINE_SIZE] = {0};

void Printer::printerLATEnable() {
    HAL_GPIO_WritePin(PRINTER_LAT_GPIO_Port, PRINTER_LAT_Pin, GPIO_PIN_RESET);
}

void Printer::printerLATDisable() {
    HAL_GPIO_WritePin(PRINTER_LAT_GPIO_Port, PRINTER_LAT_Pin, GPIO_PIN_SET);
}

void Printer::printerHeatTotalEnable() {
    PRINTER_STBs_GPIO_PORT->BSRR = (PRINTER_STB1_Pin | PRINTER_STB2_Pin | PRINTER_STB3_Pin | PRINTER_STB4_Pin | PRINTER_STB5_Pin | PRINTER_STB6_Pin);
}

void Printer::printerHeatTotalDisable() {
    PRINTER_STBs_GPIO_PORT->BSRR = (PRINTER_STB1_Pin | PRINTER_STB2_Pin | PRINTER_STB3_Pin | PRINTER_STB4_Pin | PRINTER_STB5_Pin | PRINTER_STB6_Pin) << 16;
}

void Printer::printerHeatCircle() {
    HAL_GPIO_WritePin(PRINTER_STB1_GPIO_Port, PRINTER_STB1_Pin, GPIO_PIN_SET);
    osDelay(HEAT_TIME);
    HAL_GPIO_WritePin(PRINTER_STB1_GPIO_Port, PRINTER_STB1_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(PRINTER_STB2_GPIO_Port, PRINTER_STB2_Pin, GPIO_PIN_SET);
    osDelay(HEAT_TIME);
    HAL_GPIO_WritePin(PRINTER_STB2_GPIO_Port, PRINTER_STB2_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(PRINTER_STB3_GPIO_Port, PRINTER_STB3_Pin, GPIO_PIN_SET);
    osDelay(HEAT_TIME);
    HAL_GPIO_WritePin(PRINTER_STB3_GPIO_Port, PRINTER_STB3_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(PRINTER_STB4_GPIO_Port, PRINTER_STB4_Pin, GPIO_PIN_SET);
    osDelay(HEAT_TIME);
    HAL_GPIO_WritePin(PRINTER_STB4_GPIO_Port, PRINTER_STB4_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(PRINTER_STB5_GPIO_Port, PRINTER_STB5_Pin, GPIO_PIN_SET);
    osDelay(HEAT_TIME);
    HAL_GPIO_WritePin(PRINTER_STB5_GPIO_Port, PRINTER_STB5_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(PRINTER_STB6_GPIO_Port, PRINTER_STB6_Pin, GPIO_PIN_SET);
    osDelay(HEAT_TIME);
    HAL_GPIO_WritePin(PRINTER_STB6_GPIO_Port, PRINTER_STB6_Pin, GPIO_PIN_RESET);
}

void Printer::printerClearDotLineArray() {
    memset(dotLine, 0, sizeof(dotLine));
}

void Printer::printerSendDotLineData(bool autoClear) {

    for (uint8_t i = 0; i < DOT_LINE_SIZE; i++) {
        MySPI::transmitByte(PrinterSPIx, dotLine + i, 1);// 先用值传递
    }

    printerLATEnable();
    osDelay(LAT_TIME);
    printerLATDisable();

    if (autoClear) {
        printerClearDotLineArray();
    }
}

void Printer::printerPrintDotLine() {
    printerSendDotLineData(true);

#if !USE_CIRCLE_HEAT
    printerHeatTotalEnable();
    osDelay(HEAT_TIME);
    printerHeatTotalDisable();
#else
    printerHeatCircle();
#endif

    printerRunDotLine();
}

void Printer::printerRunDotLine() {
    motorRunCircle(DOT_LINE_RUN_STEP);
}

void Printer::printerPrintLineSpace() {
    motorRunCircle(LINE_SPACE_RUN_STEP);
}

void Printer::printerPrintSegment() {
    motorRunCircle(SEGMENT_SPACE_RUN_STEP);
}

void Printer::printerHeatCustom(uint8_t selectSTB, uint8_t heatTime, uint8_t isCircleHeat) {
    uint16_t tempSTBPins[] = {PRINTER_STB1_Pin, PRINTER_STB2_Pin, PRINTER_STB3_Pin,
                              PRINTER_STB4_Pin, PRINTER_STB5_Pin, PRINTER_STB6_Pin};
    if (isCircleHeat) {
        for (uint8_t i = 0; i < 6; i++) {
            if (selectSTB & (0x01 << i)) {
                HAL_GPIO_WritePin(PRINTER_STBs_GPIO_PORT, tempSTBPins[i], GPIO_PIN_SET);
                osDelay(heatTime);
                HAL_GPIO_WritePin(PRINTER_STBs_GPIO_PORT, tempSTBPins[i], GPIO_PIN_RESET);
            }
        }
    } else {
        uint16_t portVal = 0x0000;
        for (uint8_t i = 0; i < 6; i++) {
            if (selectSTB & (0x01 << i)) {
                portVal |= tempSTBPins[i];
            }
        }
        PRINTER_STBs_GPIO_PORT->BSRR = portVal;
        osDelay(heatTime);
        PRINTER_STBs_GPIO_PORT->BSRR = portVal << 16;
    }
}

void Printer::printerPrintDotLineCustom(uint8_t autoClear, uint8_t selectSTB, uint8_t heatTime, uint8_t isCircleHeat, uint8_t autoRunDotLine) {

    printerSendDotLineData(autoClear);

    printerHeatCustom(selectSTB, heatTime, isCircleHeat);

    if (autoRunDotLine) {
        printerRunDotLine();
    }
}
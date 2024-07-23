#ifndef STM32_PRINTER_V2_X_PRINTER_H
#define STM32_PRINTER_V2_X_PRINTER_H

#include "MySPI.h"
#include "StepperMotor.h"
#include "main.h"

#define PrinterSPIx &PRINTER_SPIx

class Printer : public StepperMotor {
private:
public:
    Printer() = default;
    static uint8_t dotLine[DOT_LINE_SIZE];
    static void printerLATEnable();
    static void printerLATDisable();
    static void printerHeatTotalEnable();
    static void printerHeatTotalDisable();
    static void printerHeatCircle();
    static void printerClearDotLineArray();
    static void printerSendDotLineData(bool autoClear);
    static void printerPrintDotLine();
    static void printerRunDotLine();
    static void printerPrintLineSpace();
    static void printerPrintSegment();
    static void printerHeatCustom(uint8_t selectSTB, uint8_t heatTime, uint8_t isCircleHeat);
    static void printerPrintDotLineCustom(uint8_t autoClear, uint8_t selectSTB, uint8_t heatTime, uint8_t isCircleHeat, uint8_t autoRunDotLine);
};

#endif//STM32_PRINTER_V2_X_PRINTER_H

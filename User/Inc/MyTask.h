#ifndef STM32_PRINTER_V2_X_MYTASK_H
#define STM32_PRINTER_V2_X_MYTASK_H

#include "FontBitmap.h"
#include "LED.h"
#include "Printer.h"
#include "Serial.h"
#include "cmsis_os.h"
#include "main.h"

extern "C" {
void initialTestTaskFun(void const *argument);
void waitPrintMsgTask(void const *argument);
void printTask(void const *argument);
void printPicTask(void const *argument);
void rollPaperTask(void const *argument);
}

#endif//STM32_PRINTER_V2_X_MYTASK_H

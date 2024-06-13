#ifndef STM32_PRINTER_V2_X_MYTASK_H
#define STM32_PRINTER_V2_X_MYTASK_H

#include "LED.h"
#include "Serial.h"
#include "cmsis_os.h"
#include "main.h"

extern "C" {
void initialTestTaskFun(void const *argument);
}

#endif//STM32_PRINTER_V2_X_MYTASK_H

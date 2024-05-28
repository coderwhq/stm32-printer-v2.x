#ifndef STM32_PRINTER_V2_X_LED_H
#define STM32_PRINTER_V2_X_LED_H

#include "main.h"
#include "stm32f1xx_hal.h"

#define USE_LOW_LEVEL_DRIVE 1

#if USE_LOW_LEVEL_DRIVE
#define ON GPIO_PIN_RESET
#define OFF GPIO_PIN_SET
#else
#define ON GPIO_PIN_SET
#define OFF GPIO_PIN_RESET
#endif

class LED {
public:
    LED() = default;
    static void ledOn();
    static void ledOff();
    static void ledToggle();
};

#endif//STM32_PRINTER_V2_X_LED_H

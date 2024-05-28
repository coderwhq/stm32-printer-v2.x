#ifndef STM32_PRINTER_V2_X_LED_H
#define STM32_PRINTER_V2_X_LED_H

#include "main.h"
#include "stm32f1xx_hal.h"

class LED {
public:
    LED() = default;
    static void ledOn();
    static void ledOff();
    static void ledToggle();
};

#endif//STM32_PRINTER_V2_X_LED_H

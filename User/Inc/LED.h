#ifndef STM32_PRINTER_V2_X_LED_H
#define STM32_PRINTER_V2_X_LED_H

class LED {
public:
    LED() = default;
    static void ledOn();
    static void ledOff();
};

#endif//STM32_PRINTER_V2_X_LED_H
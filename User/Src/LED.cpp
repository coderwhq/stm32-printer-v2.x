#include "LED.h"
#include "UserConfig.h"
#include "stm32f1xx_hal.h"

void LED::ledOn() {
    HAL_GPIO_WritePin(LED_PIN_PORT, LED_PIN, ON);
}
void LED::ledOff() {
    HAL_GPIO_WritePin(LED_PIN_PORT, LED_PIN, OFF);
}

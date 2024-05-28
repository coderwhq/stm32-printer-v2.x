#include "LED.h"

void LED::ledOn() {
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, ON);
}
void LED::ledOff() {
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, OFF);
}
void LED::ledToggle() {
    if (HAL_GPIO_ReadPin(LED_GPIO_Port, LED_Pin) == ON) {
        LED::ledOff();
    } else {
        LED::ledOn();
    }
}

#include "LED.h"
#include "main.h"
#include "stm32f1xx_hal.h"

void LED::ledOn() {
    HAL_GPIO_WritePin(LED_PIN_GPIO_Port, LED_PIN_Pin, ON);
}
void LED::ledOff() {
    HAL_GPIO_WritePin(LED_PIN_GPIO_Port, LED_PIN_Pin, OFF);
}

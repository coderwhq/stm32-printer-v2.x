#include "StepperMotor.h"

StepperMotor::StepperMotor() {
    uint8_t tempMotorTable[8][4] = {
            {1, 0, 0, 0},
            {1, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 1, 1},
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
    };
    memcpy(motorTable, tempMotorTable, sizeof(tempMotorTable));
}

void StepperMotor::motorRunOneStep(uint8_t idx) {
    HAL_GPIO_WritePin(PRINTER_A1_GPIO_Port, PRINTER_A1_Pin, (GPIO_PinState) motorTable[idx][0]); /* A */
    HAL_GPIO_WritePin(PRINTER_B1_GPIO_Port, PRINTER_B1_Pin, (GPIO_PinState) motorTable[idx][1]); /* B */
    HAL_GPIO_WritePin(PRINTER_A2_GPIO_Port, PRINTER_A2_Pin, (GPIO_PinState) motorTable[idx][2]); /* A- */
    HAL_GPIO_WritePin(PRINTER_B2_GPIO_Port, PRINTER_B2_Pin, (GPIO_PinState) motorTable[idx][3]); /* B- */
}
void StepperMotor::motorStop() {
    HAL_GPIO_WritePin(PRINTER_A1_GPIO_Port, PRINTER_A1_Pin, (GPIO_PinState) 0); /* A */
    HAL_GPIO_WritePin(PRINTER_B1_GPIO_Port, PRINTER_B1_Pin, (GPIO_PinState) 0); /* B */
    HAL_GPIO_WritePin(PRINTER_A2_GPIO_Port, PRINTER_A2_Pin, (GPIO_PinState) 0); /* A- */
    HAL_GPIO_WritePin(PRINTER_B2_GPIO_Port, PRINTER_B2_Pin, (GPIO_PinState) 0); /* B- */
}

void StepperMotor::motorRunCircle(uint16_t step) {
    static uint8_t currentIdx = 0;
    for (uint16_t i = 0; i < step; i++) {
        motorRunOneStep(currentIdx);
        osDelay(4);
        currentIdx++;
        if (currentIdx >= 8) {
            currentIdx = 0;
        }
    }
    motorStop();
}
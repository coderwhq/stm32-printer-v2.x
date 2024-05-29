#ifndef STM32_PRINTER_V2_X_STEPPERMOTOR_H
#define STM32_PRINTER_V2_X_STEPPERMOTOR_H

#include "cmsis_os.h"
#include "cstring"
#include "main.h"

class StepperMotor {
private:
    uint8_t motorTable[8][4] = {};
    void motorRunOneStep(uint8_t idx);
    static void motorStop();

public:
    StepperMotor();
    void motorRunCircle(uint16_t step);
};


#endif//STM32_PRINTER_V2_X_STEPPERMOTOR_H

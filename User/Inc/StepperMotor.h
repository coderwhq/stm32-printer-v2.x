#ifndef STM32_PRINTER_V2_X_STEPPERMOTOR_H
#define STM32_PRINTER_V2_X_STEPPERMOTOR_H

#include "cmsis_os.h"
#include "cstring"
#include "main.h"

class StepperMotor {
private:
    constexpr static const uint8_t motorTable[8][4] = {
            {1, 0, 0, 0},
            {1, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 1, 1},
            {0, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
    };
    static void motorRunOneStep(uint8_t idx);
    static void motorStop();

public:
    StepperMotor() = default;
    static void motorRunCircle(uint16_t step);
};


#endif//STM32_PRINTER_V2_X_STEPPERMOTOR_H

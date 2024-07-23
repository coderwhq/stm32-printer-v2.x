#ifndef STM32_PRINTER_V2_X_SERIAL_H
#define STM32_PRINTER_V2_X_SERIAL_H

#include "cmsis_os.h"
#include "main.h"
#include "usart.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define RX_CHARACTER_BYTE_WIDTH 2
#define RX_LETTER_BYTE_WIDTH 1

class Serial {
private:
    static uint8_t currentIdx;
    static uint8_t storedByteCount;
    static uint8_t restLineByte;
    static uint8_t characterFlag;
    static void processBuffer();
    static void putLineBuffer();

public:
    static char rxBuffer[LINE_MAX_BYTE + 1];
    static char aRxBuffer;
    Serial() = default;
    static void serialSendString(UART_HandleTypeDef *huart, const char *str);
    static void serialPrintf(UART_HandleTypeDef *huart, char *format, ...);
    static void handleRxCplt(UART_HandleTypeDef *huart);
};

#endif//STM32_PRINTER_V2_X_SERIAL_H

#ifndef STM32_PRINTER_V2_X_MYSPI_H
#define STM32_PRINTER_V2_X_MYSPI_H

#include "main.h"

class MySPI {
private:
public:
    MySPI() = default;
    static void transmitByte(SPI_HandleTypeDef *spiX, uint8_t *pTxByte, uint16_t size);
    static void receiveByte(SPI_HandleTypeDef *spiX, uint8_t *pRxByte, uint16_t size);
};


#endif//STM32_PRINTER_V2_X_MYSPI_H

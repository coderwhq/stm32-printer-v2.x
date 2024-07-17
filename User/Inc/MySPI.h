#ifndef STM32_PRINTER_V2_X_MYSPI_H
#define STM32_PRINTER_V2_X_MYSPI_H

#include "main.h"

class MySPI {
private:
public:
    MySPI() = default;
    static void swapByte(SPI_HandleTypeDef *spiX, uint8_t pTxByte, uint8_t *pRxByte);
};


#endif//STM32_PRINTER_V2_X_MYSPI_H

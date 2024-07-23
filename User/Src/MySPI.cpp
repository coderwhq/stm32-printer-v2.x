#include "MySPI.h"

void MySPI::transmitByte(SPI_HandleTypeDef *spiX, uint8_t *pTxByte, uint16_t size) {
    HAL_SPI_Transmit(spiX, pTxByte, size, HAL_MAX_DELAY);
}

void MySPI::receiveByte(SPI_HandleTypeDef *spiX, uint8_t *pRxByte, uint16_t size) {
    HAL_SPI_Receive(spiX, pRxByte, size, HAL_MAX_DELAY);
}
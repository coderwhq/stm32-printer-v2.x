#include "MySPI.h"

void MySPI::swapByte(SPI_HandleTypeDef *spiX, uint8_t pTxByte, uint8_t *pRxByte) {
    HAL_SPI_TransmitReceive(spiX, &pTxByte, pRxByte, 1, HAL_MAX_DELAY);
}

#include "FontBitmap.h"

void FontBitmap::readData(uint32_t Address, uint8_t *DataArray, uint32_t Count) {
    uint32_t i;
    uint8_t *tempP;
    MySPI::swapByte(SPI, W25Q64_READ_DATA, tempP);
    MySPI::swapByte(SPI, Address >> 16, tempP);
    MySPI::swapByte(SPI, Address >> 8, tempP);
    MySPI::swapByte(SPI, Address, tempP);

    for (i = 0; i < Count; i++) {
        MySPI::swapByte(SPI, W25Q64_DUMMY_BYTE, DataArray + i);
    }
}

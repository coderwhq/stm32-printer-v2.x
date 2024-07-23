#include "FontBitmap.h"

void FontBitmap::readData(uint32_t Address, uint8_t *DataArray, uint16_t Count) {
    uint8_t command[4];
    command[0] = W25Q64_READ_DATA;
    command[1] = Address >> 16;
    command[2] = Address >> 8;
    command[3] = Address;
    
    Font_Bitmap_SPI_CS_Enable();
    MySPI::transmitByte(BitmapSPIx, command, 4);
    MySPI::receiveByte(BitmapSPIx, DataArray, Count);
    Font_Bitmap_SPI_CS_Disable();
}

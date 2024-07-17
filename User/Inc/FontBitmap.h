#ifndef STM32_PRINTER_V2_X_FONTBITMAP_H
#define STM32_PRINTER_V2_X_FONTBITMAP_H

#include "FontBitmap_Ins.h"
#include "MySPI.h"
#include "main.h"

#define SPI &FONT_BITMAP_SPIx

class FontBitmap {
private:
public:
    FontBitmap() = default;
    static void readData(uint32_t Address, uint8_t *DataArray, uint32_t Count);
};


#endif//STM32_PRINTER_V2_X_FONTBITMAP_H



#include <iostream>
#include <fstream>
#include <cstdint>

struct BITMAP_FILEHEADER
{
    uint16_t bfTybe;
    uint32_t bfSize;
    uint16_t bfreserved1;
    uint16_t bfreserved2;
    uint32_t bfOffBits;
};

struct BITMAP_INFOHEADER
{
	uint32_t size;
	uint32_t width;
	uint32_t height;
	uint16_t planes;
	uint16_t bitCount;
	uint32_t compression;
	uint32_t imageSize;
	uint32_t XpixelsPerM;
	uint32_t YpixelsPerM;
	uint32_t colorsUsed;
	uint32_t colorsImportant;
};

struct ColorTable
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t reserved;	
};

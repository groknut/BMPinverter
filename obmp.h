
#ifndef _OBMP_H_
#define _OBMP_H_

#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>

using namespace std;

#pragma pack(push,1)

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

struct BITMAP_COLORTABLE
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;	
};
#pragma pack(pop)

class OpenBMP
{
private:
	BITMAP_FILEHEADER fileHeader;
	BITMAP_INFOHEADER infoHeader;
public:
	OpenBMP(const std::string& filename);	
	std::pair<int, int> shape();
};

class OpenBMPError {};
class OpenBMPFormatError {};

ostream& operator << (ostream& out, const std::pair<int ,int>& shape);

#endif

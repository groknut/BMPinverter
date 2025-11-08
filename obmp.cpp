

#include "obmp.h"

OpenBMP::OpenBMP(const std::string& filename)
{
	std::ifstream in(filename, ios::binary);

	if (!in.is_open())
		throw OpenBMPError();

	in.read(
		reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader)		
	);
	
	in.read(
		reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader) 
	);

	if (fileHeader.bfTybe != 0x4D42)
		throw OpenBMPError();

	if (infoHeader.bitCount != 24)
		throw OpenBMPFormatError();			
}

std::pair<int, int> OpenBMP::shape()
{
	return std::make_pair(infoHeader.height, infoHeader.width);
}

ostream& operator << (ostream& out, const std::pair<int ,int>& shape)
{
	out << "(" << shape.first << ", " << shape.second << ")";
	return out;
}

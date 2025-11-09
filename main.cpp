

#include <iostream>
#include "obmp.h"

int main(int argc, char** argv)
{
	if (argc < 2)
		return 0;
		
	if (argc == 2)
	{
		OpenBMP obmp = OpenBMP(argv[1]);
		std::cout << "Shape(y, x): " << obmp.shape();
        obmp.Mirrorvertical();
        obmp.saveImage("iversion_"+std::string(argv[1]));
        std::cout<<"inverted img saved as: "<<argv[1]<<std::endl;
	}
	
	return 0;
}

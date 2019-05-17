#include <iostream>
#include "BMPReader.h"

int main()
{
	image* newImage = BMPReader::readBMPFile("inputImage.bmp");
	system("pause");
	return 0;
}
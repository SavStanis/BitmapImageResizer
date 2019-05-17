#include <iostream>
#include "BMPReader.h"
#include "BMPWriter.h"

int main()
{
	image* newImage = BMPReader::readBMPFile("inputImage.bmp");

	BMPWriter::writeBMPFile("OutputImage.bmp", newImage);
	system("pause");
	return 0;
}
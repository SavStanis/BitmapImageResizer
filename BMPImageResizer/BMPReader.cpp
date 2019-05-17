
#include <iostream>
#include <fstream>
#include "BMPReader.h"

BMPReader::BMPReader() {}

image* BMPReader::readBMPFile(const char* pathToFile)
{
	image* newImage = new image();
	std::ifstream inputImage(pathToFile, std::ios::binary);	

	if (!inputImage)
	{
		std::cout << "Try again";
		return nullptr;
	}
	inputImage.read((char*)&newImage->header, sizeof(BMPHEAD)); 

	int padding = 0;
	if ((newImage->header.width * 3) % 4 != 0)
		padding = 4 - (newImage->header.width * 3) % 4;

	newImage->pixelMatrix = new PIXELDATA*[newImage->header.depth];
	for (int i = 0; i < newImage->header.depth; i++)
		newImage->pixelMatrix[i] = new PIXELDATA[newImage->header.width];

	int8_t tmpByte;

	for (int i = 0; i < newImage->header.depth; i++)
	{
		for (int j = 0; j < newImage->header.width; j++)
			inputImage.read((char*)&newImage->pixelMatrix[i][j], sizeof(PIXELDATA));
		for (int k = 0; k < padding; k++)
			inputImage.read((char*)&tmpByte, sizeof(int8_t));
	}

	inputImage.close();
}
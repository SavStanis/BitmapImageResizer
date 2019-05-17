#include "BMPWriter.h"
#include <iostream>
#include <fstream>

BMPWriter::BMPWriter() {}

void BMPWriter::writeBMPFile(const char* pathToFile, image* imageToWrite)
{
	std::ofstream outputOfImage(pathToFile, std::ios::binary);

	outputOfImage.write((char*)&imageToWrite->header, sizeof(BMPHEAD));

	int padding = 0;
	if ((imageToWrite->header.width * 3) % 4 != 0)
		padding = 4 - (imageToWrite->header.width * 3) % 4;

	uint8_t paddingByte = 0;

	for (int i = 0; i < imageToWrite->header.depth; i++)
	{
		for (int j = 0; j < imageToWrite->header.width; j++)
			outputOfImage.write((char*)&imageToWrite->pixelMatrix[i][j], sizeof(PIXELDATA));
		for (int k = 0; k < padding; k++)
			outputOfImage.write((char*)&paddingByte, sizeof(paddingByte));
	}
	outputOfImage.close();
}
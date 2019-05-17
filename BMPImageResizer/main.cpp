#include <iostream>
#include "BMPReader.h"
#include "BMPWriter.h"
#include "BMPResizer.h"

int main(int argc, char* argv[])
{
	char* first = argv[1];
	char* second = argv[2];
	double coef = atof(argv[3]);
	std::cout << first << " " << second << " " << coef;

	image* newImage = BMPReader::readBMPFile(first);
	image* finishImage = BMPResizer::resize(newImage, coef);
	BMPWriter::writeBMPFile(second, finishImage);
	return 0;
}
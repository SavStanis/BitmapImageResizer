#pragma once
#include "image.h"

class BMPWriter
{
public:
	BMPWriter();
	static void writeBMPFile(const char* pathToFile, image* imageToWrite);
};


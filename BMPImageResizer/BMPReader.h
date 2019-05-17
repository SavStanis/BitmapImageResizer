#pragma once
#include "image.h"

class BMPReader
{
public:
	BMPReader();
	static image* readBMPFile(const char* pathToFile);
};


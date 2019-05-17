#pragma once
#include <iostream>
#include <fstream>
#include "BMPStructures.h"

class image
{
public:
	BMPHEAD header;
	PIXELDATA** pixelMatrix;
};


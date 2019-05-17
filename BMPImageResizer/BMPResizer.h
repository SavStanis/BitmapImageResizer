#pragma once
#include "image.h"

class BMPResizer
{
	static void interpolation(image* startImage, image* finishImage);
public:
	BMPResizer();
	static image* resize(image* startImage, double coef);
};


#include "BMPResizer.h"



BMPResizer::BMPResizer()
{
}

image* BMPResizer::resize(image* startImage, double coef)
{
	int newHight = floor(startImage->header.depth * coef);
	int newWidth = floor(startImage->header.width * coef);

	int padding = 0;
	if ((newWidth * sizeof(PIXELDATA)) % 4 != 0)
		padding = 4 - (newWidth * 3) % 4;

	image* finishImage = new image();
	finishImage->header = startImage->header;
	finishImage->header.width = newWidth;
	finishImage->header.depth = newHight;
	finishImage->header.filesize = sizeof(BMPHEAD) + newHight * newWidth * sizeof(PIXELDATA) + padding * newHight;
	
	finishImage->pixelMatrix = new PIXELDATA*[newHight];
	for (int i = 0; i < newHight; i++)
		finishImage->pixelMatrix[i] = new PIXELDATA[newWidth];

	interpolation(startImage, finishImage);

	return finishImage;
}

void BMPResizer::interpolation(image* startImage, image* finishImage)
{
	float t;
	int x, y, x_diff, y_diff;
	float x_ratio = (((float)(startImage->header.depth - 1)) / finishImage->header.depth);
	float y_ratio = (((float)(startImage->header.width - 1)) / finishImage->header.width);
	float d1, d2, d3, d4;
	PIXELDATA p1, p2, p3, p4, tmp;

	for (int i = 0; i < finishImage->header.depth; i++) {
		for (int j = 0; j < finishImage->header.width; j++) {

			x = floor(x_ratio*i);
			y = floor(y_ratio*j);
			x_diff = (x_ratio*i) - x;
			y_diff = (y_ratio*j) - y;

			d1 = (1 - x_diff) * (1 - y_diff);
			d2 = x_diff * (1 - y_diff);
			d3 = x_diff * y_diff;
			d4 = (1 - x_diff) * y_diff;

			p1 = startImage->pixelMatrix[x][y];
			p2 = startImage->pixelMatrix[x][y + 1];
			p3 = startImage->pixelMatrix[x + 1][y + 1];
			p4 = startImage->pixelMatrix[x + 1][y];

			tmp.blueComponent = p1.blueComponent * d1 + p2.blueComponent * d2 + p3.blueComponent*d3 + p4.blueComponent*d4;
			tmp.greenComponent = p1.greenComponent*d1 + p2.greenComponent*d2 + p3.greenComponent*d3 + p4.greenComponent*d4;
			tmp.redComponent = p1.redComponent*d1 + p2.redComponent*d2 + p3.redComponent*d3 + p4.redComponent*d4;

			finishImage->pixelMatrix[i][j] = tmp;
		}
	}
}
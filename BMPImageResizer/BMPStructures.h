#pragma once
#include <stdint.h>

#pragma pack(2)
typedef struct BMPHEAD
{
	int8_t id[2];          
	int32_t filesize;      
	int16_t reserved[2];     
	int32_t headersize;      
	int32_t infoSize;        
	int32_t width;           
	int32_t depth;           
	int16_t biPlanes;        
	int16_t bits;            
	int32_t biCompression;   
	int32_t biSizeImage;     
	int32_t biXPelsPerMeter; 
	int32_t biYPelsPerMeter; 
	int32_t biClrUsed;       
	int32_t biClrImportant;  
};

typedef struct PIXELDATA 
{
	int8_t redComponent;
	int8_t greenComponent;
	int8_t blueComponent;
} ;
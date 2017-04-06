#include "stdafx.h"
#include "MyBitmap.h"
#include <stdlib.h>


MyBitmap::MyBitmap()
{
	memset(red, 0, sizeof(red));
	memset(green, 0, sizeof(green));
	memset(blue, 0, sizeof(blue));
}

void MyBitmap::WriteImageToFile(char *strFileName)
{
	FILE *f;
	unsigned char *img = NULL;
	int filesize = 54 + 3 * IMAGE_WIDTH * IMAGE_HEIGHT;
	if (img)
		free(img);
	img = (unsigned char *)malloc(3 * IMAGE_WIDTH * IMAGE_HEIGHT);
	memset(img, 0, sizeof(img));

	for (int i = 0; i<IMAGE_WIDTH; i++)
	{
		for (int j = 0; j<IMAGE_HEIGHT; j++)
		{
			img[(i + j*IMAGE_WIDTH) * 3 + 2] = red[i][j];
			img[(i + j*IMAGE_WIDTH) * 3 + 1] = green[i][j];
			img[(i + j*IMAGE_WIDTH) * 3 + 0] = blue[i][j];
		}
	}

	unsigned char bmpfileheader[14] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0 };
	unsigned char bmpinfoheader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
	unsigned char bmppad[3] = { 0,0,0 };

	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);

	bmpinfoheader[4] = (unsigned char)(IMAGE_WIDTH);
	bmpinfoheader[5] = (unsigned char)(IMAGE_WIDTH >> 8);
	bmpinfoheader[6] = (unsigned char)(IMAGE_WIDTH >> 16);
	bmpinfoheader[7] = (unsigned char)(IMAGE_WIDTH >> 24);
	bmpinfoheader[8] = (unsigned char)(IMAGE_HEIGHT);
	bmpinfoheader[9] = (unsigned char)(IMAGE_HEIGHT >> 8);
	bmpinfoheader[10] = (unsigned char)(IMAGE_HEIGHT >> 16);
	bmpinfoheader[11] = (unsigned char)(IMAGE_HEIGHT >> 24);

	fopen_s(&f,strFileName, "wb");
	fwrite(bmpfileheader, 1, 14, f);
	fwrite(bmpinfoheader, 1, 40, f);
	for (int i = 0; i<IMAGE_HEIGHT; i++)
	{
		fwrite(img + (IMAGE_WIDTH*(IMAGE_HEIGHT - i - 1) * 3), 3, IMAGE_WIDTH, f);
		fwrite(bmppad, 1, (4 - (IMAGE_WIDTH * 3) % 4) % 4, f);
	}
	fclose(f);
}

void MyBitmap::DrawPoint(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
	if (x < 0 || y < 0 || x >= IMAGE_WIDTH || y >= IMAGE_HEIGHT)
		return;
	red[x][y] = r;
	green[x][y] = g;
	blue[x][y] = b;
}

MyBitmap::~MyBitmap()
{
}

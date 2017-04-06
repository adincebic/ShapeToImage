#include "stdafx.h"
#include "Rectangle.h"
#include "MyBitmap.h"


Rectangle::Rectangle()
{
}

Rectangle::Rectangle(int x1,int y1,int x2,int y2, unsigned char cR, unsigned char cG, unsigned char cB) : Shape (cR,cG,cB)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

Rectangle::~Rectangle()
{
}

void Rectangle::Draw(MyBitmap * bmp)
{
	for (int ix = x1; ix <= x2; ix++)
		for (int iy = y1; iy <= y2; iy++)
		{
			bmp->DrawPoint(ix, iy, cR, cG, cB);
		}
}



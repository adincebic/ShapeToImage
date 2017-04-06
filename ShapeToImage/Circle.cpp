#include "stdafx.h"
#include "Circle.h"
#include "MyBitmap.h"


Circle::Circle()
{
}

Circle::Circle(int x,int y,int r, unsigned char cR, unsigned char cG, unsigned cB) : Shape(cR,cG,cB)
{
	this->x = x;
	this->y = y;
	this->radius = r;
}


Circle::~Circle()
{
}

void Circle::Draw(MyBitmap *bmp)
{
	for (int ix = x - radius; ix <= x + radius; ix++)
		for (int iy = y - radius; iy <= y + radius; iy++)
		{
			if (IsIncludePoint(ix, iy))
				bmp->DrawPoint(ix, iy, cR, cG, cB);
		}
}

bool Circle::IsIncludePoint(int px, int py)
{
	return radius*radius>=(px-x)*(px-x)+(py-y)*(py-y);
}

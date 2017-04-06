#include "stdafx.h"
#include "Triangle.h"
#include "MyBitmap.h"
#include <math.h>

Triangle::Triangle()
{
}

Triangle::Triangle(int x1,int y1, int x2, int y2, int x3, int y3, unsigned char cR, unsigned cG, unsigned cB) : Shape(cR,cG,cB)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
}

Triangle::~Triangle()
{
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}

bool Triangle::IsIncludePoint(int px, int py)
{
	int as_x = px - x1;
	int as_y = py - y1;

	bool s_ab = (x2 - x1)*as_y - (y2 - y1)*as_x > 0;

	if ((x3 - x1)*as_y - (y3 - y1)*as_x > 0 == s_ab) return false;

	if ((x3 - x2)*(py - y2) - (y3 - y2)*(px - x2) > 0 != s_ab) return false;

	return true;
}


void Triangle::Draw(MyBitmap * bmp)
{
	int px = min(min(x1, x2), x3);
	int py = min(min(y1, y2), y3);
	int qx = max(max(x1, x2), x3);
	int qy = max(max(y1, y2), y3);

	for (int ix = px; ix <= qx; ix++)
		for (int iy = py; iy <= qy; iy++)
		{
			if (IsIncludePoint(ix, iy))
				bmp->DrawPoint(ix, iy, cR, cG, cB);
		}
}

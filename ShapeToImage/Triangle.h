#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
	int x1, y1;
	int x2, y2;
	int x3, y3;
public:
	Triangle();
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned char cR, unsigned cG, unsigned cB);
	~Triangle();
	bool IsIncludePoint(int px, int py);
	virtual void Draw(MyBitmap *bmp);
};


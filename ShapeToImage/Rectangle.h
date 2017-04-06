#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
private:
	int x1, y1;
	int x2, y2;
public:
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2, unsigned char cR, unsigned char cG, unsigned char cB);
	~Rectangle();

	virtual void Draw(MyBitmap *bmp);
};


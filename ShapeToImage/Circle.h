#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
private:
	int x, y;
	int radius;
public:
	Circle();
	Circle(int x, int y, int r, unsigned char cR, unsigned char cG, unsigned cB);
	~Circle();

	virtual void Draw(MyBitmap *bmp);
	bool IsIncludePoint(int px, int py);
};


#pragma once

class MyBitmap;
class Shape
{
protected:
	unsigned char cR;
	unsigned char cG;
	unsigned char cB;
public:
	Shape();
	Shape(unsigned char r, unsigned char g, unsigned char b);
	~Shape();

	virtual void Draw(MyBitmap* bmp);
};


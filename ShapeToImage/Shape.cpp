#include "stdafx.h"
#include "Shape.h"
#include "MyBitmap.h"

Shape::Shape()
{
}

Shape::Shape(unsigned char r, unsigned char g, unsigned char b)
{
	cR = r;
	cG = g;
	cB = b;
}

Shape::~Shape()
{
}

void Shape::Draw(MyBitmap *bmp)
{

}

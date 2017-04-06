// ShapeToImage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyBitmap.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

int main()
{
	char str[256],str1[256];
	MyBitmap bmp;

	Circle *cir;
	Triangle *tri;
	Rectangle *rec;

	while (1)
	{
		printf("1)Circle\r\n2)Triangle\r\n3)Rectangle\r\n4)End\r\nPlease select a geometric shape:");
		int a,r,g,b,radius;
		int x, y, x1, y1, x2, y2, x3, y3;
		scanf_s("%d", &a);
		if (a == 4)
			break;
		printf("Please select a color (Red, Green, Blue):");
		scanf_s("%d %d %d", &r, &g, &b);

		switch (a)
		{
		case 1:
			printf("Please select a circle cordinates (x, y, radius):");
			scanf_s("%d %d %d", &x, &y, &radius);
			cir = new Circle(x, y, radius, r, g, b);
			cir->Draw(&bmp);
			delete(cir);
			break;
		case 2:
			printf("Please select a triangle cordinates (x1, y1, x2, y2, x3, y3):");
			scanf_s("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
			tri = new Triangle(x1, y1, x2, y2, x3, y3, r, g, b);
			tri->Draw(&bmp);
			delete(tri);
			break;
		case 3:
			printf("Please select a rectangle cordinates (x1, y1, x2, y2):");
			scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
			rec = new Rectangle(x1, y1, x2, y2, r, g, b);
			rec->Draw(&bmp);
			break;
		default:
			printf("Invalid input! Please try again\r\n");
			break;
		}
	}

	printf("Please input image filename:");
	scanf_s("%s", str,255);
	sprintf_s(str1, "%s.bmp", str);
	bmp.WriteImageToFile(str1);
    return 0;
}


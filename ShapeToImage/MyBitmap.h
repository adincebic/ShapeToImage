#pragma once
class MyBitmap
{
private:
	unsigned char red[IMAGE_WIDTH][IMAGE_HEIGHT];
	unsigned char green[IMAGE_WIDTH][IMAGE_HEIGHT];
	unsigned char blue[IMAGE_WIDTH][IMAGE_HEIGHT];

public:
	MyBitmap();
	~MyBitmap();

	void DrawPoint(int x, int y, unsigned char r, unsigned char g, unsigned char b);
	void WriteImageToFile(char *strFileName);
};


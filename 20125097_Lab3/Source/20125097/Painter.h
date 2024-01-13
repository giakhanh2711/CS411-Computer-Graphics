#ifndef _PAINTER_H
#define _PAINTER_H

#include "Shape.h"
#include <queue>
#include <stack>
using namespace std;

typedef struct _RGBColor {
	unsigned char r; // 1 byte, stores 0 - 255
	unsigned char g;
	unsigned char b;
}RGBColor;

class Painter {
private:
	int screenHeight;
	int screenWidth;
	RGBColor F_Color, B_Color;

	static Painter* painter;
	Painter(int h, int w);
public:
	//Painter(int h, int w);
	static Painter* getInstance();
	
	void setColor(RGBColor F_Color, RGBColor B_Color);
	bool IsSameColor(RGBColor color1, RGBColor color2);
	RGBColor GetPixel(int x, int y);
	void PutPixel(int x, int y, RGBColor color); // Color for 1 location
	void BoundaryFill(int x, int y);
};


#endif

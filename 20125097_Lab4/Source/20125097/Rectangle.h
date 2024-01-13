#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape.h"

class Rectanglee : virtual public Shape{
public:
	Rectanglee(int xTL, int yTL, int w, int h);
	Rectanglee(int xS, int yS);

	//~Rectanglee() {};

	void drawSE();
	void draw();  // Draw with specific attributes
private:
	int xTL, yTL;
	int w, h;
};

#endif

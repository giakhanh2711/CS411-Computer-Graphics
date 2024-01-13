#ifndef _RIGHT_EQUAL_TRIANGLE_H
#define _RIGHT_EQUAL_TRIANGLE_H

#include "Shape.h"

class Right_Equal_Triangle: public Shape{
public:
	Right_Equal_Triangle(int xTop, int yTop, float edgeLength);
	Right_Equal_Triangle(int xS, int yS, int type);
	void draw();
	void drawSE();
private:
	int xTop, yTop;
	float edgeLength;

	int type;  // 0: right, 1: right-equal
};


#endif

#ifndef _RIGHT_EQUAL_TRIANGLE_H
#define _RIGHT_EQUAL_TRIANGLE_H

#include "Shape.h"

class Right_Equal_Triangle: public Shape{
public:
	Right_Equal_Triangle(int xTop, int yTop, int edgeLength);
	void draw();
private:
	int xTop, yTop;
	int edgeLength;
};


#endif

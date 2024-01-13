#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape.h"

class Rectanglee : public Shape{
public:
	Rectanglee(int xTL, int yTL, int w, int h);
	void draw();
private:
	int xTL, yTL;
	int w, h;
};

#endif

#ifndef _SQUARE_H
#define _SQUARE_H

#include "Rectangle.h"

class Square : public Rectanglee{
public:
	Square(int xTL, int yTL, int a) : Rectanglee(xTL, yTL, a, a) {};
	void draw();
};

#endif

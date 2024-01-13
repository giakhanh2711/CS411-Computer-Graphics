#ifndef _SQUARE_H
#define _SQUARE_H

#include "Rectangle.h"
#include "EquiPolygon.h"

class Square : public Rectanglee{
public:
	Square(int xTL, int yTL, int a) : Rectanglee(xTL, yTL, a, a) {};
	Square(int xS, int yS) : Rectanglee(xS, yS){};
	
	void draw();
	void drawSE();
};

#endif

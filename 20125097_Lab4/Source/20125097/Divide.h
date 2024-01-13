#ifndef _DIVIDE_H
#define _DIVIDE_H

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

class Divide : public Shape {
public:
	Divide(int xS, int yS, int lengthHorizon) : Shape(0, 0){
		this->xS = xS;
		this->yS = yS;
		this->lengthHorizon = lengthHorizon;
	}

	void draw() {
		float width = lengthHorizon / 8.0;
		float r = width;
		float xT = xS + lengthHorizon / 2.0;

		Shape* c = new Circle(xT, yS - lengthHorizon / 4.0 - r, r);
		c->draw();

		Shape* hcn = new Rectanglee(xS, yS - width / 2, lengthHorizon, width);
		hcn->draw();

		Shape* c2 = new Circle(xT, yS + lengthHorizon / 4.0 + r, r);
		c2->draw();

		delete c;
		delete hcn;
		delete c2;
	}

private:
	int xS, yS;
	int lengthHorizon;
};

#endif

#ifndef _SUBTRACT_H
#define _SUBTRACT_H

#include "Shape.h"

class Subtract : public Shape {
public:
	Subtract(int xS, int yS, int length) {
		this->xS = xS;
		this->yS = yS;
		this->length = length;
	}

	void draw() {
		float width = length / 6.0;

		glBegin(GL_LINE_LOOP);
		glVertex2f(xS, yS + width / 2);
		glVertex2f(xS, yS - width / 2);
		glVertex2f(xS + length, yS - width / 2);
		glVertex2f(xS + length, yS + width / 2);
		glEnd();
		glFlush();
	}

private:
	int xS, yS;
	int length;
};
#endif



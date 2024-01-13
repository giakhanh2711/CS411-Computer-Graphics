#include "Right_Equal_Triangle.h"
#include <math.h>

Right_Equal_Triangle::Right_Equal_Triangle(int xTop, int yTop, int edgeLength) {
	this->xTop = xTop;
	this->yTop = yTop;
	this->edgeLength = edgeLength;
}


void Right_Equal_Triangle::draw() {
	float r = edgeLength / sqrt(2);
	float xCenter = xTop, yCenter = yTop + r;

	glBegin(GL_LINE_LOOP);
	glVertex2i(xTop, yTop);
	glVertex2f(r + xCenter, 0 + yCenter);
	glVertex2f(-r + xCenter, 0 + yCenter);
	glEnd();
	glFlush();

}
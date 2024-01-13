#include "Right_Equal_Triangle.h"
#include <math.h>

Right_Equal_Triangle::Right_Equal_Triangle(int xTop, int yTop, float edgeLength) : Shape(0, 0){
	this->xTop = xTop;
	this->yTop = yTop;
	this->edgeLength = edgeLength;
	this->type = 1;
}


Right_Equal_Triangle::Right_Equal_Triangle(int xS, int yS, int type) : Shape(xS, yS) {
	xTop = yTop = edgeLength = 0;
	this->type = type;
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

void Right_Equal_Triangle::drawSE() {
	if (type == RIGHT_EQUAL) {
		setEndForEqui();
	}

	if (points.empty()) {
		points.push_back({ (float)xS, (float)yS });
		points.push_back({ (float)xS, (float)yF });
		points.push_back({ (float)xF, (float)yF });
	}

	Shape::drawSE();
}
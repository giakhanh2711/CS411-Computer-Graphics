#include "Rectangle.h"

Rectanglee::Rectanglee(int xTL, int yTL, int w, int h){
	this->xTL = xTL;
	this->yTL = yTL;
	this->w = w;
	this->h = h;
}


Rectanglee::Rectanglee(int xS, int yS) : Shape(xS, yS){
	xTL = yTL = w = h = 0;
}

void Rectanglee::draw() {
	glBegin(GL_LINE_LOOP);
		glVertex2d(xTL, yTL);
		glVertex2d(xTL, yTL + h);
		glVertex2d(xTL + w, yTL + h);
		glVertex2d(xTL + w, yTL);
	glEnd();
	glFlush();
}

void Rectanglee::drawSE() {
	if (points.empty()) {
		points.push_back({ (float)xS, (float)yS });
		points.push_back({ (float)xF, (float)yS });
		points.push_back({ (float)xF, (float)yF });
		points.push_back({ (float)xS, (float)yF });
	}
	
	Shape::drawSE();
}

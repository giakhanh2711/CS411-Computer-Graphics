#include "Rectangle.h"

Rectanglee::Rectanglee(int xTL, int yTL, int w, int h) {
	this->xTL = xTL;
	this->yTL = yTL;
	this->w = w;
	this->h = h;
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

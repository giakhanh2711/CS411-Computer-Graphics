#include "Arrow.h"

Arrow::Arrow(int length, int width, int xS, int yS){
	this->length = length;
	this->width = width;
	this->xS = xS;
	this->yS = yS;
}

void Arrow::draw() {
	float ratioW = 3;
	float ratioH = 1.0 / 4;

	glBegin(GL_LINE_LOOP);
	glVertex2f(xS, width / 2.0 + yS);
	glVertex2f(xS, -width / 2.0 + yS);
	glVertex2f(xS - length * (1.0 - ratioH), -width / 2.0 + yS);
	glVertex2f(xS - length * (1.0 - ratioH), -width / 2.0 + yS - width * ratioW / 3.0);
	glVertex2f(xS - length, yS);
	glVertex2f(xS - length * (1 - ratioH), width / 2.0 + yS + width * ratioW / 3);
	glVertex2f(xS - length * (1 - ratioH), width / 2.0 + yS);
	glEnd();

	glFlush();
}
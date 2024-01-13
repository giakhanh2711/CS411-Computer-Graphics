#include "Circle.h"
#include <Math.h>


Circle::Circle(int xT, int yT, int r){
	this->xT = xT;
	this->yT = yT;
	this->r = r;
}

// DRAW BY OPENGL
void Circle::drawByOpenGL() {
	float i = 0;
	
	glBegin(GL_LINE_LOOP);
	while (i <= 2 * PI){
		glVertex2f(xT + r * cos(i), yT + r * sin(i));
		
		i += 0.01;
	}
	glEnd();
	glFlush();
}

// DRAW BY MIDPOINT
void Circle::draw() {
	int x = 0, y = r;
	int p = 1 - r;

	while (y >= x) {
		putPixel(x + xT, y + yT);
		putPixel(-x + xT, y + yT);
		putPixel(-x + xT, -y + yT);
		putPixel(x + xT, -y + yT);
		putPixel(y + xT, x + yT);
		putPixel(-y + xT, x + yT);
		putPixel(y + xT, -x + yT);
		putPixel(-y + xT, -x + yT);
		
		x = x + 1;

		// Mid point inside circle
		if (p < 0)
			p = p + 2 * x + 3;
		else {
			p = p + 2 * x - 2 * y + 5;
			y = y - 1;
		}	
	}

	glFlush();
}
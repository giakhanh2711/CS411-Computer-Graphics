#include "Circle.h"
#include <cmath>

Circle::Circle(int xT, int yT, int r) {
	this->xT = xT;
	this->yT = yT;
	this->r = r;
}

// DRAW BY OPENGL
void Circle::drawByOpenGL() {
	glBegin(GL_LINES);

	for (int i = 0; i < 180; ++i) {
		glVertex2f(xT + r * cos(i), yT + r * sin(i));
		glVertex2f(xT + r * cos(i + 0.1), yT + r * sin(i + 0.1));
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
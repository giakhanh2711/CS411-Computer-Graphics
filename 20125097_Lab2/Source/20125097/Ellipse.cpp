#include "Ellipse.h"
#include <cmath>

Ellipsee::Ellipsee(int xT, int yT, int a, int b) {
	this->xT = xT;
	this->yT = yT;
	this->a = a;
	this->b = b;
}

void Ellipsee::draw4Point(int x, int y) {
	putPixel(x + xT, y + yT);
	putPixel(-x + xT, y + yT);
	putPixel(-x + xT, -y + yT);
	putPixel(x + xT, -y + yT);
}

void Ellipsee::draw() {
	float xq, yq, p01, p02;
	
	xq = (a * a) / sqrt(a * a + b * b);
	yq = (b * b) / sqrt(a * a + b * b);

	// Vẽ phần trên
	int x = 0, y = b;
	p01 = (b * b) - (a * a) * b + (a * a) / 4;
	while (x <= xq) {
		draw4Point(x, y);

		if (p01 < 0)
			p01 += (2 * x + 3) * (b * b);
		else {
			p01 += (2 * x + 3) * (b * b) - 2 * (a * a) * (y - 1);
			
			--y;
		}
		++x;
	}

	// Vẽ phần dưới
	x = a;
	y = 0;
	p02 = a * a - b * b * a + (b * b) / 4;
	while (x > xq) {
		draw4Point(x, y);
		
		if (p02 < 0)
			p02 += (2 * y + 3) * a * a;
		else {
			p02 += (2 * y + 3) * a * a - 2 * b * b * (x - 1);
			
			--x;
		}
		++y;
	}

	glFlush();
}

void Ellipsee::drawByOpenGL() {
	float i = 0;
	glBegin(GL_LINE_LOOP);
	while (i <= 2 * PI) {
		glVertex2f(a * cos(i) + xT, b * sin(i) + yT);
		
		i += 0.01;
	}
	glEnd();
	glFlush();
}
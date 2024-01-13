#include "Hyperbola.h"
#include <cmath>

Hyperbola::Hyperbola(int xT, int yT, int a, int b){
	this->xT = xT;
	this->yT = yT;
	this->a = a;
	this->b = b;
}

void Hyperbola::draw4Point(int x, int y) {
	putPixel(x + xT, y + yT);
	putPixel(-x + xT, y + yT);
	putPixel(-x + xT, -y + yT);
	putPixel(x + xT, -y + yT);
}

void Hyperbola::draw() {
	float xq, yq, p01, p02;

	xq = (a * a) / sqrt(a * a - b * b);
	yq = (b * b) / sqrt(a * a - b * b);

	int x = 2 * a, y = b;
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

	x = a;
	y = 0;
	p02 = -a * a + b * b * a + (b * b) / 4;
	while (x > xq) {
		draw4Point(x, y);

		if (p02 >= 0)
			p02 -= (2 * y + 3) * a * a;
		else {
			p02 += -1 * (2 * y + 3) * a * a + 2 * b * b * (x + 1);

			++x;
		}
		++y;
	}

	glFlush();
}

void Hyperbola::drawByOpenGL() {

}
#include "Parabola.h"
#include <iostream>

Parabola::Parabola(int xT, int yT, float p) {
	this->xT = xT;
	this->yT = yT;
	this->p = p;
}


void Parabola::draw() {
	int x = 0, y = 0;
	float k = 1 - 2 * p;
	int y_change = 1;

	if (y + yT > p)
		y_change = -1;

	if (y_change > 0) {
		while (y + yT >= 0 && y + yT <= HEIGHT && x + xT <= WIDTH && -x + xT >= 0) {
			putPixel(x + xT, y + yT);
			putPixel(-x + xT, y + yT);

			if (k < 0)
				k += (2 * x + 3);
			else {
				k += (2 * x + 3) - 4 * p;

				y += y_change;
			}
			++x;
		}
	}
	else {
		k = -1 - 2 * p;
		while (y + yT >= 0 && y + yT <= HEIGHT && x + xT <= WIDTH && -x + xT >= 0) {
			putPixel(x + xT, y + yT);
			putPixel(-x + xT, y + yT);

			if (k > 0)
				k -= (2 * x + 3);
			else {
				k += -1 * (2 * x + 3) + 4 * p;

				y += y_change;
			}
			++x;
		}

	}
	glFlush();
}


void Parabola::drawByOpenGL() {

}
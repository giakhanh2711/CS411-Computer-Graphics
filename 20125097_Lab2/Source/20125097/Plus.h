#ifndef _PLUS_H
#define _PLUS_H

#include "Shape.h"
#include <math.h>

class Plus : public Shape {
public:
	Plus(int xT, int yT, int length1In4) {
		this->xT = xT;
		this->yT = yT;
		this->length1In4 = length1In4;
	}

	void draw() {
		float width = 0.65 * length1In4;
		float r = width / 2 + length1In4;
		float x, y;

		float angle = 0;

		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 4; ++i) {
			x = r * cos(angle) + xT;
			y = r * sin(angle) + yT;
			glVertex2f(x + sin(angle) * width / 2, y - cos(angle) * width / 2);
			glVertex2f(x - sin(angle) * width / 2, y + cos(angle) * width / 2);
			glVertex2f(x - cos(angle) * length1In4 - sin(angle) * width / 2, y + cos(angle) * width / 2 - sin(angle) * length1In4);

			angle += PI / 2;
		}
		glEnd();
		glFlush();

	}
private:
	int xT, yT;
	int length1In4;
};

#endif

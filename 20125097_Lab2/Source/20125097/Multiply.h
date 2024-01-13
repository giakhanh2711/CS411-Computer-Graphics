#ifndef _MULTIPLY_H
#define _MULTIPLY_H

#include "Shape.h"
#include <math.h>

class Multiply : public Shape {
public:
	Multiply(int xT, int yT, int length1In4) {
		this->xT = xT;
		this->yT = yT;
		this->length1In4 = length1In4;
	}


	void draw() {
		float width = 0.55 * length1In4;
		float r1 = length1In4 + width / 2;
		float r2 = sqrt(2) * width / 2;
		float angle_big = PI / 4, angle_small = PI / 2;

		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < 4; ++i) {
			glVertex2f(r1 * cos(angle_big) + cos(i * PI / 2) * width / 2 / sqrt(2) + xT + sin(i * PI / 2) * width / 2 / sqrt(2),
					   r1 * sin(angle_big) + yT - cos(i * PI / 2) * width / 2 / sqrt(2) + sin(i * PI / 2) * width / 2 / sqrt(2));
			
			glVertex2f(r1 * cos(angle_big) - cos(i * PI / 2) * width / 2 / sqrt(2) + xT - sin(i * PI / 2) * width / 2 / sqrt(2),
					  r1 * sin(angle_big) + yT + cos(i * PI / 2) * width / 2 / sqrt(2) - sin(i * PI / 2) * width / 2 / sqrt(2));
			
			glVertex2f(r2 * cos(angle_small) + xT, r2 * sin(angle_small) + yT);

			angle_big += PI / 2;
			angle_small += PI / 2;
		}
		glEnd();
		glFlush();
	}

private:
	int xT, yT;
	int length1In4;
};

#endif

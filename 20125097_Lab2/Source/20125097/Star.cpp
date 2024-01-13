#include "Star.h"
#include <math.h>

int numOfEdges = 5;
int edgeLength = 100;

Star::Star(int xT, int yT) {
	this->xT = xT;
	this->yT = yT;
}

void Star::draw() {
	float angleAtCenter = (2 * PI) / numOfEdges;
	float r = edgeLength * sqrt(1.0 / (2 * (1 - cos(angleAtCenter))));
	float alpha = PI / 2 - angleAtCenter / 2;

	float small_r = (r - edgeLength * cos(3 * PI / 10)) / cos(PI / 5);
	float alpha_small = PI / 2;
	
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < numOfEdges; ++i) {
		glVertex2f(xT + r * cos(alpha), yT + r * sin(alpha));
		glVertex2f(xT + small_r * cos(alpha_small), yT + small_r * sin(alpha_small));
		alpha += angleAtCenter;
		alpha_small += angleAtCenter;
	}

	glEnd();
	glFlush();
}
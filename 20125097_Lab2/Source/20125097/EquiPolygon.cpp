#include "EquiPolygon.h"
#include <math.h>

EquiPolygon::EquiPolygon(int xT, int yT, int numOfEdges, int edgeLength) {
	this->xT = xT;
	this->yT = yT;
	this->numOfEdges = numOfEdges;
	this->edgeLength = edgeLength;
}

void EquiPolygon::draw() {
	float angleAtCenter = (2 * PI) / numOfEdges;
	float r = edgeLength * sqrt(1.0 / (2 * (1 - cos(angleAtCenter))));
	float alpha = PI / 2 - angleAtCenter / 2;
	
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < numOfEdges; ++i) {
		glVertex2f(xT + r * cos(alpha), yT + r * sin(alpha));
		alpha += angleAtCenter;
	}

	glEnd();
	glFlush();
}
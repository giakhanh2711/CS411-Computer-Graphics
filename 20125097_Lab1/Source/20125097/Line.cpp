#include "Line.h"
#include <cmath>


Line::Line(int x1, int y1, int x2, int y2, int type) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->type = type;
}

// DDA
void Line::drawDDA() {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int numOfSteps;

	if (abs(dx) > abs(dy))
		numOfSteps = abs(dx);
	else
		numOfSteps = abs(dy);

	float x_incr = (float)dx / numOfSteps;
	float y_incr = (float)dy / numOfSteps;

	float x = (float)x1, y = (float)y1;
	int step = 1;

	while (step <= numOfSteps) {
		putPixel(int(round(x)), int(round(y)));

		x += x_incr;
		y += y_incr;

		++step;
	}
	glFlush();
}

int Line::checkTrend(int delta) {
	if (delta < 0) return -1;
	if (delta == 0) return 0;
	if (delta > 0) return 1;
}

// BRESENHAM
void Line::drawBresenham() {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int x_change = checkTrend(dx);
	int y_change = checkTrend(dy);

	int isExchange = 0;
	if (abs(dy) > abs(dx)) {
		swap(dx, dy);
		isExchange = 1;
	}

	int x = x1, y = y1;
	int p = 2 * dy - dx;
	int const1 = 2 * dy;
	int const2 = 2 * (dy - dx);

	putPixel(x, y);

	if (isExchange == 0) {  // Chạy theo x
		if (y_change == -1)
			const2 += 4 * dx;
		if (x_change == -1) {
			const1 *= -1;
			const2 -= 4 * dy;
		}

		while (abs(x2 - x) > 0) {
			if (y_change * p < 0)
				p += const1;
			else {
				p += const2;
				y += y_change;
			}
			x += x_change;
			putPixel(x, y);
		}
	}
	else {
		if (x_change == -1)
			const2 += 4 * dx;
		if (y_change == -1) {
			const1 = const1 * -1;
			const2 -= 4 * dy;
		}

		while (abs(y2 - y) > 0) {
			if (x_change * p < 0)
				p += const1;
			else {
				p += const2;
				x += x_change;
			}
			y += y_change;
			putPixel(x, y);
		}
	}
	glFlush();
}


// DRAW
void Line::draw() {
	if (type == DDA)
		drawDDA();
	else if (type == BRESENHAM)
		drawBresenham();
}


// DRAW BY OPENGL
void Line::drawByOpenGL() {
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
	glFlush();
}


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

// x tang nhanh, y tang cham
void Line::drawType1() {
	int dx, dy, p, const1, const2, x, y;
	
	dx = x2 - x1;
	dy = y2 - y1;
	
	p = 2 * dy - dx;
	const1 = 2 * dy;
	const2 = 2 * dy - 2 * dx;

	x = x1;
	y = y1;

	while (x <= x2) {
		putPixel(x, y);

		if (p < 0)
			p += const1;
		else {
			p += const2;
			y += 1;
		}
		
		x += 1;
	}
	glFlush();
}

// x tang cham, y tang nhanh
void Line::drawType2() {
	int dx, dy, p, const1, const2, x, y;
	
	dx = x2 - x1; // 0
	dy = y2 - y1; // 200
	
	p = 2 * dx - dy; // -200
	const1 = 2 * dx;  // 0
	const2 = 2 * dx - 2 * dy; // -400

	x = x1;
	y = y1;

	while (y <= y2) {
		putPixel(x, y);

		if (p < 0)
			p += const1;
		else {
			p += const2;
			x += 1;
		}

		y += 1;
	}
	glFlush();
}

// x tang cham, y giam nhanh
void Line::drawType3() {
	int dx, dy, p, const1, const2, x, y;
	
	dx = x2 - x1;
	dy = y2 - y1;

	p = 2 * dx - dy;
	const1 = -2 * dx;
	const2 = -2 * dx - 2 * dy;

	x = x1;
	y = y1;

	while (y >= y2) {
		putPixel(x, y);

		if (p >= 0)
			p += const1;
		else {
			p += const2;
			x += 1;
		}

		y -= 1;
	}
	glFlush();
}

// x tang nhanh, y giam cham
void Line::drawType4() {
	int dx, dy, p, const1, const2, x, y;
	
	dx = x2 - x1;
	dy = y2 - y1;
	
	p = 2 * dy + dx;
	const1 = 2 * dy;
	const2 = 2 * dy + 2 * dx;

	x = x1;
	y = y1;

	while (x <= x2) {
		putPixel(x, y);

		if (p >= 0)
			p += const1;
		else {
			p += const2;
			y -= 1;
		}

		x += 1;
	}
	glFlush();
}


// BRESENHAM
void Line::drawBresenham() {
	if (x2 < x1) {
		swap(x1, x2);
		swap(y1, y2);
	}

	int dx = x2 - x1;
	int dy = y2 - y1;

	if (dx >= abs(dy) && dy >= 0)
		drawType1();
	else if (dx < abs(dy) && dy > 0)
		drawType2();
	else if (dx < abs(dy) && dy < 0)
		drawType3();
	else if (dx >= abs(dy) && dy < 0)
		drawType4();

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


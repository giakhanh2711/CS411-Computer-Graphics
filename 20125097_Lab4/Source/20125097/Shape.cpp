#include "Shape.h"

Shape::Shape(int xS, int yS) {
	this->xS = xS;
	this->yS = yS;
	this->xF = xS;
	this->yF = yS;
}

Shape::Shape() {
	xS = yS = xF = yF = 0;
}

Shape::~Shape() {
	clearPoints();
}

void Shape::setEnd(int xF, int yF) {
	this->xF = xF;
	this->yF = yF;
}

void Shape::putPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}


void Shape::setStart(int xS, int yS){
	this->xS = xS;
	this->yS = yS;
}

void Shape::setEndForEqui() {
	int dx = xF - xS;
	int dy = yF - yS;
	int sign = 1;

	if (abs(dx) < abs(dy)) {
		sign = (dy < 0) ? -1 : 1;
		Shape::setEnd(xF, yS + abs(dx) * sign);
	}
	else {
		sign = (dx < 0) ? -1 : 1;
		Shape::setEnd(xS + abs(dy) * sign, yF);
	}
}


void Shape::clearPoints() {
	for (auto v : points)
		v.clear();

	points.clear();
}

vector<vector<float>> Shape::getPoints() {
	return points;
}


void Shape::popPoint() {
	if (!points.empty())
		points.pop_back();
}

void Shape::updatePoints(vector<vector<float>> points) {
	clearPoints();
	for (auto v : points) {
		this->points.push_back(v);
	}
}


void Shape::drawSE() {
	glBegin(GL_LINE_LOOP);
	for (auto v : points)
		glVertex2fv(&v[0]);
	glEnd();
	glFlush();
}
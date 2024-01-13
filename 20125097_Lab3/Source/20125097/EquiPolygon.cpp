#include "EquiPolygon.h"
#include <math.h>

EquiPolygon::EquiPolygon(float xT, float yT, int numOfEdges, float edgeLength) : Shape(0, 0){
	this->xT = xT;
	this->yT = yT;
	this->numOfEdges = numOfEdges;
	this->edgeLength = edgeLength;
}


EquiPolygon::EquiPolygon(int xS, int yS, int type) : Shape(xS, yS) {
	this->xT = 0;
	this->yT = 0;
	this->numOfEdges = 0;
	this->edgeLength = 0;
	this->type = type;

	ratiosX[3] = { 0.5, 0 };
	ratiosY[3] = { 0, 1 };

	ratiosX[4] = { 0.5, 0, 0.5 };
	ratiosY[4] = { 0, 0.5, 1 };

	ratiosX[5] = { 0.5, 0, 0.2 };
	ratiosY[5] = { 0, 3.0 / 8, 1 };

	ratiosX[6] = { 0.5, 0, 0, 0.5 };
	ratiosY[6] = { 0, 1.0 / 4, 3.0 / 4, 1 };
}


EquiPolygon::EquiPolygon() {
	xT = 0;
	yT = 0;
	numOfEdges = 1;
	edgeLength = 0;
}


void EquiPolygon::setNumOfEdges(int numOfEdges) {
	this->numOfEdges = numOfEdges;
}


void EquiPolygon::setCoorCenter() { // For equi polygon
	setEndForEqui();

	float angleAtCenter = (2 * PI) / numOfEdges;
	float r = abs(xF - xS) / 2.0;
	
	this->edgeLength = sqrt(2 * r * r - 2 * r * r * cos(angleAtCenter));
	this->xT = xS + (xF - xS) / 2.0;
	this->yT = yS + (yF - yS) / 2.0;
}


void EquiPolygon::draw() {
	float angleAtCenter = (2 * PI) / numOfEdges;
	float r = edgeLength * sqrt(1.0 / (2 * (1 - cos(angleAtCenter))));
	float alpha = PI / 2 - angleAtCenter / 2;

	if (points.empty()) {
		for (int i = 0; i < numOfEdges; ++i) {
			points.push_back({ xT + r * cos(alpha), yT + r * sin(alpha) });
			alpha += angleAtCenter;
		}
	}

	Shape::drawSE();
}


void EquiPolygon::drawSE() {
	// Cho tam giác đều, ngũ giác đều, lục giác đều
	if (type == EQUAL) {

		setCoorCenter();
		draw();
	}

	////////////////////////////////////////////////////////////////////////////

	// Cho tam giác, ngũ giác, lục giác của paint
	else {
		int realxF = xF;
		int realyF = yF;

		float hChange, vChange;
		float x, y;

		float xTop = xS + (realxF - xS) * ratiosX[numOfEdges][0];
		float yTop = yS + (realyF - yS) * ratiosY[numOfEdges][0];

		if (points.empty()) {
			points.push_back({ xTop, yTop });

			for (int i = 1; i < ratiosX[numOfEdges].size(); ++i) {
				x = xS + (realxF - xS) * ratiosX[numOfEdges][i];
				y = yS + (realyF - yS) * ratiosY[numOfEdges][i];

				points.push_back({ x, y });
			}

			for (int i = ratiosX[numOfEdges].size() - 1; i > 0; --i) {
				x = xS + (realxF - xS) * ratiosX[numOfEdges][i];
				y = yS + (realyF - yS) * ratiosY[numOfEdges][i];

				points.push_back({ 2 * xTop - x, y });
			}
		}

		Shape::drawSE();
	}
}
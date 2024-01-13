#include "Square.h"

void Square::draw() {
	Rectanglee::draw();
}

void Square::drawSE() {
	//cout << xS << " " << yS << " " << xF << " " << yF << endl;
	setEndForEqui();
	Rectanglee::drawSE();
}
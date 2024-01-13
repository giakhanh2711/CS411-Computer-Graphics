#ifndef _MENU_H
#define _MENU_H

#include <string>
#include <iostream>
#include <vector>
#include "GL/glut.h"

#include "Shape.h"
#include "Painter.h"
#include "Line.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Square.h"
#include "EquiPolygon.h"
#include "Right_Equal_Triangle.h"
#include "Arrow.h"
#include "Star.h"
#include "Subtract.h"
#include "Plus.h"
#include "Multiply.h"
#include "Divide.h"

using namespace std;


class Menu {
private:
	static Menu* MENU;
	Menu();

	RGBColor curColor = { 255, 255, 255 };
	int currentShape = -1;

	vector < Shape*> shapes;
public:
	bool isDrawing = false;

	static Menu* getInstance();

	~Menu();
	void createMenu();
	void setCurrentShape(int a);
	void HandleAfterChoose();
	//Shape* getCurShape();
	RGBColor getCurColor();
	void draw();
	//vector<Shape*> getShapes();
};

#endif
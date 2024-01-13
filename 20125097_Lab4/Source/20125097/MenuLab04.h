#ifndef _MENULAB04_H
#define _MENULAB04_H

#include "GL/glut.h"
#include <vector>

#include "Shape.h"
#include "Line.h"
#include "Ellipse.h"
#include "Rectangle.h"
#include "Square.h"
#include "EquiPolygon.h"
#include "Right_Equal_Triangle.h"
#include "Polygon.h"

using namespace std;

class MenuLab04 {
private:
	static MenuLab04* MENU04;
	MenuLab04();
	
	vector<Shape*> shapes;
	int shapeType;
public:
	~MenuLab04();
	
	static MenuLab04* getInstance();
	static void resetInstance();
	void setCurrentShape(int value);
	Shape* getCurrentShape();
	int getShapeType();
};


#endif


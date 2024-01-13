#ifndef  _LINE_H
#define _LINE_H

#include <iostream>
#include "Shape.h"
using namespace std;

class Line : public Shape{
public:
	Line(int x1, int y1, int x2, int y2, int type);
	Line(int x1, int y1);
	void drawDDA();
	void drawType1();
	void drawType2();
	void drawType3();
	void drawType4();
	void drawBresenham();
	void draw();
	void drawByOpenGL();
	void copyPoints(int xS, int yS, int xF, int yF);

//private:
	const int DDA = 0;
	const int BRESENHAM = 1;
	
	int x1, y1;
	int x2, y2;
	int type;
};
#endif // ! _LINE_H


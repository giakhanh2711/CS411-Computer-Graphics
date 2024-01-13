#ifndef  _LINE_H
#define _LINE_H

#include <iostream>
#include "Shape.h"
using namespace std;

class Line : public Shape{
public:
	Line(int x1, int y1, int x2, int y2, int type);
	void drawDDA();
	void drawBresenham();
	void draw();
	void drawByOpenGL();
	int checkTrend(int delta);

private:
	const int DDA = 0;
	const int BRESENHAM = 1;
	
	int x1, y1;
	int x2, y2;
	int type;
};
#endif // ! _LINE_H


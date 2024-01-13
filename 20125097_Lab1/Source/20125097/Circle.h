#ifndef  _CIRCLE_H
#define _CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
public:
	Circle(int xT, int yT, int r);
	void draw();
	void drawByOpenGL();

private:
	int xT, yT;
	int r;
};
#endif // ! _CIRCLE_H

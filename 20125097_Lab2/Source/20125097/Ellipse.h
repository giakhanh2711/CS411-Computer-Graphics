#ifndef _ELLIPSE_H
#define _ELLIPSE_H

#include "Shape.h"

class Ellipsee : public Shape {
public:
	Ellipsee(int xT, int yT, int a, int b);
	void draw4Point(int x, int y);
	void draw();
	void drawByOpenGL();
private:
	int xT, yT;
	int a, b;
};
#endif // ! _ELLIPSE_H


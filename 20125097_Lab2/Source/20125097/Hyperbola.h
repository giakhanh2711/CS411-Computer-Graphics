#ifndef  _HYPERBOLA_H
#define _HYPERBOLA_H

#include "Shape.h"

class Hyperbola : public Shape {
public:
	Hyperbola(int xT, int yT, int a, int b);
	void draw();
	void drawByOpenGL();
	void draw4Point(int x, int y);
private:
	int xT, yT, a, b;
};
#endif // ! _HYPERBOLA_H


#ifndef  _SHAPE_H
#define _SHAPE_H

#include <GL/glut.h>

#define WIDTH 1000
#define HEIGHT 750

const float PI = 3.14159265f;

class Shape {
public:
	virtual void draw() = 0;
	virtual void drawByOpenGL();
	void putPixel(int x, int y);
};
#endif // ! _SHAPE_H


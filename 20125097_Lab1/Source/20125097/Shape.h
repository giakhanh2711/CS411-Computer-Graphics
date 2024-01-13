#ifndef  _SHAPE_H
#define _SHAPE_H

#include <GL/glut.h>

class Shape {
public:
	virtual void draw() = 0;
	virtual void drawByOpenGL() = 0;
	void putPixel(int x, int y);
};
#endif // ! _SHAPE_H


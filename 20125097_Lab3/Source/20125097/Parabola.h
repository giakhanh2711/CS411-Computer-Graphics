#ifndef  _PARABOLA_H
#define _PARABOLA_H

#include "Shape.h"

class Parabola : public Shape{
public:
	Parabola(int xT, int yT, float p);
	void draw();
	void drawByOpenGL();
private:
	int xT, yT;
	float p;

};
#endif // ! _PARABOLA_H


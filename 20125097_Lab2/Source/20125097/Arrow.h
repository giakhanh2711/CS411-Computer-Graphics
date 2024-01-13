#ifndef  _ARROW_H
#define _ARROW_H

#include "Shape.h"

class Arrow : public Shape {
public:
	Arrow(int length, int width, int xS, int yS);
	void draw();
private:
	int length, width;
	int xS, yS;
};

#endif // ! _ARROW_H

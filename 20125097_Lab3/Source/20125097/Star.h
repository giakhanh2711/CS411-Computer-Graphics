#ifndef _STAR_H
#define _STAR_H

#include "Shape.h"

class Star : public Shape {
public:
	Star(int xT, int yT);
	void draw();
private:
	int xT, yT;
};

#endif

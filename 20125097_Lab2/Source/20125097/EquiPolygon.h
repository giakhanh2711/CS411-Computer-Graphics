#ifndef _EQUIPOLYGON_H
#define _EQUIPOLYGON_H

#include "Shape.h"

// Tam giac deu
// Ngu giac deu
// Luc giac deu

class EquiPolygon : public Shape{
public:
	EquiPolygon(int xT, int yT, int numOfEdges, int edgeLength);
	void draw();
private:
	int xT, yT;
	int numOfEdges;
	int edgeLength;
};

#endif

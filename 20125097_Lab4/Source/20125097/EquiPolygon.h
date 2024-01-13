#ifndef _EQUIPOLYGON_H
#define _EQUIPOLYGON_H

#include "Shape.h"
#include "Circle.h"
#include <vector>
#include <unordered_map>
using namespace std;

class EquiPolygon : public Shape{
public:
	EquiPolygon(float xT, float yT, int numOfEdges, float edgeLength);
	EquiPolygon(int xS, int yS, int type);
	EquiPolygon();
	void setNumOfEdges(int numOfEdges);
	void setCoorCenter();
	void draw();
	void drawSE();
private:
	float xT, yT;
	int numOfEdges;
	float edgeLength;

	int type;

	unordered_map<int, vector<float>> ratiosX;
	unordered_map<int, vector<float>> ratiosY;
};

#endif

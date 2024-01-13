#ifndef  _SHAPE_H
#define _SHAPE_H

#include <GL/glut.h>
#include <vector>
#include <iostream>
using namespace std;

#define WIDTH 1000
#define HEIGHT 750

#define EQUAL_TRIANGLE 3
#define DIAMOND 4
#define EQUAL_FIVE 5
#define EQUAL_SIX 6

#define EQUAL 1
#define NORMAL 2
#define RIGHT_EQUAL 3
#define RIGHT 4

const float PI = 3.14159265f;

class Shape {
protected:
	int xS, yS, xF, yF;
	vector<vector<float>> points;
public:
	Shape(int xS, int yS);
	Shape();
	~Shape();
	virtual void draw() {};
	virtual void drawSE();
	virtual void drawByOpenGL() {};
	virtual void setNumOfEdges(int numOfEdges) {};
	virtual void popPoint();
	virtual void setFinish() {};
	virtual void setStartTransform() {};
	virtual bool getIsTransform() { return false; };
	void putPixel(int x, int y);
	void setStart(int xS, int yS);
	void setEnd(int xF, int yF);
	void setEndForEqui();
	void clearPoints();
	vector<vector<float>> getPoints();
	void updatePoints(vector<vector<float>> points);
};
#endif // ! _SHAPE_H


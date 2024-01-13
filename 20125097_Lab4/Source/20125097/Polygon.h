#ifndef _POLYGON_H
#define _POLYGON_H

#include "Shape.h"
#include "Line.h"

class MyPolygon : public Shape {
private:
	bool isFinish;
	bool startTransform;
public:
	MyPolygon(int xS, int yS) : Shape(xS, yS) {
		isFinish = false;
		startTransform = false;
	}

	void setFinish() {
		this->isFinish = true;
	}

	void setStartTransform() {
		this->startTransform = true;
	}

	bool getIsTransform() {
		return isFinish;
	}
	
	void draw() {
		glBegin(GL_LINE_STRIP);
		for (auto p : points)
			glVertex2fv(&p[0]);
		glEnd();
		glFlush();
	}

	void drawSE() {
		if (startTransform) {
			Shape::drawSE();
			return;
		}

		if (points.empty()) {
			points.push_back({ (float)xS, (float)yS });
			points.push_back({ (float)xF, (float)yF });
		}
		else if (!isFinish)
			points.push_back({ (float)xS, (float)yS });
		else if (isFinish) {
			points.push_back({ (float)xS, (float)yS });
			points.push_back({ points[0][0], points[0][1] });
		}
		
		this->draw();
		if (isFinish)
			points.pop_back();

		cout << "Points size " << points.size() << endl;
	}
};

#endif

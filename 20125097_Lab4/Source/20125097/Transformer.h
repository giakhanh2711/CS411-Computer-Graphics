#ifndef _TRANSFORMER_H
#define _TRANSFORMER_H

#include <vector>
#include <cmath>
#include <GL/glut.h>
#include <iostream>
#include "Shape.h"
using namespace std;

#define TRANSLATE 1
#define SCALE 2
#define ROTATE 3
#define POINT_SIZE 2

class Transformer {
private:
	float tl[2];
	float sc[2][2];
	float rt[2][2];
	float scFixedPoint[2][2];

	float alpha;

	static Transformer* TRANSFORMER;

	Transformer() {
		alpha = 0;

		rt[0][0] = cos(alpha);
		rt[0][1] = sin(alpha);
		rt[1][0] = -sin(alpha);
		rt[1][1] = cos(alpha);

		sc[0][1] = 0;
		sc[1][0] = 0;

		scFixedPoint[0][1] = 0;
		scFixedPoint[1][0] = 0;
	}


public:
	static Transformer* getInstance() {
		if (TRANSFORMER == NULL)
			TRANSFORMER = new Transformer();

		return TRANSFORMER;
	}

	void multiplyMatrix(vector<vector<float>>& points, float transformMatrix[][2]) {
		vector<vector<float>> res = points;
		for (int i = 0; i < points.size(); ++i)
			for (int j = 0; j < 2; ++j) {
				res[i][j] = 0;
				
				for (int k = 0; k < 2; ++k)
					res[i][j] += points[i][k] * transformMatrix[k][j];
			}

		for (int i = 0; i < points.size(); ++i)
			for (int j = 0; j < 2; ++j)
				points[i][j] = res[i][j];
	}


	void transform_translate(vector<vector<float>>& points) {
		for (int i = 0; i < points.size(); ++i)
			for (int j = 0; j < POINT_SIZE; ++j)
				points[i][j] += tl[j];
	}


	void transform_scale(vector<vector<float>>& points) {
		vector<float> center(POINT_SIZE, 0);

		for (int i = 0; i < points.size(); ++i) {
			center[0] += points[i][0];
			center[1] += points[i][1];
		}

		for (int i = 0; i < POINT_SIZE; ++i)
			center[i] /= points.size();

		vector<vector<float>> tmp;
		tmp.push_back(center);
		
		multiplyMatrix(points, sc);		
		multiplyMatrix(tmp, scFixedPoint);

		for (int i = 0; i < points.size(); ++i)
			for (int j = 0; j < POINT_SIZE; ++j)
				points[i][j] += tmp[0][j];
	}


	void transform_rotate(vector<vector<float>>& points) {
		vector<float> center(POINT_SIZE, 0);

		for (int i = 0; i < points.size(); ++i) {
			center[0] += points[i][0];
			center[1] += points[i][1];
		}

		for (int i = 0; i < POINT_SIZE; ++i)
			center[i] /= points.size();

		vector<vector<float>> tmp;
		for (auto p : points)
			tmp.push_back({ p[0] - center[0], p[1] - center[1] });

		multiplyMatrix(tmp, rt);

		for (int i = 0; i < points.size(); ++i) {
			points[i][0] = center[0] + tmp[i][0];
			points[i][1] = center[1] + tmp[i][1];
		}
	}


	void handle_transform(vector<vector<float>>& points, int type) {
		switch (type)
		{
		case TRANSLATE:
			transform_translate(points);
			break;
		case SCALE:
			transform_scale(points);
			break;
		case ROTATE:
			transform_rotate(points);
			break;
		default:
			return;
		}
	}

	void transform(vector<vector<float>>& points, int type, unsigned char key) {
		switch (type)
		{
		case TRANSLATE:
			switch (key)
			{
			case GLUT_KEY_UP:
				tl[0] = 0;
				tl[1] = -1;
				break;
			case GLUT_KEY_DOWN:
				tl[0] = 0;
				tl[1] = 1;
				break;
			case GLUT_KEY_LEFT:
				tl[0] = -1;
				tl[1] = 0;
				break;
			case GLUT_KEY_RIGHT:
				tl[0] = 1;
				tl[1] = 0;
				break;
			default:
				return;
			}

			break;

		case SCALE:
			switch (key)
			{
			case '+':
				sc[0][0] = sc[1][1] = sqrt(1.1);
				scFixedPoint[0][0] = scFixedPoint[1][1] = 1 - sqrt(1.1);
				break;
			case '-':
				sc[0][0] = sc[1][1] = sqrt(0.9);
				scFixedPoint[0][0] = scFixedPoint[1][1] = 1 - sqrt(0.9);
				break;
			default:
				return;
			}

			break;

		case ROTATE:
			switch (toupper(key))
			{
			case 'L':
				alpha = -PI / 180.0;
				break;
			case 'R':
				alpha = PI / 180.0;
				break;
			default:
				return;
			}

			rt[0][0] = cos(alpha);
			rt[0][1] = sin(alpha);
			rt[1][0] = -sin(alpha);
			rt[1][1] = cos(alpha);

			break;

		default:
			return;
		}

		handle_transform(points, type);
	}
};

Transformer* Transformer::TRANSFORMER = NULL;
#endif
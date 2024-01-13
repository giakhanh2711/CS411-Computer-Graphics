#include "Painter.h"

Painter* Painter::painter = NULL;

Painter* Painter::getInstance() {
	if (painter == NULL)
		painter = new Painter(HEIGHT, WIDTH);
	return painter;
}

Painter::Painter(int h, int w) {
	screenHeight = h;
	screenWidth = w;
	B_Color = { 0, 0, 0 }; 
	F_Color = { 255, 255, 255 };
}


void Painter::setColor(RGBColor F_Color, RGBColor B_Color) {
	this->F_Color = F_Color;
	this->B_Color = B_Color;
}

bool Painter::IsSameColor(RGBColor color1, RGBColor color2) {
	if (color1.r == color2.r &&
		color1.g == color2.g &&
		color1.b == color2.b)
		return true;

	return false;
}

RGBColor Painter::GetPixel(int x, int y) {
	unsigned char* ptr = new unsigned char[3];

	glReadPixels(x, screenHeight - y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);

	RGBColor color;
	color.r = ptr[0];
	color.g = ptr[1];
	color.b = ptr[2];

	delete[] ptr;

	return color;
}


// Color for 1 point
void Painter::PutPixel(int x, int y, RGBColor color) {
	unsigned char* ptr = new unsigned char[3];
	ptr[0] = color.r;
	ptr[1] = color.g;
	ptr[2] = color.b;

	glRasterPos2i(x, y);
	glDrawPixels(1, 1, GL_RGB, GL_UNSIGNED_BYTE, ptr);

	glFlush();

	delete[] ptr;
}

void Painter::BoundaryFill(int x, int y) {
	stack<pair<int, int>> q;
	q.push({ x, y });
	pair<int, int> curPoint;
	RGBColor curColor;
	int curx, cury;

	while (!q.empty()) {
		curPoint = q.top();
		q.pop();
		
		curx = curPoint.first;
		cury = curPoint.second;
		
		curColor = GetPixel(curx, cury);
		
		if (!(IsSameColor(curColor, B_Color)) && !IsSameColor(curColor, F_Color)) {
			PutPixel(curx, cury, F_Color);
			q.push({ curx + 1, cury });
			q.push({ curx - 1, cury });
			q.push({ curx, cury + 1 });
			q.push({ curx, cury - 1 });
				
		}
	}

	glFlush();
}


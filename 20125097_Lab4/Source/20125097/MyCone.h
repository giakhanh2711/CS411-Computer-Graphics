#ifndef _CONE_H
#define _CONE_H

#include "ThreeD.h"

class Cone : public ThreeD {
public:
	Cone() : ThreeD(2) {
		textures[0][0] = SOIL_load_OGL_texture
		(
			"bricks.bmp",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_INVERT_Y
		);

		glBindTexture(GL_TEXTURE_2D, textures[0][0]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	void drawGLScene() {
		glLoadIdentity();
		glTranslatef(3.5f, 0.0f, -9.0f);
		glRotatef(-80, 1, 0, 0);
		glRotatef(angle, 0.0f, 0.0f, 1.0f);

		float x, y;
		float height = 0.9;
		GLfloat angle_stepsize = 0.1;
		float alpha = 0;
		float xTex = 0.5, yTex = 0;

		glBindTexture(GL_TEXTURE_2D, textures[0][0]);
		glBegin(GL_TRIANGLE_STRIP);
		alpha = 0.0;
		xTex = 0.5;
		yTex = 0;
		while (alpha < 2 * pi) {
			x = radius * cos(alpha);
			y = radius * sin(alpha);
			glTexCoord2f(xTex, yTex); glVertex3f(x, y, 0);
			glTexCoord2f(0.5, 0.5); glVertex3f(0, 0, height);
			
			alpha = alpha + angle_stepsize;
			
			xTex = 0.5 + 0.5 * sin(alpha);
			yTex = 0.5 - 0.5 * cos(alpha);

			if (xTex > 1) xTex = 1;
			if (xTex < 0) xTex = 0;
			if (yTex < 0) yTex = 0;
			if (yTex > 1) yTex = 1;
		}
		glTexCoord2f(0.5, 0.0); glVertex3f(radius, 0.0, 0);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textures[1][0]);
		glBegin(GL_POLYGON);
		alpha = 0.0;
		xTex = 0.5;
		yTex = 0;
		while (alpha < 2 * PI) {
			x = radius * cos(alpha);
			y = radius * sin(alpha);

			glTexCoord2f(xTex, yTex); glVertex3f(x, y, 0);

			alpha = alpha + angle_stepsize;

			xTex = 0.5 + 0.5 * sin(alpha);
			yTex = 0.5 - 0.5 * cos(alpha);

			if (xTex > 1) xTex = 1;
			if (xTex < 0) xTex = 0;
			if (yTex < 0) yTex = 0;
			if (yTex > 1) yTex = 1;
		}

		glTexCoord2f(0.5, 0.0); glVertex3f(radius, 0.0, 0);
		glEnd();

		angle += 0.15f;
	}
};

#endif

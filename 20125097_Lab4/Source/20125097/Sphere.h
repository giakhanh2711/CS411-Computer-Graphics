#ifndef _SPHERE_H
#define _SPHERE_H

#include "ThreeD.h"

class Sphere : public ThreeD{
private:
	int radius;
public:
	Sphere() : ThreeD(sphere){
		radius = 1;
	}

	void drawGLScene() {
		glLoadIdentity();
		glTranslatef(-1.25f, 0.5f, -10.0f);
		glRotatef(angle, 0.0f, 1.0f, 0.0f);
		
		glEnable(GL_TEXTURE_2D);

		GLUquadric* qobj = gluNewQuadric();
		glBindTexture(GL_TEXTURE_2D, textures[0][0]);
		gluQuadricTexture(qobj, GL_TRUE);
		gluSphere(qobj, radius, 100, 100);
		gluDeleteQuadric(qobj);

		angle -= 0.15f;
	}
};

#endif

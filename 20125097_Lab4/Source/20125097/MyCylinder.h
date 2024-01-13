#ifndef _MYCYLINDER_H
#define _MYCYLINDER_H

#include "ThreeD.h"
#include <math.h>
using namespace std;

const float PI = 3.14;
float xrot = 0, yrot = 0, zrot = 0;

class MyCylinder : public ThreeD {
public:
	MyCylinder() : ThreeD(3){
        radius = 1;
        textures[0][0] = SOIL_load_OGL_texture
        (
            "tt3.jpg",
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
        glTranslatef(1.5f, 0.0f, -11.0f);
        glRotatef(-70, 1, 0, 0);
        glRotatef(-20, 0, 0, 1);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        float x, y;
        float height = 2 * radius;
        GLfloat angle_stepsize = 0.1;
        float alpha = 0;
        float xTex = 0, yTex = 0;
        glBindTexture(GL_TEXTURE_2D, textures[0][0]);
        glBegin(GL_QUAD_STRIP);
        yTex = ((0.1 * 2 * height) / (2 * PI)) / (radius * 0.1);

        while (alpha < 2 * PI) {
            x = radius * cos(alpha);
            y = radius * sin(alpha);
           
            glTexCoord2f(xTex, yTex); glVertex3f(x, y, height);
            glTexCoord2f(xTex, 0); glVertex3f(x, y, 0);
            
            alpha = alpha + angle_stepsize;
            xTex += 0.1 / (2 * PI);
        }
        glTexCoord2f(1, yTex); glVertex3f(radius, 0, height);
        glTexCoord2f(1, 0); glVertex3f(radius, 0, 0);
      
        glEnd();

        glBindTexture(GL_TEXTURE_2D, textures[1][0]);
        glBegin(GL_POLYGON);
        alpha = 0.0;
        xTex = 0.5;
        yTex = 0;
        while (alpha < 2 * PI) {
            x = radius * cos(alpha);
            y = radius * sin(alpha);

            glTexCoord2f(xTex, yTex); glVertex3f(x, y, height);

            alpha = alpha + angle_stepsize;

            xTex = 0.5 + 0.5 * sin(alpha);
            yTex = 0.5 - 0.5 * cos(alpha);
     
            if (xTex > 1) xTex = 1;
            if (xTex < 0) xTex = 0;
            if (yTex < 0) yTex = 0;
            if (yTex > 1) yTex = 1;
        }

        glTexCoord2f(0.5, 0.0); glVertex3f(radius, 0.0, height);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, textures[2][0]);
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

        angle -= 0.15f;
	}
};


#endif

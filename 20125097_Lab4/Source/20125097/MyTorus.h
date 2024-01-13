#ifndef _MYTORUS_H
#define _MYTORUS_H

#include "ThreeD.h"
#include <math.h>
using namespace std;

class MyTorus : public ThreeD{
private:
	float innerRadius;
public:
	MyTorus() : ThreeD(1) {
		innerRadius = 0.3;
        textures[0][0] = SOIL_load_OGL_texture
        (
            "tt5.jpg",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
        );

        glBindTexture(GL_TEXTURE_2D, textures[0][0]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

    void drawGLScene() {
        glLoadIdentity(); // Reset The View
        glTranslatef(-1.5f, -3.0f, -12.0f);
        glRotatef(-75, 1, 0, 0);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        float du = 2 * pi / 30;
        float dv = 2 * pi / 30;

        glBindTexture(GL_TEXTURE_2D, textures[0][0]);
        for (size_t i = 0; i < 30; i++) {

            float u = i * du;

            glBegin(GL_TRIANGLE_STRIP);
            for (size_t j = 0; j <= 30; j++) {

                float v = (j % 30) * dv;

                for (size_t k = 0; k < 2; k++)
                {
                    float a = u + k * du;
                    
                    float x = (radius + innerRadius * cos(v)) * cos(a);
                    float y = (radius + innerRadius * cos(v)) * sin(a);
                    float z = innerRadius * sin(v);

                    float tx = a / (2 * pi);
                    float ty = v / (2 * pi);

                    glTexCoord2f(tx, ty); glVertex3f(x, y, z);
                }

                v += dv;
            }
        }

        glEnd();

        angle += 0.15f;
    }

};


#endif

#pragma warning(disable : 4996)

#ifndef _THREED_H
#define _THREED_H

#include <GL/glut.h>
#include <SOIL2.h>
#include <fstream>
#include <string>
using namespace std;

#define sphere 1
#define pi 3.1415926535898

class ThreeD{
protected:
	GLuint** textures;
	int numTexture;
	GLfloat angle;
	float radius;

public:
	ThreeD(int numTexture) {
		radius = 1;
		angle = 0.0f;
		this->numTexture = numTexture;

		textures = new GLuint * [numTexture];

		for (int i = 0; i < numTexture; ++i)
			textures[i] = new GLuint[1];

		// Load Textures

		string myTexture;
		char* arr = NULL;
		ifstream myFile;
		myFile.open("texture.txt");
		if (myFile.is_open()) {
			for (int i = 0; i < numTexture; ++i) {
				getline(myFile, myTexture);
				
				char* arr = new char[myTexture.length() + 1];
				strcpy(arr, myTexture.c_str());
				
				textures[i][0] = SOIL_load_OGL_texture
				(
					arr,
					SOIL_LOAD_AUTO,
					SOIL_CREATE_NEW_ID,
					SOIL_FLAG_INVERT_Y
				);

				glBindTexture(GL_TEXTURE_2D, textures[i][0]);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

				delete[] arr;
				arr = NULL;
			}

			myFile.close();
		}
	}

	~ThreeD() {
		for (int i = 0; i < numTexture; ++i) {
			if (textures[i]) {
				delete[] textures[i];
				textures[i] = NULL;
			}
		}

		if (textures) {
			delete[] textures;
			textures = NULL;
		}
	}


	virtual void drawGLScene() = 0;
};

#endif

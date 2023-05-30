#pragma once
#ifndef _SHIP_H_
#define _SHIP_H_


// INCLUDES //
#include <glut.h>
#include <fstream>
#include <gl/gl.h>
#include <gl/glu.h>
#include<iostream>
using namespace std;

// MY CLASS INCLUDES //
#include <vector>
#include "Vector3.h"
#include "SOIL.h"

class Model
{
public:
	bool load(char* modelFilename, char* textureFilename);
	void render();

private:

	void loadTexture(char*);
	bool loadModel(char*);

	// model texture
	GLuint texture;

	// Stoagre for sorted data
	//vector<Vector3> vertex, normals, texCoords;
	vector<Vector3> vertex, normals, texCoords;


};
#endif
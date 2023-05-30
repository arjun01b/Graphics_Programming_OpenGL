#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "SOIL.h"
#include <math.h>
#include "Camera.h"
#include"Primitives.h"

class Skybox {

	//necessary variables and functions for skybox class
public:
	Skybox();
	~Skybox();
	Camera cam;
	Primitives prim;
	void renderSkybox();
	void cameraUpdate();

	
};
#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>

class Light {
public:
	Light();
	~Light();

	void renderLights();
	//Light position for using shadow making
	GLfloat Light_Position[4] = { 5.35f, 3.9f, -0.35f, 1.0f };


};

#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "SOIL.h"
#include <math.h>
#include"Primitives.h"



class ObjectHandler {
public:
	ObjectHandler();
	~ObjectHandler();
	void drawTable();
	void drawFan();
	void rotateFan(float dt);
	Primitives desk;
	float rotationAngle = 0.0;
	GLuint wall;
	GLuint table;
	GLuint cover;
};
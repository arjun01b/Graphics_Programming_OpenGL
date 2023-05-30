#pragma once
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Vector3.h"
#include "SOIL.h"
#include <math.h>

class Primitives {
public:
	Primitives();
	~Primitives();

	GLuint table;

	GLuint sky;

	void drawCube(GLuint texture);//function to draw a cube


	void drawWall(GLuint texture);//function to draw a wall

	void wideWall(Vector3,GLuint texture);//function to draw a wall of different dimensions

	void roof(GLuint texture);//function to draw roof of the room

	void Sphere(int segments, GLuint texture);//function to draw a sphere with textures

	void drawSky(GLuint texture);//function to render a skybox
};

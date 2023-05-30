// Scene class. Configures a basic 3D scene.
// Interfaces with the Input class to handle user input
// Calculates and outputs Frames Per Second (FPS) rendered.
// Important functions are the constructor (initialising the scene), 
// update (for process user input and updating scene objects) and render (renders scene).
#ifndef _SCENE_H
#define _SCENE_H

// Include GLUT, openGL, input.
#include "glut.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Input.h"
#include <stdio.h>
// Further includes should go here:
#include "SOIL.h"
#include <vector>
#include"Camera.h"
#include"Primitives.h"
#include"ObjectHandler.h"
#include"Light.h"
#include"Skybox.h"
#include"Model.h"
#include"Shadow.h"

class Scene{

public:
	Scene(Input *in);
	// Main render function
	void render();
	// Handle input function that receives delta time from parent.
	void handleInput(float dt);
	// Update function receives delta time from parent (used for frame independent updating).
	void update(float dt);
	// Resizes the OpenGL output based on new window size.
	void resize(int w, int h);
	//Function for reflection
	void reflection();
	//function for making bookshelf
	void renderBookshelf();
	//function for making a mirror
	void DrawMirror();
	//function for rendering a plane
	void makePlane(int dimension);
	
	Shadow Shadow;//shadow instance
	Camera camera;//Camera instance
	Primitives test;//primitives instance
	Primitives sky;//primitives instance
	GLuint wall;//declaration
	GLuint grass;//declaration
	GLuint a;//declaration
	GLuint b;//declaration
	GLuint c;//declaration
	ObjectHandler z;//ObjectHandler instance
	Primitives ceel;//primitives instance
	Primitives wide;//primitives instance
	Primitives floor;//primitives instance
	ObjectHandler x;//ObjectHandler instance
	ObjectHandler y;//ObjectHandler instance
	Skybox s;//Skybox instance
	Light l;//light instance
	Vector3 r;//light instance
	Model m;//model instance


protected:
	// configure opengl render pipeline
	void initialiseOpenGL();
	// Renders text (x, y positions, RGB colour of text, string of text to be rendered)
	void displayText(float x, float y, float r, float g, float b, char* string);
	// A function to collate all text output in a single location
	void renderTextOutput();
	void calculateFPS();
	bool StaticCamera;

	// draw primitive functions
	

	// For access to user input.
	Input* input;
		
	// For Window and frustum calculation.
	int width, height;
	float fov, nearPlane, farPlane;

	// For FPS counter and mouse coordinate output.
	int frame = 0, time, timebase = 0;
	char fps[40];
	char mouseText[40];

};

#endif
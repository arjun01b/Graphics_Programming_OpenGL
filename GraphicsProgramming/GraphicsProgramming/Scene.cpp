#include "Scene.h"

// Scene constructor, initilises OpenGL
// You should add further variables to need initilised.
Scene::Scene(Input *in)
{
	// Store pointer for input class
	input = in;
	initialiseOpenGL();
	
	//Loading the spaceship model with the texture
	m.load("models/spaceship.obj","models/spaceship.jpg");
	
	// Other OpenGL / render setting should be applied here.
	

	// Initialise scene variables
	
	StaticCamera = false;
	


	//Textures for different objects in the scene
	wall = SOIL_load_OGL_texture(

		"gfx/wood.png",
		
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	grass = SOIL_load_OGL_texture(

		"gfx/brick.png",

		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	a = SOIL_load_OGL_texture(

		"gfx/floor.png",

		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	b= SOIL_load_OGL_texture(

		"gfx/brick.png",

		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	c= SOIL_load_OGL_texture(

		"gfx/ceiling.png",

		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);
	glEnable(GL_LIGHT0);
}

void Scene::handleInput(float dt)
{
	// Handle user input
	if (StaticCamera == false)
		camera.input(input, dt);

	//Toggles the wireframe mode on and off
	if (input->isKeyDown('h')) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if (input->isKeyDown('j')) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	//toggles the spotlight on and off
	if (input->isKeyDown('p')) {
		glDisable(GL_LIGHT0);
	}
	if (input->isKeyDown('o')) {
		glEnable(GL_LIGHT0);
	}
	//Changes camera position and makes it static
	if (input->isKeyDown('z')) {
		StaticCamera = true;
	}
	if (input->isKeyDown('x')) {
		StaticCamera = false;
	}
}

void Scene::update(float dt)
{
	// update scene related variables.

	z.rotateFan(dt);
	s.cameraUpdate();
	
	// Calculate FPS for output
	calculateFPS();
}

//Function helping in reflection of the objects
void Scene::reflection()
{


	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_ALWAYS, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	glDisable(GL_DEPTH_TEST);
	glPushMatrix();
	    DrawMirror();
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glPushMatrix();
		glScalef(1.0, -1.0, 1.0);
		renderBookshelf();
		glScalef(6,-1.0,6);
		glTranslatef(-4, -5, -4);
		ceel.roof(c);
	glPopMatrix();



	glDisable(GL_STENCIL_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_LIGHTING);
	glColor4f(0.8f, 0.8f, 1.0f, 0.2f);

	glPushMatrix();
	       glTranslatef(0, 0.01, 0);
	       DrawMirror();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);

}


void Scene::render() {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	//camera position when static
	if (StaticCamera == true)
		gluLookAt(0.0f, 3.0f, -3.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
	if (StaticCamera == false)
		camera.update();

	// Render geometry/scene here -------------------------------------

	//Skybox
	    glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		glPushMatrix();
			glTranslatef(camera.pos.x, camera.pos.y, camera.pos.z);
			glTranslatef(-0.5, -0.5,0.5);
			glColor3f(1, 1, 1);
			test.drawSky(test.sky);
		glPopMatrix();
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);

		//lighting
		l.renderLights();

		//reflection
		reflection();

	   //Small walls
	glPushMatrix();
		glScalef(5.0, 5.0, -5.0);
		glTranslatef(2.5, 0.0, -0.5);
		glRotatef(180, 0, 1, 0);
		test.drawWall(grass);
	glPopMatrix();

	glPushMatrix();
		glScalef(5.0, 5.0, -5.0);
		glTranslatef(0.0, 0.0, 3.5);
		test.drawWall(grass);
	glPopMatrix();



	//floor
	glPushMatrix();
		glTranslatef(6, 0,-8);
		glScalef(1.5, 1,1.5);
		makePlane(30);
	glPopMatrix();


	//bookshelf
	glPushMatrix();
		glTranslatef(0, 0, 0);
		renderBookshelf();
	glPopMatrix();


	//wide wall 1
	glPushMatrix();
		r.setX(1);
		r.setY(0);
		r.setZ(0);
		glTranslatef(0.0, 0.0, 2.5);
		glScalef(1.0, 1.0, 1.0);
		wide.wideWall(r,b);
	glPopMatrix();

	//wide wall 2
	glPushMatrix();
		r.setX(-1);
		r.setY(0);
		r.setZ(0);
		glTranslatef(12.5, 5.0, 2.5);
		glRotatef(180, 0, 0, 1);
		glScalef(1.0, 1.0, 1.0);
		wide.wideWall(r,b);
	glPopMatrix();


	//ceiling
	glPushMatrix();
		glTranslatef(0.0, 5.0, 0.0);
		ceel.roof(c);
	glPopMatrix();

	


	//fan
	GLfloat Material_Ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat Material_Specular[] = { 0.75, 0.75, 0.75, 1 };
		//big cube
		glPushMatrix();
			glTranslatef(4.85, 4.47, 0.185);
			glScalef(1.0, 0.5, 1.0);
			glMaterialfv(GL_FRONT, GL_AMBIENT, Material_Ambient);
			glMaterialfv(GL_FRONT, GL_SPECULAR, Material_Specular);
			z.drawFan();
		glPopMatrix();

		//small cube
		glPushMatrix();
			glTranslatef(5.35, 4.19, -0.35);
			glRotatef(z.rotationAngle, 0, 1, 0);
			glTranslatef(-0.15,0, 0.15);
			
			glScalef(0.3, 0.3, 0.3);
			
			z.drawFan();
		
		
		//blade 1 of fan
		glPushMatrix();
			glTranslatef(1, 0,0);
			glScalef(4, 0.1, 1);
			z.drawFan();
		glPopMatrix();
		
		//blade 2 of fan
		glPushMatrix();
			glTranslatef(0.0, 0, 0);
			glScalef(4, 0.1, 1);
			glRotatef(90, 0, 1, 0);
			z.drawFan();
		glPopMatrix();

		//blade 3 of fan
		glPushMatrix();
			glTranslatef(1, 0, -1);
			glRotatef(90, 0, 1, 0);
			glScalef(4, 0.1, 1);
			z.drawFan();
		glPopMatrix();
		
		//blade 4 of fan
		
		glPushMatrix();
			glTranslatef(0, 0, 0);
			glRotatef(270, 0, 1, 0);
			glScalef(4, 0.1, 1);
			z.drawFan();
		glPopMatrix();
	    glPopMatrix();

		//shadow matrix
		float shadowMatrix[16];
		GLfloat floorVerts[] = { -1.f, 0.f, -1.f,// top left
								 -1.f, 0.f, 1.f, // bottom left
									1.f,0.f,1,//bottom right
									1.f,0.f,-1 };//top right
		l.renderLights();
		Shadow.generateShadowMatrix(shadowMatrix, l.Light_Position,floorVerts);

        glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glColor3f(0.1f, 0.1f, 0.1f); // Shadow's colour 
		glPushMatrix();
			glMultMatrixf((GLfloat*)shadowMatrix); 
			glTranslatef(5.35, 2, -0.35);
			m.render();
		glPopMatrix();
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glTranslatef(5.35, 2, -0.35);
			m.render();
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		glDisable(GL_TEXTURE_2D);


      

		//sphere
		glPushMatrix();
			glTranslatef(6,1,-15);
			glScalef(0.75, 0.75, 0.75);
			glRotatef(z.rotationAngle, 1, 1, 1);
			ceel.Sphere(20, wall);
		glPopMatrix();


		
			// End render geometry 

	// Render text, should be last object rendered.
	renderTextOutput();
	
	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

//Function for making bookshelf
void Scene::renderBookshelf()
{
	//bookshelf
	glPushMatrix();
		glTranslatef(0.6, 1.0, -13.5);
		glScalef(0.5, 0.5, 0.5);
		x.drawTable();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.6, 2.37, -13.5);
		glScalef(0.5, 0.5, 0.5);
		x.drawTable();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.6, 0.0, -16.2);
		glRotatef(90, 1, 0, 0);
		glScalef(0.5, 1.0, 0.5);
		x.drawTable();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.6, 0.0, -13.53);
		glRotatef(90, 1, 0, 0);
		glScalef(0.5, 1.0, 0.5);
		x.drawTable();
	glPopMatrix();
}

//Function to draw a mirror
void Scene::DrawMirror()
{
	glPushMatrix();
		glTranslatef(1.3, 0, -14.75);
		glRotatef(90, 1, 0, 0);
		glScalef(2.5, 3, 6);

		glBegin(GL_QUADS);
		glColor4f(1.0, 0, 0, 0.5);
		glVertex3f(-0.5f, -0.5f, 0);
		glColor4f(1.0, 0, 0, 0.5);
		glVertex3f(0.5f, -0.5f, 0);
		glColor4f(1.0, 0, 0, 0.5);
		glVertex3f(0.5f, 0.5f, 0);
		glColor4f(1.0, 0, 0, 0.5);
		glVertex3f(-0.5f, 0.5f, 0);
		glEnd();
	glPopMatrix();
}


//function to make a plane(floor)
void Scene::makePlane(int dimension) {

	glPushMatrix();

	const float sq_size = 0.5f;

	glRotatef(-90.f, 1.f, 0.f, 0.f);
	glTranslatef(-sq_size * dimension / 2.f, -sq_size * dimension / 2.f, 0.f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, a);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glBegin(GL_QUADS);
	for (int y = 0; y < dimension; y++)
	{
		for (int x = 0; x < dimension; x++)
		{
			glNormal3f(0.f, 0.f, 1.f);

			glTexCoord2f(x * sq_size, y * sq_size);
			glVertex3f(x * sq_size, y * sq_size, 0.0f);
			glTexCoord2f(x * sq_size, (y * sq_size) + sq_size);
			glVertex3f(x * sq_size, (y * sq_size) + sq_size, 0.0f);
			glTexCoord2f((x * sq_size) + sq_size, (y * sq_size) + sq_size);
			glVertex3f((x * sq_size) + sq_size, (y * sq_size) + sq_size, 0.0f);
			glTexCoord2f((x * sq_size) + sq_size, y * sq_size);
			glVertex3f((x * sq_size) + sq_size, y * sq_size, 0.0f);
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

}

void Scene::initialiseOpenGL()
{
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.39f, 0.58f, 93.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
	glEnable(GL_LIGHTING);
	
}

// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h) 
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 200.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

// Calculates FPS
void Scene::calculateFPS()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame*1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}

// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
}

// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width/(float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}

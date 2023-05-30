//Class for giving raw primitives texture and form using hierarchial modelling
#include"ObjectHandler.h"

ObjectHandler::ObjectHandler()
{
	// Initialise scene variables
	
    



	//Textures for giving the primitives
	wall = SOIL_load_OGL_texture(

		"gfx/wall.png",

		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

		

	);
	cover== SOIL_load_OGL_texture(

		"gfx/wall.png",

		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT



	);

}

ObjectHandler::~ObjectHandler() 
{

}
//Giving the bookshelf shape and texture
void ObjectHandler::drawTable()
{


	
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glPushMatrix();
	glScalef(5, 0.5, 10);
	desk.drawCube(wall);
	glPopMatrix();

	
}

//
void ObjectHandler::drawFan()
{
	
	desk.drawCube(0);
}

//Helps determine the speed of the rotation
void ObjectHandler::rotateFan(float dt)
{
    rotationAngle += 100.f*dt;
}


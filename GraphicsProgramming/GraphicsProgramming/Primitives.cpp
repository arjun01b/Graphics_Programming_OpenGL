//Primitives Class for procedural generation
#include"Primitives.h"
Primitives::Primitives() {
	//textures for the primitives used
	table = SOIL_load_OGL_texture(

		"gfx/wall.png",
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

		sky = SOIL_load_OGL_texture(

			"gfx/skybox.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT

	);

}
Primitives::~Primitives() {


}

//function for generating a cube with texture
void Primitives::drawCube(GLuint texture)
{
	if (texture != 0) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	
	// front
		glBegin(GL_QUADS);
		glColor3f(1.0, 2.0, 3.0);
		
		
	glTexCoord2f(0.f, 1.f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0, 0.0, 0.0);

    glTexCoord2f(0.f, 0.f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0, 0.0);

    glTexCoord2f(1.f, 0.f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 1.0, 0.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0, 1.0, 0.0);
	

	//right
	
	glTexCoord2f(0.f, 1.f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 0.0, 0.0);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 0.0, -1.0);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, -1.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, 0.0);

	//left
	
	glTexCoord2f(0.f, 1.f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 0.0, -1.0);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 1.0, 0.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 1.0, -1.0);

	//back
	
	glTexCoord2f(0.f, 1.f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, 0.0, -1.0);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, 1.0, -1.0);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0, 1.0, -1.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0, 0.0, -1.0);

	//top
	
	glTexCoord2f(0.f, 1.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 1.0, 0.0);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0, 1.0, 0.0);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0, 1.0, -1.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 1.0, -1.0);

	//bottom
	
	glTexCoord2f(0.f, 1.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0, 0.0, -1.0);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0, 0.0, -1.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0, 0.0, 0.0);
	
	

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

//function for drawing the wall
void Primitives::drawWall(GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	
	glTexCoord2f(0.f, 1.f);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(0.0, 0.0,- 1.0);
	glVertex3f(2.5, 0.0, 0.0);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(2.5, 1.0, 0.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, 1.0, 0.0);

	glDisable(GL_TEXTURE_2D);
	
	glEnd();
	}

//A function for drawing a wall of different dimensions
void Primitives::wideWall(Vector3 normal,GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 1.f);
	glNormal3f(normal.x, normal.y, normal.z);
	glVertex3f(0.0, 0.0, -20);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(normal.x, normal.y, normal.z);
	
	glVertex3f(0.0, 5.0, -20);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(normal.x, normal.y, normal.z);
	
	glVertex3f(0.0, 5.0, 0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(normal.x, normal.y, normal.z);
	//glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0);

	glDisable(GL_TEXTURE_2D);
	
	glEnd();
}

//Function to draw the ceiling of the room
void Primitives::roof(GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 1.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 2.5);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(12.5, 0.0, 2.5);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(12.5, 0.0, -17.5);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0, 0.0, -17.5);

	glDisable(GL_TEXTURE_2D);

	glEnd();
}

//Function to draw a sphere with coordinates and a texture
void Primitives::Sphere( int segments,GLuint texture)
{
	 

	//Variables
	float theta = 0, delta = 0;
	float res = segments;
	float u = 0, v = 0;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	for (int lon = 0; lon < res ; lon++) {
		for (int lat = 0; lat < res; lat++) {

			glBegin(GL_QUADS);

			//topLeft
			glNormal3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));
			glTexCoord2f(u, v);
			glVertex3f((cosf(theta) * sinf(delta)), cosf(delta), (sinf(theta) * sinf(delta)));

			//topRight
			glNormal3f((cosf(theta + ((2 * 3.1415) / res)) * sinf(delta)), cosf(delta), (sinf(theta + ((2 * 3.1415) / res)) * sinf(delta)));
			glTexCoord2f(u + (1 / res), v);
			glVertex3f((cosf(theta + ((2 * 3.1415) / res)) * sinf(delta)), cosf(delta), (sinf(theta + ((2 * 3.1415) / res)) * sinf(delta)));


			//BotLeft
			glNormal3f((cosf(theta + ((2 * 3.1415) / res)) * sinf(delta + (3.1415 / res))), cosf(delta + (3.1415 / res)), (sinf(theta + ((2 * 3.1415) / res)) * sinf(delta + (3.1415 / res))));
			glTexCoord2f(u + (1 / res), v + (1 / res));
			glVertex3f((cosf(theta + ((2 * 3.1415) / res)) * sinf(delta + (3.1415 / res))), cosf(delta + (3.1415 / res)), (sinf(theta + ((2 * 3.1415) / res)) * sinf(delta + (3.1415 / res))));


			//BotRight		
			glNormal3f((cosf(theta) * sinf(delta + (3.1415 / res))), cosf(delta + (3.1415 / res)), (sinf(theta) * sinf(delta + (3.1415 / res))));
			glTexCoord2f(u, v + (1 / res));
			glVertex3f((cosf(theta) * sinf(delta + (3.1415 / res))), cosf(delta + (3.1415 / res)), (sinf(theta) * sinf(delta + (3.1415 / res))));


			glEnd();

			theta += (2 * 3.1415) / res;
			u += (1 / res);

		}

		u = 0;
		delta += 3.1415 / res;
		v += (1 / res);
	}
	glDisable(GL_TEXTURE_2D);

 }

//skybox
void Primitives::drawSky(GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	//front
	glBegin(GL_QUADS);
	


	glTexCoord2f(0.75f, 0.5f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0, 0.0, 0.0);
	
	glTexCoord2f(1.0f, 0.5f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0, 0.0);
	
	glTexCoord2f(1.0f, 0.25f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 1.0, 0.0);
	
	glTexCoord2f(0.75f, 0.25f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0, 1.0, 0.0);


	//right
	
	glTexCoord2f(0.5f, 0.5f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 0.0, 0.0);
	
	glTexCoord2f(0.75f, 0.5f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 0.0, -1.0);
	
	glTexCoord2f(0.75f, 0.25f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, -1.0);
	
	glTexCoord2f(0.5f, 0.25f);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0, 1.0, 0.0);

	//left
	
	  glTexCoord2f(0.0f, 0.5f);
	  glNormal3f(-1.0f, 0.0f, 0.0f);
	  glVertex3f(0.0, 0.0, -1.0);
	  
	  glTexCoord2f(0.25f, 0.5f);
	  glNormal3f(-1.0f, 0.0f, 0.0f);
	  glVertex3f(0.0, 0.0, 0.0);
	  
	  glTexCoord2f(0.25f, 0.25f);
	  glNormal3f(-1.0f, 0.0f, 0.0f);
	  glVertex3f(0.0, 1.0, 0.0);
	  
	  glTexCoord2f(0.f, 0.25f);
	  glNormal3f(-1.0f, 0.0f, 0.0f);
	  glVertex3f(0.0, 1.0, -1.0);

	//back
    
	glTexCoord2f(0.25f, 0.25f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, 0.0, -1.0);
	
	glTexCoord2f(0.5f, 0.25f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(1.0, 1.0, -1.0);
	
	glTexCoord2f(0.5f, 0.5f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0, 1.0, -1.0);
	
	glTexCoord2f(0.25f, 0.5f);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(0.0, 0.0, -1.0);

	//top
	
	glTexCoord2f(0.25f, 0.25f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 1.0, 0.0);
	
	glTexCoord2f(0.5f, 0.25f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0, 1.0, 0.0);
	
	glTexCoord2f(0.5f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0, 1.0, -1.0);
	
	glTexCoord2f(0.25f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 1.0, -1.0);

	//bottom
	
	glTexCoord2f(0.25f, 0.75f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	
	glTexCoord2f(0.5f, 0.75f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0, 0.0, -1.0);
	
	glTexCoord2f(0.5f, 0.5f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0, 0.0, -1.0);
	
	glTexCoord2f(0.25f, 0.5f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(1.0, 0.0, 0.0);



	glEnd();
	glDisable(GL_TEXTURE_2D);

}

//another of making a floor but with less quads
/*void Primitives::drawFloor(GLuint texture)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2f(0.f, 1.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 1.0);

	glTexCoord2f(0.f, 0.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0, 0.0, 1.0);

	glTexCoord2f(1.f, 0.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0, 0.0, -1.0);

	glTexCoord2f(1.f, 1.f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 0.0, -1.0);

	glDisable(GL_TEXTURE_2D);

	glEnd();
}*/
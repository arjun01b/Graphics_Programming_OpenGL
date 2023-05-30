#include"Skybox.h"
Skybox::Skybox(){

}

Skybox::~Skybox(){

}

//function to draw a skybox with texture
void Skybox::renderSkybox()
{
	glPushMatrix();
	glTranslatef(cam.pos.x,cam.pos.y,cam.pos.z);
	glColor3f(0, 0, 0);
	prim.drawSky(prim.sky);
	glPopMatrix();
}

//update the camera position for skybox to work properly
void Skybox::cameraUpdate()
{
	cam.update();
}

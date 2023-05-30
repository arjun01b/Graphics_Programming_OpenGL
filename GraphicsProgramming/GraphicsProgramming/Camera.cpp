#include "Camera.h"

Camera::Camera() {

	//declaring different values for the camera
	pos.x = 3.0f; pos.y = 3.0f; pos.z = 6.0f;
	pitch = 0.0f; roll = 0.0f; yaw = 0.0f;

	speed = 5;
}
Camera::~Camera() {

}


void Camera::update()
{

	//Variables
	float cosR, cosP, cosY;
	float sinR, sinP, sinY;

	//Calculation for different camera aspects
	cosP = cosf((pitch * 3.1415) / 180);
	cosY = cosf((yaw * 3.1415) / 180);
	cosR = cosf((roll * 3.1415) / 180);

	sinP = sinf((pitch * 3.1415) / 180);
	sinY = sinf((yaw * 3.1415) / 180);
	sinR = sinf((roll * 3.1415) / 180);

	//Up vector
	up.x = (-cosY * sinR) - (sinY * sinP * cosR);
	up.y = cosP * cosR;
	up.z = (-sinY * sinR) - (sinP * cosR * -cosY);

	//Forward vector
	forward.x = sinY * cosP;
	forward.y = sinP;
	forward.z = cosP * -cosY;

	//Look at 
	lookAt = pos + forward;

	//apply to camera
	gluLookAt(pos.x, pos.y, pos.z,
		lookAt.x, lookAt.y, lookAt.z,
		up.x, up.y, up.z);


}

void Camera::input(Input* input, float dt) {

	//Mouse
	mousePosY = input->getMouseY();
	mousePosX = input->getMouseX();


	//Get mouse pos
	distanceX = mousePosX - (width / 2);
	distanceY = mousePosY - (height / 2);

	//Calculate direction of looking at
	yaw += distanceX * dt;
	pitch -= distanceY * dt;

	//Capping back flips
	if (pitch <= -90)
		pitch = -90;
	if (pitch >= 90)
		pitch = 90;

	//Put mouse back
	glutWarpPointer(width / 2, height / 2);


	//Get cross vector
	Vector3 cross;

	cross.x = (forward.y * up.z) - (forward.z * up.y);
	cross.y = (forward.z * up.x) - (forward.x * up.z);
	cross.z = (forward.x * up.y) - (forward.y * up.x);

	//Speed for going forward and sideways
	cross.scale(dt * speed);
	forward.scale(dt * speed);

	//declaring keys for camera movement
	if (input->isKeyDown(100)) {

		pos += cross;

	}
	else if (input->isKeyDown(97))
	{
		pos -= cross;
	}

	if (input->isKeyDown(119)) {

		pos += forward;
	}
	else if (input->isKeyDown(115))
	{
		pos -= forward;
	}
}
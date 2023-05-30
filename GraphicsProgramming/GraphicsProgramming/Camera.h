#pragma once
#include "Camera.h"
#include "glut.h"
#include <vector>
#include "Vector3.h"
#include <iostream>
#include "Input.h"

class Camera
{
public:
    Camera();
    ~Camera();
    Vector3 pos;

    void update();
    void input(Input* input, float dt);

private:

    //CVariables for calculation
    float posX = 0, posY = 0, posZ = 0;
    float lx, ly, lz;
    float upx, upy, upz;

    Vector3 forward,  lookAt, up;
    float yaw, roll, pitch;
    float speed;

    //Variables for input
    int mousePosX;
    int mousePosY;
    float distanceX;
    float distanceY;

    
    int width = 1200;
    int height = 640;


};

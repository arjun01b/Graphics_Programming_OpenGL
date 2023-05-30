#include"Light.h"


Light::Light() {

}

Light::~Light() {

}

//Function for making lights
void Light::renderLights() {
 

   //spotlight 1
   GLfloat Light_Ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
   GLfloat Light_Diffuse[] = { 1.0, 1.0, 0.0, 1.0f };
   GLfloat Light_Position[] = { 5.35f, 3.9f, -0.35f, 1.0f };
   GLfloat spot_Direction[] = { 0.0f, -1.0f, 0.0f };
   
  
  //Properties for the spotlight
   glLightfv(GL_LIGHT0, GL_AMBIENT, Light_Ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, Light_Diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, Light_Position);
   glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25.0f);
   glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_Direction);
   glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 50.0);
   glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
   glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0);
   glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0);
  
   


    //light 2
   
    GLfloat Light_Ambient1[] = { 0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat Light_Diffuse1[] = { 1.0f, 0.0f, 1.0f, 1.0f };
    GLfloat spot_Direction1[] = { -1.0f, 0.0f, 0.0f, 0.0f };
    GLfloat Light_Position1[] = { 10.0f, 5.0f, -10.0f, 0.0f };



    //Properties of the second light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, Light_Diffuse1);
    glPushMatrix();
    glLightfv(GL_LIGHT1, GL_POSITION, Light_Position1);
    glPopMatrix();
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_Direction1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, Light_Ambient1);
    glEnable(GL_LIGHT1);
}


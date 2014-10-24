/* Main.cpp
* Author: Hunter Ripsom-Gardiner
* Date: 10/16/14 
* Course: CSC 5210 Graphics
* Description: A class to represent the camera that views the scene.
* contains methods for moving the camera along the X-Y plane,
* methods for tilting the camera, and a method for repositioning the camera 180 degrees on the other side of the scene.
*/

#include "Camera.h"

//the constructor for the camera sets the location for 
//the camera by giving the frustrum the left, right, botom, top,
//near and far locations of the frustrum. Note that all values 
//of left, right, top, and bottom are those distances on the near plane. 
//Pre: all the values corespond to the apropriate pieces of a frustrum.
//post: a matrix for the frustrum is created using this data.
Camera::Camera(float left, float right, float bottom,
	float top, float near, float far)
{
	

}

void Camera::moveCameraUp (float distance)
{

}
void Camera::moveCameraDown (float distance)
{

}

void Camera::moveCameraLeft (float distance)
{

}

void Camera::moveCameraRight (float distance)
{

}
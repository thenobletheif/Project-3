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
//post: a matrix for the frustrum is stored in the "cameraFrustum" which is
//a mat4 type, which is created by including vmath. use vmath::mat4 to make a mat4.
Camera::Camera(float left, float right, float bottom,
	float top, float nearPlane, float farPlane)
{
	cameraFrustum = vmath::frustum(left, right, bottom, top, nearPlane, farPlane);

}

//Default camera constructor. sets the camera to have a basic frustum.
//Pre: none.
//Post: camera frustum is initialized
Camera::Camera()
{
	cameraFrustum = vmath::frustum(-1,1,-1,1,0,1);

}

//moves the camera up by distance.
//Pre: distance is initialized.
//Post: the frustum matrix is changed using matrix multiplaction.
void Camera::moveCameraUp (float distance)
{
	vmath::mat4 transform;
	transform = vmath::translate(0.0f, distance, 0.0f);

	cameraFrustum = cameraFrustum * transform;

}

//moves the camera down by distance.
//Pre: distance is initialized.
//Post: the frustum matrix is changed using matrix multiplaction.
void Camera::moveCameraDown (float distance)
{
	vmath::mat4 transform;
	transform = vmath::translate(0.0f, -distance, 0.0f);

	cameraFrustum = cameraFrustum * transform;
}

//moves the camera left by distance.
//Pre: distance is initialized.
//Post: the frustum matrix is changed using matrix multiplaction.
void Camera::moveCameraLeft (float distance)
{
	vmath::mat4 transform;
	transform = vmath::translate(distance, 0.0f, 0.0f);

	cameraFrustum = cameraFrustum * transform;
}

//moves the camera left by distance.
//Pre: distance is initialized.
//Post: the frustum matrix is changed using matrix multiplaction.
void Camera::moveCameraRight (float distance)
{
	vmath::mat4 transform;
	transform = vmath::translate(-distance, 0.0f, 0.0f);

	cameraFrustum = cameraFrustum * transform;
}
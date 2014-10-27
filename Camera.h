/* Main.cpp
* Author: Hunter Ripsom-Gardiner
* Date: 10/16/14 
* Course: CSC 5210 Graphics
* Description: A class to represent the camera that views the scene.
* contains methods for moving the camera along the X-Y plane,
* methods for tilting the camera, and a method for repositioning the camera 180 degrees on the other side of the scene.
*/

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cstdio>
// Local Utilities Includes
#include "vgl.h"
#include "vec.h"
#include "LoadShaders.h"

#include <vector>
#include <vmath.h>

class Camera{
public:
	Camera(float, float, float,
		float, float, float);
	Camera();
	void moveCameraUp(float);
	void moveCameraDown(float);
	void moveCameraLeft(float);
	void moveCameraRight(float);
private:
	vmath::mat4 cameraFrustum;
};
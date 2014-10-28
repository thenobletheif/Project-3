/* Main.cpp
* Author: Hunter Ripsom-Gardiner
* Date: 10/16/14 
* Course: CSC 5210 Graphics
* Description: A class to represent a cube. Contains a constructor that 
* initializes the cube based on the length of the cube, a scaling method, 
* a rotate method, and a translate method.
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

#include <vmath.h>

class Cube{
private:
	float length;	//the length of the side of the cube
	std::vector<GLuint> textureID;	//the id for the cube's texture
	GLfloat** vertices;	//A two dimensional array of the verticies.
						//defined as a pointer to a pointer, hence the **
	GLfloat** texies;
	

public:
	Cube();
	Cube(float, GLfloat, GLfloat, GLfloat);

	void scale(float);			//Scales the model by a given factor
	void rotate(float, int);			//Rotates the model by a given amount

	void translateY(float);	//Translates the model's y value by a given amount
	void translateLeft(float);	//Translates the model left by a given amount
	void translateRight(float);	//Translates the model right by a given amount

	void setTexture(std::vector<GLuint>);	//changes the current texture to a new given texture

	GLfloat** getVertices();
	GLfloat** getTexies();
		

};
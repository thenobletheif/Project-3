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
	GLfloat** vertices;	//A two dimensional array of the verticies.
						//defined as a pointer to a pointer, hence the **
	GLfloat** texies;
	GLuint texture;

	vec4 centerPoint;	//Stores the centerpoint of the cube
	vec4 angles;		//Stores the different angles this cube has been rotated around each axis

	void matMultiply(vmath::mat4, bool);	//Performs a matrix multiplication on this cube's vertices
	

public:
	Cube();		//Default constructor
	Cube(float, GLfloat, GLfloat, GLfloat);		//Constructor

	void scale(float);			//Scales the model by a given factor
	void rotate(float, int);			//Rotates the model by a given amount

	void translateY(float);	//Translates the model's y value by a given amount
	void translateX(float);	//Translates the model's x value by a given amount
	void translateZ(float);	//Translates the model's z value by a given amount

	//vec4 getAngles();	//Returns the angles vector

	void setTexture(std::vector<GLuint>);	//changes the current texture to a new given texture

	GLfloat** getVertices();	//Returns the 2D array of vertices pointer
	GLfloat** getTexies();		//Returns the 2D array of texies pointer
	void drawSelf();
	void setTextureID(GLuint);
	GLuint VAOs;
	GLuint Buffers[2];
	
};
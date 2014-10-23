/* Main.cpp
* Author: Hunter Ripsom-Gardiner
* Date: 10/16/14 
* Course: CSC 5210 Graphics
* Description: A class to represent a cube. Contains a constructor that 
* initializes the cube based on the length of the cube, a scaling method, 
* a rotate method, and a translate method.
*/

#include "Cube.h"

//the default constructor
Cube::Cube()
{

}

Cube::Cube(float sideLength, GLfloat x, GLfloat y, GLfloat z)
{
	//initialize all nescesary points for the cube

	//Set up the array
	vertices = new GLuint*[8];
	for (int i = 0; i < 8; i++)
		vertices[i] = new GLuint[4];

	//Assume that the given point is the top right point with the greatest z value, assign the vertices their values
	for (int i = 0; i < 8; i++)		//For each vertex, set each scale to 1 and set the appropriate z values
	{
		vertices[i][3] = 1;

		if (i < 4)
			vertices[i][2] = z;
		else
			vertices[i][2] = z - sideLength;
	}
	
	//Assign both sides their corrosponding x and y values
	for (int i = 0; i < 8; i += 4)
	{
		vertices[i][0] = x;
		vertices[i][1] = y;

		vertices[i + 1][0] = x;
		vertices[i + 1][1] = y - sideLength;

		vertices[i + 2][0] = x - sideLength;
		vertices[i + 2][1] = y - sideLength;

		vertices[i + 3][0] = x - sideLength;
		vertices[i + 3][1] = y;
	}

}

//Scales the model by a given factor
void Cube::scale(float factor)
{
		
}

//Rotates the model by a given amount
void Cube::rotate(float amount)
{
		
}

//Translates the model up by a given amount
void Cube::translateUp(float amount)
{

}

//Translates the model down by a given amount
void Cube::translateDown(float amount)
{

}

//Translates the model left by a given amount
void Cube::translateLeft(float amount)
{

}

//Translates the model right by a given amount
void Cube::translateRight(float amount)
{

}

//changes the current texture to a new given texture
void Cube::setTexture(std::vector<GLuint> newTexture)
{

}

//Returns this object's vertex vector
GLfloat** Cube::getVertices()
{
	return vertices;
}
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
	//<<<<<<
	//This makes no sense to me. Why are you using a single 
	//dimensional array of vertexes, and then referencing the
	//verticies as two dimensional below that?
	//>>>>>>>
	vertices = new GLfloat*[24];
	for (int i = 0; i < 24; i++)
		vertices[i] = new GLfloat[4];

	//Assume that the given point is the top right point with the greatest z value, assign the vertices their values
	for (int i = 0; i < 24; i++)		//For each vertex, set each scale to 1 and set the appropriate z values
		vertices[i][3] = 1.0;
	
	//Assign both sides their corrosponding x and y values

	//Side 1
	vertices[0][0] = x;
	vertices[0][1] = y;
	vertices[0][2] = z;

	vertices[1][0] = x;
	vertices[1][1] = y - sideLength;
	vertices[1][2] = z;

	vertices[2][0] = x + sideLength;
	vertices[2][1] = y;
	vertices[2][2] = z;

	vertices[3][0] = x + sideLength;
	vertices[3][1] = y - sideLength;
	vertices[3][2] = z;

	//Side 2
	vertices[4][0] = x;
	vertices[4][1] = y;
	vertices[4][2] = z;

	vertices[5][0] = x;
	vertices[5][1] = y;
	vertices[5][2] = z - sideLength;

	vertices[6][0] = x + sideLength;
	vertices[6][1] = y;
	vertices[6][2] = z;

	vertices[7][0] = x + sideLength;
	vertices[7][1] = y;
	vertices[7][2] = z - sideLength;

	//Side 3
	vertices[8][0] = x;
	vertices[8][1] = y;
	vertices[8][2] = z - sideLength;

	vertices[9][0] = x;
	vertices[9][1] = y - sideLength;
	vertices[9][2] = z - sideLength;

	vertices[10][0] = x + sideLength;
	vertices[10][1] = y;
	vertices[10][2] = z - sideLength;

	vertices[11][0] = x + sideLength;
	vertices[11][1] = y - sideLength;
	vertices[11][2] = z - sideLength;

	//Side 4
	vertices[12][0] = x;
	vertices[12][1] = y - sideLength;
	vertices[12][2] = z;

	vertices[13][0] = x;
	vertices[13][1] = y - sideLength;
	vertices[13][2] = z - sideLength;

	vertices[14][0] = x + sideLength;
	vertices[14][1] = y - sideLength;
	vertices[14][2] = z;

	vertices[15][0] = x + sideLength;
	vertices[15][1] = y - sideLength;
	vertices[15][2] = z - sideLength;

	//Side 5
	vertices[16][0] = x;
	vertices[16][1] = y;
	vertices[16][2] = z;

	vertices[17][0] = x;
	vertices[17][1] = y;
	vertices[17][2] = z - sideLength;

	vertices[18][0] = x;
	vertices[18][1] = y - sideLength;
	vertices[18][2] = z;

	vertices[19][0] = x;
	vertices[19][1] = y - sideLength;
	vertices[19][2] = z - sideLength;

	//Side 6
	vertices[20][0] = x + sideLength;
	vertices[20][1] = y;
	vertices[20][2] = z;

	vertices[21][0] = x + sideLength;
	vertices[21][1] = y;
	vertices[21][2] = z - sideLength;

	vertices[22][0] = x + sideLength;
	vertices[22][1] = y - sideLength;
	vertices[22][2] = z;

	vertices[23][0] = x + sideLength;
	vertices[23][1] = y - sideLength;
	vertices[23][2] = z - sideLength;

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
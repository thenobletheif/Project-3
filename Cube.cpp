/* Main.cpp
* Author: Hunter Ripsom-Gardiner, Alexander Deacon
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
	length = sideLength;
	//initialize all nescesary points for the cube
	//Set up the array
	vertices = new GLfloat*[24];
	for (int i = 0; i < 24; i++)
		vertices[i] = new GLfloat[4];

	//Assume that the given point is the top right point with the greatest z value, assign the vertices their values
	for (int i = 0; i < 24; i++)		//For each vertex, set each scale to 1 and set the appropriate z values
		vertices[i][3] = 1.0f;

	texies = new GLfloat*[24];	//create the array of texture co-ordinates
	for (int i = 0; i < 24; i++)
		texies[i] = new GLfloat[2];

	//Initialize angle's values to 0
	for (int i = 0; i < 4; i++)
		angles[i] = 0.0;

	
	//Assign all sides their corrosponding x and y values

	//Side 1 the front side
	vertices[0][0] = x;	//sets the x, y, z value for the 
	vertices[0][1] = y;	//first vertex of the first side.
	vertices[0][2] = z; //the top left back corner
	texies[0][0] = 0.0;
	texies[0][1] = 0.0;

	vertices[1][0] = x;
	vertices[1][1] = y - length;
	vertices[1][2] = z;
	texies[1][0] = 0.0;
	texies[1][1] = 1.0;

	vertices[2][0] = x + length;
	vertices[2][1] = y;
	vertices[2][2] = z;
	texies[2][0] = 1.0;
	texies[2][1] = 0.0;

	vertices[3][0] = x + length;
	vertices[3][1] = y - length;
	vertices[3][2] = z;
	texies[3][0] = 1.0;
	texies[3][1] = 1.0;

	//Side 2 the top side
	vertices[4][0] = x;	//top left back corner
	vertices[4][1] = y;
	vertices[4][2] = z;
	texies[4][0] = 0.0;
	texies[4][1] = 0.0;

	vertices[5][0] = x;
	vertices[5][1] = y;
	vertices[5][2] = z - length;
	texies[5][0] = 0.0;
	texies[5][1] = 1.0;

	vertices[6][0] = x + length;
	vertices[6][1] = y;
	vertices[6][2] = z;
	texies[6][0] = 0.0;
	texies[6][1] = 1.0;

	vertices[7][0] = x + length;
	vertices[7][1] = y;
	vertices[7][2] = z - length;
	texies[7][0] = 1.0;
	texies[7][1] = 1.0;
	
	//Side 3 the back of the cube
	vertices[8][0] = x;	//the top left near corner
	vertices[8][1] = y;
	vertices[8][2] = z - length;
	texies[8][0] = 0.0;
	texies[8][1] = 0.0;

	vertices[9][0] = x;
	vertices[9][1] = y - length;
	vertices[9][2] = z - length;
	texies[9][0] = 0.0;
	texies[9][1] = 1.0;

	vertices[10][0] = x + length;
	vertices[10][1] = y;
	vertices[10][2] = z - length;
	texies[10][0] = 1.0;
	texies[10][1] = 0.0;

	vertices[11][0] = x + length;
	vertices[11][1] = y - length;
	vertices[11][2] = z - length;
	texies[11][0] = 1.0;
	texies[11][1] = 1.0;

	//Side 4 the bottom side
	vertices[12][0] = x;	//the bottom left back corner
	vertices[12][1] = y - length;
	vertices[12][2] = z;
	texies[12][0] = 0.0;
	texies[12][1] = 1.0;

	vertices[13][0] = x;
	vertices[13][1] = y - length;
	vertices[13][2] = z - length;
	texies[13][0] = 0.0;
	texies[13][1] = 0.0;

	vertices[14][0] = x + length;
	vertices[14][1] = y - length;
	vertices[14][2] = z;
	texies[14][0] = 1.0;
	texies[14][1] = 1.0;

	vertices[15][0] = x + length;
	vertices[15][1] = y - length;
	vertices[15][2] = z - length;
	texies[15][0] = 1.0;
	texies[15][1] = 0.0;

	//Side 5 left side of the cube
	vertices[16][0] = x;	//top left back corner
	vertices[16][1] = y;
	vertices[16][2] = z;
	texies[16][0] = 0.0;
	texies[16][1] = 0.0;

	vertices[17][0] = x;
	vertices[17][1] = y;
	vertices[17][2] = z - length;
	texies[17][0] = 1.0;
	texies[17][1] = 0.0;

	vertices[18][0] = x;
	vertices[18][1] = y - length;
	vertices[18][2] = z;
	texies[18][0] = 0.1;
	texies[18][1] = 0.1;

	vertices[19][0] = x;
	vertices[19][1] = y - length;
	vertices[19][2] = z - length;
	texies[19][0] = 1.0;
	texies[19][1] = 1.0;

	//Side 6 the right side
	vertices[20][0] = x + length;
	vertices[20][1] = y;	//the top back right corner
	vertices[20][2] = z;
	texies[20][0] = 1.0;
	texies[20][1] = 0.0;

	vertices[21][0] = x + length;
	vertices[21][1] = y;
	vertices[21][2] = z - length;
	texies[21][0] = 0.0;
	texies[21][1] = 0.0;

	vertices[22][0] = x + length;
	vertices[22][1] = y - length;
	vertices[22][2] = z;
	texies[22][0] = 1.0;
	texies[22][1] = 1.0;

	vertices[23][0] = x + length;
	vertices[23][1] = y - length;
	vertices[23][2] = z - length;
	texies[23][0] = 0.0;
	texies[23][1] = 1.0;

	
	//Set the values of the centerpoint of this cube
	centerPoint[0] = x + length/2.0;
	centerPoint[1] = y - length/2.0;
	centerPoint[2] = z - length/2.0;
	centerPoint[3] = 1.0;
}




//=========================================================
//matMultiply()
//
// Multiplies a the vertices of this cube by a given transformation matrix
//
//Pre: transformMat and translate are both initialized
//Post: vertices's vertices are changed
void Cube::matMultiply(vmath::mat4 transformMat, bool translate)
{
	vmath::vec4 tempVec;	//Will hold the resulting vector values of the matrix multiplication

	for (int i = 0; i < 24; i++)
	{
		//Set each value of the temporary vector to 0, for use with this current vertex
		for (int j = 0; j < 4; j++)
			tempVec[j] = 0;

		//Perform the matrix multiplication and store the resulting vector
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				//The multiplication is different if it is a translation
				if (translate)
					tempVec[j] += vertices[i][k] * transformMat[k][j];
				else
					tempVec[j] += vertices[i][k] * transformMat[j][k];
			}
		}

		//Copy the new values into the vertices array
		for (int j = 0; j < 4; j++)
			vertices[i][j] = tempVec[j];
	}
}

//=========================================================
//scale()
//
//scales the current cube by a given factor
//
//Pre: factor is initialized
//Post: A cube may have been scaled by a certain factor
void Cube::scale(float factor)
{
	GLfloat GLfactor = factor;	//Convert the given float value to a GLfloat
	vmath::mat4 scaleMat = vmath::scale(GLfactor);	//Declare and the matrix used for this type of multiplication
	
	//Get variables to store the venterpoint's values before they change
	float origCenterX = centerPoint[0];
	float origCenterY = centerPoint[1];
	float origCenterZ = centerPoint[2];

	//Translate the cube to the origin
	this -> translateX(-1.0 * origCenterX);
	this -> translateY(-1.0 * origCenterY);
	this -> translateZ(-1.0 * origCenterZ);

	matMultiply(scaleMat, false);	//Perform the matrix multiplication for the transformation

	//Translate the cube to the original location
	this -> translateX(origCenterX);
	this -> translateY(origCenterY);
	this -> translateZ(origCenterZ);


	length = length * factor;
}

//=========================================================
//rotate()
//
//rotates the model by a given angle across the x, y, or z axis
//
//Pre: angle and state are defined.
//Post: all the verticies in the cube are rotated around a certain axis.
void Cube::rotate(float angle, int state)
{	

	GLfloat GLangle = angle;	//Convert the given float value to a GLfloat
	vmath::mat4 rotateMat;	//Declare and the matrix used for this type of multiplication

	//Get the matrix which will be used for multiplication
	if (state == 1)
	{
		rotateMat = vmath::rotate(GLangle, 1.0f, 0.0f, 0.0f);
		angles[0] += GLangle;
	}
	else if (state == 2)
	{
		rotateMat = vmath::rotate(GLangle, 0.0f, 1.0f, 0.0f);
		angles[1] += GLangle;
	}
	else
	{
		rotateMat = vmath::rotate(GLangle, 0.0f, 0.0f, 1.0f);
		angles[2] += GLangle;
	}
	

	//Get variables to store the venterpoint's values before they change
	float origCenterX = centerPoint[0];
	float origCenterY = centerPoint[1];
	float origCenterZ = centerPoint[2];

	//Translate the cube to the origin
	this -> translateX(-1.0 * origCenterX);
	this -> translateY(-1.0 * origCenterY);
	this -> translateZ(-1.0 * origCenterZ);

	matMultiply(rotateMat, false);	//Perform the matrix multiplication for the transformation

	//Translate the cube to the original location
	this -> translateX(origCenterX);
	this -> translateY(origCenterY);
	this -> translateZ(origCenterZ);
}

//=========================================================
//translateY()
//
//Translates the model across the y-axis by a given amount
//
//Pre: amount is defined.
//Post: all the verticies in the cube are translatedalong the y-axis by amount.
void Cube::translateY(float amount)
{
	
	GLfloat GLamount = amount;	//Convert the given float value to a GLfloat

	vmath::mat4 translationMat = vmath::translate(0.0f, GLamount, 0.0f);	//Declare and initalize the matrix used for this type of multiplication
	

	matMultiply(translationMat, true);	//Perform the matrix multiplication for the transformation

	centerPoint[1] += amount;	//Update the center point's location
}

//=========================================================
//translateZ()
//
//Translates the model across the z-axis by a given amount
//
//Pre: amount is defined.
//Post: all the verticies in the cube are translatedalong the z-axis by amount.
void Cube::translateZ(float amount)
{
	GLfloat GLamount = amount;	//Convert the given float value to a GLfloat

	vmath::mat4 translationMat = vmath::translate(0.0f, 0.0f, GLamount);	//Declare and initalize the matrix used for this type of multiplication


	matMultiply(translationMat, true);	//Perform the matrix multiplication for the transformation

	centerPoint[2] += amount;	//Update the center point's location
}

//=========================================================
//translateX()
//
//Translates the model across the x-axis by a given amount
//
//Pre: amount is defined.
//Post: all the verticies in the cube are translatedalong the x-axis by amount.
void Cube::translateX(float amount)
{
	
	GLfloat GLamount = amount;	//Convert the given float value to a GLfloat

	vmath::mat4 translationMat = vmath::translate(GLamount, 0.0f, 0.0f);	//Declare and initalize the matrix used for this type of multiplication
	

	matMultiply(translationMat, true);	//Perform the matrix multiplication for the transformation

	centerPoint[0] += amount;	//Update the center point's location
}


//changes the current texture to a new given texture
void Cube::setTexture(std::vector<GLuint> newTexture)
{

}

//=========================================================
//getVertices()
//
// Returns the vertices array
//
//Pre:
//Post: a 2D pointer is returned
GLfloat** Cube::getVertices()
{
	return vertices;
}

//=========================================================
//getAngles()
//
// Returns a vec4 of the angles to which this cube has been rotated around the
// x, y, and z axes
//
//Pre:
//Post: angles is returned
vec4 Cube::getAngles()
{
	return angles;
}
//Returns this object's texture vector
GLfloat** Cube::getTexies()
{
	return texies;
}
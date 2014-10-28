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
	
	//Assign all sides their corrosponding x and y values

	//Side 1 the backmost side
	vertices[0][0] = x;	//sets the x, y, z value for the 
	vertices[0][1] = y;	//first vertex of the first side.
	vertices[0][2] = z; //the top left back corner
	texies[0][0] = 0.0;
	texies[0][1] = 0.0;

	vertices[1][0] = x;
	vertices[1][1] = y - sideLength;
	vertices[1][2] = z;
	texies[1][0] = 0.0;
	texies[1][1] = 1.0;

	vertices[2][0] = x + sideLength;
	vertices[2][1] = y;
	vertices[2][2] = z;
	texies[2][0] = 1.0;
	texies[2][1] = 0.0;

	vertices[3][0] = x + sideLength;
	vertices[3][1] = y - sideLength;
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
	vertices[5][2] = z - sideLength;
	texies[5][0] = 0.0;
	texies[5][1] = 1.0;

	vertices[6][0] = x + sideLength;
	vertices[6][1] = y;
	vertices[6][2] = z;
	texies[6][0] = 0.0;
	texies[6][1] = 1.0;

	vertices[7][0] = x + sideLength;
	vertices[7][1] = y;
	vertices[7][2] = z - sideLength;
	texies[7][0] = 1.0;
	texies[7][1] = 1.0;
	
	//Side 3 the front side of the cube
	vertices[8][0] = x;	//the top left near corner
	vertices[8][1] = y;
	vertices[8][2] = z - sideLength;
	texies[8][0] = 0.0;
	texies[8][1] = 0.0;

	vertices[9][0] = x;
	vertices[9][1] = y - sideLength;
	vertices[9][2] = z - sideLength;
	texies[9][0] = 0.0;
	texies[9][1] = 1.0;

	vertices[10][0] = x + sideLength;
	vertices[10][1] = y;
	vertices[10][2] = z - sideLength;
	texies[10][0] = 1.0;
	texies[10][1] = 0.0;

	vertices[11][0] = x + sideLength;
	vertices[11][1] = y - sideLength;
	vertices[11][2] = z - sideLength;
	texies[11][0] = 1.0;
	texies[11][1] = 1.0;

	//Side 4 the bottom side
	vertices[12][0] = x;	//the bottom left back corner
	vertices[12][1] = y - sideLength;
	vertices[12][2] = z;
	texies[12][0] = 0.0;
	texies[12][1] = 1.0;

	vertices[13][0] = x;
	vertices[13][1] = y - sideLength;
	vertices[13][2] = z - sideLength;
	texies[13][0] = 0.0;
	texies[13][1] = 0.0;

	vertices[14][0] = x + sideLength;
	vertices[14][1] = y - sideLength;
	vertices[14][2] = z;
	texies[14][0] = 1.0;
	texies[14][1] = 1.0;

	vertices[15][0] = x + sideLength;
	vertices[15][1] = y - sideLength;
	vertices[15][2] = z - sideLength;
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
	vertices[17][2] = z - sideLength;
	texies[17][0] = 1.0;
	texies[17][1] = 0.0;

	vertices[18][0] = x;
	vertices[18][1] = y - sideLength;
	vertices[18][2] = z;
	texies[18][0] = 0.1;
	texies[18][1] = 0.1;

	vertices[19][0] = x;
	vertices[19][1] = y - sideLength;
	vertices[19][2] = z - sideLength;
	texies[19][0] = 1.0;
	texies[19][1] = 1.0;

	//Side 6 the right side
	vertices[20][0] = x + sideLength;
	vertices[20][1] = y;	//the top back right corner
	vertices[20][2] = z;
	texies[20][0] = 1.0;
	texies[20][1] = 0.0;

	vertices[21][0] = x + sideLength;
	vertices[21][1] = y;
	vertices[21][2] = z - sideLength;
	texies[21][0] = 0.0;
	texies[21][1] = 0.0;

	vertices[22][0] = x + sideLength;
	vertices[22][1] = y - sideLength;
	vertices[22][2] = z;
	texies[22][0] = 1.0;
	texies[22][1] = 1.0;

	vertices[23][0] = x + sideLength;
	vertices[23][1] = y - sideLength;
	vertices[23][2] = z - sideLength;
	texies[23][0] = 0.0;
	texies[23][1] = 1.0;

}

//Scales the model by a given factor
void Cube::scale(float factor)
{
	float length = vertices[2][0] - vertices[0][0];
	float newLength = length * factor;
	//These dont work, take the difference between the new sidelength 
	//and the old sidelength and then infer how much to change these by
	float x = vertices[0][0] - ((newLength - length)/2);	
	float y = vertices[0][1] + ((newLength - length)/2);
	float z = vertices[0][2] + ((newLength - length)/2);


	vertices[0][0] = x;
	vertices[0][1] = y;
	vertices[0][2] = z;

	vertices[1][0] = x;
	vertices[1][1] = y - newLength;
	vertices[1][2] = z;

	vertices[2][0] = x + newLength;
	vertices[2][1] = y;
	vertices[2][2] = z;

	vertices[3][0] = x + newLength;
	vertices[3][1] = y - newLength;
	vertices[3][2] = z;

	//Side 2
	vertices[4][0] = x;
	vertices[4][1] = y;
	vertices[4][2] = z;

	vertices[5][0] = x;
	vertices[5][1] = y;
	vertices[5][2] = z - newLength;

	vertices[6][0] = x + newLength;
	vertices[6][1] = y;
	vertices[6][2] = z;

	vertices[7][0] = x + newLength;
	vertices[7][1] = y;
	vertices[7][2] = z - newLength;

	//Side 3
	vertices[8][0] = x;
	vertices[8][1] = y;
	vertices[8][2] = z - newLength;

	vertices[9][0] = x;
	vertices[9][1] = y - newLength;
	vertices[9][2] = z - newLength;

	vertices[10][0] = x + newLength;
	vertices[10][1] = y;
	vertices[10][2] = z - newLength;

	vertices[11][0] = x + newLength;
	vertices[11][1] = y - newLength;
	vertices[11][2] = z - newLength;

	//Side 4
	vertices[12][0] = x;
	vertices[12][1] = y - newLength;
	vertices[12][2] = z;

	vertices[13][0] = x;
	vertices[13][1] = y - newLength;
	vertices[13][2] = z - newLength;

	vertices[14][0] = x + newLength;
	vertices[14][1] = y - newLength;
	vertices[14][2] = z;

	vertices[15][0] = x + newLength;
	vertices[15][1] = y - newLength;
	vertices[15][2] = z - newLength;

	//Side 5
	vertices[16][0] = x;
	vertices[16][1] = y;
	vertices[16][2] = z;

	vertices[17][0] = x;
	vertices[17][1] = y;
	vertices[17][2] = z - newLength;

	vertices[18][0] = x;
	vertices[18][1] = y - newLength;
	vertices[18][2] = z;

	vertices[19][0] = x;
	vertices[19][1] = y - newLength;
	vertices[19][2] = z - newLength;

	//Side 6
	vertices[20][0] = x + newLength;
	vertices[20][1] = y;
	vertices[20][2] = z;

	vertices[21][0] = x + newLength;
	vertices[21][1] = y;
	vertices[21][2] = z - newLength;

	vertices[22][0] = x + newLength;
	vertices[22][1] = y - newLength;
	vertices[22][2] = z;

	vertices[23][0] = x + newLength;
	vertices[23][1] = y - newLength;
	vertices[23][2] = z - newLength;
	
	/*
	//note that the last row uses 1.0 because that 
	//is what the entire vertex is divided by.
	float transform[4][4] = 
	{ {factor, 0.0, 0.0, 0.0},
	  {0.0, factor, 0.0, 0.0},
	  {0.0, 0.0, factor, 0.0},
	  {0.0, 0.0, 0.0, 1.0} }; */
}

//Rotates the model by a given amount
void Cube::rotate(float amount)
{

	//vmath::mat4 lehpse = vmath::rotate(1.0f, 0.0f, 0.0f, 0.5f);
}

//Translates the model up by amount
//Pre: amount is defined
//Post: all the verticies of the cube are translated up.
void Cube::translateUp(float amount)
{
	for (int i = 0; i < 24; i++)
	{
		vertices[i][1] = vertices[i][1] + amount;
	}
	

	/*
	GLfloat GLamount = amount;
	vmath::mat4 translationMat = vmath::translate(0.0f, amount, 0.0f);
	vmath::mat4 tempMat;
	vmath::vec4 tempVertex;


	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempMat[j] = vertices[i][j];
		}
		
		tempVertex = (tempMat*translationMat)[0];

		for (int j = 0; j < 4; j++)
		{
			//std::cout << tempVertex[1][j] << "\n";
			vertices[i][j] = tempVertex[j];
		}
	}
	*/

	//the needed transform matrix for reference
	/*
	float transform[4][4] = 
	{ {1.0, 0.0, 0.0, 0.0},
	  {0.0, 1.0, 0.0, amount},
	  {0.0, 0.0, 1.0, 0.0},
	  {0.0, 0.0, 0.0, 1.0} };*/
}

//Translates the model down by amount
//Pre: amount is defined.
//Post: all the verticies in the cube are translated down by amount.
void Cube::translateDown(float amount)
{
	for (int i = 0; i < 24; i++)
	{
		vertices[i][1] -= amount;
	}

	//the desired matirx for the translation
	/*
	float transform[4][4] = 
	{ {1.0, 0.0, 0.0, 0.0},
	  {0.0, 1.0, 0.0, -amount},
	  {0.0, 0.0, 1.0, 0.0},
	  {0.0, 0.0, 0.0, 1.0} }; */
}

//Translates the model left by amount
//Pre: amount is defined.
//Post: all the verticies in the cube are translated left by amount.
void Cube::translateLeft(float amount)
{
	for (int i = 0; i < 24; i++)
	{
		vertices[i][0] -= amount;
	}
	
	/*
	//the desired matirx for the translation
	float transform[4][4] = 
	{ {1.0, 0.0, 0.0, amount},
	  {0.0, 1.0, 0.0, 0.0},
	  {0.0, 0.0, 1.0, 0.0},
	  {0.0, 0.0, 0.0, 1.0} }; */
}

//Translates the model right by amount
//Pre: amount is defined.
//Post: all the verticies in the cube are translated right by amount.
void Cube::translateRight(float amount)
{
	for (int i = 0; i < 24; i++)
	{
		vertices[i][0] += amount;
	}


	//the desired matirx for the translation
	/*
	float transform[4][4] = 
	{ {1.0, 0.0, 0.0, amount},
	  {0.0, 1.0, 0.0, 0.0},
	  {0.0, 0.0, 1.0, 0.0},
	  {0.0, 0.0, 0.0, 1.0} };*/
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
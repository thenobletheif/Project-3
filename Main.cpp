/* Main.cpp
* Author: Hunter Ripsom-Gardiner
* Date: 10/16/14 
* Course: CSC 5210 Graphics
* Description: A program that makes a 3D scene, populates
* it with cubes and randomly textures the cubes. Alows you
* to rotate, retexture, and move cubes, as well as to manipulate the camera.
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

#include "Cube.h"
#include "Camera.h"
#include "lodepng.h"
#include <vector>


using std::cout;
using std::endl;
using std::cerr;

// Enumerations
// Vertex array objects
enum { VERTS, NUM_VAOS };
// Buffers
enum { VERTS_BUFFER, NUM_BUFFERS };
// textures
enum { PLACEHOLDER_TEXTURE, NUM_TEXTURES };

// Data is stored in these arrays
GLuint VAOs[ NUM_VAOS ];
GLuint Buffers[ NUM_BUFFERS ];
GLuint Textures[ NUM_TEXTURES ];

int currentCube = 0;
int numCubes = 3;
const int WINDOW_X = 512;
const int WINDOW_Y = 512;

GLfloat vertices[72][4];
Cube* models[3];

void updateVertices();

//randomizeTextures()
//
// Will give the 3 3D models a texture randomly out of the given
// 10 available textures
//
//
//
void randomizeTextures()
{

}

void init()
{ 
	models[0] = new Cube(0.3, -0.65, 0.15, 0);
	models[1] = new Cube(0.3, -0.15, 0.15, 0);
	models[2] = new Cube(0.3, 0.35, 0.15, 0);
	updateVertices();

	//generates NUM_TEXTURES number of ID's to be stored
	//in the array called "Textures"
	glGenTextures(NUM_TEXTURES, Textures);
	//says use the GL_TEXTURE_RECTANGLE format for the texture ID stored in
	//textures sub PLACEHOLDER_TEXTURE
	glBindTexture(GL_TEXTURE_RECTANGLE, Textures[PLACEHOLDER_TEXTURE]);

	

	

	glGenVertexArrays(NUM_VAOS, VAOs);
	glBindVertexArray(VAOs[VERTS]);

	glGenBuffers(NUM_BUFFERS, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[VERTS_BUFFER]);

	/*
	//Load raw pixel data into texture vectors
	unsigned width;
	unsigned height;
	std::vector<unsigned char> exampleTexture; //Must be of type unsigned char, which means each element is of value 0 to 255

	lodepng::decode(exampleTexture, width, height, "exampleTexture.png");
	*/

	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );

	ShaderInfo shaders[] = {
        {GL_VERTEX_SHADER, "vertices.vert"},
        {GL_FRAGMENT_SHADER, "fragments.frag"},
        {GL_NONE, NULL}
    };
	GLuint vertexOffset = 0;
	GLuint program = LoadShaders( shaders );
	glUseProgram( program );
	glVertexAttribPointer( vertexOffset, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray( vertexOffset );
}

void updateVertices()
{
	GLfloat** tempArray;
	for (int i = 0; i < 3; i++)
	{
		tempArray = models[i] -> getVertices();
		for (int j = 0; j < 24; j++)
		{
			for (int h = 0; h < 4; h++)
			{
				vertices[j + (i * 24)][h] = tempArray[j][h];
			}
		}
		delete(tempArray);
	}
}


void scaleHandler(float scale)
{
	models[currentCube] -> rotate(scale);
}

void rotationHandler(bool clockwise)
{
	int amount = 0.5;

	models[currentCube] -> rotate(amount);
}

void moveHandler(int direction)
{
	int moveDistance = 0.1;

	switch(direction)
	{
	case 1:
		models[currentCube] -> translateLeft(moveDistance);
		break;
	case 2:
		models[currentCube] -> translateDown(moveDistance);
		break;
	case 3:
		models[currentCube] -> translateRight(moveDistance);
		break;
	case 4:
		models[currentCube] -> translateUp(moveDistance);
		break;
	default:
		break;
	}

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAOs[VERTS]);
	glBindBuffer( GL_ARRAY_BUFFER, Buffers[VERTS_BUFFER] );
	glBufferData( GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW );

	glLineWidth(2);

	for (int i = 0; i < 18; i++)
	{
		glDrawArrays(GL_TRIANGLE_STRIP, i * 4, 4);
	}


	// Clear the screen
	glFlush();
}

//A function to handle mouse input
//checks mouse current position and wether left or right button is clicked or released.
//action is used for clicked or unclicked
void mouse(int button, int action, int x, int y)
{

}

//a function that handles mouse movement.
void mouseMove(int x, int y)
{

}

//A function that handles keyboard input. takes as input the key 
//clicked and the mouse's current position.
void keyboard(unsigned char key, int x, int y)
{
	switch( key ) 
	{
	case 'q':
	case 'Q':
		exit(0);
		break;

	case 'm':	//switch to next object
	case 'M':
		currentCube += 1;
		currentCube %= numCubes;
		break;

	//scaling section of code
	case 'b':	//scale the object by 1.25
	case 'B':
		scaleHandler(1.25);
		break;
	case 'n':	//scale the object by .80
	case 'N':
		scaleHandler(0.80);
		break;

	//rotation section of code
	case 'c':	//rotate the object clockwise. C for clockwise
	case 'C':
		rotationHandler(true);
		break;
	case 'v':	//rotate the object counterclockwise. 
	case 'V':
		rotationHandler(false);
		break;

	//move object section of code
	case 'a':	//move object left
	case 'A':
		moveHandler(1);
		break;
	case 's':	//move object down
	case 'S':
		moveHandler(2);
		break;
	case 'd':	//move object right
	case 'D':
		moveHandler(3);
		break;
	case 'w':	//move object up
	case 'W':
		moveHandler(4);
		break;

	case 't':	//retexture all objects.
	case 'T':
		for(int i = 0; i < numCubes; i++)
		{
			//retexture call for each cube
		}
		break;

	case 'r':	//rotate camera 180 degrees
	case 'R':
		break;

	//if any other key is pressed a message is output.
	default:
		cerr << "Invalid key pressed: " << key << endl;
		break;
	}

	glutPostRedisplay();
}

//a function that handles the arrow keys.
void SpecialInput(int key, int x, int y)
{
	switch(key)
	{
	//pressing the buttons should move the camera while keeping it pointed at the center of the scene
	case GLUT_KEY_UP:
		//do something here
		break;	
	case GLUT_KEY_DOWN:
		//do something here
		break;
	case GLUT_KEY_LEFT:
		//do something here
		break;
	case GLUT_KEY_RIGHT:
		//do something here
		break;
	}

}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//the display mode is in red, green, blue, transparancy mode.
	glutInitDisplayMode(GLUT_RGBA);
	//make the window have size equal to the 
	//constants X and Y declared at the top of the program.
	glutInitWindowSize(WINDOW_X, WINDOW_Y); 
	//using GLUT version 4.1. You need to use a ',' instead of a '.' because reasons.
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Hunter and Alex's Awesome Camera Thing"); //name the window

	glewExperimental=GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	init();
	glutSpecialFunc(SpecialInput);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);	
	glutMotionFunc(mouseMove); 
	glutKeyboardFunc( keyboard ); 
	glutMainLoop();

	

	return 0;
}




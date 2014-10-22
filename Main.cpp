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
#include "lodepng.h"
#include <vector>


using std::cout;
using std::endl;
using std::cerr;

// Enumerations
// Vertex array objects
enum { PLACEHOLDER_VAO, NUM_VAOS };
// Buffers
enum { PLACEHOLDER_BUFFER, NUM_BUFFERS };
// textures
enum { PLACEHOLDER_TEXTURE, NUM_TEXTURES };

// Data is stored in these arrays
GLuint VAOs[ NUM_VAOS ];
GLuint Buffers[ NUM_BUFFERS ];
GLuint Textures[ NUM_TEXTURES ];

int curentCube = 0;
int numCubes = 3;
const int WINDOW_X = 512;
const int WINDOW_Y = 512;

void init()
{
	//generates NUM_TEXTURES number of ID's to be stored
	//in the array called "textures"
	glGenTextures(NUM_TEXTURES, Textures);
	//says use the GL_TEXTURE_RECTANGLE format for the texture ID stored in
	//textures sub PLACEHOLDER_TEXTURE
	glBindTexture(GL_TEXTURE_RECTANGLE, Textures[PLACEHOLDER_TEXTURE]);

	

	glGenBuffers(NUM_BUFFERS, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, PLACEHOLDER_BUFFER);

	glGenVertexArrays(NUM_VAOS, VAOs);
	//vertex array objexts can only be generated one way, so the bind 
	//function does not need to take in a format for the Vertex Array Object
	glBindVertexArray(VAOs[PLACEHOLDER_VAO]);
}

void display()
{


	// Clear the screen
	glClear( GL_COLOR_BUFFER_BIT );
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
		curentCube += 1;
		curentCube %= numCubes;
		break;

	//scaling section of code
	case 'b':	//scale the object by 1.25
	case 'B':
		break;
	case 'n':	//scale the object by .80
	case 'N':
		break;

	//rotation section of code
	case 'c':	//rotate the object clockwise. C for clockwise
	case 'C':
		break;
	case 'v':	//rotate the object counterclockwise. 
	case 'V':
		break;

	//move object section of code
	case 'a':	//move object left
	case 'A':
		break;
	case 's':	//move object down
	case 'S':
		break;
	case 'd':	//move object right
	case 'D':
		break;
	case 'w':	//move object up
	case 'W':
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
	glutInitContextVersion(4,1);
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

	//Load raw pixel data into texture vectors
	unsigned width;
	unsigned height;
	std::vector<unsigned char> exampleTexture; //Must be of type unsigned char, which means each element is of value 0 to 255

	lodepng::decode(exampleTexture, width, height, "exampleTexture.png");

	return 0;
}




void moveCameraUp (float amount)
{

}
void moveCameraDown (float amount)
{

}

void moveCameraLeft (float amount)
{

}

void moveCameraRight (float amount)
{

}

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

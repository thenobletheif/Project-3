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
#include <vmath.h>


using std::cout;
using std::endl;
using std::cerr;

// Enumerations
// Vertex array objects
enum { VERTS, NUM_VAOS };
// Buffers
enum { VERTS_BUFFER, TEXTURE_BUFFER, NUM_BUFFERS };
// textures
enum { AURON_TEXTURE, WOOD_TEXTURE, COMPANION_CUBE_TEXTURE,TEXTURE4,TEXTURE5,TEXTURE6,TEXTURE7,TEXTURE8,TEXTURE9,TEXTURE10,NUM_TEXTURES };

// Data is stored in these arrays
GLuint VAOs[ NUM_VAOS ];
GLuint Buffers[ NUM_BUFFERS ];
GLuint Textures[ NUM_TEXTURES ];

int currentCube = 0;
int numCubes = 3;
const int WINDOW_X = 512;
const int WINDOW_Y = 512;

Camera hunterCam = Camera();

GLfloat vertices[72][4];
Cube* models[3];

void updateVertices();


// Will give all the cubes a texture randomly out of the given
// 10 available textures
//Pre: all the textures are initialized
//Post: textures are randomly asigned to each cube.
void randomizeTextures()
{

}

//the initialized function.
void init()
{ 
	models[0] = new Cube(0.3f, -0.65f, 0.15f, 0.0f);
	models[1] = new Cube(0.3f, -0.15f, 0.15f, 0.0f);
	models[2] = new Cube(0.3f, 0.35f, 0.15f, 0.0f);
	updateVertices();

	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER, "vertices.vert"},
		{GL_FRAGMENT_SHADER, "fragments.frag"},
		{GL_NONE, NULL}
	};
	GLuint vertexOffset = 0;
	GLuint program = LoadShaders( shaders );
	glUseProgram( program );

	//alows you to use 2D textures
	glEnable(GL_TEXTURE_2D);
	
	//generates NUM_TEXTURES number of ID's to be stored
	//in the array called "Textures"
	glGenTextures(NUM_TEXTURES, Textures);
	models[0]->setTextureID(Textures[0]);
	models[1]->setTextureID(Textures[0]);
	models[2]->setTextureID(Textures[0]);

	//Load raw pixel data into texture vectors
	//width and height GAIN the values that lodepng is using.
	unsigned width = 0;
	unsigned height = 0;
	std::vector<unsigned char> auronTexture; //Must be of type unsigned char, which means each element is of value 0 to 255

	lodepng::decode(auronTexture, width, height, "auron.png");
	glBindTexture(GL_TEXTURE_2D, Textures[AURON_TEXTURE]);
	
	// Specify the data for the texture
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // First mipmap level
		GL_RGBA,	//Internal format
		width, height, // width and height
		0,	//Border
		GL_RGBA, GL_UNSIGNED_BYTE, // format and type
		&(auronTexture[0]) ); // data

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(picData[0] );

	std::vector<unsigned char> woodTexture; //Must be of type unsigned char, which means each element is of value 0 to 255

	lodepng::decode(woodTexture, width, height, "wood.png");
	glBindTexture(GL_TEXTURE_2D, Textures[WOOD_TEXTURE]);
	
	// Specify the data for the texture
	glTexImage2D(GL_TEXTURE_2D, // target
		0, // First mipmap level
		GL_RGBA,	//Internal format
		width, height, // width and height
		0,	//Border
		GL_RGBA, GL_UNSIGNED_BYTE, // format and type
		&(woodTexture[0]) ); // data

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
	
	//sets the atribute for the texture overlay and enables that atribute.
	glVertexAttribPointer( 1, 2, GL_FLOAT, GL_FALSE , 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray( 1 );
}

//a function that handles updating the verticies 
//after the vertices have been updated in the cube.
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
	}
}

//a handler for scaling the cube.
void scaleHandler(float scale)
{
	models[currentCube] -> scale(scale);
	updateVertices();
}

//a handler for rotating the cube
void rotationHandler(bool clockwise, int state)
{
	//if the cube is rotating clockwise rotate 0.5 units
	//otherwise rotate -0.5 units.
	float amount;
	if(clockwise)
		amount = 0.5;
	else
		amount = -0.5;

	models[currentCube] -> rotate(amount, state);
	updateVertices();
}

//a handler for moving the cubes
void moveHandler(int direction)
{
	float moveDistance = 0.1;

	switch(direction)
	{
	case 1:
		models[currentCube] -> translateLeft(moveDistance);
		break;
	case 2:
		models[currentCube] -> translateY(-0.1);
		break;
	case 3:
		models[currentCube] -> translateRight(moveDistance);
		break;
	case 4:
		models[currentCube] -> translateY(0.1);
		break;
	default:
		cout<< "ERROR: Somehow you are trying to move in the " <<endl;
			cout <<"wrong dirrection. See move handler in main." <<endl;
		break;
	}
	
	updateVertices();
}

//the display function.
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);

	//each of the cubes uses its own draw self functions
	for (int i = 0; i < 3; i++)
	{
		models[i]->drawSelf();
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
	case 'f':	//rotate the object clockwise around the x-axis.
	case 'F':
		rotationHandler(true, 1);
		break;
	case 'g':	//rotate the object counterclockwise around the x-axis .
	case 'G':
		rotationHandler(false, 1);
		break;
	case 'h':	//rotate the object clockwise around the y-axis.
	case 'H':
		rotationHandler(true, 2);
		break;
	case 'j':	//rotate the object counterclockwise around the y-axis. 
	case 'J':
		rotationHandler(false, 2);
		break;
	case 'k':	//rotate the object clockwise around the z-axis.
	case 'K':
		rotationHandler(true, 3);
		break;
	case 'l':	//rotate the object counterclockwise around the z-axis. 
	case 'L':
		rotationHandler(false, 3);
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
	//enables depth test to draw things in the right order on the screen.
	//glEnable(GL_DEPTH_TEST);

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




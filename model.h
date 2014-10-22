//==============================================================================
// Alex Deacon & Hunter Ripsom Gardner
// 10/10/2014
// Project 3
//
// model.cpp : 
// This class is for a 3D model which can be translated, rotated, and scaled
// 
// Inputs: 
// Outputs: 
// =============================================================================


#include <iostream>

using namespace std;


class Model
{
private:

	

public:

	Model();					// default constructor

	void scale(float);			//Scales the model by a given factor

	void rotate(float);			//Rotates the model by a given amount

	void translateUp(float);	//Translates the model up by a given amount

	void translateDown(float);	//Translates the model down by a given amount

	void translateLeft(float);	//Translates the model left by a given amount

	void translateRight(float);	//Translates the model right by a given amount

};
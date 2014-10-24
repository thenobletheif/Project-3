#version 330 core

layout(location = 0) in vec4 vPosition;

uniform vec4 adder;

void main()
{
	gl_Position = vPosition + adder;
}

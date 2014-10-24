#version 330 core

layout(location = 0) in vec4 vPosition;

out vec4 color;

void main()
{
	gl_Position = vPosition;
}

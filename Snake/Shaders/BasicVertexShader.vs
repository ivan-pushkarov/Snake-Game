#version 120

attribute vec4 _Color;
attribute vec4 _Position; // Automatic cast to vec4 with w coordinate = 1 same as vec4(_Position.xyz, 1)

uniform mat4 mT;

void main()
{
	gl_FrontColor = _Color;
	gl_Position = mT*_Position;
}
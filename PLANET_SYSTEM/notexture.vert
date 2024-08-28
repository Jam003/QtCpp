#version 330 core

uniform mat4 View, Model, Projection;
layout (location = 0) in vec3 vPos;

void main()
{
	gl_Position = Projection * View * Model * vec4(vPos, 1);
}
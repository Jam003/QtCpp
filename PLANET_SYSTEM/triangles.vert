#version 330 core

uniform mat4 View, Model, Projection;
layout (location = 0) in vec3 vPos;
layout (location = 1) in vec2 texCoord;

out vec2 texCoord_v;

void main()
{
	gl_Position = Projection * View * Model * vec4(vPos, 1);
	texCoord_v = texCoord;
}
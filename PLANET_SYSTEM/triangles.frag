#version 330 core

in vec2 texCoord_v;
out vec4 fColor;

uniform sampler2D tex;

void main()
{
	fColor = texture(tex, texCoord_v);
	//fColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Colors
layout (location = 1) in vec3 aColor;
// Texture Coordinates
layout (location = 2) in vec2 aTex;


// Outputs the color for the Fragment Shader
out vec3 color;
// Outputs the texture coordinates to the Fragment Shader
out vec2 texCoord;


uniform mat4 camMatrix;

uniform mat4 model;
out vec3 crntPos;

out vec3 pos;

out vec3 Normal;

void main()
{
	
	crntPos=vec3(model * vec4(aPos,1.0f));
	color = aColor;
	
	texCoord = aTex;
	
	
	gl_Position =  camMatrix * model * vec4(aPos, 1.0);

	pos=aPos;

	Normal = aColor;


}
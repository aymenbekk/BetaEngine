#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;



in vec3 color;

in vec2 texCoord;

in vec3 pos;





void main()
{
  FragColor = vec4(0.5f,0.5f,0.5f,1.0f);
	
}
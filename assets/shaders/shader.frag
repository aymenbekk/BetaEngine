#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;



in vec3 color;

in vec2 texCoord;







void main()
{
  FragColor = vec4(color,1.0f);
	
}
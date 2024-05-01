#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;



in vec3 color;

in vec2 texCoord;

uniform sampler2D texture1;





void main()
{
  FragColor = texture(texture1,texCoord);
	
}
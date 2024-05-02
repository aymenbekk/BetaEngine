#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;



in vec3 color;

in vec2 texCoord;
in vec3 Normal;

uniform vec4 lightColor;

uniform vec3 lightPos;

uniform vec3 camPos;

uniform sampler2D texture1;

in vec3 pos;

in vec3 crntPos;

void main()
{

 
float ambient = 0.20f;

vec3 lightDirection = normalize(lightPos - crntPos);

float diffuse = max(dot(Normal,lightDirection),0.0f);


float specularLight= 0.5f;
vec3 viewDirection= normalize(camPos - crntPos);
vec3 reflectionDirection = reflect(-lightDirection,Normal);
float speculAmount = pow(max(dot(viewDirection, reflectionDirection),0.0f),8);
float specular = speculAmount * specularLight;



 FragColor = texture(texture1,texCoord)*lightColor*(diffuse + ambient + specular );

  
	
}
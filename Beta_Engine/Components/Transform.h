#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include "Component.h"

using namespace glm;

class Transform : public Component
{
public:

	Transform(vec3& position, vec3& rot, vec3& scale);


	//calculate the world matrix for each entity in a scene (entities and their childs)
	void updateGraph();

private:
	vec3 position = { 0.0f,0.0f,0.0f };
	vec3 eulerRotation = { 0.0f,0.0f,0.0f };
	vec3 scale = { 1.0f,1.0f,1.0f };

	//world/Model matrix use to position our entity in the world
	mat4 worldMatrix = mat4(1.0f);
	mat4 getLocalMatrix();

};


#endif // !TRANSFORM_H

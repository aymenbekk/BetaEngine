#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "../Scene/Entity.h"
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
	Transform();
	mat4 getWorldMatrix() { return worldMatrix; };
	void setWorldMatrix(mat4& matrix) { worldMatrix = matrix; };
	mat4 getLocalMatrix();
	

	//calculate the world matrix for each entity in a scene (entities and their childs)
	/*void updateSelfAndChilds();*/

	void setPosition(vec3 pos) { position = pos; };
	vec3 getPosition() { return position; };

	void update() override;

private:

	vec3 position = { 0.0f,0.0f,0.0f };
	vec3 eulerRotation = { 0.0f,0.0f,0.0f };
	vec3 scale = { 1.0f,1.0f,1.0f };

	//world/Model matrix use to position our entity in the world
	mat4 worldMatrix = mat4(1.0f);


};


#endif // !TRANSFORM_H

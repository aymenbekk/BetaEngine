#include "Transform.h"

Transform::Transform(vec3& position, vec3& rot, vec3& scale):
	position(position),
	eulerRotation(rot),
	scale(scale)
{

}
Transform::Transform() {

}


mat4 Transform::getLocalMatrix() {
	const mat4 rotx = rotate(mat4(1.0f), radians(eulerRotation.x), vec3(1.0f, 0.0f, 0.0f));
	const mat4 roty = rotate(mat4(1.0f), radians(eulerRotation.y), vec3(0.0f, 1.0f, 0.0f));
	const mat4 rotz = rotate(mat4(1.0f), radians(eulerRotation.z), vec3(0.0f, 0.0f, 1.0f));

	const mat4 rotationMatrix = rotx * roty * rotz;
	const mat4 translateMatrix = translate(mat4(1.0f), position);
	const mat4 scaleMatrix = glm::scale(mat4(1.0f), scale);

	return translateMatrix * rotationMatrix * scaleMatrix;


}


//void Transform::update() {
//
//}
//void Transform::updateSelfAndChilds() {
//	if (root->parent) {
//
//	}
//}
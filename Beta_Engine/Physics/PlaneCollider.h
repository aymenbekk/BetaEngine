#ifndef PLANE_H
#define PLANE_H

#include "../Math.h"
using namespace glm;
class PlaneCollider
{
public:
	PlaneCollider();
	~PlaneCollider();

private:
	const vec3 normal;
	const float distance;
};


#endif
#ifndef SPHERE_H
#define SPHERE_H

#include "../Math.h"
#include "vector"
#include "IntersectData.h"
using namespace glm;

class SphereCollider {


public:
	SphereCollider(const vec3 center, float radius) :center(center), radius(radius) {}
	
	IntersectData intersectSphere(const SphereCollider& other);

	inline const vec3 getCenter() { return center; }
	inline  float getRadius() { return radius; }

private:
	const vec3 center;
	const float radius;


};


#endif // !SPHERE_H

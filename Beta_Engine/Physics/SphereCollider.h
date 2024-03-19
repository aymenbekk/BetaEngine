#ifndef SPHERE_H
#define SPHERE_H



#include "./Collider.h"
#include "./PlaneCollider.h"
using namespace glm;


class PlaneCollider;
class SphereCollider : public Collider 
{


public:
	SphereCollider(const vec3 cente, float radius) :Collider(Collider::SPHERE), radius(radius) {
		center = cente;
	}
	
	IntersectData intersectSphere( SphereCollider& other);

	IntersectData intersectPlane( PlaneCollider& other);

	vec3 GetCenter() const override { return center; };
	inline const float getRadius() { return radius; }
	

private:
	/*const vec3 center;*/
	const float radius;


};


#endif // !SPHERE_H

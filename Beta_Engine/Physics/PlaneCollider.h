#ifndef PLANE_H
#define PLANE_H


#include "Collider.h"
#include "SphereCollider.h"

using namespace glm;
using namespace std;



class SphereCollider;
class PlaneCollider : public Collider
{
public:
	vector<vec3> chunkBorders;
	PlaneCollider(vec3 normal, float distance, vector<vec3> chunkBorders) :
		Collider(Collider::PLANE),
		normal(normal),
		distance(distance),
		chunkBorders(chunkBorders)
	{};




	PlaneCollider Normalized() const;

	IntersectData IntersectSphere( SphereCollider& other) const;

	inline const vec3 GetNormal() const { return normal; }
	inline float GetDistance()         const { return distance; }

private:
	const vec3 normal;
	const float distance;
	
};


#endif
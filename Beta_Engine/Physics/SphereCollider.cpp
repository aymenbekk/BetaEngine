#include "SphereCollider.h"


IntersectData SphereCollider::intersectSphere(const SphereCollider& other) {
	float radiusDistance = radiusDistance + other.radius;
	float centerDistance = (other.getCenter() - center).length();
	float distance = centerDistance - radiusDistance;
	return IntersectData(centerDistance < radiusDistance, distance);
}
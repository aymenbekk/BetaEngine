#include "SphereCollider.h"


IntersectData SphereCollider::intersectSphere( SphereCollider& other) {
	float radiusDistance = radius + other.getRadius();
	float centerDistance = length((other.GetCenter() - center));
	//cout << "radius DISTANCE" << radiusDistance << endl;
	//cout << "CENTER DISTANCE" << centerDistance << endl;

	float distance = centerDistance - radiusDistance;
	//cout << "DISTANCE" << distance << endl;
	return IntersectData(distance <= 0, distance);
}

IntersectData SphereCollider::intersectPlane( PlaneCollider& other) {
	/*cout << "cccc" << endl;*/
	//std::cout << "other: (" << GetCenter().x << ", " << GetCenter().y-getRadius() << ", " << GetCenter().z << ")" << std::endl;
	//cout << "y of terrain" << other.chunkBorders[0].y << endl;

	if (other.chunkBorders[0].y < (GetCenter() - getRadius()).y) {
		return IntersectData(false, 66.0f);
	}
	else if (other.chunkBorders[0].z > GetCenter().z || other.chunkBorders[2].z < GetCenter().z || other.chunkBorders[2].x > GetCenter().x || other.chunkBorders[1].x < GetCenter().x) {
		return IntersectData(false, 66.0f);
	}

	else if (other.chunkBorders[0].y - (GetCenter() - getRadius()).y == 0) {
		cout << "detect collision TRUE" << endl;
		return IntersectData(true, 0.0f);
	}
}


#include "PlaneCollider.h"



PlaneCollider PlaneCollider::Normalized()const {

	float magnitude = normal.length();


	return PlaneCollider(normal / magnitude, distance / magnitude,chunkBorders);

}


IntersectData PlaneCollider::IntersectSphere(SphereCollider& other)const {

	if (chunkBorders[0].y < (other.GetCenter() - other.getRadius()).y) {
		return IntersectData(false, 66.0f);
	}
	else if (chunkBorders[0].z > other.GetCenter().z || chunkBorders[2].z < other.GetCenter().z || chunkBorders[2].x > other.GetCenter().x || chunkBorders[1].x < other.GetCenter().x) {
		return IntersectData(false, 66.0f);
	}

	else if (chunkBorders[0].y - (other.GetCenter() - other.getRadius()).y  == 0) {
		return IntersectData(true, 0.0f);
	}
}
#include <iostream>
#include "Collider.h"
#include "SphereCollider.h"


IntersectData Collider::Intersect(const Collider& other) const
{
	if (m_type == TYPE_SPHERE && other.GetType() == TYPE_SPHERE)
	{
		SphereCollider* current = (SphereCollider*)this;
		return current->intersectSphere((SphereCollider&)other);
	}

	std::cerr << "Error: Collisions not implemented between specified "
		<< "colliders." << std::endl;
	exit(1);

	
	return IntersectData(false, 0);
}

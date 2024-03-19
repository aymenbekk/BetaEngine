
#include "Collider.h"
#include "./SphereCollider.h"
#include "./PlaneCollider.h"



IntersectData Collider::Intersect( Collider& other) const
{
	if (type == SPHERE && other.GetType() == SPHERE)
	{
		SphereCollider* current = (SphereCollider*)this;
		return current->intersectSphere((SphereCollider&)other);
	}

	//if (type == PLANE && other.GetType() == SPHERE)
	//{
	//	cout << "dkhalna" << endl;
	//	PlaneCollider* current = (PlaneCollider*)this;
	//	return current->IntersectSphere((SphereCollider&)other);
	//}

	if (type == SPHERE && other.GetType() == PLANE)
	{
		
		SphereCollider* current = (SphereCollider*)this;
		return current->intersectPlane((PlaneCollider&)other);
	}


	std::cerr << "Error: Collisions not implemented between specified "
		<< "colliders." << std::endl;
	exit(1);

	
	return IntersectData(false, 0);
}

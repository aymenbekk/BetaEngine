#ifndef COLLIDER_H
#define COLLIDER_H

#include "../Math.h"
#include "./IntersectData.h"

class Collider {

public : 
	enum {
		SPHERE,
		PLANE
	};

	Collider(int type) :type(type);

	IntersectData Intersect(const Collider& other) const;



	virtual void Transform(const Vector3f& translation) {}
	virtual Vector3f GetCenter() const { return Vector3f(0, 0, 0); }
	inline int GetType() const { return m_type; }

private:
	int type;
};


#endif // !COLLIDER_H

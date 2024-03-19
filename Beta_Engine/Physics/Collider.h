#ifndef COLLIDER_H
#define COLLIDER_H


#include <iostream>
#include "../Math.h"
#include "./IntersectData.h"
using namespace glm;

class Collider {

public : 
	enum {
		SPHERE,
		PLANE
	};

	Collider(int type) :type(type) {};
	Collider() {};

	IntersectData Intersect( Collider& other) const;



	virtual void Transform(const vec3 translation) {}
	virtual vec3 GetCenter() const { return center; }
	void setCenter(vec3 newC) { center = newC; };
	inline int GetType() const { return type; }

protected:    //LZM NSETI EL CENTER TA3 el collider ki el position tetupdata matensach el position ta3 el collider hiya el center ta3o so intersectSphere par ex rahi takhdem bel center we raho fix mahoch yetbedel 3la 7ssab el velocity so lzm fel update ta3 physics component nseto center ta3 our collider bel position pcq el collider ndirouh fel physic compoentn bach nakhadmo bih
	int type;
	vec3 center=vec3(0,0,0);
};


#endif // !COLLIDER_H
 
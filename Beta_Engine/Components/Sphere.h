#ifndef SPHERE_CLASS_H
#define SPHERE_CLASS_H

#include "../Math.h"
#include "../Renderer/VBO.h"
class sphere
{
public:

	vector<Vertex> vertices;
	vector<GLuint> indices;
	float radius;
	int rings;
	int sectors;

	sphere(float radius, int rings, int sectors);

	void createSphere();

private:
	void push_indices(int r, int s);

};

#endif#pragma once
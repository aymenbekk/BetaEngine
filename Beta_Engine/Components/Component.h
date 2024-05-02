#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Renderer/Shader.h"
#include "../Scene/Camera.h"

class Component {

public:
	Component();

	virtual void update()=0;
	virtual void Render(Shader* shader, Camera& camera) {};


};


#endif // !COMPONENT_H

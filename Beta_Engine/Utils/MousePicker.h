#ifndef MOUSE_PICKER_H
#define MOUSE_PICKER_H

#include "../Core/Window.h"
#include "../Scene/Camera.h"

class MousePicker {
public:
	MousePicker()  {
	
		currentRay = { 1.0f,1.0f,1.0f };
	};

	glm::vec3 getCurrentRay() { return currentRay; };


	void update(Camera* camera);

	glm::vec3 getPointOnRay(glm::vec3 ray, float distance, Camera* camera);

private:

	glm::vec3 currentRay ;
	
};

#endif

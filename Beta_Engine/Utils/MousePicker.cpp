#include "MousePicker.h"
#include "../Core/Window.h"
#include <chrono>
#include <thread>




void MousePicker::update(Camera* camera) {


	double mousePosX, mousePosY;
	glfwGetCursorPos(glfwGetCurrentContext(), &mousePosX, &mousePosY);
	//std::cout << "Camera Pos " << camera.Position.x << "/" << camera.Position.y << "/" << camera.Position.z << "/" << endl;
	int width, height;
	glfwGetWindowSize(glfwGetCurrentContext(), &width, &height);
	glm::vec3 unproject = glm::unProject(glm::vec3(mousePosX, height - mousePosY, 0.0f), camera->view, camera->projection, glm::vec4(0, 0, width, height));
	glm::vec3 unproj_dir_vec = unproject - camera->Position;
	currentRay = glm::normalize(unproj_dir_vec);

	/*std::cout << "CURRENT RAY : " << currentRay.x << "/" << currentRay.y << "/" << currentRay.z << endl;*/

}


glm::vec3 MousePicker::getPointOnRay(glm::vec3 ray, float distance,Camera* camera) {
    glm::vec3 camPos = camera->Position; 
    glm::vec3 start = { camPos.x, camPos.y, camPos.z };
    glm::vec3 scaledRay = { ray.x * distance, ray.y * distance, ray.z * distance };

  
        
        std::cout << "point on ray : x :" << start.x + scaledRay.x << "y : " << start.y + scaledRay.y << " z : " << start.z + scaledRay.z << endl;

  
       
    return { start.x + scaledRay.x, start.y + scaledRay.y, start.z + scaledRay.z };
}
//


//isTestPointInsideBlock



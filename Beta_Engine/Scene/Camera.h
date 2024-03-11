#ifndef CAMERA_H
#define CAMERA_H

#include "../Renderer/Shader.h"
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>


using namespace glm;

class Camera {


public:
	vec3 Position;
	vec3 TargetPoint = vec3(0.0f, 1.0f, 0.0f);
	vec3 Up = vec3(0.0f, 1.0f, 0.0f);
	mat4 cameraMatrix = mat4(1.0f);
	/*vec3 Right;*/

	bool firstClick = true;


	int width;
	int height;



	float Yaw = -90.0f;
	float Pitch = 0.0f;
	float lastX = 800.0f;
	float lastY = 800.0f;
	float speed;
	float sensitivity = 0.1f;

	float deltaTime = 0.0f;	// Time between current frame and last frame
	float lastFrame = 0.0f; // Time of last frame


	Camera(vec3& position, int width, int height);




	void Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform);

	void Inputs(GLFWwindow* window);

	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
	void updateCameraVectors();
};

#endif // ! CEMRA_H

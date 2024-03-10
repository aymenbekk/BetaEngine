
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <iostream>
#include <string>
#include"Camera.h"

Camera::Camera(vec3& position, int width, int height) : Position(position),width(width),height(height) {

}

void Camera::Matrix(float FOVdeg, float nearPlane, float farPlane, Shader& shader, const char* uniform)
{

	mat4 view = mat4(1.0f);
	mat4 projection = glm::mat4(1.0f);


	view = lookAt(Position, TargetPoint, Up);
	// this is the standard its doesnt change)
	projection = perspective(radians(FOVdeg), static_cast<float>(width) / static_cast<float>(height), nearPlane, farPlane);

	// Exports the camera matrix to the Vertex Shader
	GLuint camMatrixUnif = glGetUniformLocation(shader.ID, uniform);
	glUniformMatrix4fv(camMatrixUnif, 1, GL_FALSE, glm::value_ptr(projection * view));
}



void Camera::Inputs(GLFWwindow* window)
{
	float currentFrame = glfwGetTime();
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	speed = deltaTime * 2.5f;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position.z -= speed;
		TargetPoint.z -= speed;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position.x -= speed;
		TargetPoint.x -= speed;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position.z += speed;
		TargetPoint.z += speed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position.x += speed;
		TargetPoint.x += speed;
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		Position.y += speed;
		TargetPoint.y += speed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		Position.y -= speed;
		TargetPoint.y -= speed;
	}


}


void Camera::ProcessMouseMovement(float xpos, float ypos, GLboolean constrainPitch) {
	// Hides mouse cursor



	if (firstClick)
	{
		lastX = xpos;
		lastY = ypos;
		firstClick = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	Yaw += xoffset;
	Pitch += yoffset;

	if (Pitch > 89.0f)
		Pitch = 89.0f;
	if (Pitch < -89.0f)
		Pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(radians(Yaw)) * cos(radians(Pitch));
	direction.y = sin(radians(Pitch));
	direction.z = sin(radians(Yaw)) * cos(radians(Pitch));
	TargetPoint = normalize(direction);
}
#ifndef WINDOW_H
#define WINDOW_H


#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../Scene/Camera.h"


class Window {

public:

	

	Window(int width, int Height,  char* title,Camera* camera);

	GLFWwindow* get_GLFW_Window() { return window; };
	void set_GLFW_Window(GLFWwindow* windo) { window = windo; };

	int create();

	void swapBuffers();

	void processInput();


	void setFrameBufferSizeCallBack(Camera& camera);

	void setCursorPosCallback();

	bool shoudlClose();

	void checkEvents();

	void Destroy();
	GLFWwindow* window;

	Camera* camera;
private:
	int width;
	int height;
	char* title;

	

	void framBufferSizeCallback(GLFWwindow* window, int width, int height);
	void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
	




};



#endif 






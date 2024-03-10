#ifndef WINDOW_H
#define WINDOW_H


#include <GLFW/glfw3.h>
#include <glad/glad.h>


class Window {

public:

	

	Window(int width, int Height, const char* title);

	GLFWwindow* get_GLFW_Window(){return window}

	int create();

	void swapBuffers(GLfloat red,GLfloat green,GLfloat blue,GLfloat alpha);

	void processInput();


	void setFrameBufferSizeCallBack(Camera& camera);

	void setCursorPosCallback();

	bool shoudlClose();

	void checkEvents();

	void Destroy();



private:
	int width;
	int height;
	char* title;
	GLFWwindow* window;
	Camera camera;

	void framBufferSizeCallback(GLFWwindow* window, int width, int height);
	void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);
	




};



#endif 






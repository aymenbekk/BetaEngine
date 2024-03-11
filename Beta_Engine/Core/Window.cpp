#include "Window.h"


Window::Window(int width, int Height,  char* title,Camera& camera) : width(width),height(Height),title(title),camera(camera) {


}


int Window::create() {
	cout << "Here Creat" << endl;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//GLFWwindow* window = get_GLFW_Window();
	set_GLFW_Window (glfwCreateWindow(width, height, title, NULL, NULL));
	if (get_GLFW_Window() == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(get_GLFW_Window());
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -2;
	}
	glViewport(0, 0, width, height);

	return 1;
	
}

void Window::swapBuffers(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glClearColor(red, green, blue, alpha);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}

void Window::processInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}


}

//void Window::setFrameBufferSizeCallBack(Camera& camera) {
//
//	this->camera = camera;
//	glfwSetFramebufferSizeCallback(window,framBufferSizeCallback)
//	
//}
//
//void Window::framBufferSizeCallback(GLFWwindow* window, int width, int height) {
//	glViewport(0, 0, width, height);
//	camera.width = width;
//	camera.height = height;
//
//}

//void Window::setCursorPosCallback() {
//
//	glfwSetCursorPosCallback(window, mouse_callback);
//}


bool Window::shoudlClose() {
	return glfwWindowShouldClose(window);
}

void Window::checkEvents() {
	glfwPollEvents();
}

void Window::Destroy() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);
	camera.ProcessMouseMovement(xpos, ypos, true);
}


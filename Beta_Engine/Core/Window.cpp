#include "Window.h"


Window::Window(int width, int Height,  char* title,Camera* camera) : width(width),height(Height),title(title),camera(camera) {

	
}
//void Window::framBufferSizeCallback(GLFWwindow* window, int width, int height) {
//	//std::cout << "width camera" << camera << endl;
//	glViewport(0, 0, width, height);
//	
//    std::cout << cam->width << endl;
//	cam->width = width;
//	cam->height = height;
//    std::cout << cam->width << endl;
//
//}

int Window::create() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//GLFWwindow* window = get_GLFW_Window();
	set_GLFW_Window(glfwCreateWindow(width, height, title, NULL, NULL));
	if (get_GLFW_Window() == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(get_GLFW_Window());
	gladLoadGL();
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -2;
	}
	glViewport(0, 0, width, height);

	this->camera = camera;
	std::cout << camera->width << endl;
	glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
			
		});

	


	return 1;
	
}

void Window::swapBuffers() {
	
	glfwSwapBuffers(window);
}

void Window::processInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}


}




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
	camera->ProcessMouseMovement(xpos, ypos, true);
}


#include "Window.h"

Window::Window(UINT32 width, UINT32 height)
{
	this->height = height;
	this->width = width;
}

int Window::init()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Opened", nullptr, nullptr);
	if (window == nullptr) 
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return -1;
	}  
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}
	return 0;
}

void Window::run()
{
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	do {
		glfwSwapBuffers(window);
		glfwPollEvents();
		
	} // Check if the window was closed
	while (!glfwWindowShouldClose(window));
}

void Window::close()
{
}

Window::~Window()
{
}
#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <glew.h>
#include <glfw3.h>

typedef unsigned __int32 UINT32;

class Window
{
private:
	GLFWwindow * window;
	UINT32 height;
	UINT32 width;

public:
	Window(UINT32 width, UINT32 height);
	int init();
	void run();
	void close();
	~Window(); 
};
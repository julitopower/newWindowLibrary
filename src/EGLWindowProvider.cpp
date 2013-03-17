#include "../include/WindowProvider.hpp"
#include "../include/MyGLWindow.h"
#include <iostream>

void EGLWindowProvider::createWindow() {
	EGLconfig *config = new EGLconfig();
	config->setRGBA(8,8,8,0);
	// set the depth buffer
	config->setDepth(24);
	// now create a new window using the default config
	window = new MyGLWindow(config);
}

void EGLWindowProvider::swapBuffers() {
	window->swapBuffers();
}

EGLWindowProvider::~EGLWindowProvider() {
	delete window;
}

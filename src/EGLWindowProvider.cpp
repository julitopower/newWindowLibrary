/*
 * Simple Raspberry Pi OpenGl-ES window tests application 
 * Copyright (C) 2013-2014, Julio Delgado <julio.delgadomangas@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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

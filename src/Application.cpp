#include <iostream>
#include "../include/MyGLWindow.h"
#include "../include/TextureLoader.hpp"
#include "bcm_host.h"
#include <GLES/gl.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <math.h>
#include <curses.h>
#include "bcm_host.h"
#include "../include/WindowProvider.hpp"
#include "../include/Game.hpp"
#include "GameContextDemo.hpp"

#ifndef TEST
int main()
{
	bcm_host_init();
 	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	Game game;
	game.setWindowProvider(new EGLWindowProvider());
	game.setGameContext(new GameContextDemo());

	std::cout << "Finish setting up Game loop, starting ..." << std::endl;
	game.init();
	endwin();
	bcm_host_deinit();
}
#endif

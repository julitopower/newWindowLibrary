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

#include "../include/Game.hpp"

Game::Game() : window(0), context(0), running(false) {}

Game::Game(WindowProvider *  window, GameContext * context) : window(window), context(context), running(false) {
	context->setGame(this);
};

Game::~Game() {
	delete window;
	delete context;
}

void Game::setWindowProvider(WindowProvider * window) {
	this->window = window;
}

void Game::setGameContext(GameContext * context) {
	this->context = context;
	context->setGame(this);
}

void Game::init() {
	running = true;
	window->createWindow();
	context->init();
	while(running) {
		context->loop();
		window->swapBuffers();
	}
}

void Game::stop() {
	running = false;
}

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

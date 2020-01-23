#include "game.hpp"

Game::Game(const char * title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL Initialized!\n";

		_window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

		if(_window) {
			std::cout << "Window is created!\n";
		}

		_buffer = SDL_CreateRenderer(_window, -1, 0);
		if(_buffer)
		{
			std::cout << "Render is a success!\n";
		}
		_isRunning = true;
	} else {
		_isRunning = false;
	}

	_resManager = new ResourceManager();

	// TODO: delete me
	_resManager->loadTexture("House.png", _buffer);



}

Game::~Game() {

	delete _resManager;
	SDL_DestroyRenderer(_buffer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			_isRunning = false;
			break;
	}
}

void Game::update() {

}

void Game::render() {
	SDL_RenderClear(_buffer);

	// TODO: delete me
	SDL_Rect texture_rect;
	texture_rect.x = 0;  //the x coordinate
	texture_rect.y = 0; // the y coordinate
	texture_rect.w = 240; //the width of the texture
	texture_rect.h = 240; //the height of the texture


	SDL_RenderCopy(_buffer, _resManager->getTexture(0), NULL, &texture_rect);
	SDL_RenderPresent(_buffer);
}

bool Game::running() {
	return _isRunning;
}

void Game::run() {
	while (running()) {
		handleEvents();
		update();
		render();
	}
}

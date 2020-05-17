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
	_camera = new Camera();
	_tileMap = new TileMap(0, 0, 0, 0);

	// TODO: delete me
	_resManager->loadTexture("tiles/00.png", _buffer);
	_resManager->loadTexture("tiles/01.png", _buffer);
	_camera->setCameraPos(12, 7);
	_tileMap->loadFromFile("C:/dev/c++/Platformer-Project/res/maps/simp_map.dat");
}

Game::~Game() {

	delete _resManager;
	delete _camera;
	delete _tileMap;
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
	_tileMap->renderMap(_buffer, _resManager, _camera);
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

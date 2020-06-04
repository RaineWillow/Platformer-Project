#include "game.hpp"

Game::Game(const char * title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen == true) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL Initialized!\n";

		_window = SDL_CreateWindow(title, xPos, yPos, width, height, flags | SDL_WINDOW_RESIZABLE);

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

	_cw = width;
	_ch = height;
	_ox = 0;
	_oy = 0;
	_w = width;
	_h = height;

	_resManager = new ResourceManager();
	_camera = new Camera();
	_tileMap = new TileMap(0, 0, 0, 0);
	_controller = new Controller();
	_renderScreen = SDL_CreateTexture(_buffer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

	_myB = new GButton<Game, void>(200, 200, 100, 25, *this, &Game::handleButton);


	// TODO: delete me
	_resManager->loadTexture("tiles/00.png", _buffer);
	_resManager->loadTexture("tiles/01.png", _buffer);
	_resManager->loadTexture("buttons/button_up.png", _buffer);
	_camera->setCameraPos(12, 7);
	_tileMap->loadFromFile("C:/dev/c++/Platformer-Project/res/maps/simp_map.dat");

	_controller->keyAdd(SDLK_a);
	_controller->keyAdd(SDLK_UP);
	_controller->keyAdd(SDLK_s);
	_controller->mbAdd(SDL_BUTTON_LEFT);
}

Game::~Game() {

	delete _resManager;
	delete _camera;
	delete _tileMap;
	delete _controller;
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
		case SDL_WINDOWEVENT:
			handleWindowEvents(&event);
			break;
		case SDL_KEYDOWN:
			_controller->keyDown(event.key.keysym.sym);
			break;
		case SDL_KEYUP:
			_controller->keyUp(event.key.keysym.sym);
			break;
		case SDL_MOUSEMOTION:
			_controller->mouseMotion(event.motion.x, event.motion.y);
			break;
		case SDL_MOUSEBUTTONDOWN:
			_controller->mbDown(event.button.button, event.button.x, event.button.y);
			break;
		case SDL_MOUSEBUTTONUP:
			_controller->mbUp(event.button.button, event.button.x, event.button.y);
			break;
		case SDL_MOUSEWHEEL:
			break;
	}
}

void Game::update() {
	if (_controller->getKeyClicked(SDLK_a)) {
		std::cout << "A was clicked\n";
	}
	if (_controller->getKeyClicked(SDLK_UP)) {
		std::cout << "Up was clicked\n";
	}
	bool clickCheck = _controller->getMbClicked(SDL_BUTTON_LEFT);
	if (clickCheck) {
		std::cout << "left mb clicked. X: " << _controller->getMx() << " Y: " << _controller->getMy() << "\n";
	}
	if (_controller->getKeyClicked(SDLK_s)) {
		std::cout << "Mouse {X: " << _controller->getMx() << ", Y: " << _controller->getMy() << "}\n";
	}

	_myB->update(_controller->getMx(), _controller->getMy(), clickCheck);
}

void Game::render() {
	SDL_Rect renderRect;
	renderRect.w = _cw;
	renderRect.h = _ch;
	renderRect.x = _ox;
	renderRect.y = _oy;

	SDL_RenderClear(_buffer);
	SDL_SetRenderTarget(_buffer, _renderScreen);

	//render all objects here--------------------------------------------------
	_tileMap->renderMap(_buffer, _resManager, _camera);
	_myB->render(_buffer, _resManager->getTexture(2));
	//-------------------------------------------------------------------------

	SDL_SetRenderTarget(_buffer, NULL);
	SDL_RenderCopy(_buffer, _renderScreen, NULL, &renderRect);

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

void Game::handleButton(Widget<Game, void> * instance) {
	std::cout << "Button clicked!\n";
}

void Game::handleWindowEvents(SDL_Event * event) {
	if (event->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
		_cw = event->window.data1;
		_ch = event->window.data2;
		_ox = 0;
		_oy = 0;
		if (_cw-_w > _ch-_h) {
			_ox = (_cw-_w) - (_ch - _h);
			_cw -= _ox;
			_ox /= 2;
		} else if (_cw-_w < _ch-_h) {
			_oy = (_ch - _h) - (_cw-_w);
			_ch -= _oy;
			_oy /= 2;
		} else {
			_ox = 0;
			_oy = 0;
		}
	}
}

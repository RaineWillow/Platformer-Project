#ifndef Game_hpp
#define Game_hpp
#include "SDL2/SDL.h"
#include "core/resource_manager.hpp"
#include <iostream>
#include <string>

class Game {
public:
	Game(const char * title, int xPos, int yPos, int width, int height, bool fullscreen);
	~Game();

	void handleEvents();
	void update();
	void render();

	bool running();

	void run();

private:

	bool _isRunning;
	SDL_Window * _window;
	SDL_Renderer * _buffer;
	ResourceManager * _resManager;

};
#endif

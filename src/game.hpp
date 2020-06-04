#ifndef Game_hpp
#define Game_hpp
#include "SDL2/SDL.h"
#include "core/resource_manager.hpp"
#include "core/camera.hpp"
#include "map/tilemap.hpp"
#include "utils/controller.hpp"
#include "gui/widget.hpp"
#include "gui/g_button.hpp"
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


	void handleButton(Widget<Game, void> * instance);

private:

	int _cw;
	int _ch;

	int _ox;
	int _oy;

	int _w;
	int _h;

	bool _isRunning;
	SDL_Window * _window;
	SDL_Renderer * _buffer;
	ResourceManager * _resManager;
	Camera * _camera;
	TileMap * _tileMap;
	Controller * _controller;
	SDL_Texture * _renderScreen;

	GButton<Game, void> * _myB;

	void handleWindowEvents(SDL_Event * event);

};
#endif

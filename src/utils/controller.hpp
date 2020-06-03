#ifndef Controller_hpp
#define Controller_hpp
#include "SDL2/SDL.h"
#include <iostream>
#include <map>

struct ButtonData{
	bool down;
	bool clicked;
};

class Controller {
public:
	//keyboard functions
	void keyAdd(SDL_Keycode qKey);
	void keyDown(SDL_Keycode qKey);
	void keyUp(SDL_Keycode qKey);
	bool getKey(SDL_Keycode qKey);
	bool getKeyClicked(SDL_Keycode qKey);

	//mouse functions
	void mbAdd(Uint8 mb);
	void mbDown(Uint8 mb, Sint32 mx, Sint32 my);
	void mbUp(Uint8 mb, Sint32 mx, Sint32 my);
	bool getMb(Uint8 mb);
	bool getMbClicked(Uint8 mb);

	//void mouseMotion();

	Sint32 getMx();
	Sint32 getMy();
private:
	std::map<SDL_Keycode,ButtonData> _keyList;
	std::map<Uint8,ButtonData> _mbList;

	Sint32 _mx;
	Sint32 _my;

};


#endif

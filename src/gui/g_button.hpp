#ifndef G_Button_hpp
#define G_Button_hpp
#include "SDL2/SDL.h"
#include "widget.hpp"

template <typename ClassType, typename Result>
class GButton : public Widget<ClassType, Result>
{
	typedef Result (ClassType::*FunctionType)(Widget<ClassType, Result>*);
public:
	GButton(int x, int y, int width, int height, ClassType& object, FunctionType onClick) {
		_x = x;
		_y = y;
		_width = width;
		_height = height;

		this->registerEvent("onClick", object, onClick);
	}

	void update(int mx, int my, bool clicked) {
		if (((mx >= _x) && (mx <= _x+_width)) && ((my >= _y) && (my <= _y+_height))) {
			if (clicked == true) {
				this->callEvent("onClick");
			}
		}
	}

	void render(SDL_Renderer * renderer, SDL_Texture * texture) {
		SDL_Rect buttonRect;
		buttonRect.w = _width;
		buttonRect.h = _height;
		buttonRect.x = _x;
		buttonRect.y = _y;
		SDL_RenderCopy(renderer, texture, NULL, &buttonRect);
	}

private:

	int _x;
	int _y;
	int _width;
	int _height;
};


#endif

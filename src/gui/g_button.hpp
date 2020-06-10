#ifndef G_Button_hpp
#define G_Button_hpp
#include "SDL2/SDL.h"
#include "widget_base.hpp"
#include "widget.hpp"

struct GButtonData {
	int x;
	int y;
	int width;
	int height;
	SDL_Renderer * renderer;
	SDL_Texture * texture;
	bool clicked;
	int mx;
	int my;
};

template <typename ClassType, typename Result>
class GButton : public Widget<ClassType, Result>
{
	typedef Result (ClassType::*FunctionType)(WidgetBase*);
public:
	GButton(ClassType& object, FunctionType onClick)
	{
		this->registerEvent("onClick", object, onClick);
	}

	void update()
	{
		if (((*_mx >= _x) && (*_mx <= _x+_width)) && ((*_my >= _y) && (*_my <= _y+_height))) {
			if (*clicked == true) {
				this->callEvent("onClick");
			}
		}
	}

	void render()
	{
		SDL_Rect buttonRect;
		buttonRect.w = _width;
		buttonRect.h = _height;
		buttonRect.x = _x;
		buttonRect.y = _y;
		SDL_RenderCopy(renderer, texture, NULL, &buttonRect);
	}

private:

	GButtonData * _data

};


#endif

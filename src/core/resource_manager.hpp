#ifndef ResourceManager_hpp
#define ResourceManager_hpp
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <vector>
#include <iostream>
#include <string>

class ResourceManager {
public:
	ResourceManager();
	~ResourceManager();

	void loadTexture(std::string path, SDL_Renderer * renderer);

	SDL_Texture * getTexture(int id);

private:
	std::vector<SDL_Texture *> _imgLists;

	std::string _path;
};
#endif

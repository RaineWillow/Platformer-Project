#ifndef ResourceManager_hpp
#define ResourceManager_hpp
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../utils/split.hpp"

class ResourceManager {
public:
	ResourceManager(SDL_Renderer * renderer, std::string path);
	~ResourceManager();

	void loadTexture(int id, std::string path);

	SDL_Texture * getTexture(int id);

private:
	std::map<int, SDL_Texture *> _imgLists;
	SDL_Renderer * _renderer;
	std::string _path;
};
#endif

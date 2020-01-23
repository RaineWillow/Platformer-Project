#include "resource_manager.hpp"

ResourceManager::ResourceManager()
{
	// load support for the JPG and PNG image formats
	int imgFlags=IMG_INIT_JPG|IMG_INIT_PNG;
	int initted=IMG_Init(imgFlags);
	if((initted&imgFlags) != imgFlags) {
		printf("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
		// handle error
	} else {
		std::cout << "Jpg and png support init success!\n";
	}

	_path = "res/";
}

ResourceManager::~ResourceManager()
{
	for (SDL_Texture * stuff : _imgLists)
	{
		SDL_DestroyTexture(stuff);
	}
	_imgLists.clear();
}

void ResourceManager::loadTexture(std::string path, SDL_Renderer * renderer)
{
	std::string myPath = _path + path;
	SDL_Surface* texLoader = IMG_Load(myPath.c_str());

	if (texLoader == NULL)
	{
		std::cout << "Error!\n";
	}
	
	_imgLists.push_back(SDL_CreateTextureFromSurface(renderer, texLoader));
	SDL_FreeSurface(texLoader);
	return;
}

SDL_Texture * ResourceManager::getTexture(int id)
{
	return _imgLists[id];
}

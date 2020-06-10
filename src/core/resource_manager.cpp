#include "resource_manager.hpp"

ResourceManager::ResourceManager(SDL_Renderer * renderer, std::string path)
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

	_path = path;

	_renderer = renderer;

	std::ifstream input_stream;
	input_stream.open(_path + "res_data.dat");

	if (input_stream.fail()) {
		std::cout << "failed to read\n";
		return;
	}
	std::string fLine;
	std::vector<std::string> lines;
	while (getline(input_stream, fLine)) {
		std::cout << fLine << "\n";
		lines.push_back(fLine);
	}
	input_stream.close();

	if (lines[0] == "imgs:") {

		for (size_t i = 1; i < lines.size(); i++) {
			if (lines[i] == "-") {
				break;
			}
			Split myData(lines[i], " ");
			loadTexture(std::stoi(myData[0]), myData[1]);
		}
	}

}

ResourceManager::~ResourceManager()
{
	for (auto const& x : _imgLists)
	{
		SDL_DestroyTexture(x.second);
	}
	_imgLists.clear();
}

void ResourceManager::loadTexture(int id, std::string path)
{
	std::string myPath = _path + path;
	SDL_Surface* texLoader = IMG_Load(myPath.c_str());

	if (texLoader == NULL)
	{
		std::cout << "Error!\n";
	}

	_imgLists.insert({id, SDL_CreateTextureFromSurface(_renderer, texLoader)});
	SDL_FreeSurface(texLoader);
	return;
}

SDL_Texture * ResourceManager::getTexture(int id)
{
	return _imgLists[id];
}

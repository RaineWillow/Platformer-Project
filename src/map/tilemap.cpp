#include "tilemap.hpp"

TileMap::TileMap(int mapWidth, int mapHeight, int tileWidth, int tileHeight) {
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
}

TileMap::~TileMap() {

}

void TileMap::loadFromFile(std::string path) {
	std::ifstream input_stream;
	input_stream.open(path.c_str());
	if (input_stream.fail()) {
		std::cout << "failed to read\n";
		return;
	}
	input_stream >> _mapWidth >> _mapHeight >> _tileWidth >> _tileHeight;
	for (int x = 0; x < _mapWidth; x++) {
		for (int y = 0; y < _mapHeight; y++) {
			Tile newTile;
			int nextId;
			input_stream >> nextId;
			newTile.setId(nextId);
			_tMap.push_back(newTile);
		}
	}
	input_stream.close();
}

void TileMap::saveToFile(std::string path) {
	std::ofstream output_stream;
	output_stream.open(path);
	output_stream << _mapWidth << ' ' << _mapHeight << ' ' << _tileWidth << _tileHeight;

	for (int x = 0; x < _mapWidth; x++) {
		for (int y = 0; y < _mapHeight; y++) {
			output_stream << _tMap[x * _mapWidth + y].getId();
			if ((x == _mapWidth-1) && (y == _mapHeight - 1)) {
				output_stream << '\n';
			} else {
				output_stream << ' ';
			}
		}
	}
	output_stream.close();
}

void TileMap::renderMap(SDL_Renderer * renderer, ResourceManager * resman, Camera * currCam) {
	SDL_Rect tileRect;
	tileRect.w = _tileWidth;
	tileRect.h = _tileHeight;

	for (int x = 0; x < _mapWidth; x++) {
		for (int y = 0; y < _mapHeight; y++) {
			tileRect.x = x * _tileWidth;
			tileRect.y = y * _tileHeight;
			//change line later to get id of resource from animation manager
			SDL_RenderCopy(renderer, resman->getTexture(_tMap[x * _mapWidth + y].getId()), NULL, &tileRect);
		}
	}
}

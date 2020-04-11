#include "tilemap.hpp"

TileMap::TileMap(int mapWidth, int mapHeight, int tileWidth, int tileHeight) {
	_mapWidth = mapWidth;
	_mapHeight = mapHeight;
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
}

TileMap::~TileMap() {

}

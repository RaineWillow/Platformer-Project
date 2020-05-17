#ifndef TileMap_hpp
#define TileMap_hpp
#include "SDL2/SDL.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "tile.hpp"
#include "../core/resource_manager.hpp"
#include "../core/camera.hpp"

class TileMap {
public:
	TileMap(int mapWidth, int mapHeight, int tileWidth, int tileHeight);
	~TileMap();

	//void setMapWidth(int width);
	//void setMapHeight(int height);
	//void setTileWidth(int width);
	//void setTileHeight(int height);

	//int getMapWidth();
	//int getMapHeight();
	//int getTileHeight();
	//int setTileHeight();

	//Tile getTile(int tx, int ty);
	//void setTile(int tx, int ty, Tile newTile);

	//std::vector<Tile> getTileVec();

	//void loadFromMap(TileMap * newMap);
	void loadFromFile(std::string path);

	void saveToFile(std::string path);

	//void updateMap();
	//void updateOnscreenMap();
	//void updateRangeMap(int x1, int x2, int y1, int y2);

	void renderMap(SDL_Renderer * renderer, ResourceManager * resman, Camera * currCam);

private:
	int _mapWidth;
	int _mapHeight;
	int _tileWidth;
	int _tileHeight;
	std::vector<Tile> _tMap;
};

#endif

#include "tile.hpp"

void Tile::setId(int id) {
	_id = id;
}

void Tile::setSolid(bool solid) {
	_solid = solid;
}

int Tile::getId() {
	return _id;
}

int Tile::getSolid() {
	return _solid;
}

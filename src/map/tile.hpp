#ifndef Tile_hpp
#define Tile_hpp
#include <string>
#include <map>

struct TileData {
	enum {tNum, tStr} type;
	union {
		int * dNum;
		std::string * dStr;
	};
};

class Tile {
public:
	void setId(int id);
	void setSolid(bool solid);
	int getId();
	int getSolid();

	void setProperty(std::string name, TileData property);
	TileData getProperty(std::string name);
private:
	int _id;
	int _solid;
	std::map<std::string, TileData> _properties;
};

#endif

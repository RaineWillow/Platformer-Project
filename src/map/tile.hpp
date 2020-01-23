#ifndef Tile_hpp
#define Tile_hpp

class Tile {
public:
	void setId(int id);
	void setSolid(bool solid);
	int getId();
	int getSolid();
private:
	int _id;
	int _solid;
};

#endif

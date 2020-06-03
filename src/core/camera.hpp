#ifndef Camera_hpp
#define Camera_hpp

class Camera {
public:
	void setCameraPos(int x, int y);
	void setCameraZoom(double _cz);
	int camX();
	int camY();
	//int camZ();
private:
	int _cx = 0;
	int _cy = 0;
	//double _cz;
};

#endif

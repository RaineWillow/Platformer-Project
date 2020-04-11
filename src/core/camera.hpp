#ifndef Camera_hpp
#define Camera_hpp

class Camera {
public:
	void setCameraPos(int x, int y);
	int camX();
	int camY();
private:
	int _cx;
	int _cy;
};

#endif

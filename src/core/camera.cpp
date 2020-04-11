#include "camera.hpp"

void Camera::setCameraPos(int x, int y) {
	_cx = x;
	_cy = y;
}

int Camera::camX() {
	return _cx;
}

int Camera::camY() {
	return _cy;
}

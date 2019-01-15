#pragma once

#include "stdafx.h"
#include "image.h"



class CAMERA {
private:
	int _posX;
	int _posY;
	int _width;
	int _height;
	int	_left;
	int _top;
	image* _pCameraBuffer;
public:
	CAMERA();
	~CAMERA();
	
	void init(int posX, int posY, int width, int height);
	void update();

	void render(HDC hdc);

	image* getCameraBuffer() { return _pCameraBuffer; }
	HDC getMemDC() { return _pCameraBuffer->getMemDC(); }
};

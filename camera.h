#pragma once

#include "stdafx.h"
#include "image.h"

static image* _cameraBuffer = IMAGEMANAGER->addImage("magicCircle","magicCircle.bmp", MAPSIZEX, MAPSIZEY,true,RGB(255,0,255));


class CAMERA {
private:
	int _posX;
	int _posY;
	int _width;
	int _height;
	int	_left;
	int _top;

public:
	CAMERA();
	~CAMERA();
	
	void init(int posX, int posY, int width, int height);
	void update();

	void render(HDC hdc);

	image* getCameraBuffer() { return _cameraBuffer; }
	HDC getMemDC() { return _cameraBuffer->getMemDC(); }
};

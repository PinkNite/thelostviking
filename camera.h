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
	int _right;

public:
	CAMERA();
	~CAMERA();
	
	image* getCameraBuffer() { return _cameraBuffer; }
	HDC getMemDC() { return _cameraBuffer->getMemDC(); }
};

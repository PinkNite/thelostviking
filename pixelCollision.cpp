#include "stdafx.h"
#include "pixelCollision.h"

pixelCollision::pixelCollision()
{
}


pixelCollision::~pixelCollision()
{
}

HRESULT pixelCollision::init()
{
	_imgMap2Cbg = IMAGEMANAGER->addImage("map2Collision", "resource/map/map1-2_collision.bmp", 2048, 1630, true, RGB(255, 0, 255));
	
	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
}

void pixelCollision::render()
{
}

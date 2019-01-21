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
	_imgMap2Cbg = IMAGEMANAGER->addImage("map2Collision", "resource/map/map1-2_collision.bmp", 2048, 1630, false, RGB(255, 0, 255));
	
	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	/*printf("x : %f, y : %f, width : %d, height : %d\n", _pPlayer->getPosX(), _pPlayer->getPosY(), 
		_pPlayer->getWidth(), _pPlayer->getHeight());*/
	//x = _pPlayer->getPosX();
}

void pixelCollision::render(HDC hdc)
{
	_imgMap2Cbg->render(hdc);
}

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
	_imgMap2Cbg = IMAGEMANAGER->addImage("map2Collision", "resource/map/map1-2_collision4.bmp", 2048, 1630, false, RGB(255, 0, 255));
	_probeY = _pPlayer->getPosY() + (_pPlayer->getHeight() / 2);
	_isCollision = false;
	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	_probeY = _pPlayer->getPosY() + (_pPlayer->getHeight() / 2);

	for (int i = _probeY - 2; i <= _probeY; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			_pPlayer->getPosX() - _pPlayer->getWidth() / 2 + 12, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 255 && g == 0 && b == 255))
		{
			_pPlayer->setPosY(i - _pPlayer->getHeight() / 2 );
			_isCollision = true;
			break;
		}
		else
		{
			_isCollision = false;
		}
	}

	for (int i = _probeY - 10; i <= _probeY; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			_pPlayer->getPosX() + _pPlayer->getWidth() / 2 - 12, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 255 && g == 0 && b == 255))
		{
			_pPlayer->setPosY(i - _pPlayer->getHeight() / 2);
			_isCollision = true;
			break;
		}
		else
		{
			_isCollision = false;
		}
	}
	printf("Ãæµ¹ : %d\n", _isCollision);
}

void pixelCollision::render(HDC hdc)
{
}

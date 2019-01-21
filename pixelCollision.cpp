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
	_probeTopY = _pPlayer->getPosY() - (_pPlayer->getHeight() / 2);
	_probeBottomY = _pPlayer->getPosY() + (_pPlayer->getHeight() / 2);
	_probeLeftX = _pPlayer->getPosX() - (_pPlayer->getWidth() / 2);
	_probeRightX = _pPlayer->getPosX() + (_pPlayer->getWidth() / 2);
	_isCollisionLeft = false;
	_isCollisionRight = false;
	_isCollisionBottom = false;
	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	_probeTopY = _pPlayer->getPosY() - (_pPlayer->getHeight() / 2);
	_probeBottomY = _pPlayer->getPosY() + (_pPlayer->getHeight() / 2);
	_probeLeftX = _pPlayer->getPosX() - (_pPlayer->getWidth() / 2) + 6;
	_probeRightX = _pPlayer->getPosX() + (_pPlayer->getWidth() / 2) - 6;
	/*
	// 왼쪽 벽 충돌
	for (int i = _probeLeftX; i <= _probeLeftX + 10; ++i)
	{
		for (int j = _pPlayer->getPosY() - _pPlayer->getHeight() / 2;
			j <= _pPlayer->getPosY() + _pPlayer->getHeight() / 2; ++j)
		{
			//PlayerRect 왼쪽 위 범위
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				i, j);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				_pPlayer->setPosX(i + _pPlayer->getWidth() / 2);
				_isCollisionLeft = true;
				_onceCollisionLeft = true;
				break;
			}
			else
			{
				_isCollisionLeft = false;
			}
		}
		if (_onceCollisionLeft == true)
		{
			_onceCollisionLeft = false;
			break;
		}
	}

	/*
	for (int j = _pPlayer->getPosY() - _pPlayer->getHeight() / 2;
		j <= _pPlayer->getPosY() + _pPlayer->getHeight() / 2; ++j)
	{
		//PlayerRect 왼쪽 위 범위
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			_probeLeftX, j);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 255))
		{
			_pPlayer->setPosX(_probeLeftX + _pPlayer->getWidth() / 2);
			_isCollisionLeft = true;
			break;
		}
		else
		{
			_isCollisionLeft = false;
		}
	}
	
	//오른쪽 벽 충돌
	for (int i = _probeRightX; i >= _probeRightX - 10; --i)
	{
		for (int j = _pPlayer->getPosY() - _pPlayer->getHeight() / 2;
			j <= _pPlayer->getPosY() + _pPlayer->getHeight() / 2; ++j)
		{
			//PlayerRect 왼쪽 위 범위
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				i, j);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);

			if ((r == 0 && g == 255 && b == 255))
			{
				_pPlayer->setPosX(i - _pPlayer->getWidth() / 2);
				_isCollisionRight = true;
				_onceCollisionRight = true;
				break;
			}
			else
			{
				_isCollisionRight = false;
			}
		}
		if (_onceCollisionRight == true)
		{
			_onceCollisionRight = false;
			break;
		}
	}
	*/
	// 천장충돌
	for (int i = _probeTopY + _pPlayer->getWidth(); i >= _probeTopY; --i)
	{
		//PlayerRect 왼쪽 범위
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			_pPlayer->getPosX() - _pPlayer->getWidth() / 2 + 12, i);

		//PlayerRect 오른쪽 범위
		COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			_pPlayer->getPosX() + _pPlayer->getWidth() / 2 - 12, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		int r2 = GetRValue(color);
		int g2 = GetGValue(color);
		int b2 = GetBValue(color);

		if ((r == 255 && g == 255 && b == 0) || (r2 == 255 && g2 == 255 && b2 == 0))
		{
			_pPlayer->setPosY(i + _pPlayer->getHeight() / 2);
			_isCollisionTop = true;
			break;
		}
		else
		{
			_isCollisionTop = false;
		}
	}

	// 바닥충돌
	for (int i = _probeBottomY - 10; i <= _probeBottomY; ++i)
	{
		//PlayerRect 왼쪽 범위
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			_pPlayer->getPosX() - _pPlayer->getWidth() / 2 + 12, i);

		//PlayerRect 오른쪽 범위
		COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			_pPlayer->getPosX() + _pPlayer->getWidth() / 2 - 12, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		int r2 = GetRValue(color);
		int g2 = GetGValue(color);
		int b2 = GetBValue(color);

		if ((r == 255 && g == 0 && b == 255) || (r2 == 255 && g2 == 0 && b2 == 255))
		{
			_pPlayer->setPosY(i - _pPlayer->getHeight() / 2);
			_isCollisionBottom = true;
			break;
		}
		else
		{
			_isCollisionBottom = false;
		}
	}
	printf("왼쪽벽 충돌 : %d, 오른쪽 벽 충돌 : %d, 바닥 충돌 : %d\n", _isCollisionLeft,
		_isCollisionRight, _isCollisionBottom);
}

void pixelCollision::render(HDC hdc)
{
}

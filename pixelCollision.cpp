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
	ladderRect[0] = RectMake(593, 160, 16, 30);
	ladderRect[1] = RectMake(673, 160, 16, 30);
	ladderRect[2] = RectMake(1137, 160, 16, 30);
	ladderRect[3] = RectMake(1217, 160, 16, 30);
	ladderRect[4] = RectMake(1873, 448, 16, 30);
	ladderRect[5] = RectMake(1569, 800, 16, 30);
	ladderRect[6] = RectMake(1441, 800, 64, 30);
	ladderRect[7] = RectMake(193, 640, 32, 32);
	ladderRect[8] = RectMake(97, 640, 32, 32);
	ladderRect[9] = RectMake(545, 1088, 32, 32);
	ladderRect[10] = RectMake(81, 1408, 16, 30);
	ladderRect[11] = RectMake(161, 1408, 16, 30);

	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	playerRect = RectMakeCenter(_pPlayer->getPosX(), _pPlayer->getPosY(), _pPlayer->getWidth(), _pPlayer->getHeight());
	_probeTopY = _pPlayer->getPosY() - (_pPlayer->getHeight() / 2);
	_probeBottomY = _pPlayer->getPosY() + (_pPlayer->getHeight() / 2);
	_probeLeftX = _pPlayer->getPosX() - (_pPlayer->getWidth() / 2) + 6;
	_probeRightX = _pPlayer->getPosX() + (_pPlayer->getWidth() / 2) - 6;
	
	//애매한 렉트 처리
	for (int i = 0; i < 12; i++)
	{
		collisionRect(ladderRect[i], _pPlayer);
	}

	//
	for (int i = 0; i < _vDoor.size(); i++)
	{
		RECT tempRc;
		if (IntersectRect(&tempRc, &_vDoor[i]->getColiisionArea(), &playerRect))
		{
			_vDoor[i]->setIsoff(true);
		}
		else
		{
			_vDoor[i]->setIsoff(false);
		}
	}

	// 왼쪽 벽 충돌
	for (int i = _probeLeftX; i <= _probeLeftX + 10; ++i)
	{
		//PlayerRect 왼쪽 위 범위
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				i, _pPlayer->getPosY() - (_pPlayer->getHeight() / 2));
			COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				i, _pPlayer->getPosY());
			COLORREF color3 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				i, _pPlayer->getPosY() + (_pPlayer->getHeight() / 2));

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);
			int r2 = GetRValue(color2);
			int g2 = GetGValue(color2);
			int b2 = GetBValue(color2);
			int r3 = GetRValue(color3);
			int g3 = GetGValue(color3);
			int b3 = GetBValue(color3);

			if ((r == 0 && g == 255 && b == 255) || (r2 == 0 && g2 == 255 && b2 == 255) || (r3 == 0 && g3 == 255 && b3 == 255))
			{
				_pPlayer->setPosX(i + _pPlayer->getWidth() / 2);
				//_pPlayer->setPosX(_probeLeftX - 6);
				_isCollisionLeft = true;
				_onceCollisionLeft = true;
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
		//PlayerRect 왼쪽 위 범위
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			i, _pPlayer->getPosY() - (_pPlayer->getHeight() / 2));
		COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			i, _pPlayer->getPosY());
		COLORREF color3 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
			i, _pPlayer->getPosY() + (_pPlayer->getHeight() / 2));

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
		int r2 = GetRValue(color2);
		int g2 = GetGValue(color2);
		int b2 = GetBValue(color2);
		int r3 = GetRValue(color3);
		int g3 = GetGValue(color3);
		int b3 = GetBValue(color3);

		if ((r == 0 && g == 255 && b == 255) || (r2 == 0 && g2 == 255 && b2 == 255) || (r3 == 0 && g3 == 255 && b3 == 255))
		{
			_pPlayer->setPosX(i - _pPlayer->getWidth() / 2);
			//_pPlayer->setPosX(_probeRightX + 6);
			_isCollisionRight = true;
			_onceCollisionRight = true;
			break;
		}
		else
		{
			_isCollisionRight = false;
		}
	}
	
	// 천장충돌
	for (int i = _probeTopY + _pPlayer->getHeight()/2; i >= _probeTopY; --i)
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
	for (int i = 0; i < _vDoor.size(); i++)
	{
		_vDoor[i]->render(hdc);
	}
}

void pixelCollision::collisionRect(RECT rect, PLAYER * pPlayer)
{
	RECT tempRect;
	RECT playerRect = RectMakeCenter(pPlayer->getPosX(), pPlayer->getPosY(), pPlayer->getWidth(), pPlayer->getHeight());
	if (IntersectRect(&tempRect, &rect, &playerRect))
	{
		if (tempRect.left + (tempRect.right - tempRect.left) / 2 < pPlayer->getPosX())
		{
			pPlayer->setPosX(tempRect.right + pPlayer->getWidth()/2);
		}
		if (tempRect.left + (tempRect.right - tempRect.left) / 2 > pPlayer->getPosX())
		{
			pPlayer->setPosX(tempRect.left - pPlayer->getWidth() / 2);
		}
	}
}

void pixelCollision::doorInit()
{
	setDOOR* doorObtacle = new DOORS;
	doorObtacle->init("collisionDoorObc1", 449, 352, 32, 96, true, 3);
	_vDoor.push_back(doorObtacle);

	doorObtacle = new DOORS;
	doorObtacle->init("collisionDoorObc2", 865, 352, 32, 96, true, 3);
	_vDoor.push_back(doorObtacle);

	doorObtacle = new DOORS;
	doorObtacle->init("collisionDoorObc3", 193, 1312, 32, 96, true, 3);
	_vDoor.push_back(doorObtacle);

	doorObtacle = new DOORS;
	doorObtacle->init("collisionDoorObc4", 449, 1472, 32, 96, true, 3);
	_vDoor.push_back(doorObtacle);
}

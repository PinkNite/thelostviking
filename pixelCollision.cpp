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
	_imgMap2CbgCopy = IMAGEMANAGER->addImage("map2Collision2", "resource/map/map1-2_collision4.bmp", 2048, 1630, false, RGB(255, 0, 255));
	_imgElevatorC = IMAGEMANAGER->addImage("elevatorCollision", "resource/map/effect/elevatorCollision.bmp", 64, 64, false, RGB(255, 0, 255));

	for (int i = 0; i < 3; i++)
	{
		_probeTopY[i] = _pPlayer->getViking(i)->getPosY() - (_pPlayer->getViking(i)->getHeight() / 2);
		_probeBottomY[i] = _pPlayer->getViking(i)->getPosY() + (_pPlayer->getViking(i)->getHeight() / 2);
		_probeElavatorBottomY[i] = _pPlayer->getViking(i)->getPosY() + (_pPlayer->getViking(i)->getHeight() / 2);
		_probeLeftX[i] = _pPlayer->getViking(i)->getPosX() - (_pPlayer->getViking(i)->getWidth() / 2);
		_probeRightX[i] = _pPlayer->getViking(i)->getPosX() + (_pPlayer->getViking(i)->getWidth() / 2);
		_isCollisionLeft[i] = false;
		_isCollisionRight[i] = false;
		_isCollisionBottom[i] = false;
		_isCollisionElevatorBottom[i] = false;
	}
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
	
	//_rcElevatorC = RectMake(_pMap2->getRCElevator().left, _pMap2->getRCElevator().top + 31, (_pMap2->getRCElevator().right - _pMap2->getRCElevator().left), (_pMap2->getRCElevator().bottom - _pMap2->getRCElevator().top) / 2);
	return S_OK;
}

void pixelCollision::release()
{
}

void pixelCollision::update()
{
	_rcElevatorC = RectMake(_pMap2->getRCElevator().left, _pMap2->getRCElevator().top, (_pMap2->getRCElevator().right - _pMap2->getRCElevator().left), (_pMap2->getRCElevator().bottom - _pMap2->getRCElevator().top) / 2);
	
	for (int i = 0; i < 3; i++)
	{
		playerRect[i]			 = RectMakeCenter(_pPlayer->getViking(i)->getPosX(), _pPlayer->getViking(i)->getPosY(), _pPlayer->getViking(i)->getWidth(), _pPlayer->getViking(i)->getHeight());
		_probeTopY[i]			 = _pPlayer->getViking(i)->getPosY() - (_pPlayer->getViking(i)->getHeight() / 2);
		_probeBottomY[i]		 = _pPlayer->getViking(i)->getPosY() + (_pPlayer->getViking(i)->getHeight() / 2);
		_probeLeftX[i]			 = _pPlayer->getViking(i)->getPosX() - (_pPlayer->getViking(i)->getWidth() / 2) + 6;
		_probeRightX[i]			 = _pPlayer->getViking(i)->getPosX() + (_pPlayer->getViking(i)->getWidth() / 2) - 6;
		_probeElavatorBottomY[i] = _pPlayer->getViking(i)->getPosY() + (_pPlayer->getViking(i)->getHeight() / 2);
		/*
		_probeTopY[i]			 = _pPlayer->getPosY() - (_pPlayer->getHeight() / 2);
		_probeBottomY[i]		 = _pPlayer->getPosY() + (_pPlayer->getHeight() / 2);
		_probeLeftX[i]		 	 = _pPlayer->getPosX() - (_pPlayer->getWidth() / 2) + 6;
		_probeRightX[i]			 = _pPlayer->getPosX() + (_pPlayer->getWidth() / 2) - 6;
		_probeElavatorBottomY[i] = _pPlayer->getPosY() + (_pPlayer->getHeight() / 2);
		*/
	}

	//애매한 렉트 처리
	for (int i = 0; i < 12; i++)
	{
		collisionRect(ladderRect[i], _pPlayer);
	}
	
	// 왼쪽 벽 충돌
	for (int i = 0; i < 3; i++)
	{
		for (int j = _probeLeftX[i]; j <= _probeLeftX[i] + 10; ++j)
		{
			//PlayerRect 왼쪽 위 범위
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				j, _pPlayer->getViking(i)->getPosY() - (_pPlayer->getViking(i)->getHeight() / 2));
			COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				j, _pPlayer->getViking(i)->getPosY());
			COLORREF color3 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				j, _pPlayer->getViking(i)->getPosY() + (_pPlayer->getViking(i)->getHeight() / 2));

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
				_pPlayer->getViking(i)->setPosX(j + _pPlayer->getViking(i)->getWidth() / 2);
				//_pPlayer->setPosX(_probeLeftX - 6);
				_isCollisionLeft[i] = true;
				_onceCollisionLeft[i] = true;
				break;
			}
			else
			{
				_isCollisionLeft[i] = false;
			}
		}
	}

	//오른쪽 벽 충돌
	for (int i = 0; i < 3; i++)
	{
		for (int j = _probeRightX[i]; j >= _probeRightX[i] - 10; --j)
		{
			//PlayerRect 왼쪽 위 범위
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				j, _pPlayer->getViking(i)->getPosY() - (_pPlayer->getViking(i)->getHeight() / 2));
			COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				j, _pPlayer->getViking(i)->getPosY());
			COLORREF color3 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				j, _pPlayer->getViking(i)->getPosY() + (_pPlayer->getViking(i)->getHeight() / 2));

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
				_pPlayer->getViking(i)->setPosX(j - _pPlayer->getViking(i)->getWidth() / 2);
				//_pPlayer->setPosX(_probeRightX + 6);
				_isCollisionRight[i] = true;
				_onceCollisionRight[i] = true;
				break;
			}
			else
			{
				_isCollisionRight[i] = false;
			}
		}
	}
	// 천장충돌
	for (int i = 0; i < 3; i++)
	{
		for (int j = _probeTopY[i] + _pPlayer->getViking(i)->getHeight() / 2; j >= _probeTopY[i]; --j)
		{
			//PlayerRect 왼쪽 범위
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				_pPlayer->getViking(i)->getPosX() - _pPlayer->getViking(i)->getWidth() / 2 + 12, j);

			//PlayerRect 오른쪽 범위
			COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				_pPlayer->getViking(i)->getPosX() + _pPlayer->getViking(i)->getWidth() / 2 - 12, j);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);
			int r2 = GetRValue(color);
			int g2 = GetGValue(color);
			int b2 = GetBValue(color);

			if ((r == 255 && g == 255 && b == 0) || (r2 == 255 && g2 == 255 && b2 == 0))
			{
				_pPlayer->getViking(i)->setPosY(j + _pPlayer->getViking(i)->getHeight() / 2);
				_isCollisionTop[i] = true;
				break;
			}
			else
			{
				_isCollisionTop[i] = false;
			}
		}
	}
	// 바닥충돌
	for (int i = 0; i < 3; i++)
	{
		for (int j = _probeBottomY[i] - 10; j <= _probeBottomY[i]; ++j)
		{
			//PlayerRect 왼쪽 범위
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				_pPlayer->getViking(i)->getPosX() - _pPlayer->getViking(i)->getWidth() / 2 + 12, j);

			//PlayerRect 오른쪽 범위
			COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
				_pPlayer->getViking(i)->getPosX() + _pPlayer->getViking(i)->getWidth() / 2 - 12, j);

			int r = GetRValue(color);
			int g = GetGValue(color);
			int b = GetBValue(color);
			int r2 = GetRValue(color);
			int g2 = GetGValue(color);
			int b2 = GetBValue(color);

			if ((r == 255 && g == 0 && b == 255) || (r2 == 255 && g2 == 0 && b2 == 255))
			{
				_pPlayer->getViking(i)->setPosY(j - _pPlayer->getViking(i)->getHeight() / 2);
				_isCollisionBottom[i] = true;
				break;
			}
			else
			{
				_isCollisionBottom[i] = false;
			}
		}
	}
	
	// 엘베충돌
	for (int i = 0; i < 3; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &playerRect[i], &_rcElevatorC))
		{
			for (int j = _probeElavatorBottomY[i] - 10; j <= _probeElavatorBottomY[i]; ++j)
			{
				//PlayerRect 왼쪽 범위
				COLORREF color = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
					_pPlayer->getViking(i)->getPosX() - _pPlayer->getViking(i)->getWidth() / 2 + 12, j);

				//PlayerRect 오른쪽 범위
				COLORREF color2 = GetPixel(IMAGEMANAGER->findImage("map2Collision")->getMemDC(),
					_pPlayer->getViking(i)->getPosX() + _pPlayer->getViking(i)->getWidth() / 2 - 12, j);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);
				int r2 = GetRValue(color);
				int g2 = GetGValue(color);
				int b2 = GetBValue(color);

				if ((r == 255 && g == 0 && b == 255) || (r2 == 255 && g2 == 0 && b2 == 255))
				{
					_pPlayer->getViking(i)->setPosY(j - _pPlayer->getViking(i)->getHeight() / 2);
					_isCollisionElevatorBottom[i] = true;
					break;
				}
				else
				{
					_isCollisionElevatorBottom[i] = false;
				}
			}
		}
	}
	
	//printf("왼쪽벽 충돌 : %d, 오른쪽 벽 충돌 : %d, 바닥 충돌 : %d\n", _isCollisionLeft,
	//	_isCollisionRight, _isCollisionBottom);
	//printf("엘베바닥충돌 : %d\n", _isCollisionElevatorBottom);
	//printf("왼쪽 : %d, 위 : %d, 넓이 : %d, 높이 : %d\n", _pMap2->getRCElevator().left, _pMap2->getRCElevator().top + 32, (_pMap2->getRCElevator().right - _pMap2->getRCElevator().left), (_pMap2->getRCElevator().bottom - _pMap2->getRCElevator().top + 32) / 2);
	_imgMap2CbgCopy->render(IMAGEMANAGER->findImage("map2Collision")->getMemDC()); 
	_imgElevatorC->render(IMAGEMANAGER->findImage("map2Collision")->getMemDC(), _rcElevatorC.left, _rcElevatorC.top);
}

void pixelCollision::render(HDC hdc)
{
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//_imgMap2Cbg = IMAGEMANAGER->addImage("map2Collision", "resource/map/map1-2_collision4.bmp", 2048, 1630, false, RGB(255, 0, 255));
	
	//_imgElevatorC->render(IMAGEMANAGER->findImage("map2Collision")->getMemDC(), _rcElevatorC.left, _rcElevatorC.top);
	//Rectangle(getMemDC(), _rcElevatorC);
}

void pixelCollision::collisionRect(RECT rect, PLAYER * pPlayer)
{
	RECT tempRect;
	RECT playerRect = RectMakeCenter(pPlayer->getPosX(), pPlayer->getPosY(), pPlayer->getWidth(), pPlayer->getHeight());
	if (IntersectRect(&tempRect, &rect, &playerRect))
	{
		if (tempRect.left + (tempRect.right - tempRect.left) / 2 < pPlayer->getPosX())
		{
			pPlayer->setPosX(tempRect.right + pPlayer->getWidth() / 2);
		}
		if (tempRect.left + (tempRect.right - tempRect.left) / 2 > pPlayer->getPosX())
		{
			pPlayer->setPosX(tempRect.left - pPlayer->getWidth() / 2);
		}
	}
}
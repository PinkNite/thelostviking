#include "stdafx.h"
#include "player.h"
#include "eric.h"
#include "pixelCollision.h"
#include "baleog.h"

PLAYER::PLAYER()
{
}

PLAYER::~PLAYER()
{
}

void PLAYER::init()
{
	//바이킹들 초기화
	_pViking[static_cast<const int>(VIKINGNAME::ERIC)] = new ERIC();
	_pViking[static_cast<const int>(VIKINGNAME::ERIC)]->init(610, 570, 64, 64);

	_pViking[static_cast<const int>(VIKINGNAME::BALEOG)] = new BALEOG();
	_pViking[static_cast<const int>(VIKINGNAME::BALEOG)]->init(100, 100, 64, 64);




	//처음 시작 바이킹 설정
	_nCurrentViking = static_cast<int>(VIKINGNAME::ERIC);
}

void PLAYER::update()
{
	if (!_pPixelCollision->getCollisionbot())
	{
		if ( _pViking[_nCurrentViking]->getAction() != VIKING::ACTION::ON_LADDER &&  _pViking[_nCurrentViking]->getAction() != VIKING::ACTION::ON_LADDER_OVER)
		{
			_pViking[_nCurrentViking]->pressGravity();
			if (static_cast<VIKINGNAME>(_nCurrentViking) == VIKINGNAME::ERIC)
			{
				_pViking[_nCurrentViking]->setSkillAnimation();
			}
			else if (static_cast<VIKINGNAME>(_nCurrentViking) == VIKINGNAME::BALEOG) {
				_pViking[_nCurrentViking]->setSkillAnimation();

			}
		}

		_pViking[_nCurrentViking]->setIsOnGround(false);
		

	}
	else {
		_pViking[_nCurrentViking]->setIsOnGround(true);
		_pViking[_nCurrentViking]->falldownAnimation();
	}

	if (_pPixelCollision->getCollisionbot())
	{

	}

	_pViking[_nCurrentViking]->update();
}

void PLAYER::release()
{
	_pViking[_nCurrentViking]->release();
}

void PLAYER::render(HDC hdc)
{


	for (int i = 0; i < 2; i++)
	{
		_pViking[i]->render(hdc);

	}

	//for (int i = 0; i < 6; i++)
	//{
	//	Rectangle(hdc, _pMap2->getRCLadder(i).left, _pMap2->getRCLadder(i).top, _pMap2->getRCLadder(i).right, _pMap2->getRCLadder(i).bottom);

	//}

}

float PLAYER::getPosX()
{
	return _pViking[_nCurrentViking]->getPosX();
}

float PLAYER::getPosY()
{
	return _pViking[_nCurrentViking]->getPosY();
}

int PLAYER::getWidth()
{
	return _pViking[_nCurrentViking]->getWidth();
}

int PLAYER::getHeight()
{
	return _pViking[_nCurrentViking]->getHeight();
}

int PLAYER::getTop()
{
	return  _pViking[_nCurrentViking]->getTop();
}

int PLAYER::getLeft()
{
	return _pViking[_nCurrentViking]->getLeft();
}

void PLAYER::moveLeft()
{
	float	acceleration = 0.0f;
	if (_nCurrentViking == static_cast<int>(VIKINGNAME::ERIC))
	{
		acceleration = 500.0f * TIMEMANAGER->getElpasedTime();
	}
	else {
		acceleration = 0.0f;
	}
	_pViking[_nCurrentViking]->moveLeft(acceleration);
	setMovingAnimation(static_cast<int>(VIKING::DIRECTION::LEFT));

}

void PLAYER::moveRight()
{

	float	acceleration = 0.0f;
	if (_nCurrentViking == static_cast<int>(VIKINGNAME::ERIC))
	{
		acceleration = 500.0f * TIMEMANAGER->getElpasedTime();
	}
	else {
		acceleration = 0.0f;
	}
	_pViking[_nCurrentViking]->moveRight(acceleration);
	setMovingAnimation(static_cast<int>(VIKING::DIRECTION::RIGHT));

}

void PLAYER::moveUp()
{
	if (isCollisionLadder())
	{
		if (_rcTmpTop - (_pViking[_nCurrentViking]->getPosY()-32) < 63)
		{
			_pViking[_nCurrentViking]->moveUp(0.0f);
		}
	}
}

void PLAYER::moveDown()
{
	if (isCollisionLadder())
	{
		if (_rcTmpBottom != _pViking[_nCurrentViking]->getPosY() +32)
		{
			if (_pPixelCollision->getCollisionbot())
			{
				_pViking[_nCurrentViking]->moveDown(6.0f);
			}
			else {
				_pViking[_nCurrentViking]->moveDown(0.0f);

			}
		}

	}
}

void PLAYER::resetSpeed()
{
	_pViking[_nCurrentViking]->resetSpeed();
}


void PLAYER::useSkillOne()
{
	_pViking[_nCurrentViking]->skillOne();
}

void PLAYER::useSkillTwo()
{
	_pViking[_nCurrentViking]->skillTwo();
}

void PLAYER::setMovingAnimation(int direction)
{
	_pViking[_nCurrentViking]->setMovingAnimation(direction);
}

void PLAYER::setStopAnimation()
{
	_pViking[_nCurrentViking]->setStopAnimation();
}

void PLAYER::setLadderAnimation(int offset)
{

	if (isCollisionLadder())
	{

		if (_rcTmpHeight <= 32)
		{
			_pViking[_nCurrentViking]->setLadderAnimation(1, true, _rcTmpHeight);
		}
		else if (_rcTmpHeight > 32) {
			_pViking[_nCurrentViking]->setLadderAnimation(offset, false, _rcTmpHeight);
		}

	}
	
}

bool PLAYER::isCollisionLadder()
{
	RECT rcPlayer = RectMakeCenter(_pViking[_nCurrentViking]->getPosX(), _pViking[_nCurrentViking]->getPosY()+ 5,
		_pViking[_nCurrentViking]->getWidth(), _pViking[_nCurrentViking]->getHeight());
	_pMap2->getRCLadder(0);
	bool bIsCollisionLadder = false;
	int	 nLadder = 0;

	while (nLadder < 6 && !bIsCollisionLadder)
	{
		RECT rcTmp;
		if (IntersectRect(&rcTmp, &rcPlayer, &(_pMap2->getRCLadder(nLadder))))
		{
			if (rcTmp.right - rcTmp.left >= 32)
			{
				bIsCollisionLadder = true;
				_pViking[_nCurrentViking]->setPosX(_pMap2->getRCLadder(nLadder).left + (_pMap2->getRCLadder(nLadder).right - _pMap2->getRCLadder(nLadder).left) / 2);
				_rcTmpHeight = rcTmp.bottom - rcTmp.top;
				_rcTmpTop = rcTmp.top;
				_rcTmpBottom = rcTmp.bottom;
			}
			else {
				nLadder++;
			}
		}
		else
		{
			nLadder++;
		}
	}

	

	return bIsCollisionLadder;
}

void PLAYER::setPosX(float posX)
{
	_pViking[_nCurrentViking]->setPosX(posX);
}

void PLAYER::setPosY(float posY)
{
	_pViking[_nCurrentViking]->setPosY(posY);
}

void PLAYER::setWidth(int width)
{
	_pViking[_nCurrentViking]->setWidth(width);
}

void PLAYER::setHeight(int height)
{
	_pViking[_nCurrentViking]->setHeight(height);
}

void PLAYER::setTop()
{

}

void PLAYER::setLeft()
{
}

void PLAYER::nextViking()
{
	_nCurrentViking++;
	if (_nCurrentViking > 1)
	{
		_nCurrentViking = 0;
	}
}

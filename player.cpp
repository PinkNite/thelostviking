#include "stdafx.h"
#include "player.h"
#include "eric.h"
#include "pixelCollision.h"
#include "baleog.h"
#include "OLAF.h"
#include "EnemyManager.h"


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
	_pViking[static_cast<const int>(VIKINGNAME::ERIC)]->init(228, 100, 64, 64);

	_pViking[static_cast<const int>(VIKINGNAME::BALEOG)] = new BALEOG();
	_pViking[static_cast<const int>(VIKINGNAME::BALEOG)]->init(164, 100, 64, 64);

	_pViking[static_cast<const int>(VIKINGNAME::OLAF)] = new OLAF();
	_pViking[static_cast<const int>(VIKINGNAME::OLAF)]->init(100, 100, 64, 64);

	//처음 시작 바이킹 설정
	_nCurrentViking = static_cast<int>(VIKINGNAME::ERIC);
	_isAnnihilation = false;
}

void PLAYER::update()
{
	for (int i = 0; i < 3; i++)
	{
		if (_pViking[_nCurrentViking]->getIsDeath()) continue;
		if (!_pPixelCollision->getCollisionbot(i))// && !_pPixelCollision->getCollisionElevatorBottom(i))
		{
			if (_pViking[i]->getAction() != VIKING::ACTION::ON_LADDER &&  _pViking[i]->getAction() != VIKING::ACTION::ON_LADDER_OVER)
			{
				if (static_cast<VIKING::STATE>(_pViking[i]->getState()) != VIKING::STATE::DEATH_MOTION) {

					_pViking[i]->pressGravity();
					_pViking[i]->setSkillAnimation();
					
				}
			}

			_pViking[i]->setIsOnGround(false);


		}
		else {
			_pViking[i]->setIsOnGround(true);
			if (static_cast<VIKING::STATE>(_pViking[i]->getState()) != VIKING::STATE::DEATH_MOTION) {

				_pViking[i]->falldownAnimation();
			}
		}



	}


	if (_pPixelCollision->getCollisionleft(_nCurrentViking) || _pPixelCollision->getCollisionright(_nCurrentViking))
	{
		_pViking[_nCurrentViking]->setPushWallAni(true);
	}

	_pViking[_nCurrentViking]->update();


	if (_pViking[_nCurrentViking]->getIsDeath())
	{
		nextViking();
	}
	
}

void PLAYER::release()
{
	_pViking[_nCurrentViking]->release();
}

void PLAYER::render(HDC hdc)
{


	for (int i = 0; i < 3; i++)
	{
		if (_pViking[i]->getIsDeath()) continue;

		//if (static_cast<VIKING::STATE>(_pViking[i]->getState()) != VIKING::STATE::DEATH_MOTION)
		{
			_pViking[i]->render(hdc);
		}

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
	if (static_cast<VIKINGNAME>(_nCurrentViking) == VIKINGNAME::BALEOG && _pViking[_nCurrentViking]->getUseSkillOne()) return;
	if (_pViking[_nCurrentViking]->stunStop()) return;
	if (_pViking[_nCurrentViking]->getIsDeath()) return;


	float	acceleration = 0.0f;
	if (_nCurrentViking == static_cast<int>(VIKINGNAME::ERIC))
	{
		acceleration = 20.0f * TIMEMANAGER->getElpasedTime();
	}
	else {
		acceleration = 0.0f;
	}
	_pViking[_nCurrentViking]->moveLeft(acceleration);
	setMovingAnimation(static_cast<int>(VIKING::DIRECTION::LEFT));

}

void PLAYER::moveRight()
{
	if (static_cast<VIKINGNAME>(_nCurrentViking) == VIKINGNAME::BALEOG && _pViking[_nCurrentViking]->getUseSkillOne()) return;
	if (_pViking[_nCurrentViking]->stunStop()) return;
	if (_pViking[_nCurrentViking]->getIsDeath()) return;

	float	acceleration = 0.0f;
	if (_nCurrentViking == static_cast<int>(VIKINGNAME::ERIC))
	{
		acceleration = 20.0f * TIMEMANAGER->getElpasedTime();
	}
	else {
		acceleration = 0.0f;
	}
	_pViking[_nCurrentViking]->moveRight(acceleration);
	setMovingAnimation(static_cast<int>(VIKING::DIRECTION::RIGHT));

}

void PLAYER::moveUp()
{
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
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
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
	if (isCollisionLadder())
	{
		if (_rcTmpBottom != _pViking[_nCurrentViking]->getPosY() +32)
		{
			if (_pPixelCollision->getCollisionbot(_nCurrentViking))
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
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
	_pViking[_nCurrentViking]->resetSpeed();
}


void PLAYER::useSkillOne()
{
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
	_pViking[_nCurrentViking]->skillOne();
}

void PLAYER::useSkillTwo()
{
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
	_pViking[_nCurrentViking]->skillTwo();
}

void PLAYER::stopSkillOne()
{
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
	_pViking[_nCurrentViking]->skillOneEnd();
}

void PLAYER::setMovingAnimation(int direction)
{
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
	_pViking[_nCurrentViking]->setMovingAnimation(direction);
}

void PLAYER::setStopAnimation()
{
	if (_pViking[_nCurrentViking]->getIsDeath()) return;
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
	int nCount = 0;

	if (_nCurrentViking > 2)
	{
		_nCurrentViking = 0;
	}

	while (_pViking[_nCurrentViking]->getIsDeath() && nCount < 3)
	{
		_nCurrentViking++;
		if (_nCurrentViking > 2)
		{
			_nCurrentViking = 0;
		}
		nCount++;
	}
	
	if (nCount >= 3)
	{
		_isAnnihilation = true;
	}
}

void PLAYER::deathViking(VIKING::DEATH_MOTION death)
{
	_pViking[_nCurrentViking]->death(death);
	_pViking[_nCurrentViking]->setDeathMotion(_nCurrentViking);
}


void PLAYER::playerAttack()
{
	//에릭 박치기
	if (static_cast<VIKINGNAME>(_nCurrentViking) == VIKINGNAME::ERIC)
	{
		if (VIKING::ACTION::SKILL_ONE == static_cast<VIKING::ACTION>(_pViking[_nCurrentViking]->getBehavior()) && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_pViking[_nCurrentViking]->getState()))
		{

		}
	}
	//발로그 검 활
	else if (static_cast<VIKINGNAME>(_nCurrentViking) == VIKINGNAME::BALEOG)
	{

	}
}

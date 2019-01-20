#include "stdafx.h"
#include "player.h"
#include "eric.h"

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
	_pViking[static_cast<const int>(VIKINGNAME::ERIC)]->init(610, 610, 64, 64);


	//처음 시작 바이킹 설정
	_nCurrentViking = static_cast<int>(VIKINGNAME::ERIC);
}

void PLAYER::update()
{
	_pViking[_nCurrentViking]->update();
}

void PLAYER::release()
{
	_pViking[_nCurrentViking]->release();
}

void PLAYER::render(HDC hdc)
{
	_pViking[_nCurrentViking]->render(hdc);
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
}

void PLAYER::moveUp()
{
	_pViking[_nCurrentViking]->moveUp(0.0f);

}

void PLAYER::moveDown()
{
	_pViking[_nCurrentViking]->moveDown(0.0f);

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

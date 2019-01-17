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
	_pViking[static_cast<const int>(VIKING::ERIC)] = new ERIC();
	_pViking[static_cast<const int>(VIKING::ERIC)]->init(610, 610, 64, 64);



	//처음 시작 바이킹 설정
	_nCurrentViking = static_cast<int>(VIKING::ERIC);
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
	_pViking[_nCurrentViking]->moveLeft();
}

void PLAYER::moveRight()
{
	_pViking[_nCurrentViking]->moveRight();
}

void PLAYER::moveUp()
{
	_pViking[_nCurrentViking]->moveUp();

}

void PLAYER::moveDown()
{
	_pViking[_nCurrentViking]->moveDown();

}

void PLAYER::setMoveStart(bool isMoveStart)
{
	_pViking[_nCurrentViking]->setMoveStart(isMoveStart);
}

float PLAYER::getSpeedX()
{
	return _pViking[_nCurrentViking]->getSpeedX();
}

float PLAYER::getSpeedY()
{
	return _pViking[_nCurrentViking]->getSpeedY();
}


void PLAYER::useSkillOne()
{
	_pViking[_nCurrentViking]->skillOne();
}

void PLAYER::useSkillTwo()
{
	_pViking[_nCurrentViking]->skillTwo();
}

void PLAYER::setEricState(OBJECT::ERIC_STATE ericState)
{
	_pViking[static_cast<int>(PLAYER::VIKING::ERIC)]->setEricState(ericState);
}

OBJECT::ERIC_STATE PLAYER::getEricState()
{
	return _pViking[static_cast<int>(PLAYER::VIKING::ERIC)]->getEricState();
}

void PLAYER::setEricJumpPower(float power)
{
	_pViking[static_cast<int>(PLAYER::VIKING::ERIC)]->setJumpPower(power);

}

void PLAYER::setLadderAni(int nLadderAni)
{
	_pViking[_nCurrentViking]->setLadderAni(nLadderAni);
}

bool PLAYER::getJumping()
{
	return _pViking[_nCurrentViking]->getJump();
}

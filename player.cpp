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
	//����ŷ�� �ʱ�ȭ
	_pViking[static_cast<const int>(VIKING::ERIC)] = new ERIC();
	_pViking[static_cast<const int>(VIKING::ERIC)]->init(610, 610, 64, 64);



	//ó�� ���� ����ŷ ����
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

 int PLAYER::getPosX()
{
	return _pViking[_nCurrentViking]->getPosX();
}

 int PLAYER::getPosY()
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

 float PLAYER::getSpeed()
 {
	 return _pViking[_nCurrentViking]->getSpeed();
 }

 void PLAYER::useSkillOne()
 {
	 _pViking[_nCurrentViking]->skillOne();
 }

 void PLAYER::useSkillTwo()
 {
	 _pViking[_nCurrentViking]->skillTwo();
 }

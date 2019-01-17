#include "stdafx.h"
#include "object.h"

void OBJECT::init(int posX, int posY, int width, int height)
{
	_posX = posX;
	_posY = posY;
	_width = width;
	_height = height;
}

void OBJECT::setImage(image * pImage)
{
	_pImg = pImage;
}

void OBJECT::moveLeft()
{
}

void OBJECT::moveRight()
{
}

void OBJECT::moveUp()
{
}

void OBJECT::moveDown()
{
}

void OBJECT::setMoveStart(bool isMoveStart)
{
}

void OBJECT::jump()
{
}

float OBJECT::getSpeedX()
{
	return 0.0f;
}

float OBJECT::getSpeedY()
{
	return 0.0f;
}


void OBJECT::skillOne()
{
}

void OBJECT::skillTwo()
{
}

OBJECT::ERIC_STATE OBJECT::getEricState()
{
	return OBJECT::ERIC_STATE();
}

void OBJECT::setEricState(OBJECT::ERIC_STATE ericState)
{
}

void OBJECT::setJumpPower(float power)
{
}

void OBJECT::setLadderAni(int nLadderAni)
{
}


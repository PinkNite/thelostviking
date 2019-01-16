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

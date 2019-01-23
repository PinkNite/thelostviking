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


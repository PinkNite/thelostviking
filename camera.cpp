#include "stdafx.h"
#include "camera.h"
#include "player.h"

CAMERA::CAMERA()
{
}

CAMERA::~CAMERA()
{
}

void CAMERA::init(int posX, int posY, int width, int height)
{
	_posX = posX;
	_posY = posY;
	_width = width;
	_height = height;
	setLeftTop();

	_pCameraBuffer = IMAGEMANAGER->addImage("b", MAPSIZEX, MAPSIZEY);
	_pBac = IMAGEMANAGER->addImage("magicCircle", "magicCircle.bmp", MAPSIZEX, MAPSIZEY, true, RGB(255, 0, 255));
}

void CAMERA::update()
{
	//if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	//{
	//	if (_posX - _width/2 > 0)
	//	{
	//		_posX -= 5;
	//		if (_posX - _width / 2 < 0)
	//		{
	//			_posX = _width / 2;
	//		}
	//	}
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	//{
	//	if (_posX + _width / 2 < MAPSIZEX)
	//	{
	//		_posX += 5;
	//		if (_posX + _width / 2 > MAPSIZEX)
	//		{
	//			_posX = MAPSIZEX - _width / 2;
	//		}
	//	}
	//	
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_UP))
	//{
	//	if (_posY - _height / 2 > 0)
	//	_posY -= 5;
	//	if (_posY - _height / 2 < 0)
	//	{
	//		_posY = _height / 2;
	//	}
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	//{
	//	if (_posY + _height / 2 < MAPSIZEY)
	//	_posY += 5;
	//	if (_posY + _height / 2 > MAPSIZEX)
	//	{
	//		_posY = MAPSIZEX - _height / 2;
	//	}
	//}


	//_left = _posX - _width/2;
	//_top = _posY - _height/2;

	

}

void CAMERA::render(HDC hdc)
{
	_pCameraBuffer->render(hdc, 0, 0, _left, _top, _width, _height);

}

void CAMERA::renderinit()
{
	PatBlt(this->getMemDC(), 0, 0, MAPSIZEX, MAPSIZEY, WHITENESS);

	_pBac->render(this->getMemDC(), 0, 0);
}

void CAMERA::setting()
{
	_posX = _pPlayer->getPosX();
	_posY = _pPlayer->getPosY();
	setLeftTop();
}

void CAMERA::setMap(image * background)
{
	_pBac = background;
}

void CAMERA::setLeftTop()
{
	_left = _posX - _width / 2;
	_top = _posY - _height / 2;
}

void CAMERA::moveRight(float offset)
{
	_posX += offset;
	if (_posX + _width/2 >= MAPSIZEX)
	{
		_posX = MAPSIZEX - _width / 2;
	}
	setLeftTop();

}

void CAMERA::moveLeft(float offset)
{
	_posX -= offset;
	if (_posX - _width / 2 <= 0)
	{
		_posX = _width / 2;
	}
	setLeftTop();

}

void CAMERA::moveUp(float offset)
{
	_posY -= offset;
	if (_posY - _height / 2 <= 0)
	{
		_posY = _height / 2;
	}
	setLeftTop();

}

void CAMERA::moveDown(float offset)
{
	_posY += offset;
	if (_posY + _height / 2 >= MAPSIZEY)
	{
		_posY = MAPSIZEY - _height / 2;
	}
	setLeftTop();

}

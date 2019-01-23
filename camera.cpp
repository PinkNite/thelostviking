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
	moveToPlayer();
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
	if (_posX + _width / 2 >= MAPSIZEX)
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

void CAMERA::moveToPlayer()
{
	if (!_isMoving) return;


	if (_pPlayer->getPosX() > _posX) {
		float moveSpeed = (TIMEMANAGER->getElpasedTime()) * _travelRangeX;
		moveRight(moveSpeed);

	}
	else
	{
		float moveSpeed = (TIMEMANAGER->getElpasedTime()) * _travelRangeX;
		moveLeft(moveSpeed);

	}

	if (_pPlayer->getPosY() > _posY) {
		float moveSpeed = (TIMEMANAGER->getElpasedTime()) * _travelRangeY;
		moveDown(moveSpeed);
	}
	else
	{
		float moveSpeed = (TIMEMANAGER->getElpasedTime()) * _travelRangeY;
		moveUp(moveSpeed);
	}

	_time += TIMEMANAGER->getElpasedTime();

	if (_time > 1.0f)
	{
		_isMoving = false;
	}

}

void CAMERA::movingStart()
{
	if (!_isMoving)
	{
		_isMoving = true;
		_time = 0.0f;
	}
	
	if (_pPlayer->getPosX() > _posX) {
		_travelRangeX = _pPlayer->getPosX() - _posX;
	}
	else
	{
		_travelRangeX = _posX - _pPlayer->getPosX();
	}

	if (_pPlayer->getPosY() > _posY) {
		_travelRangeY = _pPlayer->getPosY() - _posY;
	}
	else
	{
		_travelRangeY = _posY - _pPlayer->getPosY();
	}

}

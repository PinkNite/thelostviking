#include "stdafx.h"
#include "camera.h"

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
	_left = _posX - _width;
	_top = _posY - _height;
}

void CAMERA::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_posX - _width/2 > 0)
		{
			_posX -= 5;
			if (_posX - _width / 2 < 0)
			{
				_posX = _width / 2;
			}
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_posX + _width / 2 < MAPSIZEX)
		{
			_posX += 5;
			if (_posX + _width / 2 > MAPSIZEX)
			{
				_posX = MAPSIZEX - _width / 2;
			}
		}
		
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if (_posY - _height / 2 > 0)
		_posY -= 5;
		if (_posY - _height / 2 < 0)
		{
			_posY = _height / 2;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_posY + _height / 2 < MAPSIZEY)
		_posY += 5;
		if (_posY + _height / 2 > MAPSIZEX)
		{
			_posY = MAPSIZEX - _height / 2;
		}
	}


	_left = _posX - _width/2;
	_top = _posY - _height/2;

}

void CAMERA::render(HDC hdc)
{
	_cameraBuffer->render(hdc, 0, 0, _left, _top, _width, _height);
}

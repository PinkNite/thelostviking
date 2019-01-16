#include "stdafx.h"
#include "eric.h"

ERIC::ERIC()
{
}

ERIC::~ERIC()
{
}

void ERIC::init(int posX, int posY, int width, int height)
{
	OBJECT::init(posX, posY, width, height);
	_hp = 3;
	_itemCount = 0;
	OBJECT::setImage(IMAGEMANAGER->findImage("eric"));
	_speed = 3.0f;
	_state = ERIC_STATE::LEFT_IDLE;
}

void ERIC::update()
{
	//�����̵� ����
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_speed = _minSpeed;
		moveLeft(static_cast<int>(_speed));
	}
	//���� �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_speed < _maxSpeed)
		{
			_speed += _upSpeed * TIMEMANAGER->getElpasedTime();
		}
		moveLeft(static_cast<int>(_speed));
	}
	//������ �̵� ����
	if(KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_speed = _speed = _minSpeed;
		3.0f;
		moveRight(static_cast<int>(_speed));
	}
	//������ �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_speed < _maxSpeed)
		{
			_speed += _upSpeed * TIMEMANAGER->getElpasedTime();
		}		
		moveLeft(static_cast<int>(_speed));
	}

	if(KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_speed = _minSpeed;
		moveDown(static_cast<int>(_speed));
	}


	if(KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_speed = _minSpeed;
		moveUp(static_cast<int>(_speed));
	}

}

void ERIC::release()
{
}

void ERIC::render(HDC hdc)
{
}

void ERIC::initAnimation()
{
	


}

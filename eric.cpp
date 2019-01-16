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
	_maxSpeed = 5;
}

void ERIC::update()
{
	//�����̵� ����
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_speed = 3.0f;
		moveLeft(static_cast<int>(_speed));
	}
	//���� �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_speed += 0.2f;
		moveLeft(static_cast<int>(_speed));
	}
	//������ �̵� ����
	if(KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_speed = 3.0f;
		moveRight(static_cast<int>(_speed));
	}
	//������ �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_speed += 0.2f;
		moveLeft(static_cast<int>(_speed));
	}

	if(KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_speed = 3.0f;
		moveDown(static_cast<int>(_speed));
	}
	if(KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_speed = 3.0f;
		moveUp(static_cast<int>(_speed));
	}

}

void ERIC::release()
{
}

void ERIC::render(HDC hdc)
{
}

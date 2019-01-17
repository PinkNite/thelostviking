#include "stdafx.h"
#include "inputMgr.h"
#include "player.h"
#include "camera.h"

void INPUTMANAGER::init(PLAYER * pPlayer, CAMERA * pCamera)
{
	_pPlayer = pPlayer;
	_pCamera = pCamera;
}

void INPUTMANAGER::update()
{
	//Ű�Է� ������ ���⼭ ���� ó�����ּ���
	//�����̵� ����
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_pPlayer->setMoveStart(true);

	}
	//���� �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_pPlayer->moveLeft();
		if (_pPlayer->getPosX() < _pCamera->getLeft() + _pCamera->getWidth() / 2 - 32)
		{
			_pCamera->moveLeft(_pPlayer->getSpeed());
		}
	}
	//���� �̵� ����
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_pPlayer->setMoveStart(false);

	}

	//������ �̵� ����
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_pPlayer->setMoveStart(true);
	}
	//������ �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_pPlayer->moveRight();
		if (_pPlayer->getPosX() > _pCamera->getLeft() + _pCamera->getWidth()/2 + 32)
		{
			_pCamera->moveRight(_pPlayer->getSpeed());
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_pPlayer->setMoveStart(false);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pPlayer->moveDown();

		if (_pPlayer->getPosY() > _pCamera->getTop() + _pCamera->getHeight() / 2 )
		{
			_pCamera->moveDown(_pPlayer->getSpeed());
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pPlayer->moveUp();

		if (_pPlayer->getPosY() < _pCamera->getTop() + _pCamera->getHeight() / 2)
		{
			_pCamera->moveUp(_pPlayer->getSpeed());
		}
	}


}

void INPUTMANAGER::release()
{
	_pPlayer = nullptr;
	_pCamera = nullptr;
}

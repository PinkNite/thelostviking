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

	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_pPlayer->setMoveStart(false);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pPlayer->moveDown();

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pPlayer->moveUp();

	}

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_pPlayer->useSkillOne();
	}

	if (_pPlayer->getPosX() < _pCamera->getLeft() + _pCamera->getWidth() / 2 - 32)
	{
		float offset = _pCamera->getLeft() + _pCamera->getWidth() / 2 - 32 - _pPlayer->getPosX();
		_pCamera->moveLeft(offset);
		//���̰� �޾Ƽ� �غ���
		
	}
	else if (_pPlayer->getPosX() > _pCamera->getLeft() + _pCamera->getWidth() / 2 + 32)
	{
		_pCamera->moveRight(_pPlayer->getSpeedX());
	}
	if (_pPlayer->getPosY() > _pCamera->getTop() + _pCamera->getHeight() / 2 + 5)
	{
		_pCamera->moveDown(_pPlayer->getSpeedY());
	}
	else if (_pPlayer->getPosY() < _pCamera->getTop() + _pCamera->getHeight() / 2 -5)
	{
		float offset = _pCamera->getTop() + _pCamera->getHeight() / 2 - 5 - _pPlayer->getPosY();
		_pCamera->moveUp(offset);
	}
}

void INPUTMANAGER::release()
{
	_pPlayer = nullptr;
	_pCamera = nullptr;
}

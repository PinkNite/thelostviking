#include "stdafx.h"
#include "inputMgr.h"
#include "player.h"
#include "camera.h"
#include "object.h"

void INPUTMANAGER::init(PLAYER * pPlayer, CAMERA * pCamera)
{
	_pPlayer = pPlayer;
	_pCamera = pCamera;
	_ericJumpPower = 0.0f;
}

void INPUTMANAGER::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{

	}
	//���� �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		{
			_pPlayer->moveLeft();
		}
	}
	//���� �̵� ����
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{

	}

	//������ �̵� ����
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{

	}
	//������ �̵� ��
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{

		_pPlayer->moveRight();


	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{

	}

	//��ٸ��� �÷��̾� ���°� ��� ���������ؾ��Ѵ�.
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pPlayer->moveDown();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
	}


	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pPlayer->moveUp();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{

	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_pPlayer->useSkillOne();
		_ericJumpPower = 500.0f;
		_jumpKeyPressTime = 0.0f;
	}
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		_jumpKeyPressTime += TIMEMANAGER->getElpasedTime();

		if (_jumpKeyPressTime >= 0.1f)
		{
		}
	}



	if (_pPlayer->getPosX() < _pCamera->getLeft() + _pCamera->getWidth() / 2 - 32)
	{
		float offset = _pCamera->getLeft() + _pCamera->getWidth() / 2 - 32 - _pPlayer->getPosX();
		_pCamera->moveLeft(offset);
	}
	else if (_pPlayer->getPosX() > _pCamera->getLeft() + _pCamera->getWidth() / 2 + 32)
	{
		float offset = _pPlayer->getPosX() - (_pCamera->getLeft() + _pCamera->getWidth() / 2 + 32);
		_pCamera->moveRight(offset);
	}
	if (_pPlayer->getPosY() > _pCamera->getTop() + _pCamera->getHeight() / 2 + 5)
	{
		float offset = _pPlayer->getPosY() - (_pCamera->getTop() + _pCamera->getHeight() / 2 + 5);
		_pCamera->moveDown(offset);
	}
	else if (_pPlayer->getPosY() < _pCamera->getTop() + _pCamera->getHeight() / 2 - 5)
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

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
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_pPlayer->moveDown();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_pPlayer->moveUp();
	}


}

void INPUTMANAGER::release()
{
	_pPlayer = nullptr;
	_pCamera = nullptr;
}

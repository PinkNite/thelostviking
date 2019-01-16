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
	//키입력 관련은 여기서 전부 처리해주세요
	//왼쪽이동 시작
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_pPlayer->setMoveStart(true);

	}
	//왼쪽 이동 중
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_pPlayer->moveLeft();
	}
	//오른쪽 이동 시작
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_pPlayer->setMoveStart(true);
	}
	//오른쪽 이동 중
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

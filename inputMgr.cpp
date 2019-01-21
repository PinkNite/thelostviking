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

	//이승재
	_isLeft = false;
	_isRight = false;
	_isTop = false;
	_isBottom = false;
	_isUse = false;
	_isOpen = false;
}

void INPUTMANAGER::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_isLeft = true;
	}
	//왼쪽 이동 중
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_pPlayer->moveLeft();
	}
	//왼쪽 이동 해제
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isLeft = false;
		_pPlayer->setStopAnimation();
	}

	//오른쪽 이동 시작
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_isRight = true;
	}
	//오른쪽 이동 중
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		
		_pPlayer->moveRight();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isRight = false;
		_pPlayer->setStopAnimation();
	}

	//사다리는 플레이어 상태가 어떻든 하이제깅해야한다.
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_isBottom = true;
		if (_pPlayer->isCollisionLadder())
		{
			_pPlayer->setLadderAnimation(-1);
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pPlayer->moveDown();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_isBottom = false;
		if (_pPlayer->isCollisionLadder())
		{
			_pPlayer->setLadderAnimation(0);
		}
	}


	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_isTop = true;
		if (_pPlayer->isCollisionLadder())
		{
			_pPlayer->setLadderAnimation(1);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pPlayer->moveUp();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isTop = false;
		if (_pPlayer->isCollisionLadder())
		{
			_pPlayer->setLadderAnimation(0);
		}
	}


	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_pPlayer->useSkillTwo();
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
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_pPlayer->useSkillOne();
	}
	//이승재
	if (KEYMANAGER->isToggleKey(VK_SPACE)&&!_isUse)//아이템사용
	{
		_isUse = true;
	}
	else
	{
		_isUse = false;
	}
	if (KEYMANAGER->isToggleKey(VK_F8)&&!_isOpen)//아이템사용
	{
		_isOpen = true;
	}
	else
	{
		_isOpen = false;
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

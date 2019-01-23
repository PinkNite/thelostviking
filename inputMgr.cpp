#include "stdafx.h"
#include "inputMgr.h"
#include "player.h"
#include "camera.h"
#include "object.h"

void INPUTMANAGER::init(PLAYER * pPlayer, CAMERA * pCamera)
{
	_pPlayer = pPlayer;
	_pCamera = pCamera;



	//이승재
	_isLeft = false;
	_isRight = false;
	_isTop = false;
	_isBottom = false;
	_isUse = false;
	_isOpen = false;
	_num=0;
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
		if (_pPlayer->isCollisionLadder())
		{
			_pPlayer->setLadderAnimation(-1);
		}
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
		if (_pPlayer->isCollisionLadder())
		{
			_pPlayer->setLadderAnimation(1);
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isTop = false;
		if (_pPlayer->isCollisionLadder())
		{
			_pPlayer->setLadderAnimation(0);
		}
	}
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		_isUse = true;
	}
	if (KEYMANAGER->isOnceKeyUp('E'))
	{
		_isUse = false;
	}
	if (KEYMANAGER->isOnceKeyUp('I'))
	{
		_num = 0;
	}
	if (KEYMANAGER->isToggleKey('I'))
	{
		
		_num++;
		switch (_num)
		{
		case 0:
			_isOpen = false;
			break;
		case 1:
			_isOpen = true;
			break;

		}
		
		
	}
	

	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_pPlayer->useSkillTwo();

	}

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_pPlayer->useSkillOne();
	}

	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_pPlayer->stopSkillOne();
	}


	if (KEYMANAGER->isOnceKeyDown(VK_CONTROL))
	{
		_pPlayer->nextViking();
		_pCamera->movingStart();
	}

	if (KEYMANAGER->isOnceKeyDown('Q')) {
		_pPlayer->deathViking(VIKING::DEATH_MOTION::ELECTRIC);
	}


	if (!_pCamera->getMoving())
	{
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

}

void INPUTMANAGER::release()
{
	_pPlayer = nullptr;
	_pCamera = nullptr;
}

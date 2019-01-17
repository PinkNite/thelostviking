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
	//키입력 관련은 여기서 전부 처리해주세요
	//왼쪽이동 시작
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_pPlayer->setMoveStart(true);
		_pPlayer->setEricState(OBJECT::ERIC_STATE::LEFT_RUN);
	}
	//왼쪽 이동 중
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (_pPlayer->getEricState() == OBJECT::ERIC_STATE::LEFT_RUN)
		{
			_pPlayer->moveLeft();
		}
	}
	//왼쪽 이동 해제
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_pPlayer->setMoveStart(false);
		if (_pPlayer->getEricState() == OBJECT::ERIC_STATE::LEFT_RUN)
		{
			_pPlayer->setEricState(OBJECT::ERIC_STATE::LEFT_IDLE);
		}

	}

	//오른쪽 이동 시작
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_pPlayer->setMoveStart(true);
		_pPlayer->setEricState(OBJECT::ERIC_STATE::RIGHT_RUN);

	}
	//오른쪽 이동 중
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_pPlayer->getEricState() == OBJECT::ERIC_STATE::RIGHT_RUN)
		{
			_pPlayer->moveRight();
		}

	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_pPlayer->setMoveStart(false);
		if (_pPlayer->getEricState() == OBJECT::ERIC_STATE::RIGHT_RUN)
		{
			_pPlayer->setEricState(OBJECT::ERIC_STATE::RIGHT_IDLE);
		}
	}

	//사다리는 플레이어 상태가 어떻든 하이제깅해야한다.
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_pPlayer->setEricState(OBJECT::ERIC_STATE::ON_LADDER);
	}
	
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pPlayer->moveDown();
		_pPlayer->setLadderAni(-1);
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_pPlayer->setLadderAni(0);
	}


	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_pPlayer->setEricState(OBJECT::ERIC_STATE::ON_LADDER);
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pPlayer->moveUp();
		_pPlayer->setLadderAni(1);
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_pPlayer->setLadderAni(0);

	}
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		_pPlayer->useSkillOne();
		_ericJumpPower = 500.0f;
		_jumpKeyPressTime = 0.0f;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_jumpKeyPressTime += TIMEMANAGER->getElpasedTime();

		if (_jumpKeyPressTime >= 0.1f)
		{
			_pPlayer->setEricJumpPower(700.0f);
		}
	}



	if (_pPlayer->getPosX() < _pCamera->getLeft() + _pCamera->getWidth() / 2 - 32)
	{
		float offset = _pCamera->getLeft() + _pCamera->getWidth() / 2 - 32 - _pPlayer->getPosX();
		_pCamera->moveLeft(offset);		
	}
	else if (_pPlayer->getPosX() > _pCamera->getLeft() + _pCamera->getWidth() / 2 + 32)
	{
		float offset = _pPlayer->getPosX() - ( _pCamera->getLeft() + _pCamera->getWidth() / 2 + 32);
		_pCamera->moveRight(offset);
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

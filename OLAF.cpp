#include "stdafx.h"
#include "OLAF.h"


OLAF::OLAF()
{
}


OLAF::~OLAF()
{
}

void OLAF::init(int posX, int posY, int width, int height)
{
	VIKING::init(posX, posY, int(VIKING_WIDTH), int(VIKING_HEIGHT));

	_arTmpFrame[11] = { 0, };
	_fallingTime = 0.0f;
	_whereBlock = OLAFSHIELD::BLOCK_FRONT;
	_isUsingSkillTwo = false;

	initKeyAnimation();
	setIsOnGround(true);

}

void OLAF::update()
{
	if (!getIsOnGround())
	{
		_fallingTime += TIMEMANAGER->getElpasedTime();
	}

	if (_fallingTime >= 2.0f && VIKING::_behavior == int(VIKING::ACTION::SKILL_TWO))
	{
		setFallOut();
	}
	else if (_fallingTime >= 6.0f)
	{
		if (getIsOnGround())
		{
			callbackFallDown();
			_fallingTime = 0.0f;
		}
	}

	if (VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER) ||
		VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER_OVER))
	{
		_fallingTime = 0.0f;
	}

	KEYANIMANAGER->update();
}

void OLAF::release()
{
}

void OLAF::render(HDC hdc)
{
	//RectangleMake(hdc, VIKING::getPosX() - VIKING::getWidth() / 2, VIKING::getPosY() - VIKING::getHeight() / 2, VIKING_WIDTH, VIKING_HEIGHT);

	VIKING::_pImg->aniRender(hdc, VIKING::_posX - VIKING::_width / 2, VIKING::_posY - VIKING::_height / 2, VIKING::_pAnimation);
}

void OLAF::skillOne()
{
	// 방패가 앞에 있을경우: 추락 O
	if (_whereBlock == OLAFSHIELD::BLOCK_FRONT)
	{
		_whereBlock = OLAFSHIELD::BLOCK_TOP;
		setAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::DIRECTION(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else // 방패가 머리에 있을경우: 추락 X
	{
		_whereBlock = OLAFSHIELD::BLOCK_FRONT;
		setAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::DIRECTION(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
}

void OLAF::skillTwo()
{
	// 방패가 앞에 있을경우: 추락 O
	if (_whereBlock == OLAFSHIELD::BLOCK_FRONT)
	{
		_whereBlock = OLAFSHIELD::BLOCK_TOP;
		setAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::DIRECTION(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else // 방패가 머리에 있을경우: 추락 X
	{
		_whereBlock = OLAFSHIELD::BLOCK_FRONT;
		setAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::DIRECTION(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
}

void OLAF::setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight)
{
	if (VIKING::ACTION(VIKING::_behavior) != VIKING::ACTION::ON_LADDER && !isOverAni)
	{
		setAnimation(VIKING::DIRECTION(_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER));
	}
	else if (VIKING::ACTION(VIKING::_behavior)!= VIKING::ACTION::ON_LADDER_OVER && !isOverAni)
	{
		setAnimation(VIKING::DIRECTION(_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER_OVER));
	}

	if (VIKING::ACTION(VIKING::_behavior) == VIKING::ACTION::ON_LADDER)
	{
		VIKING::_pAnimation->setClickVariable(offset);
	}

	if (VIKING::ACTION(VIKING::_behavior) == VIKING::ACTION::ON_LADDER_OVER)
	{
		if (rcTmpHeight < 5)
		{
			setAnimation(VIKING::DIRECTION(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, int(VIKING::IDLE::NORMAL));
			VIKING::OBJECT::setPosY(VIKING::OBJECT::getPosY());
		}
		else if (rcTmpHeight <= 36)
		{
			VIKING::_pAnimation->setFixedFrame(1);
		}
		else if (rcTmpHeight <= 48)
		{
			VIKING::_pAnimation->setFixedFrame(0);
		}
		else if (rcTmpHeight > 32)
		{
			setAnimation(VIKING::DIRECTION(_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER));
		}
	}
}

void OLAF::initKeyAnimation()
{
	VIKING::setImage(IMAGEMANAGER->findImage(this->_name));
	KEYANIMANAGER->addObject(this->_name);

	string idleNormal = VIKING::_vBehavior[int(VIKING::STATE::IDLE)][int(VIKING::IDLE::NORMAL)];
	{
		string blockFront = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_FRONT)];
		addRightAliveAnimation(blockFront, idleNormal, 0, 1, 1, true);
		addLeftAliveAnimation(blockFront, idleNormal, 1, 1, 1, true);

		string blockTop = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_TOP)];
		addRightAliveAnimation(blockTop, idleNormal, 2, 1, 1, true);
		addLeftAliveAnimation(blockTop, idleNormal, 3, 1, 1, true);
	}

	string actionTeleport = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::TELEPORT)];
	{
		addRightAliveAnimation(actionTeleport, 4, 7, 3, false);
		addLeftAliveAnimation(actionTeleport, 11, 7, 3, false);
	}

	string actionRun = VIKING::_vBehavior[int(VIKING::STATE::ACTION)][int(VIKING::ACTION::RUN)];
	{
		string blockFront = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_FRONT)];
		// 전방우이동
		addRightAliveAnimation(blockFront, actionRun, 18, 8, 4, true);
		// 전방좌이동
		addLeftAliveAnimation(blockFront, actionRun, 26, 8, 4, true);

		string blockTop = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_TOP)];
		// 상방우이동
		addRightAliveAnimation(blockTop, actionRun, 34, 8, 4, true);
		// 상방좌이동
		addLeftAliveAnimation(blockTop, actionRun, 42, 8, 4, true);
	}

	string idleSpecial = VIKING::_vBehavior[int(VIKING::STATE::IDLE)][int(VIKING::IDLE::SPECIAL)];
	{
		// 상방일때 바지 내려가는 액션
		string blockTop = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_TOP)];
		addRightAliveAnimation(blockTop, idleSpecial, 50, 4, 2, false);
		addLeftAliveAnimation(blockTop, idleSpecial, 54, 4, 2, false);

		// 전방일때 코파는 액션
		string blockFront = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_FRONT)];
		addRightAliveAnimation(blockFront, idleSpecial, 58, 4, 2, false);
		addLeftAliveAnimation(blockFront, idleSpecial, 61, 4, 2, false);
	}

	{ // 사다리
		string actionLadder = VIKING::_vBehavior[int(VIKING::STATE::ACTION)][int(VIKING::ACTION::ON_LADDER)];
		addRightAliveAnimation(actionLadder, 64, 4, 2, true);
		addLeftAliveAnimation(actionLadder, 64, 4, 2, true);

		string actionLadderOver = VIKING::_vBehavior[int(VIKING::STATE::ACTION)][int(VIKING::ACTION::ON_LADDER_OVER)];
		addRightAliveAnimation(actionLadderOver, 68, 2, 1, true);
		addLeftAliveAnimation(actionLadderOver, 68, 2, 1, true);
	}

	string actionFlyTurn = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::FLY_TURN)];
	{ // 비행 턴
		addRightAliveAnimation(actionFlyTurn, 74, 2, 1, false);
		addLeftAliveAnimation(actionFlyTurn, 76, 2, 1, false);
	}

	string actionFly = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::FLY)];
	{ // 비행
		addRightAliveAnimation(actionFly, 70, 2, 1, false);
		addLeftAliveAnimation(actionFly, 72, 2, 1, false);
	}

	string actionDamage = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)];
	{ // Damage
		addRightAliveAnimation(actionDamage, 78, 1, 1, false);
		addLeftAliveAnimation(actionDamage, 79, 1, 1, false);
	}

	string actionFallDown1 = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::FALLDOWN)];
	{ // 낙하 원
		addRightAliveAnimation(actionFallDown1, 80, 2, 1, false);
		addLeftAliveAnimation(actionFallDown1, 82, 2, 1, false);
	}

	string actionFallDown2 = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::SKILL_TWO)];
	{ // 낙하 투: 사망각 
		addRightAliveAnimation(actionFallDown2, 94, 2, 1, false);
		addLeftAliveAnimation(actionFallDown2, 96, 2, 1, false);
	}

	string actionPush = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::PUSH)];
	{ //  밀기
		addRightAliveAnimation(actionPush, 84, 4, 2, true);
		addLeftAliveAnimation(actionPush, 88, 4, 2, true);
	}

	string idleFat = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::IDLE)][static_cast<int>(VIKING::IDLE::FAT)];
	{ //  풍선
		addRightAliveAnimation(idleFat, 92, 2, 1, false);
		addLeftAliveAnimation(idleFat, 94, 2, 1, false);
	}

	string actionStun = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::STUN)];
	{ // 낙하 충돌 
		addRightAliveAnimation(actionStun, 98, 5, 2, false);
		addLeftAliveAnimation(actionStun, 103, 5, 2, false);
	}

	addRightAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE), 40, 8, 5, true, false, callbackSpecialIdle);
	addLeftAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE), 48, 8, 5, true, false, callbackSpecialIdle);

	KEYANIMANAGER->findAnimation(this->_name,
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);

	KEYANIMANAGER->findAnimation(this->_name,
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);

	KEYANIMANAGER->findAnimation(this->_name,
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setFixedRender(true);

	KEYANIMANAGER->findAnimation(this->_name,
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setFixedRender(true);


	setAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));

}

string OLAF::addString(string direction, string live, string action)
{
	string str;
	str.append(direction);
	str.append("-");
	str.append(live);
	str.append("-");
	str.append(action);
	str.append("-");
	return str;
}

string OLAF::addString(string shield, string direction, string live, string action)
{
	string str;
	str.append(shield);
	str.append("-");
	str.append(direction);
	str.append("-");
	str.append(live);
	str.append("-");
	str.append(action);
	str.append("-");

	return str;
}

void OLAF::addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(direction)], VIKING::_arLive[static_cast<int>(life)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addKeyAnimation(VIKING::OLAFSHIELD shield, VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arOlafShield[int(shield)], VIKING::_arDirection[static_cast<int>(direction)], VIKING::_arLive[static_cast<int>(life)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addLeftAliveAnimation(string shield, string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(shield,
		VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addRightAliveAnimation(string shield, string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(shield,
		VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, pCallBack, this);
}

void OLAF::addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, pCallBack, this);
}

void OLAF::addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, pCallBack, this);
}

void OLAF::addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, pCallBack, this);
}

void OLAF::addLeftAliveAnimationCoordinate(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addCoordinateFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
}

void OLAF::addRightAliveAnimationCoordinate(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
}

void OLAF::addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void OLAF::addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void OLAF::addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void OLAF::addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void OLAF::settingAniArray(int startFrame, int length)
{
	int frame = startFrame;
	for (int i = 0; i < length; i++)
	{
		_arTmpFrame[i] = frame;
		frame++;
	}
}

void OLAF::setFallOut()
{
	setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
}

void OLAF::setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior)
{
	string tmp = addString( VIKING::_arDirection[static_cast<int>(direction)],
							VIKING::_arLive[static_cast<int>(life)],
							VIKING::_vBehavior[static_cast<int>(state)][behavior]);
							VIKING::_pAnimation = KEYANIMANAGER->findAnimation(this->_name, tmp);

	VIKING::_direction = static_cast<int>(direction);
	VIKING::_life = static_cast<int>(life);
	VIKING::_state = static_cast<int>(state);
	VIKING::_behavior = behavior;

	VIKING::_pAnimation->start();
}

void OLAF::setAnimation(VIKING::OLAFSHIELD shield, VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior)
{
	string tmp = addString(
		VIKING::_arOlafShield[int(shield)],
		VIKING::_arDirection[static_cast<int>(direction)],
		VIKING::_arLive[static_cast<int>(life)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	VIKING::_pAnimation = KEYANIMANAGER->findAnimation(this->_name, tmp);

	OLAF::_whereBlock = _whereBlock;
	VIKING::_direction = static_cast<int>(direction);
	VIKING::_life = static_cast<int>(life);
	VIKING::_state = static_cast<int>(state);
	VIKING::_behavior = behavior;

	VIKING::_pAnimation->start();
}

void OLAF::setMovingAnimation(int direction)
{
	if (VIKING::STATE::IDLE == static_cast<VIKING::STATE>(_state))
	{
		setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock),  static_cast<VIKING::DIRECTION>(direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN));
	}
	else if (direction != VIKING::_direction && static_cast<int>(VIKING::ACTION::RUN) == _behavior && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_state)) {
		if (direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN));
		}
		else {
			setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN));
		}
	}
	else if (direction != VIKING::_direction && static_cast<int>(VIKING::ACTION::FALLDOWN) == _behavior && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_state))
	{
		if (direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
		}
		else {
			setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
		}
	}
	else if (direction != VIKING::_direction && static_cast<int>(VIKING::ACTION::FLY) == _behavior && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_state))
	{
		if (direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY));
		}
		else {
			setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY));
		}
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER) == _behavior && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_state)) {
		if (direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY));
		}
		else {
			setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY));
		}
	}
}

void OLAF::setStopAnimation()
{
	if (static_cast<int>(VIKING::ACTION::RUN) == _behavior || static_cast<int>(VIKING::ACTION::SKILL_ONE_END) == _behavior || static_cast<int>(VIKING::ACTION::PUSH) == _behavior) {
		setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
}

void OLAF::setSkillAnimation()
{
	if (VIKING::ACTION::FLY != static_cast<VIKING::ACTION>(VIKING::_behavior))
	{
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY));
	}
}

void OLAF::pressGravity()
{
	if (VIKING::_behavior != static_cast<int>(VIKING::ACTION::ON_LADDER) &&
		VIKING::_behavior != static_cast<int>(VIKING::ACTION::ON_LADDER_OVER))
	{
		VIKING::OBJECT::setPosY(VIKING::OBJECT::getPosY() + _gravity * TIMEMANAGER->getElpasedTime());
	}
}

void OLAF::falldownAnimation()
{
	if (static_cast<int>(VIKING::ACTION::FLY) == _behavior) {
		setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else if (static_cast<int>(VIKING::ACTION::FALLDOWN) == _behavior) {
		//callbackEricFallDown();
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER_OVER) == _behavior) {
		setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER) == _behavior) {
		setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}

	_fallingTime = 0.0f;
}

void OLAF::setPushWallAni(bool isCollisionWall)
{
	if (static_cast<STATE>(_state) == STATE::ACTION && static_cast<ACTION>(_behavior) == ACTION::RUN && isCollisionWall)
	{
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH));
	}
}

void OLAF::callbackSpecialIdle(void * obj)
{
	OLAF* pOlaf = (OLAF*)obj;
	pOlaf->callbackbaleogSpecialIdle();
}

void OLAF::callbackbaleogSpecialIdle()
{
	setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	_isUsingSkillTwo = false;
}


void OLAF::callbackFallDown()
{
}

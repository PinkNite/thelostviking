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

	if (_fallingTime >= 2.0f && VIKING::_behavior == static_cast<int>(VIKING::ACTION::FLY))
	{
		setFallOut();
	}
	else if (getIsOnGround() && VIKING::_behavior == static_cast<int>(VIKING::ACTION::FALLDOWN))
	{
		if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN));
		}
		else {
			setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN));
		}
		setIsOnGround(true);
		_fallingTime = 0.0F;
	}


	if (VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER) ||
		VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER_OVER) ||
		getIsUpperGravity())
	{
		_fallingTime = 0.0f;
	}

	KEYANIMANAGER->update();
}

void OLAF::release()
{
	_pAnimation = nullptr;
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
	if (static_cast<VIKING::ACTION>(VIKING::_behavior) != VIKING::ACTION::ON_LADDER && !isOverAni)
	{
		setAnimation(static_cast<VIKING::DIRECTION>(_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER));
	}
	else if (static_cast<VIKING::ACTION>(VIKING::_behavior) != VIKING::ACTION::ON_LADDER_OVER && isOverAni) {
		setAnimation(static_cast<VIKING::DIRECTION>(_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER_OVER));
	}


	if (static_cast<VIKING::ACTION>(VIKING::_behavior) == VIKING::ACTION::ON_LADDER)
	{
		VIKING::_pAnimation->setClickVariable(offset);
	}
	if (static_cast<VIKING::ACTION>(VIKING::_behavior) == VIKING::ACTION::ON_LADDER_OVER)
	{
		if (rcTmpHeight < 5) {
			setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
			VIKING::OBJECT::setPosY(VIKING::OBJECT::getPosY());
		}
		else if (rcTmpHeight <= 36)
		{
			VIKING::_pAnimation->setFixedFrame(1);
		}
		else if (rcTmpHeight <= 48) {
			VIKING::_pAnimation->setFixedFrame(0);
		}
		else if (rcTmpHeight > 32) {
			setAnimation(static_cast<VIKING::DIRECTION>(_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER));
		}
	}
}

void OLAF::initKeyAnimation()
{
	VIKING::setImage(IMAGEMANAGER->findImage(this->_name));
	KEYANIMANAGER->addObject(this->_name);

	addRightAliveAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::STATE::IDLE, int(VIKING::IDLE::NORMAL), 0, 1, 1, true);
	addLeftAliveAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::STATE::IDLE, int(VIKING::IDLE::NORMAL), 1, 1, 1, true);
	addRightAliveAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::STATE::IDLE, int(VIKING::IDLE::NORMAL), 2, 1, 1, true);
	addLeftAliveAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::STATE::IDLE, int(VIKING::IDLE::NORMAL), 3, 1, 1, true);

	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::TELEPORT), 4, 7, 3, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::TELEPORT), 11, 7, 3, false);

	// 전방우이동
	addRightAliveAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::STATE::ACTION, int(VIKING::ACTION::RUN),18, 8, 4, true);
	// 전방좌이동
	addLeftAliveAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::STATE::ACTION, int(VIKING::ACTION::RUN), 26, 8, 4, true);

	// 상방우이동
	addRightAliveAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::STATE::ACTION, int(VIKING::ACTION::RUN), 34, 8, 4, true);
	// 상방좌이동
	addLeftAliveAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::STATE::ACTION, int(VIKING::ACTION::RUN), 42, 8, 4, true);

	// 상방일때 바지 내려가는 액션
	addRightAliveAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::STATE::IDLE, int(VIKING::IDLE::SPECIAL), 50, 4, 2, false);
	addLeftAliveAnimation(VIKING::OLAFSHIELD::BLOCK_TOP, VIKING::STATE::IDLE, int(VIKING::IDLE::SPECIAL), 54, 4, 2, false);

	// 전방일때 코파는 액션
	addRightAliveAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::STATE::IDLE, int(VIKING::IDLE::SPECIAL), 58, 4, 2, false);
	addLeftAliveAnimation(VIKING::OLAFSHIELD::BLOCK_FRONT, VIKING::STATE::IDLE, int(VIKING::IDLE::SPECIAL), 61, 4, 2, false);

	// 사다리 
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER), 64, 4, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER), 64, 4, 2, true);
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER_OVER), 68, 2, 1, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER_OVER), 68, 2, 1, true);

	// 비행 턴
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::FLY_TURN), 74, 2, 1, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::FLY_TURN), 76, 2, 1, false);

	//비행
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::FLY), 70, 2, 1, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::FLY), 72, 2, 1, false);
	
	// damage
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::DAMEGE), 78, 1, 1, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::DAMEGE), 79, 1, 1, false);

	// 낙하 원
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::FALLDOWN), 80, 2, 1, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::FALLDOWN), 82, 2, 1, true);

	// 낙하 투: 사망각 
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::SKILL_TWO), 94, 2, 1, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::SKILL_TWO), 96, 2, 1, false);

	//  밀기
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::PUSH), 84, 4, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::PUSH), 88, 4, 2, true);

	//  풍선
	addRightAliveAnimation(VIKING::STATE::IDLE, int(VIKING::IDLE::FAT), 92, 2, 1, false);
	addLeftAliveAnimation(VIKING::STATE::IDLE, int(VIKING::IDLE::FAT), 94, 2, 1, false);

	// 낙하 충돌 
	addRightAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::STUN), 98, 5, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::ACTION, int(VIKING::ACTION::STUN), 103, 5, 2, false, callbackSpecialIdle);

	addRightAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE), 40, 8, 5, true, false, callbackSpecialIdle);
	addLeftAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE), 48, 8, 5, true, false, callbackSpecialIdle);


	addRightDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::ELECTRIC),
		133, 2, 2, false, 5, callbackDeath);
	addLeftDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::ELECTRIC),
		135, 2, 2, false, 5, callbackDeath);

	addRightDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::DROP),
		159, 6, 3, false, callbackDeath);
	addLeftDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::DROP),
		165, 6, 3, false, callbackDeath);

	addRightDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::SHOT),
		171, 7, 3, false, callbackDeath);
	addLeftDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::SHOT),
		178, 7, 3, false, callbackDeath);


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
	str.append("_");
	str.append(live);
	str.append("_");
	str.append(action);
	
	return str;
}

string OLAF::addString(string shield, string direction, string live, string action)
{
	string str;
	str.append(shield);
	str.append("_");
	str.append(direction);
	str.append("_");
	str.append(live);
	str.append("_");
	str.append(action);

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

void OLAF::addLeftAliveAnimation(OLAF::OLAFSHIELD shield, VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(
		VIKING::_arOlafShield[int(shield)],
		VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation(this->_name, strTmp, this->_name.c_str(), _arTmpFrame, length, fps, isLoop);
}

void OLAF::addRightAliveAnimation(OLAF::OLAFSHIELD shield, VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(
		VIKING::_arOlafShield[int(shield)],
		VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
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
			setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
		}
		else {
			setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
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
	pOlaf->callbackOlafSpecialIdle();
}

void OLAF::callbackOlafSpecialIdle()
{
	setAnimation(VIKING::OLAFSHIELD(OLAF::_whereBlock), static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	_isUsingSkillTwo = false;
}


void OLAF::callbackFallDown()
{
}

void OLAF::callbackDeath(void * obj)
{
	OLAF* pBalog = (OLAF*)obj;
	pBalog->callbackOlafDeath();
}

void OLAF::callbackOlafDeath()
{
	VIKING::_isDeath = true;
}



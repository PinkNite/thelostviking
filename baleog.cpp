#include "stdafx.h"
#include "baleog.h"
#include "arrow.h"

BALEOG::BALEOG()
{
}

BALEOG::~BALEOG()
{
}

void BALEOG::init(int posX, int posY, int width, int height)
{

	VIKING::init(posX, posY, static_cast<int>(VIKING_WIDTH), static_cast<int>(VIKING_HEIGHT));

	for (int i = 0; i < 11; i++)
	{
		_arTmpFrame[i] = 0;
	}

	initKeyAnimation();
	_jumpingTime = 0.0f;
	_isUsingSkillTwo = false;
	setIsOnGround(true);
	_isUsingSKillOne = false;



}

void BALEOG::update()
{
	if (!getIsOnGround())
	{
		_jumpingTime += TIMEMANAGER->getElpasedTime();
	}

	if (_jumpingTime >= 2.0f && VIKING::_behavior == static_cast<int>(VIKING::ACTION::FLY))
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
		_jumpingTime = 0.0F;
	}
	jump();

	if (VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER) ||
		VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER_OVER))
	{
		_jumpingTime = 0.0f;
	}

	if ((static_cast<int>(VIKING::ACTION::SKILL_ONE) == _behavior && VIKING::_state == static_cast<int>(VIKING::STATE::ACTION) &&
		VIKING::_pAnimation->getFramePlayingCount() == VIKING::_pAnimation->getFrameMaxCount() - 1) && !_isUsingSKillOne) 
	{
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE_END));
		//화살 나가게 하기

		updateArrow();
	}

	if (_pArrow)
	{
		_pArrow->update();
		if (_pArrow->deleteArrow())
		{
			_pArrow->release();
			delete _pArrow;
			_pArrow = nullptr;
		}
	}

	KEYANIMANAGER->update();
}
void BALEOG::updateArrow()
{
	float angle;
	if (static_cast<VIKING::DIRECTION>(VIKING::_direction) == VIKING::DIRECTION::LEFT)
	{
		angle = PI;
	}
	else {
		angle = 0.0f;
	}

	if (!_pArrow)
	{
		_pArrow = new ARROW;

		_pArrow->init(OBJECT::getPosX(), OBJECT::getPosY(), 32, 6, angle);
	}
	else {
		_pArrow->init(OBJECT::getPosX(), OBJECT::getPosY(), 32, 6, angle);
	}
}


void BALEOG::release()
{
}

void BALEOG::render(HDC hdc)
{
	VIKING::_pImg->aniRender(hdc, VIKING::_posX - VIKING::_width / 2, VIKING::_posY - VIKING::_height / 2, VIKING::_pAnimation);
	if (_pArrow)
	{
		_pArrow->render(hdc);
	}
}

void BALEOG::skillOne()
{
	setSkillOneAni();
	_isUsingSKillOne = true;
}

void BALEOG::skillTwo()
{
	setSkillTwoAni();
	_isUsingSkillTwo = true;
}

void BALEOG::setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight)
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

void BALEOG::skillOneEnd()
{

	_isUsingSKillOne = false;
}

bool BALEOG::getUseSkillOne()
{
	return _isUsingSKillOne;
}

bool BALEOG::getUseSkillTwo()
{
	return _isUsingSkillTwo;
}



void BALEOG::initKeyAnimation()
{
	VIKING::setImage(IMAGEMANAGER->findImage("baleog"));
	KEYANIMANAGER->addObject("baleog");

	//기본 아이들
	addRightAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL), 0, 2, 2, true);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL), 2, 2, 2, true);
	//텔레포트
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::TELEPORT), 4, 7, 2, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::TELEPORT), 11, 7, 2, false);
	//달리기
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN), 18, 8, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN), 26, 8, 2, true);
	//활
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE), 34, 6, 2, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE), 42, 6, 2, false);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE_END), 40, 2, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE_END), 48, 2, 2, false, callbackSpecialIdle);

	//검1
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO), 50, 4, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO), 54, 4, 2, false, callbackSpecialIdle);
	//검2
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_SPECIAL), 58, 4, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_SPECIAL), 62, 4, 2, false, callbackSpecialIdle);
	//사다리
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER), 66, 4, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER), 66, 4, 2, true);
	//사다리 오버
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER_OVER), 70, 2, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER_OVER), 70, 2, 2, true);
	//스페셜아이들
	addRightAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL), 72, 8, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL), 80, 8, 2, false, callbackSpecialIdle);
	//날기
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY), 88, 2, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY), 90, 2, 2, true);
	//밀기
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH), 92, 4, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH), 96, 4, 2, true);

	addRightAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::FAT), 100, 3, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::FAT), 103, 3, 2, false, callbackSpecialIdle);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::DAMEGE), 106, 1, 1, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::DAMEGE), 107, 1,	1, false, callbackSpecialIdle);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN),110, 6, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN), 116, 6, 2, false, callbackSpecialIdle);

	addRightAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::MUSIC), 122, 2, 2, false, callbackSpecialIdle);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::MUSIC), 124, 2, 2, false, callbackSpecialIdle);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN), 186, 1, 2, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN), 187, 1, 2, true);


	addLeftDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::ELECTRIC),
		152, 2, 2, false, 5, callbackDeath);
	addRightDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::ELECTRIC),
		150, 2, 2, false, 5, callbackDeath);

	addRightDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::DROP),
		176, 5, 2, false, callbackDeath);
	addLeftDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::DROP),
		181, 5, 2, false, callbackDeath);

	addRightDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::SHOT),
		188, 7, 2, false, callbackDeath);
	addLeftDeathAnimation(VIKING::STATE::DEATH_MOTION, static_cast<int>(VIKING::DEATH_MOTION::SHOT),
		195, 7, 2, false, callbackDeath);


	KEYANIMANAGER->findAnimation("baleog",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);

	KEYANIMANAGER->findAnimation("baleog",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);

	KEYANIMANAGER->findAnimation("baleog",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setFixedRender(true);

	KEYANIMANAGER->findAnimation("baleog",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setFixedRender(true);

	setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
}
string BALEOG::addString(string direction, string live, string action)
{
	string strTmp = "";

	strTmp += direction;
	strTmp += "_";
	strTmp += live;
	strTmp += "_";
	strTmp += action;
	return strTmp;
}
void BALEOG::addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(direction)], VIKING::_arLive[static_cast<int>(life)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);

}
void BALEOG::addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, pCallBack, this);

}
void BALEOG::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, pCallBack, this);
}
void BALEOG::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, pCallBack, this);
}
void BALEOG::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, pCallBack, this);
}
void BALEOG::addLeftAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addCoordinateFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
}
void BALEOG::addRightAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addCoordinateFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
}
void BALEOG::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}
void BALEOG::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}
void BALEOG::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}
void BALEOG::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("baleog", strTmp, "baleog", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}
void BALEOG::settingAniArray(int startFrame, int length)
{
	int frame = startFrame;
	for (int i = 0; i < length; i++)
	{
		_arTmpFrame[i] = frame;
		frame++;
	}
}


void BALEOG::setFallOut()
{
	setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
}

void BALEOG::setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior)
{
	string tmp = addString(VIKING::_arDirection[static_cast<int>(direction)],
		VIKING::_arLive[static_cast<int>(life)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	VIKING::_pAnimation = KEYANIMANAGER->findAnimation("baleog", tmp);

	VIKING::_direction = static_cast<int>(direction);
	VIKING::_life = static_cast<int>(life);
	VIKING::_state = static_cast<int>(state);
	VIKING::_behavior = behavior;

	VIKING::_pAnimation->start();
}

void BALEOG::setMovingAnimation(int direction)
{
	if (VIKING::STATE::IDLE == static_cast<VIKING::STATE>(_state))
	{
		setAnimation(static_cast<VIKING::DIRECTION>(direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN));
	}
	else if (direction != VIKING::_direction && static_cast<int>(VIKING::ACTION::RUN) == _behavior && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_state)) {
		if (direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN));
		}
		else {
			setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN));
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
	
	//벽이랑 충돌나면 밀기로
}

void BALEOG::setStopAnimation()
{
	if (static_cast<int>(VIKING::ACTION::RUN) == _behavior || static_cast<int>(VIKING::ACTION::SKILL_ONE_END) == _behavior || static_cast<int>(VIKING::ACTION::PUSH) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
}

void BALEOG::setSkillAnimation()
{
	if (VIKING::ACTION::FLY != static_cast<VIKING::ACTION>(VIKING::_behavior))
	{
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FLY));
	}
}

void BALEOG::pressGravity()
{
	if (VIKING::_behavior != static_cast<int>(VIKING::ACTION::ON_LADDER) &&
		VIKING::_behavior != static_cast<int>(VIKING::ACTION::ON_LADDER_OVER))
	{
		VIKING::OBJECT::setPosY(VIKING::OBJECT::getPosY() + _gravity * TIMEMANAGER->getElpasedTime());
	}
}

void BALEOG::falldownAnimation()
{
	if (static_cast<int>(VIKING::ACTION::FLY) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else if (static_cast<int>(VIKING::ACTION::FALLDOWN) == _behavior) {
		//callbackEricFallDown();
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER_OVER) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}

	_jumpingTime = 0.0F;
}

void BALEOG::setSkillOneAni()
{
	if ((static_cast<int>(VIKING::ACTION::RUN) == _behavior && VIKING::_state == static_cast<int>(VIKING::STATE::ACTION))||
		VIKING::_state == static_cast<int>(VIKING::STATE::IDLE )) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE));
	}
}

void BALEOG::setSkillTwoAni()
{
	if ((static_cast<int>(VIKING::ACTION::RUN) == _behavior && VIKING::_state == static_cast<int>(VIKING::STATE::ACTION)) ||
		VIKING::_state == static_cast<int>(VIKING::STATE::IDLE)) {
		int nRnd = RND->getInt(2);
		if (nRnd == 1)
		{
			setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO));
		}
		else
		{
			setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_SPECIAL));
		}
	}
}

void BALEOG::setPushWallAni(bool isCollisionWall)
{

	if (static_cast<STATE>(_state) == STATE::ACTION && static_cast<ACTION>(_behavior) == ACTION::RUN && isCollisionWall)
	{
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH));
	}
}





void BALEOG::callbackSpecialIdle(void * obj)
{
	BALEOG* pBalog = (BALEOG*)obj;
	pBalog->callbackbaleogSpecialIdle();
}

void BALEOG::callbackDeath(void * obj)
{
	BALEOG* pBalog = (BALEOG*)obj;
	pBalog->callbackBaleogDeath();
}

void BALEOG::callbackbaleogSpecialIdle()
{
	setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	_isUsingSkillTwo = false;
}

void BALEOG::callbackBaleogDeath()
{
	VIKING::_isDeath = true;
}


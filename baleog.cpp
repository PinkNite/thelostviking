#include "stdafx.h"
#include "baleog.h"

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
}

void BALEOG::update()
{
}

void BALEOG::release()
{
}

void BALEOG::render(HDC hdc)
{
}

void BALEOG::skillOne()
{
}

void BALEOG::skillTwo()
{
}

void BALEOG::setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight)
{
}

void BALEOG::initKeyAnimation()
{
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);

}

void BALEOG::addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void BALEOG::addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);

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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);
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

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);
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

	KEYANIMANAGER->addCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
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

	KEYANIMANAGER->addCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
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

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
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

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
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

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
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

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
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
}

void BALEOG::setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior)
{
}

void BALEOG::setMovingAnimation(int direction)
{
}

void BALEOG::setStopAnimation()
{
}

void BALEOG::setSkillAnimation()
{
}

void BALEOG::pressGravity()
{
}

void BALEOG::falldownAnimation()
{
}

void BALEOG::jump()
{
}

void BALEOG::fallDown()
{
}

void BALEOG::callbackRun(void * obj)
{
}

void BALEOG::callbackJump(void * obj)
{
}

void BALEOG::callbackHading(void * obj)
{
}

void BALEOG::callbackStun(void * obj)
{
}

void BALEOG::callbackBreath(void * obj)
{
}

void BALEOG::callbackEricRun()
{
}

void BALEOG::callbackEricJump()
{
}

void BALEOG::callbackEricHading()
{
}

void BALEOG::callbackEricStun()
{
}

void BALEOG::callbackEricBreath()
{
}

void BALEOG::callbackEricFallDown()
{
}

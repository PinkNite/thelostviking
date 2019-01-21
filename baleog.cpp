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
	return string();
}

void BALEOG::addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
}

void BALEOG::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void BALEOG::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void BALEOG::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void BALEOG::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void BALEOG::addLeftAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
}

void BALEOG::addRightAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
}

void BALEOG::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void BALEOG::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void BALEOG::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void BALEOG::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void BALEOG::settingAniArray(int startFrame, int length)
{
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

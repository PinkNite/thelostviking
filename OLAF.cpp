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

	_whereBlock = OLAFSHIELD::BLOCK_FRONT;

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

	KEYANIMANAGER->update();
}

void OLAF::release()
{
}

void OLAF::render(HDC hdc)
{
	RectangleMake(hdc, VIKING::getPosX() - VIKING::getWidth() / 2, VIKING::getPosY() - VIKING::getHeight() / 2, VIKING_WIDTH, VIKING_HEIGHT);

	VIKING::getImage()->aniRender(hdc, VIKING::getPosX() - VIKING::getWidth() / 2, VIKING::getPosY() - VIKING::getHeight() / 2, _pAnimation);
}

void OLAF::skillOne()
{
	// 방패가 앞에 있을경우: 추락 O
	if (_whereBlock == OLAFSHIELD::BLOCK_FRONT)
	{
		_whereBlock == OLAFSHIELD::BLOCK_TOP;
	}
	else // 방패가 머리에 있을경우: 추락 X
	{
		_whereBlock == OLAFSHIELD::BLOCK_FRONT;
	}
}

void OLAF::skillTwo()
{
	// 방패가 앞에 있을경우: 추락 O
	if (_whereBlock == OLAFSHIELD::BLOCK_FRONT)
	{
		_whereBlock == OLAFSHIELD::BLOCK_TOP;
	}
	else // 방패가 머리에 있을경우: 추락 X
	{
		_whereBlock == OLAFSHIELD::BLOCK_FRONT;
	}
}

void OLAF::setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight)
{
	if (VIKING::ACTION(VIKING::_behavior) != VIKING::ACTION::ON_LADDER)
	{
		setAnimation(VIKING::DIRECTION(_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, int(VIKING::ACTION::ON_LADDER));
	}
	else if (VIKING::ACTION(VIKING::_behavior)!= VIKING::ACTION::ON_LADDER_OVER)
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
	VIKING::_pAnimation;

	string idleNormal = VIKING::_vBehavior[int(VIKING::STATE::IDLE)][int(VIKING::IDLE::NORMAL)];
	{
		string blockTop = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_TOP)];
		addRightAliveAnimation(blockTop, idleNormal, 0, 1, 1, true);
		addLeftAliveAnimation(blockTop, idleNormal, 1, 1, 1, true);

		string blockFront = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_FRONT)];
		addRightAliveAnimation(blockFront, idleNormal, 2, 1, 1, true);
		addLeftAliveAnimation(blockFront, idleNormal, 3, 1, 1, true);
	}

	string actionTeleport = VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::TELEPORT)];
	{
		addRightAliveAnimation(actionTeleport, 4, 7, 3, false);
		addLeftAliveAnimation(actionTeleport, 11, 7, 3, false);
	}

	string idleNormal = VIKING::_vBehavior[int(VIKING::STATE::IDLE)][int(VIKING::IDLE::NORMAL)];
	{
		string blockTop = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_TOP)];
		addRightAliveAnimation(blockTop, idleNormal, 0, 1, 1, true);
		addLeftAliveAnimation(blockTop, idleNormal, 1, 1, 1, true);

		string blockFront = VIKING::_arOlafShield[int(VIKING::OLAFSHIELD::BLOCK_FRONT)];
		addRightAliveAnimation(blockFront, idleNormal, 2, 1, 1, true);
		addLeftAliveAnimation(blockFront, idleNormal, 3, 1, 1, true);
	}

}

string OLAF::addString(string direction, string live, string action)
{
	return string();
}

void OLAF::addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addLeftAliveAnimation(string block, string action, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addRightAliveAnimation(string block, string action, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop)
{
}

void OLAF::addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void OLAF::addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void OLAF::addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void OLAF::addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void OLAF::addLeftAliveAnimationCoordinate(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void OLAF::addRightAliveAnimationCoordinate(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
}

void OLAF::addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void OLAF::addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void OLAF::addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void OLAF::addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
}

void OLAF::settingAniArray(int startFrame, int length)
{
}

void OLAF::setFallOut()
{
}

void OLAF::setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior)
{
}

void OLAF::setMovingAnimation(int direction)
{
}

void OLAF::setStopAnimation()
{
}

void OLAF::setSkillAnimation()
{
}

void OLAF::pressGravity()
{
}

void OLAF::falldownAnimation()
{
}

void OLAF::fallDown()
{
}

void OLAF::callbackFallDown()
{
}

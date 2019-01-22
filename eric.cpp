#include "stdafx.h"
#include "eric.h"

ERIC::ERIC()
{
}

ERIC::~ERIC()
{
}

void ERIC::init(int posX, int posY, int width, int height)
{
	VIKING::init(posX, posY, static_cast<int>(VIKING_WIDTH), static_cast<int>(VIKING_HEIGHT));

	for (int i = 0; i < 11; i++)
	{
		_arTmpFrame[i] = 0;
	}

	initKeyAnimation();
	_jumpingTime = 0.0f;
	_saveY = 0;
	_jumpPower = 0.0f;
	_isUsingSkillTwo = false;
	setIsOnGround(true);
}

void ERIC::update()
{
	if (!getIsOnGround())
	{
		_jumpingTime += TIMEMANAGER->getElpasedTime();
	}

	if (_jumpingTime >= 2.0f && VIKING::_behavior == static_cast<int>(VIKING::ACTION::SKILL_TWO))
	{
		setFallOut();
	}
	else if (getIsOnGround() && VIKING::_behavior == static_cast<int>(VIKING::ACTION::FALLDOWN))
	{
		callbackEricFallDown();
		_jumpingTime = 0.0F;
	}
	jump();

	if (VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER)||
		VIKING::_behavior == static_cast<int>(VIKING::ACTION::ON_LADDER_OVER))
	{
		_jumpingTime = 0.0f;
	}

	KEYANIMANAGER->update();
}

void ERIC::release()
{
}

void ERIC::render(HDC hdc)
{
	RectangleMake(hdc,VIKING::getPosX() - VIKING::getWidth() / 2, VIKING::getPosY() - VIKING::getHeight() / 2, 64, 64);


	

	VIKING::getImage()->aniRender(hdc, VIKING::getPosX() - VIKING::getWidth() / 2, VIKING::getPosY() - VIKING::getHeight() / 2, _pAnimation);

	
}

void ERIC::skillOne()
{
	if (static_cast<VIKING::ACTION>(VIKING::_behavior) != VIKING::ACTION::RUN) return;
	setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE));

}

void ERIC::skillTwo()
{
	if (_isUsingSkillTwo) return;
	if (static_cast<VIKING::ACTION>(VIKING::_behavior) == VIKING::ACTION::SKILL_ONE)return;
	if (static_cast<VIKING::ACTION>(VIKING::_behavior) == VIKING::ACTION::FALLDOWN)	return;
	if (static_cast<VIKING::ACTION>(VIKING::_behavior) == VIKING::ACTION::SKILL_TWO)return;
	
	_jumpingTime = 0.0f;
	_jumpSpeed = 1500.0f;
	_jumpPower = Mins::presentPowerY(PI / 2.0f, _jumpSpeed);
	_isUsingSkillTwo = true;
	VIKING::OBJECT::setPosY(VIKING::OBJECT::getPosY() + _jumpPower * TIMEMANAGER->getElpasedTime());
	setIsOnGround(false);

	_saveY = VIKING::OBJECT::getPosY();
	setSkillAnimation();
}

void ERIC::setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight)
{
	if (static_cast<VIKING::ACTION>( VIKING::_behavior) != VIKING::ACTION::ON_LADDER && !isOverAni)
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

	_isUsingSkillTwo = false;
}

void ERIC::setPushWallAni(bool isCollisionWall)
{
	if (static_cast<STATE>(_state) == STATE::ACTION &&static_cast<ACTION>(_behavior) == ACTION::RUN && isCollisionWall)
	{
		if (static_cast<VIKING::DIRECTION>(VIKING::_direction) == DIRECTION::LEFT)
		{
			setAnimation(DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH));
		}
		else {
			setAnimation(DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH));

		}
	}
}

void ERIC::jump()
{
	if (!_isUsingSkillTwo) return;
	
	if (_jumpPower < _gravity)
	{
		_jumpPower += _gravity;

	}
	VIKING::OBJECT::setPosY(VIKING::OBJECT::getPosY() + _jumpPower * TIMEMANAGER->getElpasedTime());

	if (getIsOnGround())
	{
		//VIKING::OBJECT::setPosY(_saveY);
		_isUsingSkillTwo = false;
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
}

void ERIC::fallDown()
{
	//임시 처리하겠다.
	if (VIKING::_behavior == static_cast<int>(VIKING::ACTION::FALLDOWN))
	{
		//땅과 충돌하면 땅위에 있다고 변환시키고
		
		//callbackEricFallDown();//을 실행시킨다.

	}
}

void ERIC::initKeyAnimation()
{
	VIKING::setImage(IMAGEMANAGER->findImage("eric"));
	KEYANIMANAGER->addObject("eric");
	VIKING::_pAnimation;


	//애니메이션 삽입
	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::IDLE)][static_cast<int>(VIKING::IDLE::NORMAL)],
		0, 2, 1, true);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::IDLE)][static_cast<int>(VIKING::IDLE::NORMAL)],
		2, 2, 1, true);

	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::TELEPORT)],
		4, 7, 3, false);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::TELEPORT)],
		11, 7, 3, false);

	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		18, 3, 1, false);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		21, 3, 1, false);

	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		18, 3, 1, false);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		21, 3, 1, false);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN),
		24, 8, 10, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN),
		32, 8, 10, true);

	addRightAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE),
		40, 8, 5, true, false, callbackHading);
	addLeftAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE),
		48, 8, 5, true, false, callbackHading);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN),
		56, 11, 10, false, callbackStun);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN),
		67, 11, 10, false, callbackStun);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO),
		78, 4, 10, false, callbackJump);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO),
		82, 4, 10, false, callbackJump);

	addRightAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL),
		86, 3, 2, false, 3, callbackBreath);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL),
		89, 3, 2, false, 3, callbackBreath);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER),
		92, 4, 2, false);
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER_OVER),
		96, 2, 2, false);

	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER),
		92, 4, 2, false);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER_OVER),
		96, 2, 2, false);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH),
		98, 4, 5, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH),
		102, 4, 5, true);

	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::FAT),
		112, 3, 5, true);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::FAT),
		115, 3, 5, true);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN),
		178, 1, 1, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN),
		180, 1, 1, true);


	KEYANIMANAGER->findAnimation("eric",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);

	KEYANIMANAGER->findAnimation("eric",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);
	
	KEYANIMANAGER->findAnimation("eric",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setFixedRender(true);

	KEYANIMANAGER->findAnimation("eric",
		addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
			VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
			VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setFixedRender(true);




	//애니메이션이 끝나고 아니고로 결정되는 것들과
	//키입력으로 변하는것을 생각해야한다.


	setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));


	//좌우 이동 놓을때 아이들상태였으면 아이들?
	//하지만 액션이었을때는 아이들이나 액션으로
	//해딩 -> 스턴 -> 아이들
	//달리기 -> 한숨 or 해딩
	//점프 -> 아이들 or 달리기 or 떨어지기
	//떨어지기 -> 스턴 -> 아이들

}

string ERIC::addString(string direction, string live, string action)
{
	string strTmp = "";

	strTmp += direction;
	strTmp += "_";
	strTmp += live;
	strTmp += "_";
	strTmp += action;
	return strTmp;
}

void ERIC::addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(direction)], VIKING::_arLive[static_cast<int>(life)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);

}

void ERIC::addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//키스트링 만들기
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//배열 프레임 맞추어서 만들기
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
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
void ERIC::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
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
void ERIC::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
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
void ERIC::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
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

void ERIC::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
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
void ERIC::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
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
void ERIC::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
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
void ERIC::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
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
void ERIC::addLeftAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
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
void ERIC::addRightAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
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

void ERIC::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
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

void ERIC::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
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

void ERIC::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
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

void ERIC::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
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

void ERIC::settingAniArray(int startFrame, int length)
{
	int frame = startFrame;
	for (int i = 0; i < length; i++)
	{
		_arTmpFrame[i] = frame;
		frame++;
	}
}



void ERIC::setFallOut()
{
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
	}
}

void ERIC::setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior)
{
	string tmp = addString(VIKING::_arDirection[static_cast<int>(direction)],
		VIKING::_arLive[static_cast<int>(life)],
		VIKING::_vBehavior[static_cast<int>(state)][behavior]);
	VIKING::_pAnimation = KEYANIMANAGER->findAnimation("eric",tmp);

	VIKING::_direction = static_cast<int>(direction);
	VIKING::_life = static_cast<int>(life);
	VIKING::_state = static_cast<int>(state);
	VIKING::_behavior = behavior;

	VIKING::_pAnimation->start();

}

void ERIC::setMovingAnimation(int direction)
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
	else if (direction != VIKING::_direction && static_cast<int>(VIKING::ACTION::SKILL_TWO) == _behavior && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_state))
	{
		if (direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO));
		}
		else {
			setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO));
		}
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER) == _behavior && VIKING::STATE::ACTION == static_cast<VIKING::STATE>(_state)) {
		if (direction == static_cast<int>(VIKING::DIRECTION::LEFT))
		{
			setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO));
		}
		else {
			setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO));
		}
	}
	//벽이랑 충돌나면 밀기로
}

void ERIC::setStopAnimation()
{
	if (static_cast<int>(VIKING::ACTION::RUN) == _behavior || static_cast<int>(VIKING::ACTION::PUSH) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL));
	}

	//_jumpingTime = 0.0F;

}

void ERIC::setSkillAnimation()
{
	if (VIKING::ACTION::SKILL_TWO != static_cast<VIKING::ACTION>(VIKING::_behavior))
	{
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO));
	}
}

void ERIC::pressGravity()
{
	if (VIKING::_behavior != static_cast<int>(VIKING::ACTION::ON_LADDER) &&
		VIKING::_behavior != static_cast<int>(VIKING::ACTION::ON_LADDER_OVER))
	{
		VIKING::OBJECT::setPosY(VIKING::OBJECT::getPosY() + _gravity * TIMEMANAGER->getElpasedTime());
	}
}

void ERIC::falldownAnimation()
{
	if (static_cast<int>(VIKING::ACTION::SKILL_TWO) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else if (static_cast<int>(VIKING::ACTION::FALLDOWN) == _behavior) {
		callbackEricFallDown();
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER_OVER) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else if (static_cast<int>(VIKING::ACTION::ON_LADDER) == _behavior) {
		setAnimation(static_cast<VIKING::DIRECTION>(VIKING::_direction), VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}

	_jumpingTime = 0.0F;
}


void ERIC::callbackRun(void *obj)
{
	//해딩
	//아이들
	//점프
	//한숨
}

void ERIC::callbackJump(void *obj)
{

	ERIC* pEric = (ERIC*)obj;
	pEric->callbackEricJump();

}

void ERIC::callbackHading(void *obj)
{
	//스턴
	//달리기
	//한숨아이들
	ERIC* pEric = (ERIC*)obj;
	pEric->callbackEricHading();
}

void ERIC::callbackStun(void * obj)
{
	ERIC* pEric = (ERIC*)obj;
	pEric->callbackEricStun();
}

void ERIC::callbackBreath(void * obj)
{
	//한숨쉰후 아이들 복귀
	ERIC* pEric = (ERIC*)obj;
	pEric->callbackEricBreath();
}


void ERIC::callbackEricRun()
{
}

void ERIC::callbackEricJump()
{
	//달리기
	//아이들
	//떨어지기
	//아이들로 바꾸고 달리게 한다?



}

void ERIC::callbackEricHading()
{
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL));
	}
}

void ERIC::callbackEricStun()
{
	//스턴후 아이들
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
}

void ERIC::callbackEricBreath()
{
	//스턴후 아이들
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}

}

void ERIC::callbackEricFallDown()
{
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN));
	}
	setIsOnGround(true);
}

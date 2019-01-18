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
	OBJECT::init(posX, posY, width, height);
	_hp = 3;
	_itemCount = 0;
	OBJECT::setImage(IMAGEMANAGER->findImage("eric"));
	_speed = 100.0f;
	_state = OBJECT::ERIC_STATE::LEFT_IDLE;
	initAnimation();
	_jumpPower = 0.0f;
	_moveAngleY = 0.0f;
	_moveAngleX = 0.0f;
	_offsetX = 0;
	_offsetY = 0;
	_movingJump = false;
	_isDeath = false;
	_isOnGround = true;
	_isPreviousLeft = false;
	_isStartFalldown = false;
	_falldownTimer = 0;
	_isJumpimg = false;
}

void ERIC::update()
{

	jump();
	
	affectGravity();
	notOut();
	fallDown();



	KEYANIMANAGER->update();

}

void ERIC::release()
{
}

void ERIC::render(HDC hdc)
{


	OBJECT::getIamge()->aniRender(hdc, OBJECT::getPosX() - OBJECT::getWidth() / 2, OBJECT::getPosY() - OBJECT::getHeight() / 2, _pAnimation);
}

void ERIC::moveLeft()
{

	if (_isMoveStart)
	{
		_speed = _minSpeed;
		setMoveStart(false);
		_moveAngleX = 0.0f;
	}

	_offsetX = (Mins::presentPowerX(_moveAngleX, _speed) * TIMEMANAGER->getElpasedTime());
	OBJECT::setPosX(OBJECT::getPosX() - _offsetX);

	if (_speed < _maxSpeed)
	{
		_speed += _upSpeed;
	}
	_isPreviousLeft = true;
}

void ERIC::moveRight()
{
	if (_isMoveStart)
	{
		_speed = _minSpeed;
		setMoveStart(false);
		_moveAngleX = PI;
	}

	_offsetX = -(Mins::presentPowerX(_moveAngleX, _speed) * TIMEMANAGER->getElpasedTime());
	OBJECT::setPosX(OBJECT::getPosX() + _offsetX);

	if (_speed < _maxSpeed)
	{
		_speed += _upSpeed;
	}

	_isPreviousLeft = false;
}

void ERIC::moveUp()
{
	_speed = _minSpeed;
	_moveAngleY = PI / 2.0f;
	_offsetY = -(Mins::presentPowerY(_moveAngleY, _speed) * TIMEMANAGER->getElpasedTime());
	OBJECT::setPosY((OBJECT::getPosY() - _offsetY));

	_pAnimation->setClickVariable(1);
}

void ERIC::moveDown()
{
	_speed = _minSpeed;
	_moveAngleY = PI2 - PI / 2.0f;
	_offsetY = Mins::presentPowerY(_moveAngleY, _speed) * TIMEMANAGER->getElpasedTime();
	OBJECT::setPosY((OBJECT::getPosY() + _offsetY));

	_pAnimation->setClickVariable(-1);
}

void ERIC::jump()
{
	if (!_isJumpimg)return;

	_posY += _jumpPower;
	if (_jumpAngle <= PI2 - PI / 2.0f)
	{
		_jumpAngle += PI2 / 90.0f;
	}

	_jumpPower = Mins::presentPowerY(_jumpAngle, _upPower)*TIMEMANAGER->getElpasedTime();
	_offsetY = _jumpPower;

	if (_state == OBJECT::ERIC_STATE::LEFT_JUMP && _movingJump)
	{
		//moveLeft();
	}
	else if (_state == OBJECT::ERIC_STATE::RIGHT_JUMP&& _movingJump)
	{
		//moveRight();
	}

	//땅 착지하면 점핑을 false로 바꾸어야 하는데 지금 바닥이 없다 픽셀충돌 그렇기에 기존 위치를 받아서 임시로 처리하겠다.
	if (_posY >= _startPosY)
	{
		_posY = _startPosY;
		_isJumpimg = false;


		if (_state == OBJECT::ERIC_STATE::LEFT_JUMP  && KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			setEricState(OBJECT::ERIC_STATE::LEFT_RUN);
		}
		else if (_state == OBJECT::ERIC_STATE::LEFT_JUMP)
		{
			setEricState(OBJECT::ERIC_STATE::LEFT_IDLE);
		}
		else if (_state == OBJECT::ERIC_STATE::RIGHT_JUMP && KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			setEricState(OBJECT::ERIC_STATE::RIGHT_RUN);
		}
		else if (_state == OBJECT::ERIC_STATE::RIGHT_JUMP)
		{
			setEricState(OBJECT::ERIC_STATE::RIGHT_IDLE);

		}

		_movingJump = false;
	}
}

float ERIC::getSpeedX()
{
	return _offsetX;
}

float ERIC::getSpeedY()
{
	return _offsetY;
}



void ERIC::initAnimation()
{
	initAniFrame();
	KEYANIMANAGER->addObject("eric");
	for (int i = 0; i < static_cast<int>(OBJECT::ERIC_STATE::MAX); i++)
	{
		if (static_cast<int>(OBJECT::ERIC_STATE::LEFT_FALLDOWN) == i ||
			static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FALLDOWN) == i)
		{
			KEYANIMANAGER->addArrayFrameAnimation("eric", _arStrAniState[i], "eric", _vAniFrame[i], 1, 1, _arIsLoop[i]);

		}
		else {
			KEYANIMANAGER->addArrayFrameAnimation("eric", _arStrAniState[i], "eric", _vAniFrame[i], _arAniFrameCount[i], 10, _arIsLoop[i]);

		}
	}
	KEYANIMANAGER->findAnimation("eric", _arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::ON_LADDER_OVER)])->setClickRender(TRUE);
	KEYANIMANAGER->findAnimation("eric", _arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::ON_LADDER)])->setClickRender(TRUE);

	_pAnimation = KEYANIMANAGER->findAnimation("eric", _arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_IDLE)]);
	_pAnimation->start();
}

void ERIC::initAniFrame()
{
	//아이들 순간이동 공포
	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_IDLE)] = "RIGHT_IDLE";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_IDLE)] = 2;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_IDLE)] = "LEFT_IDLE";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_IDLE)] = 2;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_TELEPORT)] = "RIGHT_TELEPORT";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_TELEPORT)] = 7;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_TELEPORT)] = "LEFT_TELEPORT";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_TELEPORT)] = 7;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_AFFRIGHT)] = "RIGHT_AFFRIGHT";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_AFFRIGHT)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_AFFRIGHT)] = "LEFT_AFFRIGHT";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_AFFRIGHT)] = 3;

	//달리기 해딩 해딩스턴
	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_RUN)] = "RIGHT_RUN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_RUN)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_RUN)] = "LEFT_RUN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_RUN)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_HADING)] = "RIGHT_HADING";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_HADING)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_HADING)] = "LEFT_HADING";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_HADING)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_HADING_STUN)] = "RIGHT_HADING_STUN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_HADING_STUN)] = 11;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_HADING_STUN)] = "LEFT_HADING_STUN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_HADING_STUN)] = 11;

	//점프 한숨 사다리 밀기
	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_JUMP)] = "RIGHT_JUMP";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_JUMP)] = 4;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_JUMP)] = "LEFT_JUMP";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_JUMP)] = 4;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_SIGN)] = "RIGHT_SIGN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_SIGN)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_SIGN)] = "LEFT_SIGN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_SIGN)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::ON_LADDER)] = "ON_LADDER";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::ON_LADDER)] = 4;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::ON_LADDER_OVER)] = "ON_LADDER_OVER";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::ON_LADDER_OVER)] = 2;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_PUSH)] = "RIGHT_PUSH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_PUSH)] = 4;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_PUSH)] = "LEFT_PUSH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_PUSH)] = 4;

	//땅구르기 아이들 풍선아이들 기타아이들
	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FOOT_ROLL)] = "RIGHT_FOOT_ROLL";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FOOT_ROLL)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FOOT_ROLL)] = "LEFT_FOOT_ROLL";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FOOT_ROLL)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_BOOLEAN)] = "RIGHT_BOOLEAN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_BOOLEAN)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_BOOLEAN)] = "LEFT_BOOLEAN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_BOOLEAN)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_GUITAR)] = "RIGHT_GUITAR";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_GUITAR)] = 3;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_GUITAR)] = "LEFT_GUITAR";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_GUITAR)] = 3;

	//떨어지다
	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FALLDOWN)] = "RIGHT_FALLDOWN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FALLDOWN)] = 2;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FALLDOWN)] = "LEFT_FALLDOWN";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FALLDOWN)] = 2;

	//죽음 고민중 다같으니 한번에 처리?
	//스켈 물 전기
	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_SKELETON_DEATH)] = "RIGHT_SKELETON_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_SKELETON_DEATH)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_SKELETON_DEATH)] = "LEFT_SKELETON_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_SKELETON_DEATH)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_WATER_DEATH)] = "RIGHT_WATER_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_WATER_DEATH)] = 5;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_WATER_DEATH)] = "LEFT_WATER_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_WATER_DEATH)] = 5;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_ELECTRIC_DEATH)] = "RIGHT_ELECTRIC_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_ELECTRIC_DEATH)] = 2;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_ELECTRIC_DEATH)] = "LEFT_ELECTRIC_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_ELECTRIC_DEATH)] = 2;

	//불 프레스 빠짐 떨어짐 레이저
	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FIRE_DEATH)] = "RIGHT_FIRE_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FIRE_DEATH)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FIRE_DEATH)] = "LEFT_FIRE_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FIRE_DEATH)] = 8;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_PRESS_DEATH)] = "RIGHT_PRESS_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_PRESS_DEATH)] = 4;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_PRESS_DEATH)] = "LEFT_PRESS_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_PRESS_DEATH)] = 4;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FALLIN_DEATH)] = "RIGHT_FALLIN_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FALLIN_DEATH)] = 7;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FALLIN_DEATH)] = "LEFT_FALLIN_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FALLIN_DEATH)] = 7;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FALLDOWN_DEATH)] = "RIGHT_FALLDOWN_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_FALLDOWN_DEATH)] = 6;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FALLDOWN_DEATH)] = "LEFT_FALLDOWN_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_FALLDOWN_DEATH)] = 6;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_LAZER_DEATH)] = "RIGHT_LAZER_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::RIGHT_LAZER_DEATH)] = 7;

	_arStrAniState[static_cast<int>(OBJECT::ERIC_STATE::LEFT_LAZER_DEATH)] = "LEFT_LAZER_DEATH";
	_arAniFrameCount[static_cast<int>(OBJECT::ERIC_STATE::LEFT_LAZER_DEATH)] = 7;

	int nTmp = 0;


	for (int i = 0; i < static_cast<int>(OBJECT::ERIC_STATE::MAX); i++)
	{
		_vAniFrame.push_back(new int[_arAniFrameCount[i]]);
		for (int j = 0; j < _arAniFrameCount[i]; j++)
		{
			_vAniFrame[i][j] = nTmp;
			nTmp++;
		}
	}


	for (int i = 0; i < static_cast<int>(OBJECT::ERIC_STATE::MAX); i++)
	{
		_arIsLoop[i] = false;
	}
	_arIsLoop[0] = true;
	_arIsLoop[1] = true;
	_arIsLoop[6] = true;
	_arIsLoop[7] = true;
	_arIsLoop[14] = true;
	_arIsLoop[15] = true;
	_arIsLoop[17] = true;
	_arIsLoop[18] = true;
	_arIsLoop[29] = true;
	_arIsLoop[30] = true;
	_arIsLoop[35] = true;
	_arIsLoop[36] = true;
}

void ERIC::skillOne()
{
	if (_isJumpimg) return;
	_startPosY = _posY;
	_jumpAngle = PI / 2.0f;
	_upPower = 500.0f;
	_jumpPower = Mins::presentPowerY(_jumpAngle, _upPower)*TIMEMANAGER->getElpasedTime();
	_turn = -1;

	if (_state == OBJECT::ERIC_STATE::LEFT_RUN)
	{
		_movingJump = true;
		setEricState(OBJECT::ERIC_STATE::LEFT_JUMP);
	}
	else if (_state == OBJECT::ERIC_STATE::LEFT_IDLE)
	{
		setEricState(OBJECT::ERIC_STATE::LEFT_JUMP);

	}
	else if (_state == OBJECT::ERIC_STATE::RIGHT_RUN)
	{
		_movingJump = true;

		setEricState(OBJECT::ERIC_STATE::RIGHT_JUMP);
	}
	else if (_state == OBJECT::ERIC_STATE::RIGHT_IDLE)
	{
		setEricState(OBJECT::ERIC_STATE::RIGHT_JUMP);

	}
	else if (_state == OBJECT::ERIC_STATE::ON_LADDER || _state == OBJECT::ERIC_STATE::ON_LADDER_OVER)
	{
		if (_isPreviousLeft)
		{
			setEricState(OBJECT::ERIC_STATE::LEFT_JUMP);
		}
		else
		{
			setEricState(OBJECT::ERIC_STATE::RIGHT_JUMP);
		}
	}
	setJumping(true);
}

void ERIC::skillTwo()
{
	if (_state == OBJECT::ERIC_STATE::LEFT_RUN)
	{
		setEricState(OBJECT::ERIC_STATE::LEFT_HADING);
	}
	else if (_state == OBJECT::ERIC_STATE::RIGHT_RUN)
	{
		setEricState(OBJECT::ERIC_STATE::RIGHT_HADING);
	}
}

OBJECT::ERIC_STATE ERIC::getEricState()
{
	return _state;
}

void ERIC::setEricState(OBJECT::ERIC_STATE ericState)
{
	_state = ericState;
	_pAnimation = KEYANIMANAGER->findAnimation("eric", _arStrAniState[static_cast<int>(_state)]);
	_pAnimation->start();
}

void ERIC::setJumpPower(float power)
{
	_upPower = power;
}

void ERIC::setLadderAni(int nLadderAni)
{
	_pAnimation->setClickVariable(nLadderAni);
}

void ERIC::notOut()
{
	//여기는 임시 코드입니다. 픽셀 충돌이 없기에 넣어진 코드입니다.
	if (_posY >= MAPSIZEY- 100)
	{
		_posY = MAPSIZEY - 100;

		if (!_isOnGround)
		{
			if (_isPreviousLeft && _state == OBJECT::ERIC_STATE::LEFT_FALLDOWN)
			{
				setEricState(OBJECT::ERIC_STATE::LEFT_HADING_STUN);
			}
			else if (!_isPreviousLeft && _state == OBJECT::ERIC_STATE::RIGHT_FALLDOWN) {
				setEricState(OBJECT::ERIC_STATE::RIGHT_HADING_STUN);
			}
			else if (_isPreviousLeft) {
				setEricState(OBJECT::ERIC_STATE::LEFT_IDLE);
			}
			else if (!_isPreviousLeft) {
				setEricState(OBJECT::ERIC_STATE::RIGHT_IDLE);
			}
		}


		_isOnGround = true;

	}
	else {
		_isOnGround = false;
	}

}

void ERIC::affectGravity()
{
	if (_state != OBJECT::ERIC_STATE::ON_LADDER &&
		_state != OBJECT::ERIC_STATE::ON_LADDER_OVER && 
		!_isDeath &&
		!_isOnGround)
	{
		_falldownTimer += TIMEMANAGER->getElpasedTime();

		_posY += _gravity * TIMEMANAGER->getElpasedTime();

		if (_isStartFalldown)
		{
			_isStartFalldown = false;
			if (_isPreviousLeft)
			{
				setEricState(OBJECT::ERIC_STATE::LEFT_JUMP);
			}
			else {
				setEricState(OBJECT::ERIC_STATE::RIGHT_JUMP);
			}
		}
	}
	else {
		_falldownTimer = 0;

		_isStartFalldown = true;
	}
}

void ERIC::fallDown()
{
	if (_falldownTimer > 2 &&
		_state != OBJECT::ERIC_STATE::LEFT_JUMP &&
		_state != OBJECT::ERIC_STATE::RIGHT_JUMP)
	{
		if(_isPreviousLeft)
		{
			setEricState(OBJECT::ERIC_STATE::LEFT_FALLDOWN);
		}
		else {
			setEricState(OBJECT::ERIC_STATE::RIGHT_FALLDOWN);
		}
	}
}

bool ERIC::getJump()
{
	return _isJumpimg;
}

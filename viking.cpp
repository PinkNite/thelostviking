#include "stdafx.h"
#include "viking.h"

VIKING::VIKING()
{
}

VIKING::~VIKING()
{
}

void VIKING::init(int posX, int posY, int width, int height)
{
	OBJECT::init(posX, posY, width, height);
	_nHealthPoint = 3;
	//좌우
	_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)] = "LEFT";
	_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)] = "RIGHT";

	//죽었다 살았다
	_arLive[static_cast<int>(VIKING::LIFE::ALIVE)] = "ALIVE";
	_arLive[static_cast<int>(VIKING::LIFE::DEATH)] = "DEATH";

	//아이들 + 행동
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("NORMAL");
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("FAT");
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("MUSIC");
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("SPECIAL");

	//액션 + 행동
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("TELEPORT");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("RUN");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("FALLDOWN");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("STUN");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("PUSH");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("ON_LADDER");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("ON_LADDER_OVER");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("DAMAGE");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("SKILL_ONE");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("SKILL_TWO");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("SKILL_SPECIAL"); 
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("FLY");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("FLY_TURN");
	_vBehavior[static_cast<int>(VIKING::STATE::ACTION)].push_back("SKILL_ONE_END");

	
	//죽음 + 상태
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("ELECTIRC");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("FIRE");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("PRESS");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("WATER");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("DROP");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("SHOT");

	//올라프 방패 방향
	_arOlafShield[static_cast<const int>(VIKING::OLAFSHIELD::BLOCK_FRONT)] = "BLOCK_FRONT";
	_arOlafShield[static_cast<const int>(VIKING::OLAFSHIELD::BLOCK_TOP)] = "BLOCK_TOP";

	_speed = 300.0f;
	_maxSpeed = 560.0f;
	_minSpeed = 300.0f;

	_isDeath = false;
}



void VIKING::setImage(image * pImage)
{
	OBJECT::setImage(pImage);
}

void VIKING::moveLeft(float acceleration)
{
	if (DIRECTION::LEFT == static_cast<DIRECTION>(_direction)) {

		if (_speed + acceleration <= _maxSpeed)
		{
			_speed += acceleration;
		}

		float fDistance = Mins::presentPowerX(0.0f, _speed) * TIMEMANAGER->getElpasedTime();
		OBJECT::setPosX(OBJECT::getPosX() - fDistance);
	}

}

void VIKING::moveRight(float acceleration)
{
	if (DIRECTION::RIGHT == static_cast<DIRECTION>(_direction))
	{
		if (_speed + acceleration <= _maxSpeed)
		{
			_speed += acceleration;
		}
		float fDistance = -(Mins::presentPowerX(PI, _speed) * TIMEMANAGER->getElpasedTime());
		OBJECT::setPosX(OBJECT::getPosX() + fDistance);
	}

}

void VIKING::moveUp(float acceleration)
{
	float fDistance = -(Mins::presentPowerY(PI / 2.0f, _speed) * TIMEMANAGER->getElpasedTime());
	OBJECT::setPosY(OBJECT::getPosY() - fDistance);
}

void VIKING::moveDown(float acceleration)
{
	float fDistance = Mins::presentPowerY(PI2 - PI / 2.0f, _speed) * TIMEMANAGER->getElpasedTime();
	OBJECT::setPosY(OBJECT::getPosY() + fDistance + acceleration);
}

bool VIKING::stunStop()
{
	if (static_cast<VIKING::ACTION>(_behavior) == VIKING::ACTION::STUN && static_cast<VIKING::STATE>(_state) == VIKING::STATE::ACTION)
	{
		return true;
	}

	return false;
}

void VIKING::resetSpeed()
{
	_speed = _minSpeed;
}

//점프는 에릭에서해야한다!!!!
void VIKING::skillOne()
{
	//D스킬
	//에릭 -> 해딩
	//발로그 -> 활
	//올라프 -> 방패 방향 전환 -> 애니메이션은 나는것으로 한다!!!!
}

void VIKING::skillTwo()
{
	//F스킬
	//에릭 -> 점프
	//발로그 -> 검
	//올라프 -> 방패 방향 전환 -> 애니메이션은 나는 방향 전환으로 한다.
}

//애니메이션은 체크는 안에서 어떻게든 처리하자!!!!!!!!!!!!!!!!!!
void VIKING::setMovingAnimation(int direction)
{
	//아이들 상태라면 걸으라고 하고
	//

	
}

void VIKING::setStopAnimation()
{
	
}

void VIKING::falldownAnimation()
{
}

void VIKING::setSkillAnimation()
{
}

void VIKING::setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight)
{
}

void VIKING::pressGravity()
{
}

void VIKING::setPushWallAni(bool isCollisionWall)
{

}

void VIKING::setSkillOneAni()
{
}

void VIKING::setSkillTwoAni()
{
}

void VIKING::skillOneEnd()
{
}

bool VIKING::getUseSkillOne()
{
	return false;
}

bool VIKING::getUseSkillTwo()
{
	return false;
}

void VIKING::death(DEATH_MOTION death)
{
	_life = static_cast<int>(LIFE::DEATH);
	_behavior = static_cast<int>(death);
	_state = static_cast<int>(STATE::DEATH_MOTION);
}

void VIKING::setDeathMotion(int viking)
{
	string strTmp = "";
	strTmp.append(_arDirection[_direction]);
	strTmp.append("_");
	strTmp.append(_arLive[_life]);
	strTmp.append("_");
	strTmp.append(_vBehavior[_state][_behavior]);

	if (viking == 0)
	{
		_pAnimation = KEYANIMANAGER->findAnimation("eric", strTmp);

	}
	else if (viking == 1)
	{
		_pAnimation = KEYANIMANAGER->findAnimation("baleog", strTmp);

	}
	else if (viking == 2)
	{
		_pAnimation = KEYANIMANAGER->findAnimation("olaf", strTmp);
	}
}


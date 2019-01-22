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
	//�¿�
	_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)] = "LEFT";
	_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)] = "RIGHT";

	//�׾��� ��Ҵ�
	_arLive[static_cast<int>(VIKING::LIFE::ALIVE)] = "ALIVE";
	_arLive[static_cast<int>(VIKING::LIFE::DEATH)] = "DEATH";

	//���̵� + �ൿ
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("NORMAL");
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("FAT");
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("MUSIC");
	_vBehavior[static_cast<int>(VIKING::STATE::IDLE)].push_back("SPECIAL");

	//�׼� + �ൿ
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


	//���� + ����
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("ELECTIRC");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("FIRE");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("PRESS");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("WATER");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("DROP");
	_vBehavior[static_cast<int>(VIKING::STATE::DEATH_MOTION)].push_back("SHOP");

	//�ö��� ���� ����
	_arOlafShield[static_cast<const int>(VIKING::OLAFSHIELD::BLOCK_TOP)] = "BLOCK_TOP";
	_arOlafShield[static_cast<const int>(VIKING::OLAFSHIELD::BLOCK_FRONT)] = "BLOCK_FRONT";

	_speed = 300.0f;
	_maxSpeed = 560.0f;
	_minSpeed = 300.0f;
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

void VIKING::resetSpeed()
{
	_speed = _minSpeed;
}

//������ ���������ؾ��Ѵ�!!!!
void VIKING::skillOne()
{
	//D��ų
	//���� -> �ص�
	//�߷α� -> Ȱ
	//�ö��� -> ���� ���� ��ȯ -> �ִϸ��̼��� ���°����� �Ѵ�!!!!
}

void VIKING::skillTwo()
{
	//F��ų
	//���� -> ����
	//�߷α� -> ��
	//�ö��� -> ���� ���� ��ȯ -> �ִϸ��̼��� ���� ���� ��ȯ���� �Ѵ�.
}

//�ִϸ��̼��� üũ�� �ȿ��� ��Ե� ó������!!!!!!!!!!!!!!!!!!
void VIKING::setMovingAnimation(int direction)
{
	//���̵� ���¶�� ������� �ϰ�
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

void VIKING::setSkillOneAni()
{
}

void VIKING::setSkillTwoAni()
{
}


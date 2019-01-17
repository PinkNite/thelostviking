#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}

void enemy::init(int posX, int posY, int width, int height)
{
	OBJECT::init(posX, posY, width, height);
	_hp = 1;

}

void enemy::update()
{
}

void enemy::release()
{
}

void enemy::render(HDC hdc)
{
}

void enemy::setEnemyType(ENEMY_TYPE type)
{
	switch (_type)
	{
	case enemy::ENEMY_TYPE::RED:
		OBJECT::setImage(IMAGEMANAGER->findImage("redEnemy"));
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::BLUE:
		OBJECT::setImage(IMAGEMANAGER->findImage("blueEnemy"));
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::GREEN:
		OBJECT::setImage(IMAGEMANAGER->findImage("greenEnemy"));
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::BLUE_BALL:
		OBJECT::setImage(IMAGEMANAGER->findImage("blueBallEnemy"));
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::YELLOW_BALL:
		OBJECT::setImage(IMAGEMANAGER->findImage("yellowBallEnemy"));
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::MIRA:
		OBJECT::setImage(IMAGEMANAGER->findImage("miraEnemy"));
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::CANNON:
		OBJECT::setImage(IMAGEMANAGER->findImage("cannonEnemy"));
		_moveType = ENEMY_MOVE_TYPE::STAND;
		break;
	case enemy::ENEMY_TYPE::sNAIL:
		OBJECT::setImage(IMAGEMANAGER->findImage("snailEnemy"));
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		break;
	case enemy::ENEMY_TYPE::GOLIATH:
		OBJECT::setImage(IMAGEMANAGER->findImage("goliathEnemy"));
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		break;
	case enemy::ENEMY_TYPE::BOSS:
		OBJECT::setImage(IMAGEMANAGER->findImage("bossEnemy"));
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		break;
	}

}

void enemy::moveLeft()
{
}

void enemy::moveRight()
{
}

void enemy::moveUp()
{
}

void enemy::moveDown()
{
}

void enemy::jump()
{
}

float enemy::getSpeedX()
{
	return 0.0f;
}

float enemy::getSpeedY()
{
	return 0.0f;
}

void enemy::initAnimation()
{
}

void enemy::initAniFrame()
{
}

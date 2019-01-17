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
		_typeName = "redEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::BLUE:
		_typeName = "blueEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::GREEN:
		_typeName = "greenEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::BLUE_BALL:
		_typeName = "blueBallEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::YELLOW_BALL:
		_typeName = "yellowBallEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::MIRA:
		_typeName = "miraEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		break;
	case enemy::ENEMY_TYPE::CANNON:
		_typeName = "cannonEnemy";
		_moveType = ENEMY_MOVE_TYPE::STAND;
		break;
	case enemy::ENEMY_TYPE::sNAIL:
		_typeName = "snailEnemy";
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		break;
	case enemy::ENEMY_TYPE::GOLIATH:
		_typeName = "goliathEnemy";
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		break;
	case enemy::ENEMY_TYPE::BOSS:
		_typeName = "bossEnemy";
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		break;
	}

	OBJECT::setImage(IMAGEMANAGER->findImage(_typeName));
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
	initAniFrame();
	KEYANIMANAGER->addObject(_typeName);


}

void enemy::initAniFrame()
{
	int* frameNum;
	switch (_type)
	{
	case enemy::ENEMY_TYPE::RED: case enemy::ENEMY_TYPE::BLUE:

		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		frameNum = new int [1] {0};
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		frameNum = new int [1] {10};
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 4;
		frameNum = new int [4] {0, 1, 2, 3};
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 4;
		frameNum = new int [4] {7, 8, 9, 10};
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_RIGHT)] = "ATTACK_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_RIGHT)] = 7;
		frameNum = new int [7] {14, 15, 16, 17, 18, 19, 20};
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_LEFT)] = "ATTACK_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_LEFT)] = 7;
		frameNum = new int [7] {21, 22, 23, 24, 25, 26, 27};
		_vAniFrame.push_back(frameNum);

		break;
	case enemy::ENEMY_TYPE::GREEN:

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

#include "stdafx.h"
#include "enemy.h"


ENEMY::ENEMY()
{
}


ENEMY::~ENEMY()
{
}

void ENEMY::init(int posX, int posY, int width, int height, float speed, ENEMY_TYPE type)
{
	OBJECT::init(posX, posY, width, height);
	_hp = 1;
	_speed = speed;
	
	_startX = posX;
	
	_moveRange = 200.0f;
	
	_endX = _startX + _moveRange;

	_attackRange = 200.0f;

	setEnemyType(type);
}

void ENEMY::update()
{
	if (_moveType != ENEMY_MOVE_TYPE::STAND)
	{
		if (_startX >= OBJECT::_posX)
		{
			stateUpdate(ENEMY_STATE::MOVE_RIGHT);
		}
		
		if (OBJECT::_posX >= _endX )
		{
			stateUpdate(ENEMY_STATE::MOVE_LEFT);
		}

	}
	else
	{
		// TODO: 플레이어가 근접한경우 처리
		float _deltaX = abs(_startX - OBJECT::_posX);
		if (OBJECT::_posX - _deltaX >= -_attackRange)
		{
			//stateUpdate(ENEMY_STATE::ATTACK_LEFT);
		}

		if (OBJECT::_posX - _deltaX <= _attackRange)
		{
			stateUpdate(ENEMY_STATE::ATTACK_RIGHT);
		}

		stateUpdate(ENEMY_STATE::ATTACK_RIGHT);

		fire();
	}

	moveUpdate();

	KEYANIMANAGER->update();
}

// 상태에 맞는 애니메이션 설정
void ENEMY::stateUpdate(ENEMY_STATE state)
{
	_state = state;
	switch (_state)
	{
	case ENEMY::ENEMY_STATE::IDLE_RIGHT:
		_pAnimation = KEYANIMANAGER->findAnimation(_typeName, _arAniFrameStrKey[int(_state)]);
		_pAnimation->start();
		break;
	case ENEMY::ENEMY_STATE::IDLE_LEFT:
		_pAnimation = KEYANIMANAGER->findAnimation(_typeName, _arAniFrameStrKey[int(_state)]);
		_pAnimation->start();
		break;
	case ENEMY::ENEMY_STATE::MOVE_RIGHT:
		_pAnimation = KEYANIMANAGER->findAnimation(_typeName, _arAniFrameStrKey[int(_state)]);
		_pAnimation->start();
		break;
	case ENEMY::ENEMY_STATE::MOVE_LEFT:
		_pAnimation = KEYANIMANAGER->findAnimation(_typeName, _arAniFrameStrKey[int(_state)]);
		_pAnimation->start();
		break;
	case ENEMY::ENEMY_STATE::ATTACK_RIGHT:
		_pAnimation = KEYANIMANAGER->findAnimation(_typeName, _arAniFrameStrKey[int(_state)]);
		_pAnimation->start();
		break;
	case ENEMY::ENEMY_STATE::ATTACK_LEFT:
		_pAnimation = KEYANIMANAGER->findAnimation(_typeName, _arAniFrameStrKey[int(_state)]);
		_pAnimation->start();
		break;
	case ENEMY::ENEMY_STATE::DEATH:
		//OBJECT::setImage(IMAGEMANAGER->findImage("enemyDeath"));
		//_pAnimation = KEYANIMANAGER->findAnimation("enemyDeath", "enemyDeath");
		//_pAnimation->start();
		break;
	}
}


void ENEMY::moveUpdate()
{
	
	switch (_state)
	{
	case ENEMY::ENEMY_STATE::MOVE_RIGHT:
		if (_moveType != ENEMY_MOVE_TYPE::STAND)
		{
			OBJECT::_posX += _speed;
		}
		break;
	case ENEMY::ENEMY_STATE::MOVE_LEFT:
		if (_moveType != ENEMY_MOVE_TYPE::STAND)
		{
			OBJECT::_posX -= _speed;
		}
		break;
	case ENEMY::ENEMY_STATE::ATTACK_RIGHT:
		//OBJECT::_posX += _speed;
		_bulletX += _speed;
		break;
	case ENEMY::ENEMY_STATE::ATTACK_LEFT:
		//OBJECT::_posX -= _speed;
		_bulletX -= _speed;
		break;
	}
}

void ENEMY::release()
{
	delete _pAnimation;
	_vAniFrame.clear();
}

void ENEMY::render(HDC hdc)
{
	if (_bullet != NULL)
	{
		_bullet->render(hdc, _bulletX, OBJECT::_posY);
	}
	OBJECT::getImage()->aniRender(hdc, OBJECT::getPosX() - OBJECT::getWidth() / 2, OBJECT::getPosY() - OBJECT::getHeight() / 2, _pAnimation);
}

// 적의 종류 설정
void ENEMY::setEnemyType(ENEMY_TYPE type)
{
	_type = type;
	switch (_type)
	{
	case ENEMY::ENEMY_TYPE::RED:
		_typeName = "redEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	case ENEMY::ENEMY_TYPE::BLUE:
		_typeName = "blueEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	case ENEMY::ENEMY_TYPE::GREEN:
		_typeName = "greenEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		_state = (ENEMY_STATE)RND->getInt(4);
		break;
	case ENEMY::ENEMY_TYPE::BLUE_BALL:
		_typeName = "blueBallEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	case ENEMY::ENEMY_TYPE::YELLOW_BALL:
		_typeName = "yellowBallEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		_state = (ENEMY_STATE)RND->getInt(4);
		break;
	case ENEMY::ENEMY_TYPE::MIRA:
		_typeName = "miraEnemy";
		_moveType = ENEMY_MOVE_TYPE::MOVER;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	case ENEMY::ENEMY_TYPE::CANNON:
		_typeName = "cannonEnemy";
		_moveType = ENEMY_MOVE_TYPE::STAND;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	case ENEMY::ENEMY_TYPE::SNAIL:
		_typeName = "snailEnemy";
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	case ENEMY::ENEMY_TYPE::GOLIATH:
		_typeName = "goliathEnemy";
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	case ENEMY::ENEMY_TYPE::BOSS:
		_hp = 3;
		_typeName = "bossEnemy";
		_moveType = ENEMY_MOVE_TYPE::SHOOTER;
		_state = (ENEMY_STATE)RND->getInt(6);
		break;
	}

	OBJECT::setImage(IMAGEMANAGER->findImage(_typeName));

	initAnimation();
}

void ENEMY::moveLeft()
{
}

void ENEMY::moveRight()
{
}

void ENEMY::fire()
{
	if (_isFire == false)
	{
		_bullet = IMAGEMANAGER->findImage("laser");
		_bulletX = OBJECT::_posX;
		_isFire = true;
	}
}

void ENEMY::setDeath()
{
}

void ENEMY::initAnimation()
{
	KEYANIMANAGER->addObject(_typeName);
	/*
	if (KEYANIMANAGER->findAnimation("enemyDeath", "enemyDeath") == nullptr)
	{
		KEYANIMANAGER->addObject("enemyDeath");
		KEYANIMANAGER->addArrayFrameAnimation("enemyDeath", "death", "enemyDeath", new int[5]{0,1,2,3,4}, 5, 10, false);
	}*/
	initAniFrame();

	_pAnimation = KEYANIMANAGER->findAnimation(_typeName, _arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)]);
	_pAnimation->start();
}

void ENEMY::initAniFrame()
{
	int* frameNum;
	int _maxAniFrame;
	switch (_type)
	{
	case ENEMY::ENEMY_TYPE::RED: case ENEMY::ENEMY_TYPE::BLUE:

		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		frameNum = new int[1]{ 0 };
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		frameNum = new int[1]{ 10 };
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 4;
		frameNum = new int[4]{ 0, 1, 2, 3 };
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 4;
		frameNum = new int[4]{ 7, 8, 9, 10 };
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_RIGHT)] = "ATTACK_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_RIGHT)] = 7;
		frameNum = new int[7]{ 14, 15, 16, 17, 18, 19, 20 };
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_LEFT)] = "ATTACK_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_LEFT)] = 7;
		frameNum = new int[7]{ 21, 22, 23, 24, 25, 26, 27 };
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_maxAniFrame = 6;

		break;

	case ENEMY::ENEMY_TYPE::GREEN:

		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		frameNum = new int[1]{ 0 };
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		frameNum = new int[1]{ 6 };
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 3;
		frameNum = new int[3]{ 0, 1, 2 };
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 3;
		frameNum = new int[3]{ 3, 4, 5 };
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		_maxAniFrame = 4;


		break;

	case ENEMY::ENEMY_TYPE::BLUE_BALL:

		frameNum = new int[1]{ 0 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[1]{ 11 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[6]{ 0, 1, 2, 3, 4, 5 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 6;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[6]{ 6, 7, 8, 9, 10, 11 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 6;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[3]{ 12, 13, 14 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_RIGHT)] = "ATTACK_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_RIGHT)] = 3;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[3]{ 18, 19, 20 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_LEFT)] = "ATTACK_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_LEFT)] = 3;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_maxAniFrame = 6;

		break;
	case ENEMY::ENEMY_TYPE::YELLOW_BALL:

		frameNum = new int[1]{ 0 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[1]{ 3 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[2]{ 0, 1 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 2;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[2]{ 2, 3 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 2;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_maxAniFrame = 4;

		break;

	case ENEMY::ENEMY_TYPE::MIRA:

		frameNum = new int[1]{ 0 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[1]{ 11 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[6]{ 0, 1, 2, 3, 4, 5 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 6;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[6]{ 6, 7, 8, 9, 10, 11 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 6;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[6]{ 12, 13, 14, 15, 16, 17 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_RIGHT)] = "ATTACK_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_RIGHT)] = 6;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[6]{ 18, 19, 20, 21, 22, 23 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_LEFT)] = "ATTACK_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_LEFT)] = 6;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_maxAniFrame = 6;

		break;

	case ENEMY::ENEMY_TYPE::CANNON:

		frameNum = new int[1]{ 0 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[1]{ 3 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[2]{ 2, 3 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 2;
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[2]{ 0, 1 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 2;
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[2]{ 2, 3 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_RIGHT)] = "ATTACK_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_RIGHT)] = 2;
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[2]{ 0, 1 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_LEFT)] = "ATTACK_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_LEFT)] = 2;
		_frameFps.push_back(2);
		_vAniFrame.push_back(frameNum);

		_maxAniFrame = 6;

		break;

	case ENEMY::ENEMY_TYPE::SNAIL: case ENEMY::ENEMY_TYPE::GOLIATH:

		frameNum = new int[1]{ 0 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_RIGHT)] = "IDLE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_RIGHT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[1]{ 9 };
		_arAniFrameStrKey[int(ENEMY_STATE::IDLE_LEFT)] = "IDLE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::IDLE_LEFT)] = 1;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[5]{ 0, 1, 2, 3, 4 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_RIGHT)] = "MOVE_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_RIGHT)] = 5;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[5]{ 5, 6, 7, 8, 9 };
		_arAniFrameStrKey[int(ENEMY_STATE::MOVE_LEFT)] = "MOVE_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::MOVE_LEFT)] = 5;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[5]{ 10, 11, 12, 13, 14 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_RIGHT)] = "ATTACK_RIGHT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_RIGHT)] = 5;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		frameNum = new int[5]{ 15, 16, 17, 18, 19 };
		_arAniFrameStrKey[int(ENEMY_STATE::ATTACK_LEFT)] = "ATTACK_LEFT";
		_arAniFrameCount[int(ENEMY_STATE::ATTACK_LEFT)] = 5;
		_frameFps.push_back(4);
		_vAniFrame.push_back(frameNum);

		_maxAniFrame = 6;

		break;
		
	}

	// 키프레임 animation 등록
	for (int i = 0; i < _frameFps.size(); i++)
	{
		KEYANIMANAGER->addArrayFrameAnimation(_typeName, _arAniFrameStrKey[i], _typeName.c_str(), _vAniFrame[i], _arAniFrameCount[i], _frameFps[i], true);
	}

}

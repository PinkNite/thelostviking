#include "stdafx.h"
#include "EnemyManager.h"
#include <algorithm>


EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init()
{
	int i = 0; // 꼭대기 층
	_arrEnemyLocations[i].posX = 950.0f; _arrEnemyLocations[i].posY = 125.0f;
	_arrEnemyLocations[i].width = 40;   _arrEnemyLocations[i].height = 64;
	_arrEnemyLocations[i].left = _arrEnemyLocations[i].posX - (_arrEnemyLocations[i].width / 2);
	_arrEnemyLocations[i].top  = _arrEnemyLocations[i].posY - (_arrEnemyLocations[i].height / 2);

	i++; // 플레이어 시작층
	_arrEnemyLocations[i].posX = 1200.0f; _arrEnemyLocations[i].posY = 420.0f;
	_arrEnemyLocations[i].width = 40;   _arrEnemyLocations[i].height = 64;
	_arrEnemyLocations[i].left = _arrEnemyLocations[i].posX - (_arrEnemyLocations[i].width / 2);
	_arrEnemyLocations[i].top  = _arrEnemyLocations[i].posY - (_arrEnemyLocations[i].height / 2);

	i++;	
	_arrEnemyLocations[i].posX = 300.0f; _arrEnemyLocations[i].posY = 610.0f;
	_arrEnemyLocations[i].width = 40;   _arrEnemyLocations[i].height = 64;
	_arrEnemyLocations[i].left = _arrEnemyLocations[i].posX - (_arrEnemyLocations[i].width / 2);
	_arrEnemyLocations[i].top = _arrEnemyLocations[i].posY - (_arrEnemyLocations[i].height / 2);

	i++;
	_arrEnemyLocations[i].posX = 200.0f; _arrEnemyLocations[i].posY = 1378.0f;
	_arrEnemyLocations[i].width = 40;   _arrEnemyLocations[i].height = 64;
	_arrEnemyLocations[i].left = _arrEnemyLocations[i].posX - (_arrEnemyLocations[i].width / 2);
	_arrEnemyLocations[i].top = _arrEnemyLocations[i].posY - (_arrEnemyLocations[i].height / 2);

	i++;
	_arrEnemyLocations[i].posX = 200.0f; _arrEnemyLocations[i].posY = 1536.0f;
	_arrEnemyLocations[i].width = 40;   _arrEnemyLocations[i].height = 64;
	_arrEnemyLocations[i].left = _arrEnemyLocations[i].posX - (_arrEnemyLocations[i].width / 2);
	_arrEnemyLocations[i].top = _arrEnemyLocations[i].posY - (_arrEnemyLocations[i].height / 2);


	_enemyCount = i;

	return S_OK;
}

void EnemyManager::update()
{
	for (auto &enemy : _vEnemy)
	{
		enemy->update();
	}
}

void EnemyManager::release()
{
}

void EnemyManager::render()
{
}

void EnemyManager::render(HDC hdc)
{
	/*
	for (auto &enemy : _vEnemy)
	{
		enemy->render(hdc);
	}*/

	// included: algorithm for lambda
	//std::for_each(_vEnemy.begin(), _vEnemy.end(), [&](auto& enemy) {
	//	enemy->render(hdc);
	//});

	for (int i = 0; i < getEnemySize(); i++)
	{
		_vEnemy[i]->render(hdc);
	}
}

void EnemyManager::addEnemy(int count, ENEMY::ENEMY_TYPE type)
{
	if (count > _enemyCount + 1)
		count = _enemyCount + 1;

	float speed = 0.5f;
	for (int i = 0; i < count; i++)
	{
		speed += 0.5f;
		ENEMY* enemy = new ENEMY();
		enemy->init(_arrEnemyLocations[i].posX,
			_arrEnemyLocations[i].posY,
			_arrEnemyLocations[i].width,
			_arrEnemyLocations[i].height,
			speed,
			type);

		_vEnemy.push_back(enemy);
	}
}

void EnemyManager::setDeath(int num)
{
	_vEnemy[num]->setDeath();
}

void EnemyManager::deleteEnemy(int nIndex)
{
	_vEnemy[nIndex]->release();
	_vEnemy.erase(_vEnemy.begin() + nIndex);
}


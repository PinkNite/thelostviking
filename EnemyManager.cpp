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
	int i = 0; // 1Ãþ
	_arrEnemyLocations[i].posX = 600.0f; _arrEnemyLocations[i].posY = 420.0f;
	_arrEnemyLocations[i].width = 40;   _arrEnemyLocations[i].height = 64;
	_arrEnemyLocations[i].left = _arrEnemyLocations[i].posX - (_arrEnemyLocations[i].width / 2);
	_arrEnemyLocations[i].top  = _arrEnemyLocations[i].posY - (_arrEnemyLocations[i].height / 2);

	i++;	
	_arrEnemyLocations[i].posX = 400.0f; _arrEnemyLocations[i].posY = 610.0f;
	_arrEnemyLocations[i].width = 40;   _arrEnemyLocations[i].height = 64;
	_arrEnemyLocations[i].left = _arrEnemyLocations[i].posX - (_arrEnemyLocations[i].width / 2);
	_arrEnemyLocations[i].top = _arrEnemyLocations[i].posY - (_arrEnemyLocations[i].height / 2);

	i++;	// 2Ãþ
	_arrEnemyLocations[i].posX = 100.0f; _arrEnemyLocations[i].posY = 610.0f;
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
	std::for_each(_vEnemy.begin(), _vEnemy.end(), [&](auto& enemy) {
		enemy->render(hdc);
	});

}

void EnemyManager::addEnemy(int count, ENEMY::ENEMY_TYPE type)
{
	if (count > _enemyCount + 1)
		count = _enemyCount + 1;

	for (int i = 0; i < count; i++)
	{
		ENEMY* enemy = new ENEMY();
		enemy->init(_arrEnemyLocations[i].posX,
			_arrEnemyLocations[i].posY,
			_arrEnemyLocations[i].width,
			_arrEnemyLocations[i].height,
			2.0f,
			type);

		_vEnemy.push_back(enemy);
	}
}


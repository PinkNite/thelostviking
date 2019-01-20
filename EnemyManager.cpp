#include "stdafx.h"
#include "EnemyManager.h"


EnemyManager::EnemyManager()
{
}


EnemyManager::~EnemyManager()
{
}

HRESULT EnemyManager::init()
{
	_arrEnemyLocations[0].posX = 600.0f; _arrEnemyLocations[0].posY = 600.0f;
	_arrEnemyLocations[0].width = 40;   _arrEnemyLocations[0].height = 64;
	_arrEnemyLocations[0].left = _arrEnemyLocations[0].posX - (_arrEnemyLocations[0].width / 2);
	_arrEnemyLocations[0].top  = _arrEnemyLocations[0].posY - (_arrEnemyLocations[0].height / 2);

	_arrEnemyLocations[1].posX = 600.0f; _arrEnemyLocations[1].posY = 600.0f;
	_arrEnemyLocations[1].width = 40;   _arrEnemyLocations[1].height = 64;
	_arrEnemyLocations[1].left = _arrEnemyLocations[1].posX - (_arrEnemyLocations[1].width / 2);


	return S_OK;
}

void EnemyManager::update()
{
}

void EnemyManager::release()
{
}

void EnemyManager::render()
{
}

void EnemyManager::render(HDC hdc)
{
}

void EnemyManager::addEnemy(int count, ENEMY::ENEMY_TYPE type)
{
	ENEMY* enemy = new ENEMY();
	//enemy->init();

}

#pragma once
#include "gameNode.h"
#include "enemy.h"

struct EnemyPosition
{
	float		posX;		//중심좌표 x
	float		posY;		//중심좌표 y
	int			width;		//가로길이
	int			height;		//세로길이
	int			left;		//사각형 왼쪽
	int			top;		//사각형 위
};

class EnemyManager : public gameNode
{
private: 
	typedef vector<ENEMY*>					vEnemy;
	typedef vector<ENEMY*>::iterator		viEnemy;

private:
	vEnemy				_vEnemy;
	viEnemy				_viEnemy;	

	//bullet*			_bullet;

	// 생성 가능한 수
	int _enemyCount;
	// enemy 생성 초기 좌표
	EnemyPosition _arrEnemyLocations[10];

public:
	EnemyManager();
	~EnemyManager();

	HRESULT init();

	void update() override;
	void release()override;
	void render() override;
	
	// Camera hdc
	void render(HDC hdc);

	// 
	void addEnemy(int count, ENEMY::ENEMY_TYPE type);

	// properties
	int getEnemySize() { return _vEnemy.size(); }



};


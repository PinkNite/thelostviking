#pragma once
#include "gameNode.h"
#include "enemy.h"

struct EnemyPosition
{
	float		posX;		//�߽���ǥ x
	float		posY;		//�߽���ǥ y
	int			width;		//���α���
	int			height;		//���α���
	int			left;		//�簢�� ����
	int			top;		//�簢�� ��
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

	// ���� ������ ��
	int _enemyCount;
	// enemy ���� �ʱ� ��ǥ
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


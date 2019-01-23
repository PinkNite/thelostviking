#pragma once
#include "gameNode.h"
#include "camera.h"
#include "player.h"
#include "inputMgr.h"
#include "map1.h"
#include "map2.h"
#include "enemy.h"
#include "EnemyManager.h"
#include "pixelCollision.h"
#include "itemManager.h"
#include "UI.h"





class SCENESTAGE :public gameNode
{
private:
	CAMERA *		_pCamera;
	PLAYER*			_pPlayer;
	INPUTMANAGER*	_pInputMgr;
	MAP1*           _pMap1;
	MAP2*           _pMap2;

	ENEMY*			_enemy;
	EnemyManager*	_enemyManager;

	pixelCollision* _pixel;

	ITEMMANAGER*    _pItemManager;
	UI*				_pUI;

	bool _isPlay;
public:
	SCENESTAGE();
	~SCENESTAGE();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//상호참조 여기서 하세요
	void	link();
};
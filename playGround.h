#pragma once
#include "gameNode.h"
#include "camera.h"
#include "TestStage1.h"
#include "player.h"
#include "inputMgr.h"
#include "map1.h"
#include "map2.h"
#include "enemy.h"
#include "EnemyManager.h"
#include "pixelCollision.h"
#include "itemManager.h"
#include "UI.h"
#include "sceneIntro.h"
#include "sceneMenu.h"
#include "sceneOption.h"
#include "scenePassword.h"
enum GAMESTATE
{
	INTRO,
	MENU,
	OPTION,
	PASSWORD,
	INVENTORY,
	PLAY,

};
class playGround : public gameNode
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
	GAMESTATE       _gameState;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	playGround();
	~playGround();
	//이미지 로드 여기서 하세요
	void	load();
	//상호참조 여기서 하세요
	void	link();
};


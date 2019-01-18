#pragma once
#include "gameNode.h"
#include "camera.h"
#include "player.h"
#include "inputMgr.h"
#include "map1.h"
#include "map2.h"
#include "sceneIntro.h"
#include "UI.h"
#include "itemManager.h"


class TestStage1 : public gameNode
{
private:
	ITEMMANAGER* _pItemManager;
	CAMERA *		_pCamera;
	PLAYER*			_pPlayer;
	INPUTMANAGER*	_pInputMgr;
	MAP1*           _pMap1;
	MAP2*           _pMap2;
	UI* _pUI;


public:
	TestStage1();
	~TestStage1();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//�̹��� �ε� ���⼭ �ϼ���
	void	load();
	//��ȣ���� ���⼭ �ϼ���
	void	link();
};


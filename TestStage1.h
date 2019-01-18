#pragma once
#include "gameNode.h"
#include "camera.h"
#include "player.h"
#include "inputMgr.h"
#include "map1.h"
#include "map2.h"

class TestStage1 : public gameNode
{
private:
	CAMERA *		_pCamera;
	PLAYER*			_pPlayer;
	INPUTMANAGER*	_pInputMgr;
	MAP1*           _pMap1;
	MAP2*           _pMap2;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	TestStage1();
	~TestStage1();
	//�̹��� �ε� ���⼭ �ϼ���
	void	load();
	//��ȣ���� ���⼭ �ϼ���
	void	link();
};


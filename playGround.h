#pragma once
#include "gameNode.h"
#include "camera.h"
#include "TestStage1.h"
#include "player.h"
#include "inputMgr.h"
#include "map1.h"
#include "map2.h"
#include "sceneIntro.h"


class playGround : public gameNode
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
	

	playGround();
	~playGround();
	//이미지 로드 여기서 하세요
	void	load();
	//상호참조 여기서 하세요
	void	link();
};


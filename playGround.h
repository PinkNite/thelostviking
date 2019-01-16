#pragma once
#include "gameNode.h"
#include "camera.h"
#include "TestStage1.h"
#include "player.h"
#include "sceneStart.h"//이승재 2019-01-16
#include "inputMgr.h"


class playGround : public gameNode
{
private:
	CAMERA *		_pCamera;
	PLAYER*			_pPlayer;
	SCENESTART*		_pSceneStart;//이승재 2019-01-16
	INPUTMANAGER*	_pInputMgr;
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


#pragma once
#include "gameNode.h"
#include "camera.h"
#include "TestStage1.h"
#include "player.h"
#include "sceneStart.h"//ÀÌ½ÂÀç 2019-01-16

class playGround : public gameNode
{
private:
	CAMERA * _pCamera;
	PLAYER* _pPlayer;
	SCENESTART* _pSceneStart;//ÀÌ½ÂÀç 2019-01-16
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	playGround();
	~playGround();

	void	load();
};


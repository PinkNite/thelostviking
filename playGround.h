#pragma once
#include "gameNode.h"
#include "camera.h"
#include "TestStage1.h"

class playGround : public gameNode
{
private:
	CAMERA * _pCamera;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	playGround();
	~playGround();

	void	load();
};


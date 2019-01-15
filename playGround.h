#pragma once
#include "gameNode.h"
#include "camera.h"

class playGround : public gameNode
{
private:
	CAMERA * pCamera;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	playGround();
	~playGround();

	void	load();
};


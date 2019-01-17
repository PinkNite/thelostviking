#include "player.h"
#include "map1.h"
#pragma once

class pixelCollision
{
private:
	PLAYER* _pPlayer;
	MAP1* _pMap1;

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release(); 
	void update();
	void render();
};


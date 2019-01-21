#pragma once

#include "player.h"
#include "map1.h"
#include "map2.h"
#include "player.h"

class pixelCollision
{
private:
	image* _imgMap1Cbg;
	image* _imgMap2Cbg;

private:
	PLAYER* _pPlayer;
	MAP1* _pMap1;
	MAP2* _pMap2;
	float x;

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release(); 
	void update();
	void render(HDC hdc);
	void setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }
};


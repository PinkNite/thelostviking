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
	int _probeTopY;
	int _probeBottomY;
	int _probeLeftX;
	int _probeRightX;
	bool _isCollisionTop;
	bool _isCollisionBottom;
	bool _isCollisionLeft;
	bool _isCollisionRight;
	bool _onceCollisionLeft;
	bool _onceCollisionRight;

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release(); 
	void update();
	void render(HDC hdc);
	void setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }

	bool getCollisionbot() { return _isCollisionBottom; }
	void setCollisionbot(bool isCollisionBottom) { _isCollisionBottom = isCollisionBottom;	}
};


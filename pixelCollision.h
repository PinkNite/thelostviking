#pragma once

#include "player.h"
#include "map1.h"
#include "map2.h"
#include "player.h"
#include <vector>
#include "gameNode.h"

class pixelCollision : public gameNode
{
private:
	image* _imgMap1Cbg;
	image* _imgMap2Cbg;
	image* _imgElevatorC;

	RECT ladderRect[12];
	RECT playerRect;
	RECT _rcElevatorC;

private:
	PLAYER* _pPlayer;
	MAP1* _pMap1;
	MAP2* _pMap2;
	float x;
	int _probeTopY;
	int _probeBottomY;
	int _probeElavatorBottomY;
	int _probeLeftX;
	int _probeRightX;

	bool _isCollisionTop;
	bool _isCollisionBottom;
	bool _isCollisionElevatorBottom;
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
	void collisionRect(RECT rect, PLAYER* pPlayer);

	bool getCollisionbot() { return _isCollisionBottom; }
	void setCollisionbot(bool isCollisionBottom) { _isCollisionBottom = isCollisionBottom;	}
	bool getCollisionleft() { return _isCollisionLeft; }
	void setCollisionleft(bool isCollisionLeft) { _isCollisionLeft = isCollisionLeft; }
	bool getCollisionright() { return _isCollisionRight; }
	void setCollisionright(bool isCollisionRight) { _isCollisionRight = isCollisionRight; }
	void setMap2(MAP2* pMap2) { _pMap2 = pMap2; }
};


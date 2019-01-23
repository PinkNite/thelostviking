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
	image* _imgMap2CbgCopy;
	image* _imgElevatorC;

	RECT ladderRect[12];
	RECT playerRect[3];
	RECT _rcElevatorC;

private:
	PLAYER* _pPlayer;

	MAP1* _pMap1;
	MAP2* _pMap2;
	float x;
	int _probeTopY[3];
	int _probeBottomY[3];
	int _probeElavatorBottomY[3];
	int _probeLeftX[3];
	int _probeRightX[3];

	bool _isCollisionTop[3];
	bool _isCollisionBottom[3];
	bool _isCollisionElevatorBottom[3];
	bool _isCollisionLeft[3];
	bool _isCollisionRight[3];
	bool _onceCollisionLeft[3];
	bool _onceCollisionRight[3];

public:
	pixelCollision();
	~pixelCollision();

	HRESULT init();
	void release(); 
	void update();
	void render(HDC hdc);
	void setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }
	void collisionRect(RECT rect, PLAYER* pPlayer);

	bool getCollisionbot(int index) { return _isCollisionBottom[index]; }
	void setCollisionbot(bool isCollisionBottom, int index) { _isCollisionBottom[index] = isCollisionBottom;	}
	bool getCollisionleft(int index) { return _isCollisionLeft[index]; }
	void setCollisionleft(bool isCollisionLeft, int index) { _isCollisionLeft[index] = isCollisionLeft; }
	bool getCollisionright(int index) { return _isCollisionRight[index]; }
	void setCollisionright(bool isCollisionRight, int index) { _isCollisionRight[index] = isCollisionRight; }

	bool getCollisionElevatorBottom(int index) { return _isCollisionElevatorBottom[index]; }
	void setCollisionElevatorBottom(bool isCollisionElevatorBottom, int index) { _isCollisionBottom[index] = isCollisionElevatorBottom; }



	void setMap2(MAP2* pMap2) { _pMap2 = pMap2; }
};


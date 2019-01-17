#pragma once
#include "stdafx.h"

class PLAYER;
class CAMERA;

class INPUTMANAGER {
private:
	PLAYER *	_pPlayer;
	CAMERA*		_pCamera;

	float		_ericJumpPower;
	float		_jumpKeyPressTime;
public:
	void init(PLAYER * pPlayer,CAMERA* pCamera);
	void update();
	void release();
};
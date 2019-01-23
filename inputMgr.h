#pragma once
#include "stdafx.h"

class PLAYER;
class CAMERA;

class INPUTMANAGER {
private:
	PLAYER *	_pPlayer;
	CAMERA*		_pCamera;


	//ÀÌ½ÂÀç
	bool _isLeft;
	bool _isRight;
	bool _isTop;
	bool _isBottom;
	bool _isUse;
	bool _isOpen;
public:
	void init(PLAYER * pPlayer,CAMERA* pCamera);
	void update();
	void release();


	//ÀÌ½ÂÀç
	bool getLeft() { return _isLeft; }
	bool getRight() { return _isRight; }
	bool getTop() { return _isTop; }
	bool getBottom() { return _isBottom; }
	bool getUse() { return _isUse; }
	bool getOpen() { return _isOpen; }
};
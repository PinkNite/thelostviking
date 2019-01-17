#pragma once
#include "gameNode.h"
class SCENEPASSWORD :public gameNode
{
private:
	image* _pBackGround;//배경화면
	int _backGroundAlphaCount;
	image* _pImage;// 변하는화면임

public:
	SCENEPASSWORD();
	~SCENEPASSWORD();

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


#pragma once
#include "gameNode.h"
class SCENE0 :public gameNode
{
private:
	image* _pImage;
	int _alphaCount;
public:
	SCENE0();
	~SCENE0();
	HRESULT init();
	void release();
	void update();
	void render();


};


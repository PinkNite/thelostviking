#pragma once
#include "gameNode.h"
class BACKGROUND :public gameNode
{
private:
	image* _pImage;
	int _alphaCount;
public:
	BACKGROUND();
	~BACKGROUND();
	HRESULT init();
	void release();
	void update();
	void render();
};
class BACKGROUND2 :public gameNode
{
private:
	image* _pImage;
	int _alphaCount;
public:
	BACKGROUND2();
	~BACKGROUND2();
	HRESULT init();
	void release();
	void update();
	void render();
};


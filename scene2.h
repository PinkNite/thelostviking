#pragma once
#include "gameNode.h"
class SCENE2 :public gameNode
{
private:
	image* _pImage;
	int _alphaCount;
public:
	SCENE2();
	~SCENE2();
	HRESULT init();
	void release();
	void update();
	void render();
	void action(float numA //보다 시간이 크고
		, float numB  //보다 시간이 작으면
		, float numC);    //보다 시간이 커지면 알파값 줄임
};


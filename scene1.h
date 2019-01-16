#pragma once
#include "gameNode.h"
class SCENE1 :public gameNode
{
private:
	image* _pImage;
	int _alphaCount;
public:
	SCENE1();
	~SCENE1();
	HRESULT init();
	void release();
	void update();
	void render();
	void action(float numA //보다 시간이 크고
		, float numB  //보다 시간이 작으면
		, float numC);    //보다 시간이 커지면 알파값 줄임
};


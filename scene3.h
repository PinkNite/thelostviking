#pragma once
#include "gameNode.h"
class SCENE3 :public gameNode
{
	image* _pImage;
	int _alphaCount;
public:
	SCENE3();
	~SCENE3();
	HRESULT init();
	void release();
	void update();
	void render();
	//보다 시간이 크고  //보다 시간이 작으면    //보다 시간이 커지면 알파값 줄임
	void action(float numA, float numB, float numC);
	//보다 시간이 크고    //보다 시간이 작으면
	void action(float numA, float numB);
};


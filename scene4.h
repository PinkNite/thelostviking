#pragma once
#include "gameNode.h"
class SCENE4 :public gameNode
{
private:
	image* _pImage;
	int _alphaCount;
	int _y;//이미지를 위아래 움직이게 할값
	int _jumpPower;
	int _gravity;
	int _jumpCount;
public:
	SCENE4();
	~SCENE4();
	HRESULT init();
	void release();
	void update();
	void render();
	//보다 시간이 크고  //보다 시간이 작으면    //보다 시간이 커지면 알파값 줄임
	void action(float numA, float numB, float numC);
	//보다 시간이 크고    //보다 시간이 작으면
	void action(float numA, float numB);
};


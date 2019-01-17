#pragma once
#include "gameNode.h"
class SCENEINTRO :public gameNode
{
	image* _pBackGround;//검은화면 고정이미지
	image* _pImage;//변하고 출력되는 이미지
	int _imageAlphaCount;
	image* _pImage2;//제목 움직일것
	int _image2AlphaCount;
	float _y;//움직이게 할 와이값
	float _y2;//와이2는 3번이미지움직임
	float time;//시간
	float _jumpPower;
	int _jumpCount;
	float _gravity;

	int _backGroundAlphaCount;
	float _time;



public:
	SCENEINTRO();
	~SCENEINTRO();
	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void actionOnOff(float numA, float numB, float numC, int* alpha, const char* keyName);//에이보다 크고 비보다 작은시가넹 나옴 알파값이 255 될때까지
	void actionOn(float numA, float numB, float numC, int* alpha, const char* keyName);//정해진 시간에 이미지 교체하고 나오기만함
	void actionJump(float numA, float numB, float numC, int * alpha, const char * keyName, float* y, float* y2);//인트로 점프할것


};


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
	void action(float numA //���� �ð��� ũ��
		, float numB  //���� �ð��� ������
		, float numC);    //���� �ð��� Ŀ���� ���İ� ����
};


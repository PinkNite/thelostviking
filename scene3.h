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
	//���� �ð��� ũ��  //���� �ð��� ������    //���� �ð��� Ŀ���� ���İ� ����
	void action(float numA, float numB, float numC);
	//���� �ð��� ũ��    //���� �ð��� ������
	void action(float numA, float numB);
};


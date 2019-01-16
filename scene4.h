#pragma once
#include "gameNode.h"
class SCENE4 :public gameNode
{
private:
	image* _pImage;
	int _alphaCount;
	int _y;//�̹����� ���Ʒ� �����̰� �Ұ�
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
	//���� �ð��� ũ��  //���� �ð��� ������    //���� �ð��� Ŀ���� ���İ� ����
	void action(float numA, float numB, float numC);
	//���� �ð��� ũ��    //���� �ð��� ������
	void action(float numA, float numB);
};


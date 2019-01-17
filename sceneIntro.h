#pragma once
#include "gameNode.h"
class SCENEINTRO :public gameNode
{
	image* _pBackGround;//����ȭ�� �����̹���
	image* _pImage;//���ϰ� ��µǴ� �̹���
	int _imageAlphaCount;
	image* _pImage2;//���� �����ϰ�
	int _image2AlphaCount;
	float _y;//�����̰� �� ���̰�
	float _y2;//����2�� 3���̹���������
	float time;//�ð�
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
	void actionOnOff(float numA, float numB, float numC, int* alpha, const char* keyName);//���̺��� ũ�� �񺸴� �����ð��� ���� ���İ��� 255 �ɶ�����
	void actionOn(float numA, float numB, float numC, int* alpha, const char* keyName);//������ �ð��� �̹��� ��ü�ϰ� �����⸸��
	void actionJump(float numA, float numB, float numC, int * alpha, const char * keyName, float* y, float* y2);//��Ʈ�� �����Ұ�


};


#pragma once
#include "gameNode.h"
class SCENEPASSWORD :public gameNode
{
private:
	image* _pBackGround;//���ȭ��
	int _backGroundAlphaCount;
	image* _pImage;// ���ϴ�ȭ����

public:
	SCENEPASSWORD();
	~SCENEPASSWORD();

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


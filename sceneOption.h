#pragma once
#include "gameNode.h"
class SCENEOPTION :public gameNode
{
private:
	image* _pBackGround;//����ȭ�� �����̹���
	int _backGroundAlphaCount;
	image* _pImageTitle;//����
	int _imageTitleAlphaCount;
	image* _pImageMenu;//���ϰ� ��µǴ� �̹���
	int _imageMenuAlphaCount;
	image* _pImageSelect;//���ϰ� ��µǴ� �̹���
	int _imageSelectAlphaCount;
	image* _pImageNumButton;//���ڹ�ư
	int _numButtonFrameX;
	int _imageNumButton;
	image* _pImageOnOffButton;//onoff
	int _onOffButtonFrameX;
	int _onOffButtonFrameX2;
	int _onOffButtonFrameX3;
	int _imageOnOffButton;


	float _y;

public:
	SCENEOPTION();
	~SCENEOPTION();
	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};


#pragma once
#include "gameNode.h"
class SCENEOPTION :public gameNode
{
private:
	image* _pBackGround;//검은화면 고정이미지
	int _backGroundAlphaCount;
	image* _pImageTitle;//제목
	int _imageTitleAlphaCount;
	image* _pImageMenu;//변하고 출력되는 이미지
	int _imageMenuAlphaCount;
	image* _pImageSelect;//변하고 출력되는 이미지
	int _imageSelectAlphaCount;
	image* _pImageNumButton;//숫자버튼
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


#pragma once
#include "gameNode.h"

class SCENEMENU : public gameNode
{
private:
	image* _pBackGround;//검은화면 고정이미지
	image* _pImageTitle;//제목
	image* _pImageMenu;//변하고 출력되는 이미지
	image* _pImageSelect;//변하고 출력되는 이미지
	int _imageMenuAlphaCount;
	int _imageTitleAlphaCount;
	int _imageSelectAlphaCount;
	float _y;//이거는 셀렉트가 움직일 값
	int _backGroundAlphaCount;

	int _gameStart;

public:
	SCENEMENU();
	~SCENEMENU();
	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	int getGameStart() { return _gameStart; }
};


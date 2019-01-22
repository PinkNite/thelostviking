#pragma once
#include "gameNode.h"

class SCENEMENU : public gameNode
{
private:
	image* _pBackGround;//����ȭ�� �����̹���
	image* _pImageTitle;//����
	image* _pImageMenu;//���ϰ� ��µǴ� �̹���
	image* _pImageSelect;//���ϰ� ��µǴ� �̹���
	int _imageMenuAlphaCount;
	int _imageTitleAlphaCount;
	int _imageSelectAlphaCount;
	float _y;//�̰Ŵ� ����Ʈ�� ������ ��
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


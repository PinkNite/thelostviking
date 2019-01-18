#pragma once
#include "gameNode.h"
struct tagUI
{
	bool isAllive;
	image* pImage;
};
class UI :public gameNode
{
private:
	tagUI _ui;
	tagUI _life[9];
public:
	UI();
	~UI();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


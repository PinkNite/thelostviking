#pragma once
#include "gameNode.h"
class UI:public gameNode
{
private:
	image* _pUI;
	image* _pLife[9];
public:
	UI();
	~UI();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


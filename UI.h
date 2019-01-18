#pragma once
#include "gameNode.h"
class UI:public gameNode
{
private:
	image* _image;
public:
	UI();
	~UI();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


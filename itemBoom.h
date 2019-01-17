#pragma once
#include "itemFrame.h"
class ITEMBOOM :public ITEMFRAME
{
private:

public:
	ITEMBOOM();
	~ITEMBOOM();
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render();
};


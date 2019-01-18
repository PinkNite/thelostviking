#pragma once
#include "itemFrame.h"

class ITEMMEAT:public ITEMFRAME
{
public:
	ITEMMEAT();
	~ITEMMEAT();
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};



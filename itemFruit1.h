#pragma once
#include "itemFrame.h"
class ITEMFRUIT1 :public ITEMFRAME
{
public:
	ITEMFRUIT1();
	~ITEMFRUIT1();
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


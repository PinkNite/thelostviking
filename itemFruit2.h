#pragma once
#include "itemFrame.h"
class ITEMFRUIT2 :public ITEMFRAME
{
public:
	ITEMFRUIT2();
	~ITEMFRUIT2();
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


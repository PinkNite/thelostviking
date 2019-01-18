#pragma once
#include "ITEMBOOM.h"
class ITEMMANAGER :public ITEMBOOM
{
	ITEMBOOM* _pItemBoom;
public:
	ITEMMANAGER();
	~ITEMMANAGER();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


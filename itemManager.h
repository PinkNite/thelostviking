#pragma once
#include "ITEMBOOM.h"
class ITEMMANAGER :public ITEMBOOM
{
	ITEMBOOM* _pItemBoom[2];
public:
	ITEMMANAGER();
	~ITEMMANAGER();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
};


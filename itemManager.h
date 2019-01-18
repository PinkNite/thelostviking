#pragma once
#include "ITEMBOOM.h"
class ITEMMANAGER 
{
	ITEMBOOM* _pItemBoom[2];
public:
	ITEMMANAGER();
	~ITEMMANAGER();
	 HRESULT init();
	 void release();
	 void update();
	 void render(HDC hdc);
};


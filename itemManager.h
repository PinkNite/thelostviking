#pragma once
#include "itemBoom.h"
#include "itemFruit1.h"
#include "itemFruit2.h"
#include "itemMeat.h"
#include "itemQuestionMark.h"
class ITEMMANAGER 
{
	ITEMBOOM* _pItemBoom[2];
	ITEMFRUIT1* _pItemFruit1[2];
	ITEMFRUIT2* _pItemFruit2[2];
	ITEMMEAT* _pItemMeat;
public:
	ITEMMANAGER();
	~ITEMMANAGER();
	 HRESULT init();
	 void release();
	 void update();
	 void render(HDC hdc);
};


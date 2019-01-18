#include "stdafx.h"
#include "itemManager.h"




ITEMMANAGER::ITEMMANAGER()
{
}

ITEMMANAGER::~ITEMMANAGER()
{
}

HRESULT ITEMMANAGER::init()
{
	_pItemBoom[0] = new ITEMBOOM;
	_pItemBoom[1] = new ITEMBOOM;
	_pItemBoom[0]->init(1410, 82, 40, 38);//
	_pItemBoom[1]->init(1410, 120, 40, 38);//

	for (int  i = 0; i < 2; i++)
	{
		_pItemFruit1[i] = new ITEMFRUIT1;
	}
		_pItemFruit1[0]->init(268, 350, 33, 40);
		_pItemFruit1[1]->init(510, 100, 33, 40);
	for (int i = 0; i < 2; i++)
	{
		_pItemFruit2[i] = new ITEMFRUIT2;
	}
		_pItemFruit2[0]->init(20, 20, 40, 35);
		_pItemFruit2[1]->init(40, 40, 40, 35);
	_pItemMeat = new ITEMMEAT;
	_pItemMeat->init(50, 50, 40, 35);
	return S_OK;
}

void ITEMMANAGER::release()
{
}

void ITEMMANAGER::update()
{
}

void ITEMMANAGER::render(HDC hdc)
{
	for (int i = 0; i < 2; i++)
	{
		_pItemBoom[i]->render(hdc);

	}
	for (int i = 0; i < 2; i++)
	{
		_pItemFruit1[i]->render(hdc);

	}
	for (int i = 0; i < 2; i++)
	{
		_pItemFruit2[i]->render(hdc);

	}
	_pItemMeat->render(hdc);
}

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
	_pItemBoom[0]->init(1380, 130, 32, 30);//
	_pItemBoom[1]->init(1412, 130, 32, 30);//


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
}

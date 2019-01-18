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
	_pItemBoom = new ITEMBOOM;
	_pItemBoom->init(1333, 96, 32, 30);//ÀÓÀÇÀÇ ÁÂÇ¥

	

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
	_pItemBoom->render(hdc);
}

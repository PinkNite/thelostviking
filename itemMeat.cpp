#include "stdafx.h"
#include "itemMeat.h"

ITEMMEAT::ITEMMEAT()
{
}

ITEMMEAT::~ITEMMEAT()
{
}

HRESULT ITEMMEAT::init(int x, int y, int width, int height)
{
	ITEMFRAME::setItem(x, y, width, height);
	ITEMFRAME::setImage(IMAGEMANAGER->findImage("meat"));
	return S_OK;
}

void ITEMMEAT::release()
{
}

void ITEMMEAT::update()
{
}

void ITEMMEAT::render(HDC hdc)
{
	ITEMFRAME::getImage()->render(hdc, ITEMFRAME::getX(), ITEMFRAME::getY());
}



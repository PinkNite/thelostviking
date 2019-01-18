#include "stdafx.h"
#include "itemFruit1.h"

ITEMFRUIT1::ITEMFRUIT1()
{
}

ITEMFRUIT1::~ITEMFRUIT1()
{
}

HRESULT ITEMFRUIT1::init(int x, int y, int width, int height)
{
	ITEMFRAME::setItem(x, y, width, height);
	ITEMFRAME::setImage(IMAGEMANAGER->findImage("fruit1"));
	return S_OK;
}



void ITEMFRUIT1::release()
{
}

void ITEMFRUIT1::update()
{
}

void ITEMFRUIT1::render(HDC hdc)
{
	ITEMFRAME::getImage()->render(hdc, ITEMFRAME::getX(), ITEMFRAME::getY());
}


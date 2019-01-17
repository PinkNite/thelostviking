#include "stdafx.h"
#include "itemBoom.h"

ITEMBOOM::ITEMBOOM()
{
}

ITEMBOOM::~ITEMBOOM()
{
}

HRESULT ITEMBOOM::init(int x, int y, int width, int height)
{
	ITEMFRAME::init(x, y, width, height);
	ITEMFRAME::setImage(IMAGEMANAGER->findImage("boom"));
	return S_OK;
}

void ITEMBOOM::release()
{
}

void ITEMBOOM::update()
{
}

void ITEMBOOM::render()
{
	ITEMFRAME::getImage()->getMemDC();
}

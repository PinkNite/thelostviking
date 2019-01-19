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
	ITEMFRAME::setItem(x, y, width, height);
	ITEMFRAME::setImage(IMAGEMANAGER->findImage("boom"));
	return S_OK;
}

void ITEMBOOM::release()
{
}

void ITEMBOOM::update()
{
	

}

void ITEMBOOM::render(HDC hdc)
{
	if (ITEMFRAME::getIsAllive())//트루면 //렌더하시고
	{
		ITEMFRAME::getImage()->alphaRender(hdc, ITEMFRAME::getX(), ITEMFRAME::getY(),ITEMFRAME::getAlphaCount());
	}
}

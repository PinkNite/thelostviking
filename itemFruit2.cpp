#include "stdafx.h"
#include "itemFruit2.h"



ITEMFRUIT2::ITEMFRUIT2()
{
}

ITEMFRUIT2::~ITEMFRUIT2()
{
}

HRESULT ITEMFRUIT2::init(int x, int y, int width, int height)
{
	ITEMFRAME::setItem(x, y, width, height);
	ITEMFRAME::setImage(IMAGEMANAGER->findImage("fruit2"));
	return S_OK;
}

void ITEMFRUIT2::release()
{
}

void ITEMFRUIT2::update()
{

}

void ITEMFRUIT2::render(HDC hdc)
{
	if (ITEMFRAME::getIsAllive())//트루면 //렌더하시고
	{
		ITEMFRAME::getImage()->alphaRender(hdc, ITEMFRAME::getX(), ITEMFRAME::getY(), ITEMFRAME::getAlphaCount());
	}
}


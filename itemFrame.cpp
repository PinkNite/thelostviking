#include "stdafx.h"
#include "itemFrame.h"



ITEMFRAME::ITEMFRAME()
{
}

ITEMFRAME::~ITEMFRAME()
{
}

HRESULT ITEMFRAME::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	return S_OK;
}

void ITEMFRAME::release()
{
}

void ITEMFRAME::update()
{
}

void ITEMFRAME::render(HDC hdc)
{

}

void ITEMFRAME::setImage(image * image)
{
	_pImage = image;
}

void ITEMFRAME::setItem(int x, int y, int width, int height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_isAllive = true;
	_alphaCount = 255;
	_isUse = false;
}

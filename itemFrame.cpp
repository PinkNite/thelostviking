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

void ITEMFRAME::render()
{
	//_pImage->render(getMemDC(), _x, _y);
}

void ITEMFRAME::setImage(image * image)
{
	_pImage = image;
}

#include "stdafx.h"
#include "UI.h"


UI::UI()
{
}


UI::~UI()
{
}

HRESULT UI::init()
{
	_image = new image;
	_image = IMAGEMANAGER->findImage("UI");

	return S_OK;
}

void UI::release()
{
}

void UI::update()
{
}

void UI::render()
{
	_image->render(getMemDC(), 0,370 );
}

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
	_pUI = new image;
	_pUI = IMAGEMANAGER->findImage("UI");
	for (int i = 0; i < 9; i++)
	{
		_pLife[i] = new image;
		_pLife[i] = IMAGEMANAGER->findImage("life");
	}
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
	_pUI->render(getMemDC(), 0,370 );
	for (int i = 0; i < 9; i++)
	{
		switch (i)
		{
		case 0:
			_pLife[i]->render(getMemDC(), 40, 466);
			break;
		case 1:
			_pLife[i]->render(getMemDC(), 40+20, 466);
			break;
		case 2:
			_pLife[i]->render(getMemDC(), 60+20, 466);
			break;
		case 3:
			_pLife[i]->render(getMemDC(), 220, 466);
			break;
		case 4:
			_pLife[i]->render(getMemDC(), 220 + 20, 466);
			break;
		case 5:
			_pLife[i]->render(getMemDC(), 240 + 20, 466);
			break;
		case 6:
			_pLife[i]->render(getMemDC(), 400, 466);
			break;
		case 7:
			_pLife[i]->render(getMemDC(), 400 + 20, 466);
			break;
		case 8:
			_pLife[i]->render(getMemDC(), 420 + 20, 466);
			break;
		}
	}
}

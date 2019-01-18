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
	_ui.pImage = new image;
	_ui.pImage = IMAGEMANAGER->findImage("UI");

	for (int i = 0; i < 9; i++)
	{
		_life[i].pImage = new image;
		_life[i].isAllive = true;
		_life[i].pImage = IMAGEMANAGER->findImage("life");
	}
	return S_OK;
}

void UI::release()
{

	for (int i = 0; i < 9; i++)
	{
		if (!_life[i].isAllive)
		{
			delete _life[i].pImage;
			_life[i].pImage = nullptr;
		}
	}

}

void UI::update()
{
	if (KEYMANAGER->isOnceKeyDown('T'))
	{
		_life[0].isAllive = false;
	}
}

void UI::render()
{
	_ui.pImage->render(getMemDC(), 0, 370);
	for (int i = 0; i < 9; i++)
	{
		switch (i)
		{
		case 0:
			_life[i].pImage->render(getMemDC(), 40, 466);
			break;
		case 1:
			_life[i].pImage->render(getMemDC(), 40 + 20, 466);
			break;
		case 2:
			_life[i].pImage->render(getMemDC(), 60 + 20, 466);
			break;
		case 3:
			_life[i].pImage->render(getMemDC(), 220, 466);
			break;
		case 4:
			_life[i].pImage->render(getMemDC(), 220 + 20, 466);
			break;
		case 5:
			_life[i].pImage->render(getMemDC(), 240 + 20, 466);
			break;
		case 6:
			_life[i].pImage->render(getMemDC(), 400, 466);
			break;
		case 7:
			_life[i].pImage->render(getMemDC(), 400 + 20, 466);
			break;
		case 8:
			_life[i].pImage->render(getMemDC(), 420 + 20, 466);
			break;
		}
	}
}

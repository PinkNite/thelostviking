#include "stdafx.h"
#include "setElectric.h"


SETELECTRIC::SETELECTRIC()
{
}


SETELECTRIC::~SETELECTRIC()
{
}

HRESULT SETELECTRIC::init(string strKey, int x, int y, int width, int height, int frameSpeed)
{
	Electric4.isOff = false;
	Electric4.imgElectric4 = IMAGEMANAGER->addFrameImage(strKey, "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	Electric4.rcElectric4 = RectMake(x, y, width, height);

	_frameCount = 0;
	_index = 0;
	_frameSpeed = frameSpeed;

	return S_OK;
}

void SETELECTRIC::release()
{
}

void SETELECTRIC::update()
{
	if (_frameCount % _frameSpeed == 0)
	{
		Electric4.imgElectric4->SetFrameX(_index);
		_index++;
		if (_index > Electric4.imgElectric4->getMaxFrameX())
		{
			_index = 0;
		}
		_frameCount = 0;
	}
	_frameCount++;
}

void SETELECTRIC::render(HDC hdc)
{
	Electric4.imgElectric4->frameRender(hdc, Electric4.rcElectric4.left, Electric4.rcElectric4.top);
}

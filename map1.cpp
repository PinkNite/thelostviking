#include "stdafx.h"
#include "map1.h"


MAP1::MAP1()
{
}


MAP1::~MAP1()
{
}

HRESULT MAP1::init()
{
	_imgMap1bg = IMAGEMANAGER->addImage("맵1배경", "resource/map/map1-1.bmp", 960, 960, true, RGB(255, 0, 255));
	_imgDoor1 = IMAGEMANAGER->addFrameImage("1-1문", "resource/map/effect/open_Door.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	_imgDoor2 = IMAGEMANAGER->addFrameImage("1-2문", "resource/map/effect/open_Door.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	_imgElectric1 = IMAGEMANAGER->addFrameImage("전기1", "resource/map/effect/electric_Shock.bmp", 384, 32, 3, 1, true, RGB(255, 0, 255));

	_rcDoor1 = RectMake(320, 448, 32, 96);
	_rcDoor2 = RectMake(672, 256, 32, 96);
	_rcElectric1 = RectMake(160, 896, 64, 16);
	_rcLadder1 = RectMake(192, 352, 64, 192);
	_rcLadder2 = RectMake(544, 352, 64, 192);
	_rcLadder3 = RectMake(384, 544, 64, 192);
	_rcHelp1 = RectMake(336, 824, 32, 32);
	_rcExit = RectMake(704, 448, 64, 96);

	_frameCount = 0;
	_indexElectric1 = 0;
	_frameSpeed = 5;

	return S_OK;
}

void MAP1::release()
{
}

void MAP1::update()
{
	if (_frameCount % _frameSpeed == 0)
	{
		_imgElectric1->SetFrameX(_indexElectric1);
		_indexElectric1++;
		if (_indexElectric1 > _imgElectric1->getMaxFrameX())
		{
			_indexElectric1 = 0;
		}
		_frameCount = 0;
	}

	_frameCount++;
}

void MAP1::render(HDC hdc)
{
	_imgElectric1->frameRender(hdc, _rcElectric1.left, _rcElectric1.top);
}

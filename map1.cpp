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
	_imgMap1bg = IMAGEMANAGER->addImage("Map1bg", "resource/map/map1-1.bmp", 960, 960, true, RGB(255, 0, 255));
	_imgElectric1 = IMAGEMANAGER->addFrameImage("electric1", "resource/map/effect/electric_Shock.bmp", 384, 32, 3, 1, true, RGB(255, 0, 255));

	_rcElectric1 = RectMake(160, 896, 64, 16);
	_rcLadder[0] = RectMake(192, 352, 64, 192);
	_rcLadder[1] = RectMake(544, 352, 64, 192);
	_rcLadder[2] = RectMake(384, 544, 64, 192);
	_rcHelp = RectMake(336, 824, 32, 32);
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

void MAP1::doorInit()
{
	setDOOR* doorObtacle = new DOORS;
	doorObtacle->init("doorObc1", 320, 448, 32, 96, false);
	_vDoor.push_back(doorObtacle);

	doorObtacle = new DOORS;
	doorObtacle->init("doorObc2", 672, 256, 32, 96, false);
	_vDoor.push_back(doorObtacle);
}
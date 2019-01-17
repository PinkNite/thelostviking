#include "stdafx.h"
#include "map2.h"


MAP2::MAP2()
{
}


MAP2::~MAP2()
{
}

HRESULT MAP2::init()
{
	_imgMap2bg = IMAGEMANAGER->addImage("맵2배경", "resource/map/map1-2.bmp", 2048, 1630, true, RGB(255, 0, 255));
	_imgElectric3 = IMAGEMANAGER->addFrameImage("전기3", "resource/map/effect/electric_Shock3.bmp", 448, 32, 7, 1, true, RGB(255, 0, 255));
	_imgElectric4_1 = IMAGEMANAGER->addFrameImage("전기4_1", "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	_imgElectric4_2 = IMAGEMANAGER->addFrameImage("전기4_2", "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	_imgElectric4_3 = IMAGEMANAGER->addFrameImage("전기4_3", "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	_imgElectric4_4 = IMAGEMANAGER->addFrameImage("전기4_4", "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	_imgElectric4_5 = IMAGEMANAGER->addFrameImage("전기4_5", "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	_imgElectric4_6 = IMAGEMANAGER->addFrameImage("전기4_6", "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	_imgElectric4_7 = IMAGEMANAGER->addFrameImage("전기4_7", "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	_imgHandle = IMAGEMANAGER->addFrameImage("손잡이", "resource/map/effect/handle.bmp", 56, 30, 2, 1, true, RGB(255, 0, 255));
	_imgDoor1 = IMAGEMANAGER->addFrameImage("1문", "resource/map/effect/open_Door.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	_imgDoor2 = IMAGEMANAGER->addFrameImage("2문", "resource/map/effect/open_Door.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	_imgDoor3 = IMAGEMANAGER->addFrameImage("3문", "resource/map/effect/open_Door.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	_imgDoor4 = IMAGEMANAGER->addFrameImage("4문", "resource/map/effect/open_Door.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	_imgButton1 = IMAGEMANAGER->addFrameImage("버튼1", "resource/map/effect/toggle_Button.bmp", 56, 28, 2, 1, true, RGB(255, 0, 255));
	_imgButton2 = IMAGEMANAGER->addFrameImage("버튼2", "resource/map/effect/toggle_Button.bmp", 56, 28, 2, 1, true, RGB(255, 0, 255));
	_imgButton3 = IMAGEMANAGER->addFrameImage("버튼3", "resource/map/effect/toggle_Button.bmp", 56, 28, 2, 1, true, RGB(255, 0, 255));
	_imgBrokenblock = IMAGEMANAGER->addFrameImage("부러진블록", "resource/map/effect/broken_Block.bmp", 96, 32, 3, 1, true, RGB(255, 0, 255));
	_imgBrokencomputer = IMAGEMANAGER->addImage("부러진컴퓨터", "resource/map/effect/broken_computer.bmp", 64, 80, true, RGB(255, 0, 255));
	_imgUpeffect = IMAGEMANAGER->addFrameImage("업효과", "resource/map/effect/up_Effect2.bmp", 512, 512, 4, 1, true, RGB(255, 0, 255));
	_imgElevator = IMAGEMANAGER->addImage("엘레베이터", "resource/map/effect/elevator.bmp", 64, 64, true, RGB(255, 0, 255));

	_rcElectric3 = RectMake(1889, 1504, 64, 32);
	_rcElectric4_1 = RectMake(577, 32, 32, 128);
	_rcElectric4_2 = RectMake(769, 32, 32, 128);
	_rcElectric4_3 = RectMake(1345, 32, 32, 128);
	_rcElectric4_4 = RectMake(1761, 672, 32, 128);
	_rcElectric4_5 = RectMake(1793, 672, 32, 128);
	_rcElectric4_6 = RectMake(1665, 1312, 32, 128);
	_rcElectric4_7 = RectMake(1121, 1312, 32, 128);
	_rcHandle = RectMake(1233, 976, 28, 30);
	_rcDoor1 = RectMake(449, 352, 32, 96);
	_rcDoor2 = RectMake(865, 352, 32, 96);
	_rcDoor3 = RectMake(193, 131, 32, 96);
	_rcDoor4 = RectMake(449, 1472, 32, 96);
	_rcButton1 = RectMake(689, 96, 28, 28);
	_rcButton2 = RectMake(1313, 96, 28, 28);
	_rcButton3 = RectMake(1617, 1376, 28, 28);
	_rcBrokenblock;
	_rcBrokencomputer = RectMake(1249, 1360, 64, 80);
	_rcUpeffect = RectMake(1089, 512, 128, 512);
	_rcLadder1 = RectMake(609, 160, 64, 288);
	_rcLadder2 = RectMake(1153, 160, 64, 288);
	_rcLadder3 = RectMake(1505, 800, 64, 224);
	_rcLadder4 = RectMake(129, 640, 64, 448);
	_rcLadder5 = RectMake(481, 1088, 64, 320);
	_rcLadder6 = RectMake(97, 1408, 64, 160);
	_rcHelp1 = RectMake(305, 398, 32, 32);
	_rcHelp2 = RectMake(369, 398, 32, 32);
	_rcHelp3 = RectMake(625, 104, 32, 32);
	_rcHelp4 = RectMake(1841, 392, 32, 32);
	_rcHelp5 = RectMake(1777, 1384, 32, 32);
	_rcHelp6 = RectMake(1393, 1384, 32, 32);
	_rcElevator = RectMake(1889, 416, 64, 64);

	_frameCount = 0;
	_indexElectric3 = 0;
	_indexElectric4 = 0;
	_indexUpeffect = 0;
	_frameSpeed = 3;

	return S_OK;
}

void MAP2::release()
{
}

void MAP2::update()
{
	if(_frameCount % _frameSpeed == 0)
	{
		_imgElectric3->SetFrameX(_indexElectric3);
		_indexElectric3++;
		if (_indexElectric3 > _imgElectric3->getMaxFrameX())
		{
			_indexElectric3 = 0;
		}

		_frameCount = 0;
	}
	_frameCount++;
}

void MAP2::render(HDC hdc)
{
	_imgElevator->render(hdc, _rcElevator.left, _rcElevator.top);
	_imgElectric3->frameRender(hdc, _rcElectric3.left, _rcElectric3.top);
}

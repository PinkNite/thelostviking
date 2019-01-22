#include "stdafx.h"
#include "map2.h"
#include "player.h"

MAP2::MAP2()
{
}


MAP2::~MAP2()
{
}

HRESULT MAP2::init()
{
	_imgMap2bg = IMAGEMANAGER->addImage("Map2bg", "resource/map/map1-2.bmp", 2048, 1630, true, RGB(255, 0, 255));
	_imgElectric3 = IMAGEMANAGER->addFrameImage("electric3", "resource/map/effect/electric_Shock3.bmp", 448, 32, 7, 1, true, RGB(255, 0, 255));
	_imgHandleOff = IMAGEMANAGER->addImage("handleOff", "resource/map/effect/handleOff.bmp", 28, 30, true, RGB(255, 0, 255));
	_imgHandleOn = IMAGEMANAGER->addImage("handleOn", "resource/map/effect/handleOn.bmp", 28, 30, true, RGB(255, 0, 255));
    for (int i = 0; i < MAXBROKENBLOCK; i++)
	{
		//sprintf_s(str, "brokenBlock%d", i);
		_imgBrokenblock[i] = IMAGEMANAGER->addFrameImage(str, "resource/map/effect/broken_Block.bmp", 96, 32, 3, 1, true, RGB(255, 0, 255));
		_arrBool[i] = false;
	}

	_imgBrokencomputer = IMAGEMANAGER->addImage("brokenComputer", "resource/map/effect/broken_computer.bmp", 64, 80, true, RGB(255, 0, 255));
	_imgUpeffect = IMAGEMANAGER->addFrameImage("upEffect", "resource/map/effect/up_Effect2.bmp", 512, 512, 4, 1, true, RGB(255, 0, 255));
	_imgElevator = IMAGEMANAGER->addImage("elevator", "resource/map/effect/elevator.bmp", 64, 64, true, RGB(255, 0, 255));
	
	_rcElectric3 = RectMake(1889, 1504, 64, 32);
	_rcHandle = RectMake(1233, 976, 28, 30);
	_rcBrokenblocks = RectMake(673, 960, 96, 128);
	_rcBrokencomputer = RectMake(1249, 1360, 64, 80);
	_rcUpeffect = RectMake(1089, 512, 128, 512);
	_rcLadder[0] = RectMake(609, 160, 64, 288);
	_rcLadder[1] = RectMake(1153, 160, 64, 288);
	_rcLadder[2] = RectMake(1505, 800, 64, 224);
	_rcLadder[3] = RectMake(129, 640, 64, 448);
	_rcLadder[4] = RectMake(481, 1088, 64, 320);
	_rcLadder[5] = RectMake(97, 1408, 64, 160);
	_rcHelp[0] = RectMake(305, 398, 32, 32);
	_rcHelp[1] = RectMake(369, 398, 32, 32);
	_rcHelp[2] = RectMake(625, 104, 32, 32);
	_rcHelp[3] = RectMake(1841, 392, 32, 32);
	_rcHelp[4] = RectMake(1777, 1384, 32, 32);
	_rcHelp[5] = RectMake(1393, 1384, 32, 32);
	_rcElevator = RectMake(1889, 416, 64, 64);
	_rcExit = RectMake(609, 1472, 64, 96);
	for (int i = 0; i < 3; i++)
	{
		_rcBrokenblock[i] = RectMake(673, 1055 - i * 32, 32, 32);
	}
	for (int i = 3; i < 6; i++)
	{
		_rcBrokenblock[i] = RectMake(673 + 32, 992 + (i-3) * 32, 32, 32);
	}
	for (int i = 6; i < 9; i++)
	{
		_rcBrokenblock[i] = RectMake(673 + 64, 1055 - (i-6) * 32, 32, 32);
	}

	_indexElectric3 = 0;
	_indexElectric4 = 0;
	_indexUpeffect = 0;
	_indexBrokenblock = 0;
	_countUpeffect = 0;
	_countBrokenblock = 0;
	_speedUpeffect = 5;
	_speedBrokenblock = 20;
	_arrBlocki = 0;
	_arrBlockj = 0;
	_arrNum = 0;

	_isElevatorMove = false;
	_checkElevatorUpdown = false;
	_isHandle = false;
	_isBrokenblocks = false;

	electricInit();
	doorInit();
	buttonInit();

	return S_OK;
}

void MAP2::release()
{
}

void MAP2::update()
{
	playerRect = RectMakeCenter(_pPlayer->getPosX(), _pPlayer->getPosY(), _pPlayer->getWidth(), _pPlayer->getHeight());

	for (int i = 0; i < _vElectric.size(); i++)
	{
		_vElectric[i]->update();
	}
	for (int i = 0; i < _vDoor.size(); i++)
	{
		_vDoor[i]->update();
	}
	for (int i = 0; i < _vButton.size(); i++)
	{
		_vButton[i]->update();
	}

	// moving Elevator start
	if (_isElevatorMove == true && _checkElevatorUpdown == true)
	{
		if (_rcElevator.top > 416 && _rcElevator.top <= 768)
		{	
			if (_rcElevator.top == 418)
			{
				_rcElevator.top -= _speedElevator;
				_rcElevator.bottom -= _speedElevator;
				_isElevatorMove = false;
			}
			else
			{
				_rcElevator.top -= _speedElevator;
				_rcElevator.bottom -= _speedElevator;
			}
		}

		else if (_rcElevator.top > 768 && _rcElevator.top <= 1408)
		{
			if (_rcElevator.top == 770)
			{
				_rcElevator.top -= _speedElevator;
				_rcElevator.bottom -= _speedElevator;
				_isElevatorMove = false;
			}
			else
			{
				_rcElevator.top -= _speedElevator;
				_rcElevator.bottom -= _speedElevator;
			}
		}
	}

	if (_isElevatorMove == true && _checkElevatorUpdown == false)
	{
		if (_rcElevator.top >= 416 && _rcElevator.top < 768)
		{
			if (_rcElevator.top == 766)
			{
				_rcElevator.top += _speedElevator;
				_rcElevator.bottom += _speedElevator;
				_isElevatorMove = false;
			}
			else
			{
				_rcElevator.top += _speedElevator;
				_rcElevator.bottom += _speedElevator;
			}
		}
		
		else if (_rcElevator.top >= 768 && _rcElevator.top < 1408)
		{
			if (_rcElevator.top == 1406)
			{
				_rcElevator.top += _speedElevator;
				_rcElevator.bottom += _speedElevator;
				_isElevatorMove = false;
			}
			else
			{
				_rcElevator.top += _speedElevator;
				_rcElevator.bottom += _speedElevator;
			}
		}
	}
	// moving Elevator end

	if (_isHandle == true)
	{
		if (_countUpeffect % _speedUpeffect == 0)
		{
			_imgUpeffect->SetFrameX(_indexUpeffect);
			_indexUpeffect++;
			if (_indexUpeffect > _imgUpeffect->getMaxFrameX())
			{
				_indexUpeffect = 0;
			}
			_countUpeffect = 0;
		}
		_countUpeffect++;
	}

	if (_isBrokenblocks == true)
	{
		if (_arrNum < MAXBROKENBLOCK)
		{
			_arrBool[_arrNum] = true;
			if (_countBrokenblock % _speedBrokenblock == 0)
			{
				_imgBrokenblock[_arrNum]->SetFrameX(_indexBrokenblock);
				_indexBrokenblock++;
				if (_indexBrokenblock > _imgBrokenblock[_arrNum]->getMaxFrameX())
				{
					_imgBrokenblock[_arrNum]->SetFrameX(_imgBrokenblock[_arrNum]->getMaxFrameX());
					_indexBrokenblock = 0;
					_arrNum++;
				}
				_countBrokenblock = 0;
			}
			_countBrokenblock++;
		}
	}
	for (int i = 0; i < 12; i++)
	{
		//printf("_arrBool[%d] : %d \n", i, _arrBool[i]);
		//printf("_imgBrokenblock[%d]->getFrameX(%d) \n", i, _imgBrokenblock[i]->getFrameX());
	}
	/*테스트용*/
	
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_isBrokenblocks = true;
	}
	
	// 자동문
	for (int i = 0; i < _vDoor.size(); i++)
	{
		RECT tempRc;
		if (IntersectRect(&tempRc, &_vDoor[i]->getColiisionArea(), &playerRect))
		{
			_vDoor[i]->setIsoff(true);
		}
		else
		{
			_vDoor[i]->setIsoff(false);
		}
	}
//		if (KEYMANAGER->isOnceKeyDown('S'))
//	{
//	}
	/*
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_isHandle = true;
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_isHandle = false;
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_isMove = true;
		_checkUpdown = false;
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_isMove = true;
		_checkUpdown = true;
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_vElectric[0]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('1'))
	{
		_vElectric[0]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_vElectric[1]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('2'))
	{
		_vElectric[1]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_vElectric[2]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('3'))
	{
		_vElectric[2]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_vElectric[3]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('4'))
	{
		_vElectric[3]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_vElectric[4]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('5'))
	{
		_vElectric[4]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_vElectric[5]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('6'))
	{
		_vElectric[5]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_vElectric[6]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('7'))
	{
		_vElectric[6]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_vDoor[0]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('1'))
	{
		_vDoor[0]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_vDoor[1]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('2'))
	{
		_vDoor[1]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_vDoor[2]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('3'))
	{
		_vDoor[2]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_vDoor[3]->setIsoff(true);
	}
	else if (KEYMANAGER->isOnceKeyUp('4'))
	{
		_vDoor[3]->setIsoff(false);
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_vButton[0]->setIsoff(true);
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_vButton[1]->setIsoff(true);
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_vButton[2]->setIsoff(true);
	}
	*/
}

void MAP2::render(HDC hdc)
{
	_imgElevator->render(hdc, _rcElevator.left, _rcElevator.top);
	_imgElectric3->frameRender(hdc, _rcElectric3.left, _rcElectric3.top);

	if (_isBrokenComputer == true)
	{
		_imgBrokencomputer->render(hdc, _rcBrokencomputer.left, _rcBrokencomputer.top);
	}
	if (_isHandle == false)
	{
		_imgHandleOff->render(hdc, _rcHandle.left, _rcHandle.top);
		_imgUpeffect->frameRender(hdc, _rcUpeffect.left, _rcUpeffect.top);
	}
	else if (_isHandle == true)
	{
		_imgHandleOn->render(hdc, _rcHandle.left, _rcHandle.top);
		_imgUpeffect->frameRender(hdc, _rcUpeffect.left, _rcUpeffect.top);
	}

	for (int i = 0; i < _vElectric.size(); i++)
	{
		if (_vElectric[i]->getIsoff() == false)
		{
			_vElectric[i]->render(hdc);
		}
	}
	for (int i = 0; i < _vDoor.size(); i++)
	{
		_vDoor[i]->render(hdc);
	}
	for (int i = 0; i < _vButton.size(); i++)
	{
		_vButton[i]->render(hdc);
	}
	
	if (_isBrokenblocks == true)
	{
		for (int i = 0; i < MAXBROKENBLOCK; i++)
		{
			if (_arrBool[i] == true)
			{
				_imgBrokenblock[i]->frameRender(hdc, _rcBrokenblock[i].left, _rcBrokenblock[i].top);
			}
		}
	}
	
}

void MAP2::electricInit()
{
	/*
	_rcElectric4_1 = RectMake(577, 32, 32, 128);
	_rcElectric4_2 = RectMake(769, 32, 32, 128);
	_rcElectric4_3 = RectMake(1345, 32, 32, 128);
	_rcElectric4_4 = RectMake(1761, 672, 32, 128);
	_rcElectric4_5 = RectMake(1793, 672, 32, 128);
	_rcElectric4_6 = RectMake(1665, 1312, 32, 128);
	_rcElectric4_7 = RectMake(1121, 1312, 32, 128);
	*/
	setELECTRIC* electricObtacle = new ELECTRICS;
	electricObtacle->init("electricObc1", 577, 32, 32, 128);
	_vElectric.push_back(electricObtacle);

	electricObtacle = new ELECTRICS;
	electricObtacle->init("electricObc2", 769, 32, 32, 128);
	_vElectric.push_back(electricObtacle);

	electricObtacle = new ELECTRICS;
	electricObtacle->init("electricObc3", 1345, 32, 32, 128);
	_vElectric.push_back(electricObtacle);

	electricObtacle = new ELECTRICS;
	electricObtacle->init("electricObc4", 1761, 672, 32, 128);
	_vElectric.push_back(electricObtacle);

	electricObtacle = new ELECTRICS;
	electricObtacle->init("electricObc5", 1793, 672, 32, 128);
	_vElectric.push_back(electricObtacle);

	electricObtacle = new ELECTRICS;
	electricObtacle->init("electricObc6", 1665, 1312, 32, 128);
	_vElectric.push_back(electricObtacle);

	electricObtacle = new ELECTRICS;
	electricObtacle->init("electricObc7", 1121, 1312, 32, 128);
	_vElectric.push_back(electricObtacle);
}

void MAP2::doorInit()
{
	setDOOR* doorObtacle = new DOORS;
	doorObtacle->init("doorObc1", 449, 352, 32, 96, false, 3);
	_vDoor.push_back(doorObtacle);

	doorObtacle = new DOORS;
	doorObtacle->init("doorObc2", 865, 352, 32, 96, false, 3);
	_vDoor.push_back(doorObtacle);

	doorObtacle = new DOORS;
	doorObtacle->init("doorObc3", 193, 1312, 32, 96, false, 3);
	_vDoor.push_back(doorObtacle);

	doorObtacle = new DOORS;
	doorObtacle->init("doorObc4", 449, 1472, 32, 96, false, 3);
	_vDoor.push_back(doorObtacle);
}

void MAP2::buttonInit()
{
	setBUTTON* buttonTrigger = new BUTTONS;
	buttonTrigger->init("buttonTri1", 689, 96, 28, 28);
	_vButton.push_back(buttonTrigger);

	buttonTrigger = new BUTTONS;
	buttonTrigger->init("buttonTri2", 1313, 96, 28, 28);
	_vButton.push_back(buttonTrigger);

	buttonTrigger = new BUTTONS;
	buttonTrigger->init("buttonTri3", 1617, 1376, 28, 28);
	_vButton.push_back(buttonTrigger);
}

#include "stdafx.h"
#include "setTRIGGER.h"


setTRIGGER::setTRIGGER()
{
}

setTRIGGER::~setTRIGGER()
{
}

setELECTRIC::setELECTRIC()
{
}

setELECTRIC::~setELECTRIC()
{
}

HRESULT setELECTRIC::init(string strKey, int x, int y, int width, int height, int frameSpeed)
{
	Electric4.isOff = false;
	Electric4.imgTrigger = IMAGEMANAGER->addFrameImage(strKey, "resource/map/effect/electric_Shock4.bmp", 96, 128, 3, 1, true, RGB(255, 0, 255));
	Electric4.rcTrigger = RectMake(x, y, width, height);
	_currentFrameX = _currentFrameY = 0;
	_currentPframeX = _currentPframeY = 0;

	_index = 0;
	_frameSpeed = frameSpeed;

	return S_OK;
}

void setELECTRIC::release()
{
}

void setELECTRIC::update()
{
	if (_frameCount % _frameSpeed == 0)
	{
		Electric4.imgTrigger->SetFrameX(_currentFrameX);
		_currentFrameX++;
		if (_currentFrameX > Electric4.imgTrigger->getMaxFrameX())
		{
			_currentFrameX = 0;
		}
		_frameCount = 0;
	}
	_frameCount++;
}

void setELECTRIC::render(HDC hdc)
{
	Electric4.imgTrigger->frameRender(hdc, Electric4.rcTrigger.left, Electric4.rcTrigger.top, _currentFrameX, _currentFrameY);
}

setDOOR::setDOOR()
{
}

setDOOR::~setDOOR()
{
}

HRESULT setDOOR::init(string strKey, int x, int y, int width, int height, bool isCollision, int frameSpeed)
{
	Door.isOff = false;
	if(isCollision == false)
	{
		Door.imgTrigger = IMAGEMANAGER->addFrameImage(strKey, "resource/map/effect/open_Door.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	}
	else
	{
		Door.imgTrigger = IMAGEMANAGER->addFrameImage(strKey, "resource/map/effect/open_DoorCollision.bmp", 128, 96, 4, 1, true, RGB(255, 0, 255));
	}
	Door.rcTrigger = RectMake(x, y, width, height);
	Door.rcColiisionArea = RectMake(x - 30, y, width + 60, height);

	_currentFrameX = _currentFrameY = 0;
	_currentPframeX = _currentPframeY = 0;

	_index = 0;
	_frameSpeed = frameSpeed;

	return S_OK;
}

void setDOOR::release()
{
}

void setDOOR::update()
{
	if (Door.isOff == false)
	{
		if (_frameCount % _frameSpeed == 0)
		{
			Door.imgTrigger->SetFrameX(_currentFrameX);
			_currentFrameX--;
			if (_currentFrameX <= 0)
			{
				_currentFrameX = 0;
			}
			_frameCount = 0;
		}
		_frameCount++;
	}

	if (Door.isOff == true)
	{
		if (_frameCount % _frameSpeed == 0)
		{
			Door.imgTrigger->SetFrameX(_currentFrameX);
			_currentFrameX++;
			if (_currentFrameX > Door.imgTrigger->getMaxFrameX())
			{
				_currentFrameX = Door.imgTrigger->getMaxFrameX();
			}
			_frameCount = 0;
		}
		_frameCount++;
	}
}

void setDOOR::render(HDC hdc)
{
	Door.imgTrigger->frameRender(hdc, Door.rcTrigger.left, Door.rcTrigger.top, _currentFrameX, _currentFrameY);
}

setBUTTON::setBUTTON()
{
}

setBUTTON::~setBUTTON()
{
}

HRESULT setBUTTON::init(string strKey, int x, int y, int width, int height, int frameSpeed)
{
	Button.isOff = false;
	Button.imgTrigger = IMAGEMANAGER->addFrameImage(strKey, "resource/map/effect/toggle_Button.bmp", 140, 28, 5, 1, true, RGB(255, 0, 255));
	Button.rcTrigger = RectMake(x, y, width, height);

	_currentFrameX = _currentFrameY = 0;
	_currentPframeX = _currentPframeY = 0;

	_index = 0;
	_frameSpeed = frameSpeed;

	return S_OK;
}

void setBUTTON::release()
{
}

void setBUTTON::update()
{
	if (Button.isOff == true)
	{
		if (_frameCount % _frameSpeed == 0)
		{
			Button.imgTrigger->SetFrameX(_currentFrameX);
			_currentFrameX++;
			if (_currentFrameX > Button.imgTrigger->getMaxFrameX())
			{
				Button.imgTrigger->SetFrameX(0);
				_currentFrameX = 0;
				Button.isOff = false;
			}
			_frameCount = 0;
		}
		_frameCount++;
	}

	//printf("1버튼 상태 : %d, 현재 프레임은? : %d\n", Button.isOff, _currentFrameX);
}

void setBUTTON::render(HDC hdc)
{
	Button.imgTrigger->frameRender(hdc, Button.rcTrigger.left, Button.rcTrigger.top, _currentFrameX, _currentFrameY);
}

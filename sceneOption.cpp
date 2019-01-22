#include "stdafx.h"
#include "sceneOption.h"




SCENEOPTION::SCENEOPTION()
{
}

SCENEOPTION::~SCENEOPTION()
{
}

HRESULT SCENEOPTION::init()
{
	_pBackGround = new image;
	_pBackGround = IMAGEMANAGER->findImage("black");
	_backGroundAlphaCount = 255;

	_pImageTitle = new image;
	_pImageTitle = IMAGEMANAGER->findImage("introTitle");
	_imageTitleAlphaCount = 255;

	_pImageMenu = new image;
	_pImageMenu = IMAGEMANAGER->findImage("option");
	_imageMenuAlphaCount = 255;

	_pImageSelect = new image;
	_pImageSelect = IMAGEMANAGER->findImage("select");
	_imageSelectAlphaCount = 255;

	_pImageNumButton = new image;
	_pImageNumButton = IMAGEMANAGER->findImage("ONETWO");
	_imageNumButton = 255;

	_pImageOnOffButton = new image;
	_pImageOnOffButton = IMAGEMANAGER->findImage("ONOFF");
	_imageOnOffButton = 255;

	_numButtonFrameX = 0;
	_onOffButtonFrameX = 0;
	_onOffButtonFrameX2 = 0;
	_onOffButtonFrameX3 = 0;
	_y = 208;//32씩 더하면 이동함
	return S_OK;
}

void SCENEOPTION::release()
{
}

void SCENEOPTION::update()
{
	if (_numButtonFrameX % 2 == -1)
	{
		_numButtonFrameX = 1;
	}
	if (_numButtonFrameX % 2 == 0)
	{
		_numButtonFrameX = 0;
	}
	if (_onOffButtonFrameX % 2 == -1)
	{
		_onOffButtonFrameX = 1;
	}
	if (_onOffButtonFrameX % 2 == 0)
	{
		_onOffButtonFrameX = 0;
	}
	if (_onOffButtonFrameX2 % 2 == -1)
	{
		_onOffButtonFrameX2 = 1;
	}
	if (_onOffButtonFrameX2 % 2 == 0)
	{
		_onOffButtonFrameX2 = 0;
	}
	if (_onOffButtonFrameX3 % 2 == -1)
	{
		_onOffButtonFrameX3 = 1;
	}
	if (_onOffButtonFrameX3 % 2 == 0)
	{
		_onOffButtonFrameX3 = 0;
	}


	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _y > 208)
	{
		if (_y == 360)
		{
			_y = 304;
		}
		else if (_y <= 304)
		{
			_y -= 32;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _y <= 360)
	{
		if (_y == 304)
		{
			_y = 360;
		}
		if (_y < 304)
		{
			_y += 32;
		}

	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _y == 360)
	{
		SCENEMANAGER->changeScene("MENU");
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT) || KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		switch ((int)_y)
		{
		case 208:
			_numButtonFrameX++;
			break;
		case 240:

			_onOffButtonFrameX++;
			break;
		case 272:


			_onOffButtonFrameX2++;
			break;
		case 304:

			_onOffButtonFrameX3++;
			break;

		}
	}
	if (KEYMANAGER->isOnceKeyDown('V'))//예시
	{
		_onOffButtonFrameX++;
	}
}

void SCENEOPTION::render()
{


	//_pBackGround->render(getMemDC(), 0, 0);
	_pImageTitle->alphaRender(getMemDC(), 0, 0, _imageTitleAlphaCount);
	_pImageMenu->alphaRender(getMemDC(), 0, 213, _imageMenuAlphaCount);
	_pImageSelect->alphaRender(getMemDC(), -20, _y, _imageSelectAlphaCount);

	_pImageNumButton->frameRender(getMemDC(), 386, 224, _numButtonFrameX, 0);
	//키입력을 받으면 x가 증가 하거나 마이너스한다 
	_pImageOnOffButton->frameRender(getMemDC(), 386, 256, _onOffButtonFrameX, 0);
	_pImageOnOffButton->frameRender(getMemDC(), 386, 288, _onOffButtonFrameX2, 0);
	_pImageOnOffButton->frameRender(getMemDC(), 386, 320, _onOffButtonFrameX3, 0);



}

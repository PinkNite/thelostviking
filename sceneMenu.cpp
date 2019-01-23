#include "stdafx.h"
#include "sceneMenu.h"

SCENEMENU::SCENEMENU()
{
}

SCENEMENU::~SCENEMENU()
{
}

HRESULT SCENEMENU::init()
{
	_pBackGround = new image;
	_pBackGround = IMAGEMANAGER->findImage("black");
	_backGroundAlphaCount = 255;

	_pImageTitle = new image;
	_pImageTitle = IMAGEMANAGER->findImage("introTitle");
	_imageTitleAlphaCount = 255;

	_pImageMenu = new image;
	_pImageMenu = IMAGEMANAGER->findImage("menu");
	_imageMenuAlphaCount = 255;

	_pImageSelect = new image;
	_pImageSelect = IMAGEMANAGER->findImage("select");
	_imageSelectAlphaCount = 255;

	_y = 240;


	_gameStart = 0;
	return S_OK;
}

void SCENEMENU::release()
{
}

void SCENEMENU::update()
{

	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _y > 240)
	{
		SOUNDMANAGER->play("button", 1.0f);
		_y -= 32;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN) && _y <= 272)
	{
		SOUNDMANAGER->play("button", 1.0f);
		_y += 32;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("button", 1.0f);
		switch ((int)_y)
		{
		case 240:
			
			//SCENEMANAGER->changeScene("GAMEPLAY");
			break;
		case 272:


			
			SCENEMANAGER->changeScene("OPTION");
			break;
		case 304:
			
			SCENEMANAGER->changeScene("PASSWORD");
			break;
		}
	}


	/*

	_y값을 받아서 처리 할수 있도록한다.

	_y가 240이면 스타트 뉴게임 뉴게임이면 다른신으로 전환
	if(와이가 240이고 키입력을 받으면)
	{
		알파값전달
	}
	_y가 240
	*/
}

void SCENEMENU::render()
{
	_pBackGround->render(getMemDC(), 0, 0);
	_pImageTitle->alphaRender(getMemDC(), 0, 0, _imageTitleAlphaCount);
	_pImageMenu->alphaRender(getMemDC(), 0, 240, _imageMenuAlphaCount);
	_pImageSelect->alphaRender(getMemDC(), 0, _y, _imageSelectAlphaCount);
}

#include "stdafx.h"
#include "scenePassword.h"


SCENEPASSWORD::SCENEPASSWORD()
{
}

SCENEPASSWORD::~SCENEPASSWORD()
{
}

HRESULT SCENEPASSWORD::init()
{
	_pBackGround = new image;
	_pBackGround = IMAGEMANAGER->findImage("password");
	_backGroundAlphaCount = 255;
	return S_OK;
}

void SCENEPASSWORD::release()
{
}

void SCENEPASSWORD::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene("MENU");
	}
}

void SCENEPASSWORD::render()
{
	_pBackGround->alphaRender(getMemDC(), 0, 0, _backGroundAlphaCount);
}

#include "stdafx.h"
#include "backGround.h"

BACKGROUND::BACKGROUND()
{
}

BACKGROUND::~BACKGROUND()
{
}

HRESULT BACKGROUND::init()
{
	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("�������ȭ��");
	_alphaCount = 255;
	return S_OK;
}

void BACKGROUND::release()
{
}

void BACKGROUND::update()
{
}

void BACKGROUND::render()
{
	_pImage->alphaRender(getMemDC(), 0, 0, _alphaCount);
}

BACKGROUND2::BACKGROUND2()
{
}

BACKGROUND2::~BACKGROUND2()
{
}

HRESULT BACKGROUND2::init()
{
	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("��ũ���");
	_alphaCount = 255;
	return S_OK;

}

void BACKGROUND2::release()
{
}

void BACKGROUND2::update()
{
}

void BACKGROUND2::render()
{
	_pImage->alphaRender(getMemDC(), 0, 0, _alphaCount);
}

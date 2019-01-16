#include "stdafx.h"
#include "scene0.h"

SCENE0::SCENE0()
{
}

SCENE0::~SCENE0()
{
}

HRESULT SCENE0::init()
{
	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("검은배경화면");

	_alphaCount = 255;
	return S_OK;
}

void SCENE0::release()
{
}

void SCENE0::update()
{

}

void SCENE0::render()
{
	_pImage->alphaRender(getMemDC(), 0, 0, _alphaCount);
}

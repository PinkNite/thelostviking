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
	return S_OK;
}

void SCENEMENU::release()
{
}

void SCENEMENU::update()
{

	/*

	_y���� �޾Ƽ� ó�� �Ҽ� �ֵ����Ѵ�.

	_y�� 240�̸� ��ŸƮ ������ �������̸� �ٸ������� ��ȯ
	if(���̰� 240�̰� Ű�Է��� ������)
	{
		���İ�����
	}
	_y�� 240
	*/
}

void SCENEMENU::render()
{
	_pBackGround->render(getMemDC(), 0, 0);
	_pImageTitle->alphaRender(getMemDC(), 0, 0, _imageTitleAlphaCount);
	_pImageMenu->alphaRender(getMemDC(), 0, 240, _imageMenuAlphaCount);
	_pImageSelect->alphaRender(getMemDC(), 0, _y, _imageSelectAlphaCount);
}

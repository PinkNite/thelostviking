#include "stdafx.h"
#include "scene1.h"


SCENE1::SCENE1()
{
}

SCENE1::~SCENE1()
{
}

HRESULT SCENE1::init()
{
	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("��Ʈ��1");
	_alphaCount = 0;
	return S_OK;
}

void SCENE1::release()
{
}

void SCENE1::update()
{

	action(0, 7.0f, 7.0f);
}

void SCENE1::render()
{
	_pImage->alphaRender(getMemDC(), 0, 0, _alphaCount);
}

void SCENE1::action(float numA, float numB, float numC)
{
	if (_alphaCount < 255 && TIMEMANAGER->getWorldTime() < numB
		&&TIMEMANAGER->getWorldTime() > numA)
	{

		_alphaCount++;
	}
	if (TIMEMANAGER->getWorldTime() >= numC)//12�ʳ����� ���İ� �ٿ��� �������
	{

		if (_alphaCount > 0)
		{
			_alphaCount -= 5;//�� �� ������ ������� �ϱ� ����
		}
	}
}

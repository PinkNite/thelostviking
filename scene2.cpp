#include "stdafx.h"
#include "scene2.h"




SCENE2::SCENE2()
{
}

SCENE2::~SCENE2()
{
}

HRESULT SCENE2::init()
{

	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("��Ʈ��2");
	_alphaCount = 0;

	return S_OK;
}

void SCENE2::release()
{
}

void SCENE2::update()
{

	action(9.0f, 12.0f, 12.0f);

}

void SCENE2::render()
{
	_pImage->alphaRender(getMemDC(), 0, 0, _alphaCount);
}

void SCENE2::action(float numA, float numB, float numC)
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
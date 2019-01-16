#include "stdafx.h"
#include "scene3.h"




SCENE3::SCENE3()
{
}

SCENE3::~SCENE3()
{
}

HRESULT SCENE3::init()
{
	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("인트로3");
	_alphaCount = 0;


	return S_OK;
}

void SCENE3::release()
{
}

void SCENE3::update()
{

	action(14.0f, 18.0f);
}

void SCENE3::render()
{
	_pImage->alphaRender(getMemDC(), 0, 0, _alphaCount);
}

void SCENE3::action(float numA, float numB, float numC)
{
	if (_alphaCount < 255 && TIMEMANAGER->getWorldTime() < numB
		&&TIMEMANAGER->getWorldTime() > numA)
	{

		_alphaCount += 5;
	}
	if (TIMEMANAGER->getWorldTime() >= numC)//12초넘으면 알파갑 줄여서 사라지게
	{

		if (_alphaCount > 0)
		{
			_alphaCount -= 5;//좀 더 빠르게 사라지게 하기 위함
		}
	}
}
void SCENE3::action(float numA, float numB)
{
	if (_alphaCount < 255 && TIMEMANAGER->getWorldTime() < numB
		&&TIMEMANAGER->getWorldTime() > numA)
	{

		_alphaCount++;
	}

}

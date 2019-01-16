#include "stdafx.h"
#include "scene4.h"


SCENE4::SCENE4()
{
}

SCENE4::~SCENE4()
{
}

HRESULT SCENE4::init()
{

	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("인트로행님");
	_y = -204;
	_alphaCount = 255;
	_jumpPower = 0;
	_gravity = 1;
	_jumpCount = 1;
	//튀는 이미지를 위해서 176이 도착지점 

	return S_OK;
}

void SCENE4::release()
{
}

void SCENE4::update()
{
	//action(14.0f, 18.0f);//알파값받으면서 생김?
	//움직여라
	if (TIMEMANAGER->getWorldTime() >= 17.0f&&_y <= 176)
	{
		_y -= _jumpPower;//점프파워
		_jumpPower -= _gravity;//중력적용
	}

	if (_y >= 176)
	{
		switch (_jumpCount)//카운트에따라 다르게 점프한번만 시키자
		{
		case 0:
			_y = 176;
			break;
		case 1:  //점프해야함
			_jumpCount--;
			_jumpPower = 10;

			break;

		}
	}


}
void SCENE4::render()
{
	_pImage->alphaRender(getMemDC(), 0, _y, _alphaCount);
}

void SCENE4::action(float numA, float numB, float numC)
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

void SCENE4::action(float numA, float numB)
{
	if (_alphaCount < 255 && TIMEMANAGER->getWorldTime() < numB
		&&TIMEMANAGER->getWorldTime() > numA)
	{

		_alphaCount++;
	}
}

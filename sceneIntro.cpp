#include "stdafx.h"
#include "sceneIntro.h"


SCENEINTRO::SCENEINTRO()
{
}

SCENEINTRO::~SCENEINTRO()
{
}

HRESULT SCENEINTRO::init()
{
	_pBackGround = new image;
	_pBackGround = IMAGEMANAGER->findImage("black");

	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("pink");//초기화

	_pImage2 = new image;
	_pImage2 = IMAGEMANAGER->findImage("pink");


	_imageAlphaCount = 0;
	_image2AlphaCount = 255;
	_backGroundAlphaCount = 255;
	_y = -204;
	_y2 = 0;
	_jumpPower = 0;
	_jumpCount = 1;
	_gravity = 0.5f;
	_time = 0;

	return S_OK;
}

void SCENEINTRO::release()
{
}

void SCENEINTRO::update()
{
	_time += TIMEMANAGER->getElpasedTime();//신이 시작되면 이렇게됨..

	actionOnOff(5.0f, 6.0f, 9.0f, &_imageAlphaCount, "intro1");//5초에 나오고 9초에 사라짐
	actionOnOff(12.0f, 13.0f, 16.0f, &_imageAlphaCount, "intro2");
	actionOn(19.0f, 20.0f, 23.0f, &_imageAlphaCount, "intro3");//1920
	actionJump(21, 21.7f, 23, &_image2AlphaCount, "introTitle", &_y, &_y2);//2122



}

void SCENEINTRO::render()
{
	_pBackGround->alphaRender(getMemDC(), 0, 0, _backGroundAlphaCount);//렌더는 계속중임
	_pImage->alphaRender(getMemDC(), 0, _y2, _imageAlphaCount);//렌더는 계속중임
	_pImage2->alphaRender(getMemDC(), 0, _y, _image2AlphaCount);//

	char str[128];
	sprintf_s(str, "%lf", _time);
	TextOut(getMemDC(), 200, 200, str, strlen(str));

}

void SCENEINTRO::actionOnOff(float numA, float numB, float numC, int* alpha, const char* keyName)//_pImage
{

	if (_time >= numA &&
		_time < numB&&
		*alpha < 255)
	{

		_pImage = IMAGEMANAGER->findImage(keyName);

	}
	if ((*alpha) < 255 && _time < numC&&_time >= numA)
	{
		(*alpha) += 5;
	}
	if (_time >= numC && _time < (numC + 2) && (*alpha) > 0)
	{
		(*alpha) -= 5;
	}


}

void SCENEINTRO::actionOn(float numA, float numB, float numC, int * alpha, const char * keyName)
{
	if (_time >= numA &&
		_time < numB&&
		*alpha < 255)
	{
		_pImage = IMAGEMANAGER->findImage(keyName);

	}
	if ((*alpha) < 255 && _time < numC&&_time >= numA)
	{
		(*alpha) += 5;
	}


}

void SCENEINTRO::actionJump(float numA, float numB, float numC, int * alpha, const char * keyName, float* y, float* y2)
{

	if (_time >= numA &&
		_time < numB&&
		*alpha <= 255)
	{
		_pImage2 = IMAGEMANAGER->findImage(keyName);

	}
	if (*y < 176 && _time >= numA)
	{
		*y -= _jumpPower;
		_jumpPower -= _gravity;
	}
	if (*y >= 176 && _jumpCount == 1)
	{

		_jumpPower = 10.5f;
		*y -= _jumpPower;
		_jumpCount--;

		time = _time;

	}
	if (_time > numB&&time <= _time + 2.0f)
	{
		*y2 = RND->getFromIntTo(0, 10);
	}

	if (*y >= 176 && _jumpCount == 0)
	{
		*y = 176;
		*y2 = 0;
	}

}


#include "stdafx.h"
#include "ship.h"


ship::ship()
{
}


ship::~ship()
{
}

HRESULT ship::init(const char * imageName, int x, int y)
{
	//키 값으로 배의 이미지를 찾아서 대입해준다
	_image = IMAGEMANAGER->findImage(imageName);

	_x = x;
	_y = y;

	_angle = 0.0f;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

	_speed = 0;
	_radius = _image->getFrameWidth() / 2;

	return S_OK;
}

void ship::release()
{
}

void ship::update()
{
	move();
}

void ship::render()
{
	draw();
}

void ship::draw()
{
	_image->frameRender(getMemDC(), _rc.left, _rc.top);

	char str[128];
	sprintf_s(str, "%d 도, %3.2f", int(_angle * 180 / PI), _speed);
	TextOut(getMemDC(), _rc.left, _rc.top - 15, str, strlen(str));
}

void ship::keyControl()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_angle += 0.04f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_angle -= 0.04f;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP)) _speed += 0.04f;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _speed -= 0.04f;
}

//죵말죵말중요
void ship::move()
{
	int frame;			//각도에 따른 프레임 번호
	float angle;		//이미지 각도

	angle = _angle + PI16;

	frame = int(angle / PI8);
	_image->SetFrameX(frame);

	float elapsedTime = TIMEMANAGER->getElpasedTime();
	float moveSpeed = elapsedTime * 100;

	_x += cosf(_angle) * _speed * moveSpeed;
	_y += -sinf(_angle) * _speed * moveSpeed;

	_rc = RectMakeCenter(_x, _y, _image->getFrameWidth(), _image->getFrameHeight());

}

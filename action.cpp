#include "stdafx.h"
#include "action.h"


action::action()
{
}


action::~action()
{
}

HRESULT action::init()
{
	_worldTimeCount = 0;
	_isMoving = false;

	return S_OK;
}

void action::release()
{
}

void action::update()
{
	moving();
}

void action::render()
{
}

void action::moveTo(image* image, float endX, float endY, float time)
{
	if (!_isMoving)
	{
		_image = image;

		_endX = endX;	//������ ��ǥ�� �޾Ƶΰ�
		_endY = endY;

		_startX = image->GetX();//�̹����� ������ǥ�� �ް�
		_startY = image->GetY();

		//����Ÿ��� ���صд�
		_travelRange = getDistance(_startX, _startY, _endX, _endY);

		//������ �����ش�
		_angle = getAngle(_startX, _startY, _endX, _endY);

		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_time = time;

		_isMoving = true;
	}
}

void action::moving()
{
	if (!_isMoving) return;

	float elapsedTime = TIMEMANAGER->getElpasedTime();

	//����� �ٽ��Դ���!!! ��κ�!!!
	float moveSpeed = (elapsedTime / _time) * _travelRange;

	_image->SetX(_image->GetX() + cosf(_angle) * moveSpeed);
	_image->SetY(_image->GetY() + -sinf(_angle) * moveSpeed);

	if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())
	{
		_worldTimeCount = TIMEMANAGER->getWorldTime();

		_image->SetX(_endX);
		_image->SetY(_endY);

		_isMoving = false;
	}
}

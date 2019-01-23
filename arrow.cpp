#include "stdafx.h"
#include "arrow.h"
#include "pixelCollision.h"

ARROW::ARROW()
{
}

ARROW::~ARROW()
{
}

void ARROW::init(int posX, int posY, int width, int height, float angle)
{
	OBJECT::init(posX, posY, width, height);

	OBJECT::_left = posX - width / 2;
	OBJECT::_top = posY - height / 2;
	
	_angle = angle;

	setImage(IMAGEMANAGER->findImage("arrow"));
}

void ARROW::update()
{
	OBJECT::setPosX(OBJECT::getPosX() + Mins::presentPowerX(_angle, 600.0f)*TIMEMANAGER->getElpasedTime());
	

}

void ARROW::release()
{
	OBJECT::_pImg = nullptr;
}

void ARROW::render(HDC hdc)
{
	OBJECT::getImage()->renderCenter(hdc, OBJECT::_posX, OBJECT::_posY);
}

bool ARROW::deleteArrow()
{
	if (OBJECT::getPosX() - OBJECT::getWidth() / 2 > MAPSIZEX ||
		OBJECT::getPosX() + OBJECT::getWidth() / 2 < 0) {
		return true;

	}
	return false;
}
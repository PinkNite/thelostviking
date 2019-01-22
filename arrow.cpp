#include "stdafx.h"
#include "arrow.h"

ARROW::ARROW()
{
}

ARROW::~ARROW()
{
}

void ARROW::init(int posX, int posY, int width, int height)
{
	OBJECT::init(posX, posY, width, height);

	OBJECT::_left = posX - width / 2;
	OBJECT::_top = posY - height / 2;
	


}

void ARROW::update()
{
}

void ARROW::release()
{
}

void ARROW::render(HDC hdc)
{
}


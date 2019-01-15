#include "stdafx.h"
#include "player.h"

PLAYER::PLAYER():
	_nHp(0)
{
}

PLAYER::~PLAYER()
{
}

void PLAYER::create()
{
	OBJECT::init(5,5,20,20);
	_nHp = 3;
}

void PLAYER::update()
{
}

void PLAYER::release()
{
}

void PLAYER::render(HDC hdc)
{

}

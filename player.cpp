#include "stdafx.h"
#include "player.h"
#include "eric.h"

PLAYER::PLAYER()
{
}

PLAYER::~PLAYER()
{
}

void PLAYER::init()
{
	_pEric = new ERIC();
	_pEric->init(100, 100, 32, 32);
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

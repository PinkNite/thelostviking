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
	//����ŷ�� �ʱ�ȭ
	_pViking[static_cast<const int>(VIKING::ERIC)] = new ERIC();
	_pViking[static_cast<const int>(VIKING::ERIC)]->init(610, 610, 32, 32);



	//ó�� ���� ����ŷ ����
	_nCurrentViking = static_cast<int>(VIKING::ERIC);
}

void PLAYER::update()
{
	_pViking[_nCurrentViking]->update();
}

void PLAYER::release()
{
	_pViking[_nCurrentViking]->release();
}

void PLAYER::render(HDC hdc)
{
	_pViking[_nCurrentViking]->render(hdc);
}

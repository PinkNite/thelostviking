#include "stdafx.h"
#include "inputMgr.h"
#include "player.h"
#include "camera.h"

void INPUTMANAGER::init(PLAYER * pPlayer, CAMERA * pCamera)
{
	_pPlayer = pPlayer;
	_pCamera = pCamera;
}

void INPUTMANAGER::update()
{
	//Ű�Է� ������ ���⼭ ���� ó�����ּ���


}

void INPUTMANAGER::release()
{
	_pPlayer = nullptr;
	_pCamera = nullptr;
}

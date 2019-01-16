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
	//키입력 관련은 여기서 전부 처리해주세요


}

void INPUTMANAGER::release()
{
	_pPlayer = nullptr;
	_pCamera = nullptr;
}

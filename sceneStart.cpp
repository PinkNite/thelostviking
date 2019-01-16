#include "stdafx.h"
#include "sceneStart.h"

SCENESTART::SCENESTART()
{
}

SCENESTART::~SCENESTART()
{
}

HRESULT SCENESTART::init()
{

	_pScene0 = new SCENE0;
	_pScene0->init();

	_pScene1 = new SCENE1;
	_pScene1->init();

	_pScene2 = new SCENE2;
	_pScene2->init();

	_pScene3 = new SCENE3;
	_pScene3->init();

	_pScene4 = new SCENE4;
	_pScene4->init();

	_pBlackBackGround = new BACKGROUND;
	_pBlackBackGround->init();
	_pPinkBackGround = new BACKGROUND2;
	_pPinkBackGround->init();

	_pBackGroundScene = _pBlackBackGround;//검은화면 초기화



	_pScene = _pScene0;//씬이미지 초기화 0번

	_pSceneBoss = _pPinkBackGround;//핑크행님 초기화


	return S_OK;
}

void SCENESTART::release()
{
}

void SCENESTART::update()
{

	//여기서 조건을 걸면 씬이 바뀐다.

	//맨처음에는 검으화면이고  2초후 1번인트로화면
	if (TIMEMANAGER->getWorldTime() < 3.0f&&TIMEMANAGER->getWorldTime() >= 2.0f)
	{
		_pScene = _pScene1;
	}
	//7초지나면사라지고 8초후 2번씬 출력
	if (TIMEMANAGER->getWorldTime() >= 9.0f&&TIMEMANAGER->getWorldTime() <= 10.0f)
	{
		_pScene = _pScene2;
	}
	//14초 지나면 다른 이미지를 교체
	if (TIMEMANAGER->getWorldTime() >= 14.0f&&TIMEMANAGER->getWorldTime() <= 15.0f)
	{
		_pScene = _pScene3;
	}
	//17초에 핑크행님 등장
	if (TIMEMANAGER->getWorldTime() >= 17.0f&&TIMEMANAGER->getWorldTime() <= 18.0f)
	{
		_pSceneBoss = _pScene4;
	}
	///////////////////////////////////여기 까지는 플레이어 키입력전에 기본적으로 나오는 화면 ///////////////////////////




	//////////////////////확인용//////////키

	/*if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_pScene = _pScene1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_pScene = _pScene0;
	}*/

	// update()

	_pScene0->update();
	_pScene1->update();
	_pScene2->update();
	_pScene3->update();
	_pScene4->update();
}

void SCENESTART::render()
{
	//그리는 위치
	//배경
	_pBackGroundScene->render();//고정이미지  

	_pScene->render();//바뀌는 이미지

	_pSceneBoss->render();//움직이는 이미지
}

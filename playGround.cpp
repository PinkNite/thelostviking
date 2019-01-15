#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

void playGround::load()
{
	//이미지 넣는것은 여기서 하세요
}


HRESULT playGround::init()
{
	gameNode::init(true);
	
	load();

	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();




	SCENEMANAGER->update();
	
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);



	pCamera->getCameraBuffer()->render(getMemDC(), 0, 0, 200, 200, 800, 600);
	//getMemDc 대신 뭐 넣을때는 pCamera->getMemDc()를 쓰세요.

	pCamera->getMemDC();

	TIMEMANAGER->render(getMemDC());
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


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
	IMAGEMANAGER->addFrameImage("eric", "resource/viking/ericSprites.bmp", 352, 576, 11, 18, true, RGB(105, 0, 152));
}


HRESULT playGround::init()
{
	gameNode::init(true);
	
	load();
	_pCamera = new CAMERA();
	_pCamera->init(512, 512, WINSIZEX, WINSIZEY);

	// working on: Test Enemies Scene 
	SCENEMANAGER->addScene("TestStage1", new TestStage1);
	SCENEMANAGER->changeScene("TestStage1");

	return S_OK;
}


void playGround::release()
{
	gameNode::release();
	delete _pCamera;
	_pCamera = nullptr;

}


void playGround::update()
{
	gameNode::update();

	_pCamera->update();


	SCENEMANAGER->update();
	
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	_pCamera->render(getMemDC());

	//pCamera->getCameraBuffer()->render(getMemDC(), 0, 0, 200, 200, 800, 600);
	////getMemDc 대신 뭐 넣을때는 pCamera->getMemDc()를 쓰세요.

	//SCENEMANAGER->render();

	//pCamera->getMemDC();

	TIMEMANAGER->render(getMemDC());
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


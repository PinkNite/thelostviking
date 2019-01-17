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
	IMAGEMANAGER->addFrameImage("eric", "resource/viking/ericSprites.bmp", 704, 1344, 11, 21, true, RGB(255, 0, 255));

	//이승재 2019-01-16
	IMAGEMANAGER->addImage("검은배경화면", "resource/intro/검은배경화면.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("핑크행님", "resource/intro/제외배경화면.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인트로1", "resource/intro/인트로1.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인트로2", "resource/intro/인트로2.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("인트로3", "resource/intro/인트로3.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("인트로행님", "resource/intro/인트로제목.bmp", 640, 204, true, RGB(255, 0, 255));


	
}

void playGround::link()
{
	_pCamera->setPlayer(_pPlayer);
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

	_pPlayer = new PLAYER;
	_pPlayer->init();

	link();

	_pMap2 = new MAP2;
	_pMap2->init();
	_pCamera->setMap(IMAGEMANAGER->findImage("맵2배경"));

	_pCamera->setting();

	_pInputMgr = new INPUTMANAGER();
	_pInputMgr->init(_pPlayer, _pCamera);

	return S_OK;
}


void playGround::release()
{
	gameNode::release();

	_pInputMgr->release();

	delete _pCamera;
	_pCamera = nullptr;
	delete _pPlayer;
	_pPlayer = nullptr;
}


void playGround::update()
{
	gameNode::update();

	_pCamera->update();

	_pMap2->update();

	_pPlayer->update();

	_pInputMgr->update();

	SCENEMANAGER->update();
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	_pCamera->renderinit();

	_pMap2->render(_pCamera->getMemDC());
	_pPlayer->render(_pCamera->getMemDC());

	//pCamera->getCameraBuffer()->render(getMemDC(), 0, 0, 200, 200, 800, 600);
	////getMemDc 대신 뭐 넣을때는 pCamera->getMemDc()를 쓰세요.

	//SCENEMANAGER->render();

	//pCamera->getMemDC();
	
	//UI

	//Scene
	//_pSceneStart->render();//이승재 2019-01-16
	
	TIMEMANAGER->render(getMemDC());
	_pCamera->render(getMemDC()); 

	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


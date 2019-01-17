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

	//이승재 2019-01-17
	//인트로
	IMAGEMANAGER->addImage("black", "resource/intro/blackBackground.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("pink", "resource/intro/pinkBackground.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro1", "resource/intro/intro1.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro2", "resource/intro/intro2.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro3", "resource/intro/intro3.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("introTitle", "resource/intro/introTitle.bmp", 640, 204, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu", "resource/intro/menu.bmp", 640, 240, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("select", "resource/intro/select.bmp", 640, 240, true, RGB(255, 0, 255));
	//옵션
	IMAGEMANAGER->addFrameImage("ONOFF", "resource/intro/ONOFF.bmp", 92, 14, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ONETWO", "resource/intro/ONETWO.bmp", 92, 14, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("option", "resource/intro/option.bmp", 640, 267, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("password", "resource/intro/passwordBackground.bmp", 640, 480, false, RGB(0, 0, 0));


	//맵


	//아이템
	IMAGEMANAGER->addImage("meat", "resource/item/meat.bmp", 32, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fruit1", "resource/item/fruit.bmp", 26, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fruit2", "resource/item/fruit2.bmp", 32, 28, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("questionMark", "resource/item/questionMark.bmp", 32, 32, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boom", "resource/item/boom.bmp", 32, 30, true, RGB(255, 0, 255));



	// enemy image resources
	IMAGEMANAGER->addImage("redEnemy", "resource/enemies/red.bmp", 259, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueEnemy", "resource/enemies/blue.bmp", 259, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("greenEnemy", "resource/enemies/green.bmp", 105, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("blueBallEnemy", "resource/enemies/blueBall.bmp", 210, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yellowBallEnemy", "resource/enemies/yellowBall.bmp", 74, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("miraEnemy", "resource/enemies/mira.bmp", 222, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cannonEnemy", "resource/enemies/cannon.bmp", 78, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("snailEnemy", "resource/enemies/snail.bmp", 175, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("goliathEnemy", "resource/enemies/goliath.bmp", 175, 128, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bossEnemy", "resource/enemies/bossTomator.bmp", 300, 300, true, RGB(255, 0, 255));
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


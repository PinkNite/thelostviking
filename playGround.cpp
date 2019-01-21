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
	IMAGEMANAGER->addFrameImage("redEnemy", "resource/enemies/red.bmp", 518, 256, 7, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("blueEnemy", "resource/enemies/blue.bmp", 518, 256, 7, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("greenEnemy", "resource/enemies/green.bmp", 210, 128, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("blueBallEnemy", "resource/enemies/blueBall.bmp", 420, 256, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("yellowBallEnemy", "resource/enemies/yellowBall.bmp", 148, 128, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("miraEnemy", "resource/enemies/mira.bmp", 444, 256, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("cannonEnemy", "resource/enemies/cannon.bmp", 156, 128, 2, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("snailEnemy", "resource/enemies/snail.bmp", 350, 256, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goliathEnemy", "resource/enemies/goliath.bmp", 350, 256, 5, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goliatBullet", "resource/enemies/goliatBullet.bmp", 16, 24, 1, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bossEnemy", "resource/enemies/bossTomator.bmp", 300, 300, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("bossBullet", "resource/enemies/bossBullet.bmp", 51, 16, 3, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("laser", "resource/enemies/laser.bmp", 32, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("enemyDeath", "resource/enemies/death.bmp", 51, 16, 3, 1, true, RGB(255, 0, 255));
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
	_pCamera->setMap(IMAGEMANAGER->findImage("Map2bg"));

	_pixel = new pixelCollision;
	_pixel->setPlayer(_pPlayer);
	_pixel->init();
	_pCamera->setMap(IMAGEMANAGER->findImage("map2Collision"));

	_pCamera->setting();

	_pInputMgr = new INPUTMANAGER();
	_pInputMgr->init(_pPlayer, _pCamera);

	_enemy = new ENEMY();
	_enemy->init(800, 600, 40, 64, 2.0f, ENEMY::ENEMY_TYPE::CANNON);
	
	_pPlayer->setMap2(_pMap2);
	_pPlayer->setPixelCollision(_pixel);
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

	_enemy->update();
	
	_pixel->update();

	SCENEMANAGER->update();
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	_pCamera->renderinit();

	_pMap2->render(_pCamera->getMemDC());
	_pixel->render(_pCamera->getMemDC());
	_pPlayer->render(_pCamera->getMemDC());

	_enemy->render(_pCamera->getMemDC());

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


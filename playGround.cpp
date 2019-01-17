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
	//�̹��� �ִ°��� ���⼭ �ϼ���
	IMAGEMANAGER->addFrameImage("eric", "resource/viking/ericSprites.bmp", 704, 1344, 11, 21, true, RGB(255, 0, 255));

	//�̽��� 2019-01-16
	IMAGEMANAGER->addImage("�������ȭ��", "resource/intro/�������ȭ��.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��ũ���", "resource/intro/���ܹ��ȭ��.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʈ��1", "resource/intro/��Ʈ��1.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʈ��2", "resource/intro/��Ʈ��2.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʈ��3", "resource/intro/��Ʈ��3.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��Ʈ�����", "resource/intro/��Ʈ������.bmp", 640, 204, true, RGB(255, 0, 255));

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
	_pCamera->setMap(IMAGEMANAGER->findImage("��2���"));

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
	////getMemDc ��� �� �������� pCamera->getMemDc()�� ������.

	//SCENEMANAGER->render();

	//pCamera->getMemDC();
	
	//UI

	//Scene
	//_pSceneStart->render();//�̽��� 2019-01-16
	
	TIMEMANAGER->render(getMemDC());
	_pCamera->render(getMemDC()); 

	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


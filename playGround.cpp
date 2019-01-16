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
	IMAGEMANAGER->addFrameImage("eric", "resource/viking/ericSprites.bmp", 352, 672, 11, 21, true, RGB(255, 0, 255));

	//�̽��� 2019-01-16
	IMAGEMANAGER->addImage("�������ȭ��", "resource/intro/�������ȭ��.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��ũ���", "resource/intro/���ܹ��ȭ��.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʈ��1", "resource/intro/��Ʈ��1.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʈ��2", "resource/intro/��Ʈ��2.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��Ʈ��3", "resource/intro/��Ʈ��3.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("��Ʈ�����", "resource/intro/��Ʈ������.bmp", 640, 204, true, RGB(255, 0, 255));


	
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
	//�̽��� 2019-01-16
	_pSceneStart = new SCENESTART;
	_pSceneStart->init();

	return S_OK;
}


void playGround::release()
{
	gameNode::release();
	delete _pCamera;
	_pCamera = nullptr;
	delete _pPlayer;
	_pPlayer = nullptr;
}


void playGround::update()
{
	gameNode::update();

	_pCamera->update();

	_pPlayer->update();
	SCENEMANAGER->update();
	_pSceneStart->update();//�̽��� 2019-01-16
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	_pPlayer->render(_pCamera->getMemDC());

	//pCamera->getCameraBuffer()->render(getMemDC(), 0, 0, 200, 200, 800, 600);
	////getMemDc ��� �� �������� pCamera->getMemDc()�� ������.

	//SCENEMANAGER->render();

	//pCamera->getMemDC();
	
	_pCamera->render(getMemDC());
	//UI

	//Scene
	_pSceneStart->render();//�̽��� 2019-01-16

	TIMEMANAGER->render(getMemDC());
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


#include "stdafx.h"
#include "TestStage1.h"


TestStage1::TestStage1()
{
}


TestStage1::~TestStage1()
{
}

HRESULT TestStage1::init()
{
	gameNode::init();
	_pCamera = new CAMERA;
	_pItemManager = new ITEMMANAGER;
	_pItemManager->init();

	load();
	_pCamera = new CAMERA();
	_pCamera->init(512, 512, WINSIZEX, WINSIZEY);

	// working on: Test Enemies Scene 
	//SCENEMANAGER->addScene("TestStage1", new TestStage1);
	//SCENEMANAGER->changeScene("TestStage1");
	//SCENEMANAGER->addScene("sceneIntro", new SCENEINTRO);
	_pPlayer = new PLAYER;
	_pPlayer->init();

	link();

	_pMap2 = new MAP2;
	_pMap2->init();
	_pCamera->setMap(IMAGEMANAGER->findImage("맵2배경"));

	_pCamera->setting();

	_pInputMgr = new INPUTMANAGER();
	_pInputMgr->init(_pPlayer, _pCamera);

	_pUI = new UI;
	_pUI->init();

	return S_OK;
}

void TestStage1::release()
{
	gameNode::release();
	_pInputMgr->release();

	delete _pCamera;
	_pCamera = nullptr;
	delete _pPlayer;
	_pPlayer = nullptr;
}

void TestStage1::update()
{
	gameNode::update();
	_pCamera->update();

	_pMap2->update();

	_pPlayer->update();

	_pInputMgr->update();
	

	_pUI->update();
}

void TestStage1::render()
{
	gameNode::render();
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	_pCamera->renderinit();

	_pMap2->render(_pCamera->getMemDC());
	_pPlayer->render(_pCamera->getMemDC());

	//pCamera->getCameraBuffer()->render(getMemDC(), 0, 0, 200, 200, 800, 600);
	////getMemDc 대신 뭐 넣을때는 pCamera->getMemDc()를 쓰세요.


	_pCamera->getMemDC();

	//UI

	//Scene
	_pItemManager->render(_pCamera->getMemDC());


	TIMEMANAGER->render(getMemDC());
	_pCamera->render(getMemDC());
	_pUI->render();
	//SCENEMANAGER->render();
	
}

void TestStage1::load()
{

	
}

void TestStage1::link()
{
	_pCamera->setPlayer(_pPlayer);
}

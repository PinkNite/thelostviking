#include "stdafx.h"
#include "sceneStage.h"


SCENESTAGE::SCENESTAGE()
{
}


SCENESTAGE::~SCENESTAGE()
{
}

HRESULT SCENESTAGE::init()
{
	
	_pCamera = new CAMERA();
	_pCamera->init(512, 512, WINSIZEX, WINSIZEY);

	_pPlayer = new PLAYER;
	_pPlayer->init();

	_pItemManager = new ITEMMANAGER;
	_pItemManager->init();
	_pUI = new UI;
	_pUI->init();
	_pInputMgr = new INPUTMANAGER();
	_pInputMgr->init(_pPlayer, _pCamera);
	link();

	_pMap2 = new MAP2;
	_pMap2->setPlayer(_pPlayer);
	_pMap2->init();
	_pCamera->setMap(IMAGEMANAGER->findImage("Map2bg"));

	_pixel = new pixelCollision;
	_pixel->setPlayer(_pPlayer);
	_pixel->setMap2(_pMap2);
	_pixel->init();
	//_pCamera->setMap(IMAGEMANAGER->findImage("map2Collision"));

	_pCamera->setting();



	_enemy = new ENEMY();
	_enemy->init(100, 608, 40, 64, 2.0f, ENEMY::ENEMY_TYPE::CANNON);

	_enemyManager = new EnemyManager();
	_enemyManager->init();
	_enemyManager->addEnemy(5, ENEMY::ENEMY_TYPE::GREEN);

	_pPlayer->setMap2(_pMap2);
	_pPlayer->setPixelCollision(_pixel);
	_pPlayer->linkEnemyMgr(_enemyManager);

	_isPlay = true;
	return S_OK;
}

void SCENESTAGE::release()
{
	_pInputMgr->release();

	delete _pCamera;
	_pCamera = nullptr;
	delete _pPlayer;
	_pPlayer = nullptr;
}

void SCENESTAGE::update()
{
	_pCamera->update();
	if (_isPlay && !SOUNDMANAGER->isPlaySound("mainStageBGM"))
	{
		
		SOUNDMANAGER->play("mainStageBGM");

	}
	_pMap2->update();

	_pPlayer->update();

	_pInputMgr->update();

	_enemy->update();

	_enemyManager->update();

	_pixel->update();

	_pItemManager->update();//ÀÌ½ÂÀç

	_pUI->update();//ÀÌ½ÂÀç
}

void SCENESTAGE::render()
{

	_pCamera->renderinit();

	_pMap2->render(_pCamera->getMemDC());
	_pixel->render(_pCamera->getMemDC());
	_pPlayer->render(_pCamera->getMemDC());

	_enemy->render(_pCamera->getMemDC());
	_enemyManager->render(_pCamera->getMemDC());


	_pItemManager->render(_pCamera->getMemDC());

	//TIMEMANAGER->render(getMemDC());
	_pCamera->render(getMemDC());
	_pUI->render(getMemDC());


}

void SCENESTAGE::link()
{
	_pCamera->setPlayer(_pPlayer);

	_pItemManager->setLinkPlayer(_pPlayer);

	_pUI->linkItemManger(_pItemManager);
	_pUI->linkPlayer(_pPlayer);
	_pUI->linkInputManager(_pInputMgr);
	_pItemManager->setLinkUI(_pUI);

}


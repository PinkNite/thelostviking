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
	IMAGEMANAGER->addFrameImage("baleog", "resource/viking/baleogSprites.bmp", 704, 1216, 11, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("olaf", "resource/viking/olafSprites.bmp", 704, 1088, 11, 17, true, RGB(255, 0, 255));

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


	//npc레드
	IMAGEMANAGER->addFrameImage("npc", "resource/NPC_red.bmp", 140, 64, 4, 2, true, RGB(255, 0, 255));
	//맵


	//아이템
	IMAGEMANAGER->addImage("meat", "resource/item/meat.bmp", 40, 35, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fruit1", "resource/item/fruit.bmp", 33, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fruit2", "resource/item/fruit2.bmp", 40, 35, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("questionMark", "resource/item/questionMark.bmp", 40, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("boom", "resource/item/boom.bmp", 40, 38, true, RGB(255, 0, 255));

	//UI
	IMAGEMANAGER->addImage("UI", "resource/UI/UI.bmp", 640, 118, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("life", "resource/UI/life.bmp", 14, 12, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("trashCan", "resource/UI/remove.bmp", 37, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("selectYellow", "resource/UI/selectYellow.bmp", 40, 40, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("baleogOn", "resource/UI/baleogOn.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("baleogOff", "resource/UI/baleogOff.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("baleogDead", "resource/UI/baleogDead.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("erikOn", "resource/UI/erikOn.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("erikOff", "resource/UI/erikOff.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("erikDead", "resource/UI/erikDead.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("olafOn", "resource/UI/olafOn.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("olafOff", "resource/UI/olafOff.bmp", 80, 60, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("olafDead", "resource/UI/olafDead.bmp", 80, 60, true, RGB(255, 0, 255));

	//bgm
	SOUNDMANAGER->addSound("doorOpen", "resource/MUSIC/doorOpen.mp3", true, 0);
	SOUNDMANAGER->addSound("laser", "resource/MUSIC/laser.wav", true, 0);
	SOUNDMANAGER->addSound("mainStage", "resource/MUSIC/mainStage.mp3", true, true);
	SOUNDMANAGER->addSound("sword", "resource/MUSIC/sword.wav", true, false);
	SOUNDMANAGER->addSound("telepote", "resource/MUSIC/telepote.wav", true, false);
	SOUNDMANAGER->addSound("title", "resource/MUSIC/Title.wav", true, true);
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


	IMAGEMANAGER->addImage("arrow","resource/arrow.bmp", 32, 6, true, RGB(255, 0, 255));
}

void playGround::link()
{
	_pCamera->setPlayer(_pPlayer);

	_pItemManager->setLinkPlayer(_pPlayer);

	_pUI->linkItemManger(_pItemManager);
	_pUI->linkPlayer(_pPlayer);
	_pUI->linkInputManager(_pInputMgr);
	_pItemManager->setLinkUI(_pUI);
	
	
}


HRESULT playGround::init()
{
	gameNode::init(true);
	
	load();
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
	_enemy->init(100, 610, 40, 64, 2.0f, ENEMY::ENEMY_TYPE::CANNON);
	
	_enemyManager = new EnemyManager();
	_enemyManager->init();
	_enemyManager->addEnemy(3, ENEMY::ENEMY_TYPE::GREEN);

	_pPlayer->setMap2(_pMap2);
	_pPlayer->setPixelCollision(_pixel);

	SCENEMANAGER->addScene("INTRO", new SCENEINTRO);
	SCENEMANAGER->addScene("MENU", new SCENEMENU);
	SCENEMANAGER->addScene("OPTION", new SCENEOPTION);
	SCENEMANAGER->addScene("PASSWORD", new SCENEPASSWORD);
	
	SCENEMANAGER->changeScene("INTRO");
	
	_gameState = PLAY;
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
	if (_gameState==PLAY)
	{
		_pCamera->update();

		_pMap2->update();

		_pPlayer->update();

		_pInputMgr->update();

		_enemy->update();

		_enemyManager->update();

		_pixel->update();

		_pItemManager->update();//이승재

		_pUI->update();//이승재
	}
	else
	{
		SCENEMANAGER->update();
	}
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY+118, BLACKNESS);
	_pCamera->renderinit();
	if (_gameState ==PLAY)
	{
		_pMap2->render(_pCamera->getMemDC());
		_pixel->render(_pCamera->getMemDC());
		_pPlayer->render(_pCamera->getMemDC());

		_enemy->render(_pCamera->getMemDC());
		_enemyManager->render(_pCamera->getMemDC());

		//pCamera->getCameraBuffer()->render(getMemDC(), 0, 0, 200, 200, 800, 600);
		////getMemDc 대신 뭐 넣을때는 pCamera->getMemDc()를 쓰세요.

		//pCamera->getMemDC();

		//UI

		//Scene
		//_pSceneStart->render();//이승재 2019-01-16
		_pItemManager->render(_pCamera->getMemDC());

		TIMEMANAGER->render(getMemDC());
		_pCamera->render(getMemDC());
		_pUI->render(getMemDC());
	}
	else
	{
		SCENEMANAGER->render();
	}
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


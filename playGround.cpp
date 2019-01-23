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
	IMAGEMANAGER->addFrameImage("baleog", "resource/viking/baleogSprites.bmp", 704, 1216, 11, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("olaf", "resource/viking/olafSprites.bmp", 704, 1088, 11, 17, true, RGB(255, 0, 255));

	//�̽��� 2019-01-17
	//��Ʈ��
	IMAGEMANAGER->addImage("black", "resource/intro/blackBackground.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("pink", "resource/intro/pinkBackground.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro1", "resource/intro/intro1.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro2", "resource/intro/intro2.bmp", 640, 480, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("intro3", "resource/intro/intro3.bmp", 640, 480, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("introTitle", "resource/intro/introTitle.bmp", 640, 204, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu", "resource/intro/menu.bmp", 640, 240, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("select", "resource/intro/select.bmp", 640, 240, true, RGB(255, 0, 255));
	//�ɼ�
	IMAGEMANAGER->addFrameImage("ONOFF", "resource/intro/ONOFF.bmp", 92, 14, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ONETWO", "resource/intro/ONETWO.bmp", 92, 14, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("option", "resource/intro/option.bmp", 640, 267, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("password", "resource/intro/passwordBackground.bmp", 640, 480, false, RGB(0, 0, 0));


	//npc����
	IMAGEMANAGER->addFrameImage("npc", "resource/NPC_red.bmp", 140, 64, 4, 2, true, RGB(255, 0, 255));
	//��


	//������
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
	SOUNDMANAGER->addSound("doorOpenBGM", "resource/MUSIC/doorOpen.mp3", true, 0);
	SOUNDMANAGER->addSound("laserBGM", "resource/MUSIC/laser.wav", true, 0);
	SOUNDMANAGER->addSound("mainStageBGM", "resource/MUSIC/mainStage.mp3", true, true);
	SOUNDMANAGER->addSound("swordBGM", "resource/MUSIC/sword.wav", true, false);
	SOUNDMANAGER->addSound("telepoteBGM", "resource/MUSIC/telepote.wav", true, false);
	SOUNDMANAGER->addSound("titleBGM", "resource/MUSIC/Title.mp3", true, true);
	SOUNDMANAGER->addSound("buttonBGM", "resource/MUSIC/button.ogg", true, false);
	SOUNDMANAGER->addSound("boomBGM", "resource/MUSIC/boom.wav", true, false);
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
	IMAGEMANAGER->addFrameImage("enemyDeath", "resource/enemies/death.bmp", 370, 64, 5, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("arrow","resource/arrow.bmp", 32, 6, true, RGB(255, 0, 255));
}




HRESULT playGround::init()
{
	gameNode::init(true);
	
	load();
	

	SCENEMANAGER->addScene("INTRO", new SCENEINTRO);
	SCENEMANAGER->addScene("MENU", new SCENEMENU);
	SCENEMANAGER->addScene("OPTION", new SCENEOPTION);
	SCENEMANAGER->addScene("PASSWORD", new SCENEPASSWORD);
	SCENEMANAGER->addScene("GAMESTAGE", new SCENESTAGE);
	SCENEMANAGER->changeScene("INTRO");
	
	


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
		SOUNDMANAGER->update();
}



void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY+118, BLACKNESS);
	
		SCENEMANAGER->render();
	
	//===========================================================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}


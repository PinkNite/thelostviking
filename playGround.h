#pragma once
#include "gameNode.h"
#include "camera.h"
#include "TestStage1.h"
#include "player.h"
#include "sceneStart.h"//�̽��� 2019-01-16
#include "inputMgr.h"


class playGround : public gameNode
{
private:
	CAMERA *		_pCamera;
	PLAYER*			_pPlayer;
	SCENESTART*		_pSceneStart;//�̽��� 2019-01-16
	INPUTMANAGER*	_pInputMgr;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	playGround();
	~playGround();
	//�̹��� �ε� ���⼭ �ϼ���
	void	load();
	//��ȣ���� ���⼭ �ϼ���
	void	link();
};


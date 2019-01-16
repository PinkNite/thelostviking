#pragma once
#include "gameNode.h"
#include "backGround.h"
#include "scene0.h"
#include "scene1.h"
#include "scene2.h"
#include "scene3.h"
#include "scene4.h"
class SCENESTART :public gameNode
{
private:
	BACKGROUND* _pBlackBackGround;//검은색 배경화면
	BACKGROUND2* _pPinkBackGround;//자주색 배경화면
	gameNode* _pBackGroundScene;//고정된 배경화면
	gameNode* _pScene;//교체용 
	gameNode* _pSceneBoss; //인트로행님들어갈곳
	SCENE0* _pScene0;
	SCENE1* _pScene1;
	SCENE2* _pScene2;
	SCENE3* _pScene3;
	SCENE4* _pScene4;

public:
	SCENESTART();
	~SCENESTART();

	HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


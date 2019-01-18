#pragma once
#include "gameNode.h"

#include "TestStage1.h"

#include "inputMgr.h"


class playGround //:// public gameNode
{
private:


public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	

	playGround();
	~playGround();
	//이미지 로드 여기서 하세요
	void	load();
	//상호참조 여기서 하세요
	void	link();
};


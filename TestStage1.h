#pragma once
#include "gameNode.h"
#include "itemBoom.h"

class TestStage1 : public gameNode
{
private:
	ITEMBOOM* _pItem;


public:
	TestStage1();
	~TestStage1();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};


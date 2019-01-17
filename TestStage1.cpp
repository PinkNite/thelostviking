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
	_pItem = new ITEMBOOM;
	_pItem->init(100,100,_pItem->getImage()->GetWidth(),_pItem->getImage()->GetHeight());
	return S_OK;
}

void TestStage1::release()
{
}

void TestStage1::update()
{
}

void TestStage1::render()
{
	_pItem->render();
}

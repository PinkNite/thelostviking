#include "stdafx.h"
#include "itemManager.h"
#include "player.h"
#include "UI.h"



ITEMMANAGER::ITEMMANAGER()
{
}

ITEMMANAGER::~ITEMMANAGER()
{
}

HRESULT ITEMMANAGER::init()
{
	_pItemBoom[0] = new ITEMBOOM;
	_pItemBoom[1] = new ITEMBOOM;
	_pItemBoom[0]->init(1410, 82, 40, 38);//
	_pItemBoom[1]->init(1410, 120, 40, 38);//

	for (int i = 0; i < 2; i++)
	{
		_pItemFruit1[i] = new ITEMFRUIT1;
	}
	_pItemFruit1[0]->init(268, 350, 33, 40);
	_pItemFruit1[1]->init(510, 100, 33, 40);
	for (int i = 0; i < 2; i++)
	{
		_pItemFruit2[i] = new ITEMFRUIT2;
	}
	_pItemFruit2[0]->init(1970, 410, 40, 35);
	_pItemFruit2[1]->init(995, 1380, 40, 35);



	for (int i = 0; i < 2; i++)
	{
		_itemBoom[i] = 0;
		_itemFruit1[i] = 0;
		_itemFruit2[i] = 0;
	}
	for (int i = 0; i < 2; i++)
	{
		_pItemMeat[i] = new ITEMMEAT;
		_pItemMeat[i]->init(1700, 530, 40, 35);
		_itemMeat[i] = 0;
	}
	

	return S_OK;
}

void ITEMMANAGER::release()
{
}

void ITEMMANAGER::update()
{
	
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::ERIC)
	{
		isCollisionPlayer();
	}
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::BALEOG)
	{
		isCollisionPlayer();
	}
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::OLAF)
	{
		isCollisionPlayer();
	}
}

void ITEMMANAGER::render(HDC hdc)
{
	for (int i = 0; i < 2; i++)
	{
		_pItemBoom[i]->render(hdc);

	}
	for (int i = 0; i < 2; i++)
	{
		_pItemFruit1[i]->render(hdc);

	}
	for (int i = 0; i < 2; i++)
	{
		_pItemFruit2[i]->render(hdc);

	}
	//_pItemMeat->render(hdc);//고기는 출력안해도됨

}

void ITEMMANAGER::isCollisionPlayer()
{

	//플레이어 상태값을 받아야함
	
	for (int i = 0; i < 2; i++)
	{
		if (isCollision(_pItemBoom[i]->getX(), _pItemBoom[i]->getY(), 40, 38, _pPlayer->getPosX(), _pPlayer->getPosY(), 64, 64) && _pItemBoom[i]->getIsAllive())
		{

			_pItemBoom[i]->SetIsAlliveFalse();//죽이고 죽으면 안보임 그리고 신호를 보내줘야함
			_itemBoom[i] = 1;
			break;
		}
		else
		{
			_itemBoom[i] = 0;
		}
		if (isCollision(_pItemFruit1[i]->getX(), _pItemFruit1[i]->getY(), 33, 40, _pPlayer->getPosX(), _pPlayer->getPosY(), 64, 64) && _pItemFruit1[i]->getIsAllive())
		{
			_pItemFruit1[i]->SetIsAlliveFalse();
			_itemFruit1[i] = 1;
			break;
		}
		else
		{
			_itemFruit1[i] = 0;
		}
		if (isCollision(_pItemFruit2[i]->getX(), _pItemFruit2[i]->getY(), 40, 35, _pPlayer->getPosX(), _pPlayer->getPosY(), 64, 64) && _pItemFruit2[i]->getIsAllive())
		{
			_pItemFruit2[i]->SetIsAlliveFalse();
			_itemFruit2[i] = 1;
			break;
		}
		else
		{
			_itemFruit2[i] = 0;
		}
		if (isCollision(_pItemMeat[i]->getX(), _pItemMeat[i]->getY(), 40, 38, _pPlayer->getPosX(), _pPlayer->getPosY(), 64, 64) && _pItemMeat[i]->getIsAllive())
		{
			_pItemMeat[i]->SetIsAlliveFalse();
			_itemMeat[i] = 1;
		}
		else
		{
			_itemMeat[i] = 0;
		}
	}


}

inline bool ITEMMANAGER::isCollision(int x, int y, int width, int height, int x1, int y1, int width1, int height1)
{
	RECT temp, rc, rc1;
	rc.left = x - width / 2;
	rc.right = x + width / 2;
	rc.top = y - height / 2;
	rc.bottom = y + height / 2;
	rc1.left = x1 - width1 / 2;
	rc1.right = x1 + width1 / 2;
	rc1.top = y1 - height1 / 2;
	rc1.bottom = y1 + height1 / 2;
	if (IntersectRect(&temp, &rc, &rc1))
	{

		return true;
	}


	return false;
}

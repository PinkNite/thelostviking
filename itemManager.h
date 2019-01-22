#pragma once
#include "itemBoom.h"
#include "itemFruit1.h"
#include "itemFruit2.h"
#include "itemMeat.h"
#include "itemQuestionMark.h"

class UI;
class PLAYER;
class ITEMMANAGER
{
	ITEMBOOM* _pItemBoom[2];
	int _itemBoom[2];

	ITEMFRUIT1* _pItemFruit1[2];
	int _itemFruit1[2];

	ITEMFRUIT2* _pItemFruit2[2];
	int _itemFruit2[2];
	ITEMMEAT* _pItemMeat[2];
	int _itemMeat[2];
	PLAYER* _pPlayer;
	UI* _pUI;
public:
	ITEMMANAGER();
	~ITEMMANAGER();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void isCollisionPlayer();//아이템과 플레이어 충돌
	
public:

	inline void setLinkPlayer(PLAYER* _player) { _pPlayer = _player; }

	inline bool isCollision(int x, int y, int width, int height, int x1, int y1, int width1, int height1);
	//아이템이 먹었는지 겟으로 보내줘야함
	inline void setLinkUI(UI* ui) { _pUI = ui; }



	bool getItemFalseBoomA() { return  _pItemBoom[0]->getIsAllive(); }
	bool getItemFalseBoomB() { return  _pItemBoom[1]->getIsAllive(); }
	bool getItemFalseFruit1A() { return _pItemFruit1[0]->getIsAllive(); }
	bool getItemFalseFruit1B() { return  _pItemFruit1[1]->getIsAllive(); }
	bool getItemFalseFruit2A() { return  _pItemFruit2[0]->getIsAllive(); }
	bool getItemFalseFruit2B() { return  _pItemFruit2[1]->getIsAllive(); }
	bool getItemFalseMeatA() { return _pItemMeat[0]->getIsAllive(); }
	bool getItemFalseMeatB() { return _pItemMeat[1]->getIsAllive(); }
	int getItemCollisionBoomA() { return  _itemBoom[0]; }
	int getItemCollisionBoomB() { return  _itemBoom[1]; }
	int getItemCollisionFruit1A() { return _itemFruit1[0]; }
	int getItemCollisionFruit1B() { return  _itemFruit1[1]; }
	int getItemCollisionFruit2A() { return  _itemFruit2[0]; }
	int getItemCollisionFruit2B() { return  _itemFruit2[1]; }
	int getItemCollisionMeatA() { return _itemMeat[0]; }
	int getItemCollisionMeatB() { return _itemMeat[1]; }
};



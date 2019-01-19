#pragma once
#include "gameNode.h"
#include "itemBoom.h"
#include "itemFruit1.h"
#include "itemFruit2.h"
#include "itemMeat.h"

enum baleogState
{
	BALEOG_ON,
	BALEOG_OFF,
	BALEOG_DEAD,
	
};
enum erikState
{
	ERIK_ON,
	ERIK_OFF,
	ERIK_DEAD,
};
enum olafState
{
	OLAF_ON,
	OLAF_OFF,
	OLAF_DEAD,
};
enum trashCanState
{
	TRASHCAN_ON,
	TRASHCAN_OFF,
	
};
enum selectState
{
	SELECT_LEFT_TOP,
	SELECT_LEFT_BOTTOM,
	SELECT_RIGHT_TOP,
	SELECT_RIGHT_BOTTOM
};
enum itemMemory
{
	ITEM_0,
	ITEM_1,
	ITEM_2,
	ITEM_3,
	ITEM_4,
	ITEM_MAX
};


struct tagUI
{
	bool isAllive;
	image* pImage;
	int alphaCount;
	int x;
	int y;

};
class UI :public gameNode
{
private:
	tagUI _ui;
	tagUI _life[9];
	tagUI _baleog[3];//0이 온 1이 오프 2 이 죽음
	tagUI _erik[3];
	tagUI _olaf[3];
	tagUI _select[3];
	tagUI _trashCan;

	ITEMBOOM* _pItemBoom[2];
	ITEMFRUIT1* _pItemFruit1[2];
	ITEMFRUIT2* _pItemFruit2[2];
	ITEMMEAT* _pItemMeat;
	
	trashCanState _trashCanState;
	baleogState _baleogState;
	olafState _olafState;
	erikState _erikState;
	selectState _selectState[3];
	itemMemory _erikItem;
	itemMemory _baleogItem;
	itemMemory _olafItem;


	int _iii;
	//콜리젼 했는지 알변수
	bool _isCollision;
public:
	UI();
	~UI();
	 HRESULT init();
	 void release();
	 void update();
	 void render();
	 void selectMove();
	 //캐릭 네임 주소를 넣으면 그 해당 인벤토리 설정됨
	 void getItem(itemMemory* name, int x, int y, int x1, int y1);
	 //           아이템X , 아이템Y, 아이템 넓이, 아이템 높이 , 아이템이넘문의 주소, 이넘문 변화값, 해당 폭탄의 배열번호 
	 void itemBoom(int x, int y, int width, int height, itemMemory* name, itemMemory item,int i); //폭탄 좌표
	 void itemFruit1(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i);
	 void itemFruit2(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i);
	 void itemMeat(int x, int y, int width, int height, itemMemory* name, itemMemory item);
	 
	 void itemRender(itemMemory* name, itemMemory* name1, itemMemory* name2);
	 void selectCollision(int i, int x, int y);
	 void itemUpdate();
public :
	itemMemory getItemMax(itemMemory item) { if(item==ITEM_MAX)return ITEM_MAX; }
};


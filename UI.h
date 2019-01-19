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

	
	trashCanState _trashCanState;
	baleogState _baleogState;
	olafState _olafState;
	erikState _erikState;
	selectState _selectState[3];
public:
	UI();
	~UI();
	 HRESULT init();
	 void release();
	 void update();
	 void render();
	 void selectMove();
public :
	
};


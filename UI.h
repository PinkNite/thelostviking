#pragma once
#include "gameNode.h"
#include "itemBoom.h"
#include "itemFruit1.h"
#include "itemFruit2.h"
#include "itemMeat.h"
//#include <vector>


class PLAYER;
class ITEMMANAGER;
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
	/*vector<itemMemory>          _vItem;
	vector<itemMemory>::iterator  _viItem;*/
	tagUI _ui;
	tagUI _life[9];
	tagUI _baleog[3];//0�� �� 1�� ���� 2 �� ����
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

	ITEMMANAGER* _pItemMG;

	//�÷��̾�
	PLAYER* _pPlayer;

public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render();
	void selectMove();
	//ĳ�� ���� �ּҸ� ������ �� �ش� �κ��丮 ������
	void getItem(itemMemory* name, int x, int y, int x1, int y1);
	//           ������X , ������Y, ������ ����, ������ ���� , �������̳ѹ��� �ּ�, �̳ѹ� ��ȭ��, �ش� ��ź�� �迭��ȣ 
	void itemBoom(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i); //��ź ��ǥ
	void itemFruit1(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i);
	void itemFruit2(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i);
	void itemMeat(int x, int y, int width, int height, itemMemory* name, itemMemory item);

	void itemRender();
	void selectCollision();

public:
	itemMemory getErikItemMax() { return _erikItem; }//������ ������ ������ ��á�ٴ� �ɺ���
	itemMemory getBaleogItemMax() { return _baleogItem; }//������ ������ ������ ��á�ٴ� �ɺ���
	itemMemory getOlafItemMax() { return _olafItem; }//������ ������ ������ ��á�ٴ� �ɺ���

	inline bool isCollision(int x, int y, int width, int height, int x1, int y1, int width1, int height1);

	void linkItemManger(ITEMMANAGER* _item) { _pItemMG = _item; }
	void linkPlayer(PLAYER* _player) { _pPlayer = _player; }
};


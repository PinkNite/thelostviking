#pragma once
#include "itemBoom.h"
#include "itemFruit1.h"
#include "itemFruit2.h"
#include "itemMeat.h"
//#include <vector>

class INPUTMANAGER;
class PLAYER;
class ITEMMANAGER;
enum BALEOGSTATE
{
	BALEOG_ON,
	BALEOG_OFF,
	BALEOG_DEAD,

};
enum ERIKSTATE
{
	ERIK_ON,
	ERIK_OFF,
	ERIK_DEAD,
};
enum OLAFSTATE
{
	OLAF_ON,
	OLAF_OFF,
	OLAF_DEAD,
};
enum TRASHCANSTATE
{
	TRASHCAN_ON,
	TRASHCAN_OFF,

};
enum SELECTSTATE
{
	SELECT_LEFT_TOP,
	SELECT_LEFT_BOTTOM,
	SELECT_RIGHT_TOP,
	SELECT_RIGHT_BOTTOM,
	SELECT_REMOVE,
	SELECT_BACK
};
enum ITEMMEMORY
{
	ITEM_0,
	ITEM_1,
	ITEM_2,
	ITEM_3,
	ITEM_4,
	ITEM_MAX
};


struct TAGUI
{
	bool isAllive;
	image* pImage;
	int alphaCount;
	int x;
	int y;

};
class UI 
{
private:
	/*vector<itemMemory>          _vItem;
	vector<itemMemory>::iterator  _viItem;*/
	TAGUI _ui;
	TAGUI _life[9];
	TAGUI _baleog[3];//0�� �� 1�� ���� 2 �� ����
	TAGUI _erik[3];
	TAGUI _olaf[3];
	TAGUI _select[3];
	TAGUI _trashCan;
	

	ITEMBOOM* _pItemBoom[2];
	TAGUI _itemBoom[2];
	ITEMFRUIT1* _pItemFruit1[2];
	TAGUI _itemFruit1[2];
	ITEMFRUIT2* _pItemFruit2[2];
	TAGUI _itemFruit2[2];
	ITEMMEAT* _pItemMeat[2];
	TAGUI _itemMeat[2];

	TRASHCANSTATE _trashCanState;
	BALEOGSTATE _baleogState;
	OLAFSTATE _olafState;
	ERIKSTATE _erikState;
	SELECTSTATE _selectState[3];
	SELECTSTATE _selectStateTemp[3];
	ITEMMEMORY _erikItem;
	ITEMMEMORY _baleogItem;
	ITEMMEMORY _olafItem;

	ITEMMANAGER* _pItemMG;

	//�÷��̾�
	PLAYER* _pPlayer;
	INPUTMANAGER* _pInputMG;
	
	int _countNum;
	int _countLeft;
	int _countRight;
	int _countSelect;
	bool _isCountSelect;
	bool _isCollision;

	int sss;
	int _selectX;
	int _selectY;
	int _selectTempX;
	int _selectTempY;
public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void selectMove();
	//ĳ�� ���� �ּҸ� ������ �� �ش� �κ��丮 ������
	void getItem(ITEMMEMORY* name, int x, int y, int x1, int y1);
	//           ������X , ������Y, ������ ����, ������ ���� , �������̳ѹ��� �ּ�, �̳ѹ� ��ȭ��, �ش� ��ź�� �迭��ȣ 
	void itemBoom(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item, int i); //��ź ��ǥ
	void itemFruit1(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item, int i);
	void itemFruit2(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item, int i);
	void itemMeat(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item,int i);

	void itemRender(HDC hdc);
	void selectCollision();
	//�÷��̾� ��ȭ�Ҷ� �ʻ�ȭ��
	void changePlayer();
	void moveItem();
	bool isCollisionSelectItem();
	bool isCollisionSelectRemove();

	void moveItemTrashCan(int j);
	void moveTrashCanItem(int j);

	SELECTSTATE conveyValue(SELECTSTATE* ss) { return *ss; }

public:
	ITEMMEMORY getErikItemMax() { return _erikItem; }//������ ������ ������ ��á�ٴ� �ɺ���
	ITEMMEMORY getBaleogItemMax() { return _baleogItem; }//������ ������ ������ ��á�ٴ� �ɺ���
	ITEMMEMORY getOlafItemMax() { return _olafItem; }//������ ������ ������ ��á�ٴ� �ɺ���

	inline bool isCollision(int x, int y, int width, int height, int x1, int y1, int width1, int height1);

	void linkItemManger(ITEMMANAGER* _item) { _pItemMG = _item; }
	void linkPlayer(PLAYER* _player) { _pPlayer = _player; }
	void linkInputManager(INPUTMANAGER* _mg) { _pInputMG = _mg; }

	int getMoveX(int x) { return x; }
	int getMoveY(int y) { return y; }
};


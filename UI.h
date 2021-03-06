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
	TAGUI _baleog[3];//0이 온 1이 오프 2 이 죽음
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

	//플레이어
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
	//캐릭 네임 주소를 넣으면 그 해당 인벤토리 설정됨
	void getItem(ITEMMEMORY* name, int x, int y, int x1, int y1);
	//           아이템X , 아이템Y, 아이템 넓이, 아이템 높이 , 아이템이넘문의 주소, 이넘문 변화값, 해당 폭탄의 배열번호 
	void itemBoom(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item, int i); //폭탄 좌표
	void itemFruit1(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item, int i);
	void itemFruit2(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item, int i);
	void itemMeat(int x, int y, int width, int height, ITEMMEMORY* name, ITEMMEMORY item,int i);

	void itemRender(HDC hdc);
	void selectCollision();
	//플레이어 변화할때 초상화값
	void changePlayer();
	void moveItem();
	bool isCollisionSelectItem();
	bool isCollisionSelectRemove();

	void moveItemTrashCan(int j);
	void moveTrashCanItem(int j);
	void playerDeath();
	void useItem();
	void useSelectCollisionItem();
	SELECTSTATE conveyValue(SELECTSTATE* ss) { return *ss; }

public:
	ITEMMEMORY getErikItemMax() { return _erikItem; }//겟으로 아이템 공간이 꽉찼다는 걸보냄
	ITEMMEMORY getBaleogItemMax() { return _baleogItem; }//겟으로 아이템 공간이 꽉찼다는 걸보냄
	ITEMMEMORY getOlafItemMax() { return _olafItem; }//겟으로 아이템 공간이 꽉찼다는 걸보냄

	inline bool isCollision(int x, int y, int width, int height, int x1, int y1, int width1, int height1);

	void linkItemManger(ITEMMANAGER* _item) { _pItemMG = _item; }
	void linkPlayer(PLAYER* _player) { _pPlayer = _player; }
	void linkInputManager(INPUTMANAGER* _mg) { _pInputMG = _mg; }

	int getMoveX(int x) { return x; }
	int getMoveY(int y) { return y; }
};


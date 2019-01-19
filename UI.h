#pragma once
#include "gameNode.h"

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

struct tagUI
{
	bool isAllive;
	image* pImage;
	int alphaCount;

};
class UI :public gameNode
{
private:
	tagUI _ui;
	tagUI _life[9];
	tagUI _baleog[3];//0이 온 1이 오프 2 이 죽음
	tagUI _erik[3];
	tagUI _olaf[3];
	tagUI _select;
	tagUI _trashCan;
	
	trashCanState _trashCanState;
	baleogState _baleogState;
	olafState _olafState;
	erikState _erikState;
public:
	UI();
	~UI();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public :

};


#include "Electrics.h"
#include <vector>

#pragma once
class MAP2
{
private:
	image* _imgMap2bg;
	image* _imgElectric3;
	image* _imgHandle;
	image* _imgDoor1;
	image* _imgDoor2;
	image* _imgDoor3;
	image* _imgDoor4;
	image* _imgButton1;
	image* _imgButton2;
	image* _imgButton3;
	image* _imgBrokenblock;
	image* _imgBrokencomputer;
	image* _imgUpeffect;
	image* _imgElevator;

	RECT _rcElectric3;
	RECT _rcHandle;
	RECT _rcDoor1;
	RECT _rcDoor2;
	RECT _rcDoor3;
	RECT _rcDoor4;
	RECT _rcButton1;
	RECT _rcButton2;
	RECT _rcButton3;
	RECT _rcBrokenblock;
	RECT _rcBrokencomputer;
	RECT _rcUpeffect;
	RECT _rcLadder1;
	RECT _rcLadder2;
	RECT _rcLadder3;
	RECT _rcLadder4;
	RECT _rcLadder5;
	RECT _rcLadder6;
	RECT _rcHelp1;
	RECT _rcHelp2;
	RECT _rcHelp3;
	RECT _rcHelp4;
	RECT _rcHelp5;
	RECT _rcHelp6;
	RECT _rcElevator;
	RECT _rcExit;

private:
	typedef vector<SETELECTRIC*>			    _vElectric4;
	typedef vector<SETELECTRIC*>::iterator		_viElectric4;

	_vElectric4   _vElectric;
	_viElectric4  _viElectric;

	int _frameCount;
	int _indexElectric3;
	int _indexElectric4;
	int _indexUpeffect;
	int _frameSpeed;

public:
	MAP2();
	~MAP2();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void electricInit();
};


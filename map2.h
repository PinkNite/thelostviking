#include "electrics.h"
#include "doors.h"
#include "buttons.h"
#include <vector>

#pragma once
class MAP2
{
private:
	image* _imgMap2bg;
	image* _imgElectric3;
	image* _imgHandle;
	image* _imgButton1;
	image* _imgButton2;
	image* _imgButton3;
	image* _imgBrokenblock;
	image* _imgBrokencomputer;
	image* _imgUpeffect;
	image* _imgElevator;

	RECT _rcElectric3;
	RECT _rcHandle;
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
	typedef vector<setELECTRIC*>					_vElectric4;
	typedef vector<setELECTRIC*>::iterator			_viElectric4;
	_vElectric4   _vElectric;
	_viElectric4  _viElectric;

	vector<setDOOR*>								_vDoor;
	vector<setDOOR*>::iterator						_viDoor;

	vector<setBUTTON*>								_vButton;
	vector<setBUTTON*>::iterator					_viButton;

	int _indexElectric3;
	int _indexElectric4;
	int _indexUpeffect;

public:
	MAP2();
	~MAP2();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void electricInit();
	void doorInit();
	void buttonInit();
};


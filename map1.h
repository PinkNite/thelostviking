#include "doors.h"

#pragma once
class MAP1
{
private:
	image* _imgMap1bg;
	image* _imgDoor1;
	image* _imgDoor2;
	image* _imgElectric1;

	RECT _rcElectric1;
	RECT _rcLadder[3];
	RECT _rcHelp;
	RECT _rcExit;

private:
	int _frameCount;
	int _indexElectric1;
	int _frameSpeed;
	vector<setDOOR*>								_vDoor;
	vector<setDOOR*>::iterator						_viDoor;

public:
	MAP1();
	~MAP1();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void doorInit();

	vector<setDOOR*>				getVDoor() { return _vDoor; }
	vector<setDOOR*>::iterator		getVIDoor() { return _viDoor; }
	RECT							getRCLadder(int arrNum) { return _rcLadder[arrNum]; }
	RECT							getRCHelp() { return _rcHelp; }
	RECT							getRCExit() { return _rcExit; }
	RECT							getElectric() { return _rcElectric1; }
};


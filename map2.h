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
	image* _imgBrokenblock;
	image* _imgBrokencomputer;
	image* _imgUpeffect;
	image* _imgElevator;

	RECT _rcElectric3;
	RECT _rcHandle;
	RECT _rcBrokenblock;
	RECT _rcBrokencomputer;
	RECT _rcUpeffect;
	RECT _rcLadder[6];
	RECT _rcHelp[6];
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
	bool _isMove;
	bool _checkUpdown;

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

	vector<setELECTRIC*>			getVElectric() { return _vElectric; }
	vector<setELECTRIC*>::iterator	getVIElectric() { return _viElectric; }
	vector<setDOOR*>				getVDoor() { return _vDoor; }
	vector<setDOOR*>::iterator		getVIDoor() { return _viDoor; }
	vector<setBUTTON*>				getVButton() { return _vButton; }
	vector<setBUTTON*>::iterator	getVIButton() { return _viButton; }
	RECT							getRCLadder(int arrNum) { return _rcLadder[arrNum]; }
	RECT							getRCHelp(int arrNum) { return _rcHelp[arrNum]; }
	RECT							getRCElevator() { return _rcElevator; }
	RECT							getRCExit() { return _rcExit; }
	// isMove(true = active elevator, false = unactive elevator), checkUpdown(true = Up, false = down)
	void							setElevatorFloor(bool isMove, bool checkUpdown) { _isMove = isMove; _checkUpdown = checkUpdown; }
};
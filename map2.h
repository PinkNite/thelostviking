#include "electrics.h"
#include "doors.h"
#include "buttons.h"
#include <vector>

#define MAXBROKENBLOCK 9

#pragma once
class PLAYER;

class MAP2
{
private:
	PLAYER* _pPlayer;

	image* _imgMap2bg;
	image* _imgElectric3;
	image* _imgHandleOn;
	image* _imgHandleOff;
	image* _imgBrokenblock[MAXBROKENBLOCK];
	image* _imgBrokencomputer;
	image* _imgUpeffect;
	image* _imgElevator;

	RECT _rcElectric3;
	RECT _rcHandle;
	RECT _rcBrokenblocks;
	RECT _rcBrokencomputer;
	RECT _rcUpeffect;
	RECT _rcLadder[6];
	RECT _rcHelp[6];
	RECT _rcElevator;
	RECT _rcExit;
	RECT _rcBrokenblock[MAXBROKENBLOCK];

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
	int _indexBrokenblock;
	int _countUpeffect;
	int _countBrokenblock;
	int _speedUpeffect;
	int _speedBrokenblock;
	int _speedElevator;
	int _arrBlocki;
	int _arrBlockj;
	int _arrNum;
	bool _arrBool[12];
	char str[128];

	bool _isElevatorMove;
	bool _checkElevatorUpdown;
	bool _isHandle;
	bool _isBrokenComputer;
	bool _isBrokenblocks;
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
	RECT							getRCHandle() { return _rcHandle; }
	RECT							getRCBrokencomputer() { return _rcBrokencomputer; }
	RECT							getRCBrokenblocks() { return _rcBrokenblocks; }
	// isMove(true = active elevator, false = unactive elevator), checkUpdown(true = Up, false = down), speedElevator(1, 2, 4)
	void							setElevatorFloor(bool isMove, bool checkUpdown, int speedElevator = 2)
	{
		_isElevatorMove = isMove; _checkElevatorUpdown = checkUpdown; _speedElevator = speedElevator;
	}
	void							setHandle(bool isHandle) { _isHandle = isHandle; }
	void							setBrokencomputer(bool isBrokenComputer) { _isBrokenComputer = isBrokenComputer; }
	void							setBrokenblocks(bool isBrokenblocks) { _isBrokenblocks = isBrokenblocks; }
	void							setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }
};
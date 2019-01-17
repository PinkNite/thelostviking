#pragma once
class MAP1
{
private:
	image* _imgMap1bg;
	image* _imgDoor1;
	image* _imgDoor2;
	image* _imgElectric1;

	RECT _rcDoor1;
	RECT _rcDoor2;
	RECT _rcElectric1;
	RECT _rcLadder1;
	RECT _rcLadder2;
	RECT _rcLadder3;
	RECT _rcHelp1;
	RECT _rcExit;

private:
	int _frameCount;
	int _indexElectric1;
	int _frameSpeed;

public:
	MAP1();
	~MAP1();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};


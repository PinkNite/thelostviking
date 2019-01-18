#pragma once

struct tagElectric4
{
	image* imgElectric4;
	RECT rcElectric4;
	bool isOff;
};
class SETELECTRIC
{
private:
	tagElectric4 Electric4;

	const char* _imgName;
	int _frameCount;
	int _frameSpeed;
	int _index;

public:
	SETELECTRIC();
	~SETELECTRIC();

	HRESULT init(string strKey, int x, int y, int width, int height, int frameSpeed = 5);
	void release();
	void update();
	void render(HDC hdc);

	bool getIsoff() { return Electric4.isOff; }
	void setIsoff(bool setIsoff) { Electric4.isOff = setIsoff; }
};


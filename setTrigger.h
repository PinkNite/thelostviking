#pragma once

struct tagTrigger
{
	image* imgTrigger;
	RECT rcTrigger;
	bool isOff;
};
class setTRIGGER
{
private:
public:
	setTRIGGER();
	~setTRIGGER();
};

class setELECTRIC
{
private:
	tagTrigger Electric4;

	const char* _imgName;
	int _currentFrameX;
	int _currentFrameY;
	int _currentPframeX;
	int _currentPframeY;

	int _frameCount;
	int _frameSpeed;
	int _index;

public:
	setELECTRIC();
	~setELECTRIC();

	HRESULT init(string strKey, int x, int y, int width, int height, int frameSpeed = 5);
	void release();
	void update();
	void render(HDC hdc);

	bool getIsoff() { return Electric4.isOff; }
	void setIsoff(bool setIsoff) { Electric4.isOff = setIsoff; }
};

class setDOOR
{
private:
	tagTrigger Door;

	const char* _imgName;
	int _currentFrameX;
	int _currentFrameY;
	int _currentPframeX;
	int _currentPframeY;

	int _frameCount;
	int _frameSpeed;
	int _index;

public:
	setDOOR();
	~setDOOR();

	HRESULT init(string strKey, int x, int y, int width, int height, int frameSpeed = 5);
	void release();
	void update();
	void render(HDC hdc);

	bool getIsoff() { return Door.isOff; }
	void setIsoff(bool setIsoff) { Door.isOff = setIsoff; }
};

class setBUTTON
{
private:
	tagTrigger Button;

	const char* _imgName;
	int _currentFrameX;
	int _currentFrameY;
	int _currentPframeX;
	int _currentPframeY;

	int _frameCount;
	int _frameSpeed;
	int _index;

public:
	setBUTTON();
	~setBUTTON();

	HRESULT init(string strKey, int x, int y, int width, int height, int frameSpeed = 10);
	void release();
	void update();
	void render(HDC hdc);

	bool getIsoff() { return Button.isOff; }
	void setIsoff(bool setIsoff) { Button.isOff = setIsoff; }
};
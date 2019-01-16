#pragma once


class ERIC;

class PLAYER
{
private:
	ERIC * _pEric;
public:
	PLAYER();
	~PLAYER();

public:
	void	init();
	void update()			;
	void release()			;
	void render(HDC hdc)	;
};

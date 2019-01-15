#pragma once


class ERIC;

class PLAYER
{
private:

public:
	PLAYER();
	~PLAYER();

public:
	void	init();
	void update()			;
	void release()			;
	void render(HDC hdc)	;
};

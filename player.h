#pragma once
#include "stdafx.h"

class ERIC;
class OBJECT;

class PLAYER
{
private:
	enum class VIKING {
		ERIC = 0,
		BALEOG,
		OLAF,
		MAX
	};

private:
	OBJECT* _pViking[static_cast<const int>(VIKING::MAX)];
	int		_nCurrentViking;

public:
	PLAYER();
	~PLAYER();

public:
	void	init();
	void update()			;
	void release()			;
	void render(HDC hdc)	;

	int getPosX	();
	int getPosY	();
	int getWidth();
	int getHeight();
	int getTop	();
	int getLeft	();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void setMoveStart(bool isMoveStart);
};

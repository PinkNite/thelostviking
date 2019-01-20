#pragma once
#include "stdafx.h"
#include "object.h"
#include "viking.h"

class ERIC;
class OBJECT;

class PLAYER
{
private:
	enum class VIKINGNAME {
		ERIC = 0,
		BALEOG,
		OLAF,
		MAX
	};

private:
	VIKING * _pViking[3];
	int		_nCurrentViking;

public:
	PLAYER();
	~PLAYER();

public:
	void	init();
	void update();
	void release();
	void render(HDC hdc);

	float getPosX();
	float getPosY();
	int getWidth();
	int getHeight();
	int getTop();
	int getLeft();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();


	void useSkillOne();
	void useSkillTwo();

};

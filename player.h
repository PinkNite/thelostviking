#pragma once
#include "stdafx.h"
#include "object.h"

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

	float getPosX();
	float getPosY();
	int getWidth();
	int getHeight();
	int getTop	();
	int getLeft	();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void setMoveStart(bool isMoveStart);

	float getSpeedX();
	float getSpeedY();

	void useSkillOne();
	void useSkillTwo();

	void setEricState(OBJECT::ERIC_STATE ericState);
	OBJECT::ERIC_STATE getEricState();

	void setEricJumpPower(float power);
	void	setLadderAni(int nLadderAni);
};

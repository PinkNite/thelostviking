#pragma once
#include "stdafx.h"
#include "object.h"
#include "viking.h"
#include "map2.h"

class ERIC;
class OBJECT;
class MAP2;

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
	MAP2*	_pMap2;
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

	void resetSpeed();

	void useSkillOne();
	void useSkillTwo();

	void setMovingAnimation(int direction);
	void setStopAnimation();

	inline	void setMap2(MAP2* pMap) { _pMap2 = pMap; }


	void	setPosX	 (float posX);
	void	setPosY	 (float posY);
	void	setWidth (int width);
	void	setHeight(int height);
	void	setTop	 ();
	void	setLeft	 ();
};

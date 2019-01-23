#pragma once
#include "stdafx.h"
#include "object.h"
#include "viking.h"
#include "map2.h"

class ERIC;
class OBJECT;
class MAP2;
class pixelCollision;
class BALEOG;
class EnemyManager;

class PLAYER
{
public://∞Ì√∆¥Ÿ µø»÷æﬂ
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

	int		_rcTmpHeight;
	pixelCollision*		_pPixelCollision;

	int		_rcTmpTop;
	int		_rcTmpBottom;

	bool	_isAnnihilation;

	EnemyManager*	_pEnemyMgr;

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

	void stopSkillOne();

	void setMovingAnimation(int direction);
	void setStopAnimation();
	void setLadderAnimation(int offset);

	bool isCollisionLadder();

	inline	void setMap2(MAP2* pMap) { _pMap2 = pMap; }
	inline	void	setPixelCollision(pixelCollision* pPiexl) { _pPixelCollision = pPiexl; }

	void	setPosX	 (float posX);
	void	setPosY	 (float posY);
	void	setWidth (int width);
	void	setHeight(int height);
	void	setTop	 ();
	void	setLeft	 ();

	VIKINGNAME		getCurrentViking() { return static_cast<VIKINGNAME>(_nCurrentViking); }

	void	nextViking();

	void	deathViking(VIKING::DEATH_MOTION death);


	inline VIKING*	getViking(int index) { return _pViking[index]; }
	inline void		linkEnemyMgr(EnemyManager* pEnemyMgr) { _pEnemyMgr = pEnemyMgr; }

	void	playerAttack();
};

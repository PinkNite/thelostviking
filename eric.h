#pragma once

#include "object.h"

class ERIC : public OBJECT{
private:
	enum class ERIC_STATE 
	{
		RIGHT_IDLE = 0,
		LEFT_IDLE,
		RIGHT_TELEPORT,
		LEFT_TELEPORT,
		RIGHT_AFFRIGHT,
		LEFT_AFFRIGHT,
		RIGHT_RUN,
		LEFT_RUN,
		RIGHT_HADING,
		LEFT_HADING,
		RIGHT_HADING_STUN,
		LEFT_HADING_STUN,
		RIGHT_JUMP,
		LEFT_JUMP,
		RIGHT_SIGN,
		LEFT_SIGN,
		ON_LADDER,
		RIGHT_PUSH,
		LEFT_PUSH,
		RIGHT_FOOT_ROLL,
		LEFT_FOOT_ROLL,
		RIGHT_BOOLEAN,
		LEFT_BOOLEAN,
		RIGHT_GUITAR,
		LEFT_GUITAR,
		RIGHT_SKELETON_DEATH,
		LEFT_SKELETON_DEATH,
		RIGHT_WATER_DEATH,
		LEFT_WATER_DEATH,
		RIGHT_ELECTRIC_DEATH,
		LEFT_ELECTRIC_DEATH,
		RIGHT_FIRE_DEATH,
		LEFT_FIRE_DEATH,
		RIGHT_PRESS_DEATH,
		LEFT_PRESS_DEATH,
		RIGHT_FALLDOWN,
		LEFT_FALLDOWN,
		RIGHT_FALLIN_DEATH,
		LEFT_FALLIN_DEATH,
		RIGHT_FALLDOWN_DEATH,
		LEFT_FALLDOWN_DEATH,
		RIGHT_LAZER_DEATH,
		LEFT_LAZER_DEATH,
		MAX
	};
	
	const	float	_maxSpeed = 7.0f;
	const	float	_minSpeed = 3.0f;
	const	float	_upSpeed = 0.2f;

private:
	int				_hp;
	int				_itemCount;
	float			_speed;
	ERIC_STATE		_state;
	vector<int*>	_vAniFrame;
	int				_arAniFrameCount[static_cast<const int>(ERIC_STATE::MAX)];
	string			_arStrAniState[static_cast<const int>(ERIC_STATE::MAX)];
	bool			_arIsLoop[static_cast<const int>(ERIC_STATE::MAX)];
	animation*		_pAnimation;

	bool			_isMoveStart;

	float			_jumpPower;
	bool			_isJumpimg;
	
	//임시변수들입니다.
	int				_startPosY;
public:
	ERIC();
	~ERIC();

public:
	void	init(int posX,int posY, int width, int height);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

	//이동 함수
	virtual void moveLeft() override;
	virtual void moveRight() override;
	virtual void moveUp() override;
	virtual void moveDown() override;
	virtual void jump() override;


	float	getSpeed();

	void	initAnimation();
	void	initAniFrame();

	//스킬
	virtual void skillOne() override;
	virtual void skillTwo()	override;
public:
	//인라인 함수
	inline void	setMoveStart(bool isMoveStart) { _isMoveStart = isMoveStart; }
	inline int	getPosX() { return OBJECT::getPosX(); }
	inline int	getPosY() { return OBJECT::getPosY(); }
	inline int	getWidth() { return OBJECT::getWidth(); }
	inline int	getHeight() { return OBJECT::getHeight(); }
	inline int	getTop() { return OBJECT::getTop(); }
	inline int	getLeft() { return OBJECT::getLeft(); }
	inline void	setJumping(bool isJumping) { _isJumpimg = isJumping; }
	inline void	setJumpPower(float jumpPower) { _jumpPower = jumpPower; }
};
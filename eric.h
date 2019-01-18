#pragma once

#include "object.h"

class ERIC : public OBJECT {
public:


	const	float	_maxSpeed = 560.0f;
	const	float	_minSpeed = 300.0f;
	const	float	_upSpeed = 1.0f;

	//이동 -> 단위벡터 * 속도 * 시간

private:
	int				_hp;
	int				_itemCount;
	float			_speed;
	OBJECT::ERIC_STATE		_state;
	vector<int*>	_vAniFrame;
	int				_arAniFrameCount[static_cast<const int>(ERIC_STATE::MAX)];
	string			_arStrAniState[static_cast<const int>(ERIC_STATE::MAX)];
	bool			_arIsLoop[static_cast<const int>(ERIC_STATE::MAX)];
	animation*		_pAnimation;

	bool			_isMoveStart;

	float			_jumpPower;
	bool			_isJumpimg;

	bool			_movingJump;

	//임시변수들입니다.
	int				_startPosY;
	int				_upPower;
	int				_turn;
	float			_jumpAngle;
	float			_moveAngleX;
	float			_moveAngleY;
	float			_offsetX;
	float			_offsetY;

	int				_ladderAniIndex;


	//죽음
	bool			_isDeath;
public:
	ERIC();
	~ERIC();

public:
	void	init(int posX, int posY, int width, int height);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

	//이동 함수
	virtual void moveLeft() override;
	virtual void moveRight() override;
	virtual void moveUp() override;
	virtual void moveDown() override;
	virtual void jump() override;


	float	getSpeedX();
	float	getSpeedY();

	void	initAnimation();
	void	initAniFrame();

	//스킬
	virtual void skillOne() override;
	virtual void skillTwo()	override;

	//상태 변화
	virtual OBJECT::ERIC_STATE	getEricState();
	virtual void				setEricState(OBJECT::ERIC_STATE ericState);

	void	setJumpPower(float power);

	virtual void	setLadderAni(int nLadderAni) override;

	void	notOut();
	void	affectGravity();
public:
	//인라인 함수
	inline void	setMoveStart(bool isMoveStart) { _isMoveStart = isMoveStart; }
	inline float getPosX() { return OBJECT::getPosX(); }
	inline float getPosY() { return OBJECT::getPosY(); }
	inline int	getWidth() { return OBJECT::getWidth(); }
	inline int	getHeight() { return OBJECT::getHeight(); }
	inline int	getTop() { return OBJECT::getTop(); }
	inline int	getLeft() { return OBJECT::getLeft(); }
	inline void	setJumping(bool isJumping) { _isJumpimg = isJumping; }

	virtual bool	getJump();

	
};
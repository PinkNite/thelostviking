#pragma once

#include "object.h"

class ERIC : public OBJECT {
public:


	const	float	_maxSpeed = 560.0f;
	const	float	_minSpeed = 300.0f;
	const	float	_upSpeed = 1.0f;

	//�̵� -> �������� * �ӵ� * �ð�

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

	//�ӽú������Դϴ�.
	int				_startPosY;
	int				_upPower;
	int				_turn;
	float			_jumpAngle;
	float			_moveAngleX;
	float			_moveAngleY;
	float			_offsetX;
	float			_offsetY;

	int				_ladderAniIndex;


	//����
	bool			_isDeath;
public:
	ERIC();
	~ERIC();

public:
	void	init(int posX, int posY, int width, int height);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

	//�̵� �Լ�
	virtual void moveLeft() override;
	virtual void moveRight() override;
	virtual void moveUp() override;
	virtual void moveDown() override;
	virtual void jump() override;


	float	getSpeedX();
	float	getSpeedY();

	void	initAnimation();
	void	initAniFrame();

	//��ų
	virtual void skillOne() override;
	virtual void skillTwo()	override;

	//���� ��ȭ
	virtual OBJECT::ERIC_STATE	getEricState();
	virtual void				setEricState(OBJECT::ERIC_STATE ericState);

	void	setJumpPower(float power);

	virtual void	setLadderAni(int nLadderAni) override;

	void	notOut();
	void	affectGravity();
public:
	//�ζ��� �Լ�
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
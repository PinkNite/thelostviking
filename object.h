#pragma once

#include "stdafx.h"


class OBJECT abstract {
public:
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
		ON_LADDER_OVER,
		RIGHT_PUSH,
		LEFT_PUSH,
		RIGHT_FOOT_ROLL,
		LEFT_FOOT_ROLL,
		RIGHT_BOOLEAN,
		LEFT_BOOLEAN,
		RIGHT_GUITAR,
		LEFT_GUITAR,
		RIGHT_SKELETON_DEATH	=	26,
		LEFT_SKELETON_DEATH		=	27,
		RIGHT_WATER_DEATH		=	28,
		LEFT_WATER_DEATH		=	29,
		RIGHT_ELECTRIC_DEATH	=	30,
		LEFT_ELECTRIC_DEATH		=	31,
		RIGHT_FIRE_DEATH		=	32,
		LEFT_FIRE_DEATH			=	33,
		RIGHT_PRESS_DEATH		=	34,
		LEFT_PRESS_DEATH		=	35,
		RIGHT_FALLDOWN,
		LEFT_FALLDOWN,
		RIGHT_FALLIN_DEATH		=	38,
		LEFT_FALLIN_DEATH		=	39,
		RIGHT_FALLDOWN_DEATH	=	40,
		LEFT_FALLDOWN_DEATH		=	41,
		RIGHT_LAZER_DEATH		=	42,
		LEFT_LAZER_DEATH		=	43,
		MAX
	};

protected:
	float		_posX;		//중심좌표 x
	float		_posY;		//중심좌표 y
	int			_width;		//가로길이
	int			_height;	//세로길이
	int			_left;		//사각형 왼쪽
	int			_top;		//사각형 위
	image*		_pImg;		//이미지 설정

public:
	//x,y가로길이 세로길이 초기화
	virtual void init(int posX, int posY, int width, int height);

	//자식들에서 재정의 필수
	virtual void update()			abstract;
	virtual void release()			abstract;
	virtual void render(HDC hdc)	abstract;

	void setImage(image* pImage);

public:
	//get set 모음
	inline float getPosX() { return _posX; }
	inline float getPosY() { return _posY; }
	inline int getWidth() { return _width; }
	inline int getHeight() { return _height; }
	inline int getLeft() { return _left; }
	inline int getTop() { return _top; }
	inline image* getImage() { return _pImg; }


	inline void setPosX(int posX) { _posX = posX; }
	inline void setPosY(int posY) { _posY = posY; }
	inline void setWidth(int width) { _width = width; }
	inline void setHeight(int height) { _height = height; }

	//이동함수
	virtual void moveLeft();
	virtual void moveRight();
	virtual void moveUp();
	virtual void moveDown();
	virtual void setMoveStart(bool isMoveStart);
	virtual void jump();

	virtual float getSpeedX();
	virtual float getSpeedY();

	//스킬 각자 받아서 공격이나 특이 행동을 쓸때 쓰는 오버라이딩 함수
	virtual void skillOne();
	virtual void skillTwo();

	virtual OBJECT::ERIC_STATE getEricState();
	virtual void	setEricState(OBJECT::ERIC_STATE ericState);
	virtual void	setJumpPower(float power);

	virtual void	setLadderAni(int nLadderAni);
	virtual bool	getJump();

};


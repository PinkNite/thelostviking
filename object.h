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
	float		_posX;		//�߽���ǥ x
	float		_posY;		//�߽���ǥ y
	int			_width;		//���α���
	int			_height;	//���α���
	int			_left;		//�簢�� ����
	int			_top;		//�簢�� ��
	image*		_pImg;		//�̹��� ����

public:
	//x,y���α��� ���α��� �ʱ�ȭ
	virtual void init(int posX, int posY, int width, int height);

	//�ڽĵ鿡�� ������ �ʼ�
	virtual void update()			abstract;
	virtual void release()			abstract;
	virtual void render(HDC hdc)	abstract;

	void setImage(image* pImage);

public:
	//get set ����
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

	//�̵��Լ�
	virtual void moveLeft();
	virtual void moveRight();
	virtual void moveUp();
	virtual void moveDown();
	virtual void setMoveStart(bool isMoveStart);
	virtual void jump();

	virtual float getSpeedX();
	virtual float getSpeedY();

	//��ų ���� �޾Ƽ� �����̳� Ư�� �ൿ�� ���� ���� �������̵� �Լ�
	virtual void skillOne();
	virtual void skillTwo();

	virtual OBJECT::ERIC_STATE getEricState();
	virtual void	setEricState(OBJECT::ERIC_STATE ericState);
	virtual void	setJumpPower(float power);

	virtual void	setLadderAni(int nLadderAni);
	virtual bool	getJump();

};


#pragma once

#include "stdafx.h"


class OBJECT abstract{
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
	virtual void init(int posX,int posY,int width, int height);

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
	inline image* getIamge() { return _pImg; }


	inline void setPosX(int posX) { _posX = posX; }
	inline void setPosY(int posY) { _posY = posY; }
	inline void setWidth(int width) { _width = width; }
	inline void setHeight(int height) { _height = height; }
	
	//�̵��Լ�
	virtual void moveLeft()	;
	virtual void moveRight();
	virtual void moveUp()	;
	virtual void moveDown()	;
	virtual void setMoveStart(bool isMoveStart);
	virtual void jump();

	virtual float getSpeedX();
	virtual float getSpeedY();

	//��ų ���� �޾Ƽ� �����̳� Ư�� �ൿ�� ���� ���� �������̵� �Լ�
	virtual void skillOne();
	virtual void skillTwo();

	virtual OBJECT::ERIC_STATE getEricState();
	virtual void	setEricState(OBJECT::ERIC_STATE ericState);
};


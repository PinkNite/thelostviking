#pragma once
#include "object.h"
#include "stdafx.h"



enum { VIKING_WIDTH = 64 };
enum { VIKING_HEIGHT = 64 };


class VIKING : public OBJECT {
public:
	VIKING();
	~VIKING();

	enum class DIRECTION {
		LEFT = 0,
		RIGHT,
		MAX
	};

	//���� ����
	enum class OLAFSHIELD
	{
		BLOCK_TOP,
		BLOCK_FRONT,
		MAX
	};

	enum class LIFE {
		ALIVE = 0,
		DEATH,
		MAX
	};

	enum class STATE
	{
		IDLE = 0,
		ACTION,
		DEATH_MOTION,
		MAX
	};

	enum class IDLE {
		NORMAL = 0,
		FAT,
		MUSIC,
		SPECIAL,
		MAX
	};

	enum class ACTION {
		TELEPORT = 0,
		RUN,
		FALLDOWN,
		STUN,
		PUSH,
		ON_LADDER,
		ON_LADDER_OVER,
		DAMEGE,
		SKILL_ONE,
		SKILL_TWO,
		SKILL_SPECIAL,
		FLY,
		FLY_TURN,
		SKILL_ONE_END,
		MAX
	};

	enum class DEATH_MOTION {
		ELECTRIC = 0,
		FIRE,
		PRESS,
		FALLIN,
		DROP,
		SHOT,
		MAX
	};


protected:
	//���� + ��� + ���� + ���̵�
	//�׼�
	//�׼� �ݹ� ���̵�
	//��� �ݹ� ����
	//�׼� �ݹ� �׼�


	//�÷��̾��� �׼��� �������� 
	int				_direction; //����
	int				_life;	    //��ҳ� �׾���
	int				_state;	    //����
	int				_behavior;  //�ൿ

	string			_arDirection[static_cast<const int>(VIKING::DIRECTION::MAX)];			//����
	string			_arLive[static_cast<const int>(VIKING::LIFE::MAX)];						//��� �״�
	string			_arOlafShield[static_cast<const int>(VIKING::OLAFSHIELD::MAX)];			//�ö��� ���� ���� ����
	vector<string>	_vBehavior[3];			//���̵�, �׼�, �������


	float			_speed;					//�ӵ�
	float			_minSpeed;				//�����ӵ�
	float			_maxSpeed;				//�ִ�ӵ�

	float			_moveSpeed;				//��¥ �����̴� �ӵ����� �ش�

	int				_nHealthPoint;			//ü��

	animation*		_pAnimation;				//������ �ִϸ��̼��� ��´�
	bool			_isOnGround;

public:
	void init(int posX, int posY, int width, int height);
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
	inline bool getIsOnGround() {return _isOnGround; }

	inline void setPosX(float posX) { _posX = posX; }
	inline void setPosY(float posY) { _posY = posY; }
	inline void setWidth(int width) { _width = width; }
	inline void setHeight(int height) { _height = height; }
	inline void	setIsOnGround(bool isOnGround) { _isOnGround = isOnGround; }

	//�̵��Լ�
	//������ �ִϸ��̼� ���� ����
	//�� ���¸� ����.
	//���̵��̸� �޸��� �޸��� �׼����� ��ȯ
	//�׼��̸� (���� ��ų1 -> ����, �ö��� ��ų1,���� �������� �ְų�) ���⸸ �°� ��ȯ�Ѵ�.
	//�ö����� ��ų1 ���¸� ��ų2 ȣ���� ��ų2�� ���ϰ� ��ų 1 �ݹ��ع�����
	virtual void moveLeft(float acceleration);
	virtual void moveRight(float acceleration);
	virtual void moveUp(float acceleration);
	virtual void moveDown(float acceleration);

	void	resetSpeed();

	//��ų ���� �޾Ƽ� �����̳� Ư�� �ൿ�� ���� ���� �������̵� �Լ�
	virtual void skillOne();
	virtual void skillTwo();

	virtual void	setMovingAnimation(int direction)	;
	virtual	void	setStopAnimation()					;

	virtual void	falldownAnimation();

	virtual	void	setSkillAnimation();

	virtual	void	setLadderAnimation(int offset,bool isOverAni,int rcTmpHeight);
	virtual void	pressGravity();
	virtual VIKING::ACTION	getAction() { return static_cast<VIKING::ACTION>(_behavior); }

	//�߷α�
	virtual void	setSkillOneAni();
	virtual void	setSkillTwoAni();

	virtual void	skillOneEnd();

	virtual bool	getUseSkillOne();
	virtual bool	getUseSkillTwo();

	virtual void	death(DEATH_MOTION death);
};

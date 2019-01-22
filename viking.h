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

	//막는 방향
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
	//방향 + 살다 + 상태 + 아이들
	//액션
	//액션 콜백 아이들
	//살다 콜백 죽음
	//액션 콜백 액션


	//플레이어의 액션을 꺼내오는 
	int				_direction; //방향
	int				_life;	    //살았나 죽었나
	int				_state;	    //상태
	int				_behavior;  //행동

	string			_arDirection[static_cast<const int>(VIKING::DIRECTION::MAX)];			//방향
	string			_arLive[static_cast<const int>(VIKING::LIFE::MAX)];						//살다 죽다
	string			_arOlafShield[static_cast<const int>(VIKING::OLAFSHIELD::MAX)];			//올라프 방패 막는 방향
	vector<string>	_vBehavior[3];			//아이들, 액션, 죽음모션


	float			_speed;					//속도
	float			_minSpeed;				//최저속도
	float			_maxSpeed;				//최대속도

	float			_moveSpeed;				//진짜 움직이는 속도값을 준다

	int				_nHealthPoint;			//체력

	animation*		_pAnimation;				//실행할 애니메이션을 담는다
	bool			_isOnGround;

public:
	void init(int posX, int posY, int width, int height);
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
	inline image* getIamge() { return _pImg; }
	inline bool getIsOnGround() {return _isOnGround; }

	inline void setPosX(float posX) { _posX = posX; }
	inline void setPosY(float posY) { _posY = posY; }
	inline void setWidth(int width) { _width = width; }
	inline void setHeight(int height) { _height = height; }
	inline void	setIsOnGround(bool isOnGround) { _isOnGround = isOnGround; }

	//이동함수
	//움직임 애니메이션 변경 생각
	//현 상태를 본다.
	//아이들이면 달리는 달리는 액션으로 전환
	//액션이면 (에릭 스킬1 -> 점프, 올라프 스킬1,전부 떨어지고 있거나) 방향만 맞게 전환한다.
	//올라프는 스킬1 상태면 스킬2 호출후 스킬2는 다하고 스킬 1 콜백해버리자
	virtual void moveLeft(float acceleration);
	virtual void moveRight(float acceleration);
	virtual void moveUp(float acceleration);
	virtual void moveDown(float acceleration);

	void	resetSpeed();

	//스킬 각자 받아서 공격이나 특이 행동을 쓸때 쓰는 오버라이딩 함수
	virtual void skillOne();
	virtual void skillTwo();

	virtual void	setMovingAnimation(int direction)	;
	virtual	void	setStopAnimation()					;

	virtual void	falldownAnimation();

	virtual	void	setSkillAnimation();

	virtual	void	setLadderAnimation(int offset,bool isOverAni,int rcTmpHeight);
	virtual void	pressGravity();
	virtual VIKING::ACTION	getAction() { return static_cast<VIKING::ACTION>(_behavior); }

	//발로그
	virtual void	setSkillOneAni();
	virtual void	setSkillTwoAni();

	virtual void	skillOneEnd();

	virtual bool	getUseSkillOne();
	virtual bool	getUseSkillTwo();

	virtual void	death(DEATH_MOTION death);
};

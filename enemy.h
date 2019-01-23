#pragma once
#include "object.h"


class ENEMY : public OBJECT
{
public:
	enum class ENEMY_STATE
	{
		IDLE_RIGHT,
		IDLE_LEFT,
		MOVE_RIGHT,
		MOVE_LEFT,
		ATTACK_RIGHT,
		ATTACK_LEFT,
		//AIR_JUMP, // boss
		DEATH,
		MAX
	};

	enum class ENEMY_TYPE
	{
		RED,
		BLUE,
		GREEN,
		BLUE_BALL,
		YELLOW_BALL,
		MIRA,

		// 탄발사 공격
		CANNON,
		SNAIL,
		GOLIATH,
		BOSS
	};

	enum class ENEMY_MOVE_TYPE
	{
		STAND,
		MOVER,
		SHOOTER
	};

private:
	ENEMY_TYPE	_type;
	ENEMY_STATE _state;
	ENEMY_MOVE_TYPE _moveType;

	// key animation data
	animation*	 _pAnimation;
	vector<int*> _vAniFrame;
	vector<int>  _frameFps;
	int			 _arAniFrameCount[int(ENEMY_STATE::MAX)];
	string		 _arAniFrameStrKey[int(ENEMY_STATE::MAX)];

	int _hp;
	float _speed;

	// 생성 위치
	float _startX;

	// 이동 영역 끝 좌표
	float _endX;

	// 이동 영역 거리
	float  _moveRange;

	// 공격 인식 거리
	float  _attackRange;

	// Enemy Key Name;
	string _typeName;

	image* _bullet;
	float _bulletX;
	bool _isFire;

public:
	ENEMY();
	~ENEMY();

	//void init(int posX, int posY, int width, int height);
	void init(int posX, int posY, int width, int height, float speed, ENEMY_TYPE type);
	virtual void update()		 override;
	virtual void release()		 override;
	virtual void render(HDC hdc) override;



	// 키애니메이션 설정
	void initAnimation();
	void initAniFrame();

	// 적 종류 설정
	void setEnemyType(ENEMY_TYPE type);
	void stateUpdate(ENEMY_STATE state);
	void moveUpdate();

	void setDeath();
	void fire();

	void setMoveRange(float range) {
		_moveRange = range;
		_endX = _startX + _moveRange;
	};


};


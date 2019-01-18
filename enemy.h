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
	int			 _arAniFrameCount[int(ENEMY_STATE::MAX)];
	string		 _arAniFrameStrKey[int(ENEMY_STATE::MAX)];
	int			 _maxAniFrame;

	int _hp;
	int _startTime;
	int _moveTime;
	float _speed;

	string _typeName;

public:
	ENEMY();
	~ENEMY();

	//void init(int posX, int posY, int width, int height);
	void init(int posX, int posY, int width, int height, float _speed);
	virtual void update()		 override;
	virtual void release()		 override;
	virtual void render(HDC hdc) override;

	// 적 종류 설정
	void setEnemyType(ENEMY_TYPE type);

	virtual void moveLeft() override;
	virtual void moveRight() override;

	void moveUp();
	void moveDown();

	void fire();

	void initAnimation();
	void initAniFrame();

};


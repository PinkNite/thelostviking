#pragma once
#include "object.h"


class enemy : public OBJECT
{
private: 
	enum class ENEMY_STATE
	{
		IDLE_RIGHT,
		IDLE_LEFT,
		MOVE_RIGHT,
		MOVE_LEFT,
		ATTACK_RIGHT,
		ATTACK_LEFT,
		AIR_JUMP, // boss
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
		sNAIL,
		GOLIATH,
		BOSS
	};

	enum class ENEMY_MOVE_TYPE
	{
		STAND,
		MOVER,
		SHOOTER
	};

	const float _speed = 3.0f;

private:
	ENEMY_TYPE	_type;
	ENEMY_STATE _state;
	ENEMY_MOVE_TYPE _moveType;

	// key animation data
	animation*	 _pAnimation;
	vector<int*> _vAniFrame;
	int			 _arAniFrameCount[int(ENEMY_STATE::MAX)];
	string		 _arAniFrameStrKey[int(ENEMY_STATE::MAX)];

	int _hp;
	string _typeName;

public:
	enemy();
	~enemy();

	void init(int posX, int posY, int width, int height);
	virtual void update()		 override;
	virtual void release()		 override;
	virtual void render(HDC hdc) override;

	// 적 종류 설정
	void setEnemyType(ENEMY_TYPE type);
	
	virtual void moveLeft() override;
	virtual void moveRight() override;

	void moveUp();
	void moveDown();
	
	void jump();
	void fire();

	float getSpeedX();
	float getSpeedY();

	void initAnimation();
	void initAniFrame();

};


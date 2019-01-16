#pragma once
#include "object.h"

class enemy : public OBJECT
{
private: 
	enum class ENEMY_STATE
	{
		IDLE,
		IDLE_RIGHT,
		IDLE_LEFT,
		ATTACK_RIGHT,
		ATTACK_LEFT,
		AIR_JUMP, // boss
		DEATH
	};


public:
	enemy();
	~enemy();
};


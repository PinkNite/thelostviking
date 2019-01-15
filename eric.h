#pragma once

#include "player.h"

class ERIC : public PLAYER {

private:


public:
	ERIC();
	~ERIC();

private:
	void	init();
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

};
#pragma once

#include "object.h"

class ERIC : public OBJECT{

private:
	int _nHp;

public:
	ERIC();
	~ERIC();

private:
	void	init();
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

};
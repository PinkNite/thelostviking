#pragma once

#include "object.h"


class PLAYER : public OBJECT
{
private:
	int _nHp;
public:
	PLAYER();
	~PLAYER();

public:
	void	create();
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;
};

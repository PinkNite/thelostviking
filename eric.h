#pragma once

#include "object.h"

class ERIC : public OBJECT{

private:
	int _hp;
	int _itemCount;
public:
	ERIC();
	~ERIC();

public:
	void	init(int posX,int posY, int width, int height);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;


	inline int getPosX() { return OBJECT::getPosX(); }
	inline int getPosY() { return OBJECT::getPosY(); }
	inline int getWidth() { return OBJECT::getWidth(); }
	inline int getHeight() { return OBJECT::getHeight(); }
	inline int getTop() { return OBJECT::getTop(); }
	inline int getLeft() { return OBJECT::getLeft(); }


};
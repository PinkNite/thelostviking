#pragma once

#include "object.h"
#include "stdafx.h"

class ARROW :public OBJECT {
private:


public:
	ARROW();
	~ARROW();


	//x,y가로길이 세로길이 초기화
	void init(int posX, int posY, int width, int height);

	//자식들에서 재정의 필수
	virtual void update()			abstract;
	virtual void release()			abstract;
	virtual void render(HDC hdc)	abstract;

};
#pragma once

#include "object.h"
#include "stdafx.h"

class pixelCollision;

class ARROW :public OBJECT {
private:
	float	_angle;

public:
	ARROW();
	~ARROW();


	//x,y가로길이 세로길이 초기화
	void init(int posX, int posY, int width, int height, float angle);

	//자식들에서 재정의 필수
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;


	bool	deleteArrow();
};
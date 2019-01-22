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


	//x,y���α��� ���α��� �ʱ�ȭ
	void init(int posX, int posY, int width, int height, float angle);

	//�ڽĵ鿡�� ������ �ʼ�
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;


	bool	deleteArrow();
};
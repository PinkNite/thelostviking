#pragma once

#include "object.h"
#include "stdafx.h"

class ARROW :public OBJECT {
private:


public:
	ARROW();
	~ARROW();


	//x,y���α��� ���α��� �ʱ�ȭ
	void init(int posX, int posY, int width, int height);

	//�ڽĵ鿡�� ������ �ʼ�
	virtual void update()			abstract;
	virtual void release()			abstract;
	virtual void render(HDC hdc)	abstract;

};
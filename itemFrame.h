#pragma once
#include "stdafx.h"
class ITEMFRAME
{
protected:

	int _x;
	int _y;
	int _centerX;//�߽ɿ���
	int _centerY;//�߽ɿ���
	int _top;//�簢�� ��
	int _left;//�簢������
	int _width;//����
	int _height;//����
	image* _pImage;


public:
	ITEMFRAME();
	~ITEMFRAME();
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render();

	void setImage(image* image);
	inline image* getImage() { return _pImage; }

};


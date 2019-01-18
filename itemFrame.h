#pragma once
#include "stdafx.h"


class ITEMFRAME
{
protected:
	
	int _x;
	int _y;
	int _centerX;//중심엑스
	int _centerY;//중심와이
	int _top;//사각형 위
	int _left;//사각형왼쪽
	int _width;//넓이
	int _height;//높이
	image* _pImage;
	


public:
	ITEMFRAME();
	~ITEMFRAME();
	virtual HRESULT init(int x, int y, int width, int height);
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);


	void setImage(image* image);
	void setItem(int x, int y, int width, int height);

public:

	inline image* getImage() { return _pImage; }
	inline int getX() { return _x; }
	inline int getY() { return _y; }
};


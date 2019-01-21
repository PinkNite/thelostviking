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
	bool _isAllive;//살아있냐
	int _alphaCount;//알파값
	bool _isUse;//사용했냐

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
	inline int setX(int x) { _x = x; }//위치 변할값
	inline int setY(int y) { _y = y; }
	inline bool getIsAllive() { return _isAllive; }
	inline void SetIsAlliveFalse() { _isAllive = false; }
	inline int getAlphaCount() { return _alphaCount; }
	inline void setAlphaCountPlus(int num) { _alphaCount += num; }//값을넣으면 그만큼 알파카운트가 증가한다.
	inline void setAlphaCount(int num) { _alphaCount = num; }//값을넣으면 그만큼 알파카운트가 증가한다.
	inline bool getUse() { return _isUse; }
	inline void setUse(bool _bool) { _isUse = _bool; }



};


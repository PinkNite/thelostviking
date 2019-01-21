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
	bool _isAllive;//����ֳ�
	int _alphaCount;//���İ�
	bool _isUse;//����߳�

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
	inline int setX(int x) { _x = x; }//��ġ ���Ұ�
	inline int setY(int y) { _y = y; }
	inline bool getIsAllive() { return _isAllive; }
	inline void SetIsAlliveFalse() { _isAllive = false; }
	inline int getAlphaCount() { return _alphaCount; }
	inline void setAlphaCountPlus(int num) { _alphaCount += num; }//���������� �׸�ŭ ����ī��Ʈ�� �����Ѵ�.
	inline void setAlphaCount(int num) { _alphaCount = num; }//���������� �׸�ŭ ����ī��Ʈ�� �����Ѵ�.
	inline bool getUse() { return _isUse; }
	inline void setUse(bool _bool) { _isUse = _bool; }



};


#pragma once

#include "stdafx.h"


class OBJECT abstract{
protected:
	int			_posX;		//�߽���ǥ x
	int			_posY;		//�߽���ǥ y
	int			_width;		//���α���
	int			_height;	//���α���
	int			_left;		//�簢�� ����
	int			_top;		//�簢�� ��
public:
	//x,y���α��� ���α��� �ʱ�ȭ
	void	init(int posX,int posY,int width, int height);

	//�ڽĵ鿡�� ������ �ʼ�
	virtual void update()			abstract;
	virtual void release()			abstract;
	virtual void render(HDC hdc)	abstract;


public:
	//get set ����
	inline int getPosX() { return _posX; }
	inline int getPosY() { return _posY; }
	inline int getWidth() { return _width; }
	inline int getHeight() { return _height; }


	inline void setPosX(int posX) { _posX = posX; }
	inline void setPosY(int posY) { _posY = posY; }
	inline void setWidth(int width) { _width = width; }
	inline void setHeight(int height) { _height = height; }

};


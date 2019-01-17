#pragma once

#include "stdafx.h"
#include "image.h"


class PLAYER;


class CAMERA {
private:
	int _posX;
	int _posY;
	int _width;
	int _height;
	int	_left;
	int _top;
	image* _pCameraBuffer;
	HDC		_hdc;
	image*	_pBac;
	PLAYER*	_pPlayer;

public:
	CAMERA();
	~CAMERA();
	
	void init(int posX, int posY, int width, int height);
	void update();

	void render(HDC hdc);
	void renderinit();
	image* getCameraBuffer() { return _pCameraBuffer; }
	HDC getMemDC() { return _pCameraBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }

	void	setting();
	void	setMap(image* background);


private:
	void	setLeftTop();

public:
	inline	void	setPlayer(PLAYER* pPlayer) { _pPlayer = pPlayer; }

	void	moveRight(int offset);
	void	moveLeft(int offset);
	void	moveUp(int offset);
	void	moveDown(int offset);



public:
	inline	int	getLeft() { return _left; }
	inline	int	getTop() { return _top; }
	inline	int	getRight() { return _left + _width; }
	inline	int	getBotton() { return _top + _height; }
	inline	int	getWidth() { return _width; }
	inline	int	getHeight() { return _height; }


};

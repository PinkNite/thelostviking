#pragma once

#include "stdafx.h"
#include "image.h"

class PLAYER;

class CAMERA {
private:
	float _posX;
	float _posY;
	int _width;
	int _height;
	int	_left;
	int _top;
	image* _pCameraBuffer;
	HDC		_hdc;
	image*	_pBac;
	PLAYER*	_pPlayer;
	bool	_isMoving;
	float	_time;
	float	_travelRangeX;
	float	_travelRangeY;
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

	void	moveRight(float offset);
	void	moveLeft(float offset);
	void	moveUp(float offset);
	void	moveDown(float offset);

	void	moveToPlayer();
	void	movingStart();
	void	outOfRange();

public:
	inline	float	getLeft() { return _left; }
	inline	float	getTop() { return _top; }
	inline	int	getRight() { return _left + _width; }
	inline	int	getBotton() { return _top + _height; }
	inline	int	getWidth() { return _width; }
	inline	int	getHeight() { return _height; }
	inline	bool getMoving() { return _isMoving; }
};

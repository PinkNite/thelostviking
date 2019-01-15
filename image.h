#pragma once

//=============================================
// ## 18.12.03 ## image Class ## ��� 100% �սô�
//=============================================

#include "animation.h"

class image
{
public:

	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,			//���ҽ��κ��� �̹�����
		LOAD_FILE,				//���Ϸκ��� �̹�����
		LOAD_EMPTY,				//�� BMP����
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		
		DWORD		resID;
		HDC			hMemDC;
		HBITMAP		hBit;
		HBITMAP		hOBit;
		float		x;				//�̹����� X��ǥ�� ���� ����
		float		y;				//�̹����� Y��ǥ�� ���� ����
		int			width;			//�̹����� ��ü ����ũ��
		int			height;			//�̹����� ��ü ����ũ��
		int			currentFrameX;	//���� ������ ���ι�ȣ (X��)
		int			currentFrameY;	//���� ������ ���ι�ȣ (Y��)
		int			maxFrameX;		//�ִ� ������ ���ΰ��� (X��)
		int			maxFrameY;		//�ִ� ������ ���ΰ��� (Y��)
		int			frameWidth;		//�������̹����� ����ũ��
		int			frameHeight;	//�������̹����� ����ũ��
		BYTE		loadType;

		tagImageInfo()
		{
			resID			= 0;
			hMemDC			= NULL;
			hBit			= NULL;
			hOBit			= NULL;
			x				= NULL;
			y				= NULL;
			width			= NULL;
			height			= NULL;
			currentFrameX	= NULL;
			currentFrameY	= NULL;
			maxFrameX		= NULL;
			maxFrameY		= NULL;
			frameWidth = 0;
			frameHeight = 0;
			loadType		= LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO		_imageInfo;		//�̹��� ������ ���� ����ü
	CHAR*				_fileName;		//�����̸��� ����� ĳ����������
	BOOL				_trans;			//Ư�� Į�� ������?
	COLORREF			_transColor;	//������ Į���� RGB ����?

	BLENDFUNCTION		_blendFunc;		//���ĺ��� ���� �Լ��� ����
	LPIMAGE_INFO		_blendImage;	//����ó���� �̹���

public:
	image();
	~image();

	//�� ��Ʈ�� �̹��� ����
	HRESULT init(int width, int height);

	//���ҽ��κ��� �о���� ���
	HRESULT init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	//�̹��� �ʱ�ȭ(�����̸�, �̹�������ũ��, �̹�������ũ��, Ư��Į�����ܿ���, Ư��Į��)
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = RGB(0, 0, 0));

	//���Ϸκ��� �̹����� �о���̴� �Լ� (��������, �̹��� �Ѹ���ǥ X, Y �̹��� ���μ���ũ��)
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	//���Ϸκ��� �̹��� �о���̴� �Լ� (�������̹��� ��)
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = FALSE);

	//���Ϸκ��� �̹��� �о���̴� �Լ� (�������̹��� ��)
	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	void release();

	void setTransColor(BOOL trans, COLORREF transColor);

	void render(HDC hdc);
	//�̹��� �����Լ�(�ѷ���DC, 
	void render(HDC hdc, int destX, int destY);

	//�̹��� �����Լ�(�ѷ���DC �ѷ��� left, top, �̹��� ������ Left, Top, Width, Height)
	void render(HDC hdc, int destX, int destY,
		int sourX, int sourY, int sourWidth, int sourHeight);

	//�̹��� ���� �߽�x,y�� �������� �׷��ش�
	void renderCenter(HDC hdc, int dstX, int dstY);

	//�̹��� ������ ����(�ѷ��� DC, �ѷ��� X(Left), Y(Top))
	void frameRender(HDC hdc, int destX, int destY);
	//�̹��� ������ ����(�ѷ��� DC, �ѷ��� Left, �ѷ��� Top, ������X��ȣ, ������Y��ȣ)
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//�̹��� ������ ���� �߽�x,y�� �������� �׷��ش�
	void frameRenderCenter(HDC hdc, int dstX, int dstY);
	void frameRenderCenter(HDC hdc, int dstX, int dstY, int currentFrameX, int currentFrameY);

	//�̹��� �� ������ �����������ϱ�(�ѷ���DC, �ѷ��ٿ���(��Ʈ), ��������X, ��������Y)
	void loopRender(HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);

	void alphaRender(HDC hdc, BYTE alpha);

	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);

	void aniRender(HDC hdc, int destX, int destY, animation* ani);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	//=================================================
	// �̹��� ���� ������, ������ �������� ���ϰ� ������ ^_^)/
	//=================================================

	//�̹��� ��ǥ X 
	inline void SetX(float x) { _imageInfo->x = x; }
	inline float GetX() { return _imageInfo->x; }

	//�̹��� ��ǥ Y
	inline void SetY(float y) { _imageInfo->y = y; }
	inline float GetY() { return _imageInfo->y; }

	//�̹��� ������ǥ(X, Y)
	inline void SetCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline float GetCenterX()
	{
		return _imageInfo->maxFrameX <= 0 ?
			_imageInfo->x + (_imageInfo->width / 2) :
			_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	inline float GetCenterY()
	{
		return _imageInfo->maxFrameY <= 0 ?
			_imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);
	}

	//���� ũ��
	inline int GetWidth() { return _imageInfo->width; }

	//���� ũ��
	inline int GetHeight() { return _imageInfo->height; }

	inline void SetFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;

		//����ó�� ���� �����ӹ�ȣ�� �ִ������ӹ�ȣ���� ũ�� �ִ������ӹ�ȣ�� �����
		if (frameX > _imageInfo->maxFrameX)
			_imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}

	inline void SetFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;

		if (frameY > _imageInfo->maxFrameY)
			_imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	inline int getMaxFrameX() { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY() { return _imageInfo->maxFrameY; }

	inline int getFrameX() { return _imageInfo->currentFrameX; }
	inline int getFrameY() { return _imageInfo->currentFrameY; }

	inline int getFrameWidth() { return _imageInfo->frameWidth; }
	inline int getFrameHeight() { return _imageInfo->frameHeight; }


};


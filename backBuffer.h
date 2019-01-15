#pragma once
class backBuffer
{
public:
	typedef struct tagBackBufferInfo
	{
		HDC		hMemDC;		//�޸� DC
		HBITMAP hBit;		//��Ʈ�� �ڵ�
		HBITMAP hOBit;		//��Ʈ�� �ڵ�(�õ�)
		int		width;		//����ũ��
		int		height;		//����ũ��

		tagBackBufferInfo()
		{
			hMemDC		= NULL;
			hBit		= NULL;
			hOBit		= NULL;
			width		= 0;
			height		= 0;
		}
	}BACKBUFFER_INFO, *LPBACKBUFFER_INFO;

private:
	LPBACKBUFFER_INFO _backBuffer;

public:

	backBuffer();
	~backBuffer();

	//��DC �ʱ�ȭ��	DCũ��
	HRESULT init(int width, int height);

	void release();

	void render(HDC hdc, int destX, int destY);

	inline HDC getMemDC() { return _backBuffer->hMemDC; }
};


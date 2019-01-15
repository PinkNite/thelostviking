#include "stdafx.h"
#include "backBuffer.h"


backBuffer::backBuffer()
	: _backBuffer(NULL)
{
}


backBuffer::~backBuffer()
{
}

HRESULT backBuffer::init(int width, int height)
{
	//����۰� �����Ǿ� ������ == ������ �����Ͱ� ���������� ������ ��Ų��.
	if (_backBuffer != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_backBuffer = new BACKBUFFER_INFO;
	_backBuffer->hMemDC = CreateCompatibleDC(hdc); //���ο� �� DC������ �������ش�.
	_backBuffer->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_backBuffer->hOBit = (HBITMAP)SelectObject(_backBuffer->hMemDC, _backBuffer->hBit);
	_backBuffer->width = width;
	_backBuffer->height = height;

	if(_backBuffer->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

void backBuffer::release()
{
	if (_backBuffer)
	{
		SelectObject(_backBuffer->hMemDC, _backBuffer->hOBit);
		DeleteObject(_backBuffer->hBit);
		DeleteDC(_backBuffer->hMemDC);

		SAFE_DELETE(_backBuffer);
	}
}

void backBuffer::render(HDC hdc, int destX, int destY)
{
	//DC ���� �� ��Ӻ��� �Լ�
	BitBlt(
		hdc,					//������ DC
		destX,					//������
		destY,					//������
		_backBuffer->width,		//������ ũ�� (����ũ��)
		_backBuffer->height,	//������ ũ�� (����ũ��)
		_backBuffer->hMemDC,	//����� DC
		0, 0,					//����� ��ǥ X, Y
		SRCCOPY);				//�������� �����Ѵ�.
}

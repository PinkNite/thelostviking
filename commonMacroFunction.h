#pragma once

//=====================================
// ## 18.11.20 ## ��ũ�θ� ��Ƶ��� ##
//=====================================

inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };

	return pt;
}

inline void LineMake(HDC hdc, int startX, int startY, int endX, int endY)
{
	MoveToEx(hdc, startX, startY, NULL);
	LineTo(hdc, endX, endY);
}

//================= ��Ʈ ���� �Լ� ========================
//    ��Ʈ�� �����(����Ʈ, ž, ����ũ��, ����ũ��)
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };

	return rc;
}

//    ��Ʈ�� �����(����X��ǥ, ����Y��ǥ, ����ũ��, ����ũ��)
inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };

	return rc;
}

//================= �簢�� ���� �Լ� ======================
//          �簢�� �����Լ�(�ѷ���DC, left, top, ����ũ��, ����ũ��
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

inline void Rectangle(HDC hdc,RECT& rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

//====================== �� �� �� �� ���� ===============================
//        �� �����Լ� (hdc, left, top, ����ũ��, ����ũ��)
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}
//        �� �����Լ� (hdc, ������ǥ X, ������ǥ Y, ����ũ��, ����ũ��)
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

inline void Ellipse(HDC hdc, RECT& rc)
{
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

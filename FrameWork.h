#pragma once

#include "stdafx.h"

namespace Mins {

	//���� rect�� �޾ƿ´� �߽�X �߽�Y ������
	inline RECT GetcircleRect(int nPosX, int nPosY, int nRadius) {
		RECT rcTemp;
		rcTemp.left = nPosX - nRadius;
		rcTemp.right = nPosX + nRadius;
		rcTemp.top = nPosY - nRadius;
		rcTemp.bottom = nPosY + nRadius;

		return rcTemp;
	}

	//���� ���浹�� �˷��ִ� �Լ� ù���� x y ������ �ι��� ���� x y ������
	inline bool IsCollisionCirtoCir(int nDstPosX, int nDstPosY, int nDstRadius, int nSrcPosX, int nSrcPosY, int nSrcRadius) {
		int nDisX = nDstPosX - nSrcPosX;
		int nDisY = nDstPosY - nSrcPosY;
		int nDisRR = nDstRadius + nSrcRadius;


		if (nDisX * nDisX + nDisY * nDisY <= nDisRR * nDisRR)
		{
			return true;
		}
		return false;
	}

	//���� �� �浹�� �˷��ִ� �Լ� ù���� x, y, ������ , ���� x, ���� y 
	inline bool IsCollisionCirtoPt(int nDstPosX, int nDstPosY, int nDstRadius, int nSrcX, int nSrcY) {
		int nDisX = nDstPosX - nSrcX;
		int nDisY = nDstPosY - nSrcY;

		if (nDisX * nDisX + nDisY * nDisY <= nDstRadius * nDstRadius)
		{
			return true;
		}
		return false;
	}

	//���� �簢�� �浹 Ȯ�� �Լ�	���� x, ���� y, ���� ������, �簢���� �߽� x, �簢���� �߽� y, �簢���� ����, �簢���� ����
	inline bool IsCollisionCirRect(int nCirPosX, int nCirPosY, int nCirRadius, int nRectPosX, int nRectPosY, int nRectWidth, int nRectHeight) {

		//���μ��μ��� �浹
		if ((nCirPosX >= nRectPosX - nRectWidth / 2 && nCirPosX <= nRectPosX + nRectWidth / 2) ||
			((nCirPosY >= nRectPosY - nRectHeight / 2 && nCirPosY <= nRectPosY + nRectHeight / 2)))
		{
			//�簢���� ���� ������ ��ŭ Ȯ���Ų��
			RECT rcCollision;
			rcCollision.bottom = nRectPosY + nRectHeight / 2 + nCirRadius;
			rcCollision.top = nRectPosY - nRectHeight / 2 - nCirRadius;
			rcCollision.left = nRectPosX - nRectWidth / 2 - nCirRadius;
			rcCollision.right = nRectPosX + nRectWidth / 2 + nCirRadius;

			//���� �߽� �����͸� �����
			POINT ptTemp;
			ptTemp.x = nCirPosX;
			ptTemp.y = nCirPosY;

			//�����Ͱ� Ȯ�� �簢���� ������
			if (PtInRect(&rcCollision, ptTemp))
			{
				return true;
			}
		}
		else {
			//left-top
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, nRectPosX - nRectWidth / 2, nRectPosY - nRectHeight / 2))
			{
				return true;
			}
			//right- top
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, nRectPosX + nRectWidth / 2, nRectPosY - nRectHeight / 2))
			{
				return true;
			}
			//left - bottom
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, nRectPosX - nRectWidth / 2, nRectPosY + nRectHeight / 2))
			{
				return true;
			}
			//right - bottom
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, nRectPosX + nRectWidth / 2, nRectPosY + nRectHeight / 2))
			{
				return true;
			}
		}

		return false;
	}

	//���� ����� �浹
	inline bool IsCollisionCirRect(int nCirPosX, int nCirPosY, int nCirRadius,LPCRECT rc) {

		//���μ��μ��� �浹
		if ((nCirPosX >= rc->left && nCirPosX <= rc->right) ||
			((nCirPosY >= rc->top && nCirPosY <= rc->bottom)))
		{
			//�簢���� ���� ������ ��ŭ Ȯ���Ų��
			RECT rcCollision;
			rcCollision.bottom = rc->bottom + nCirRadius;
			rcCollision.top = rc->top - nCirRadius;
			rcCollision.left = rc->left - nCirRadius;
			rcCollision.right = rc->right + nCirRadius;

			//���� �߽� �����͸� �����
			POINT ptTemp;
			ptTemp.x = nCirPosX;
			ptTemp.y = nCirPosY;

			//�����Ͱ� Ȯ�� �簢���� ������
			if (PtInRect(&rcCollision, ptTemp))
			{
				return true;
			}
		}
		else {
			//left-top
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, rc->left, rc->top))
			{
				return true;
			}
			//right- top
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, rc->right, rc->top))
			{
				return true;
			}
			//left - bottom
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, rc->left, rc->bottom))
			{
				return true;
			}
			//right - bottom
			if (IsCollisionCirtoPt(nCirPosX, nCirPosY, nCirRadius, rc->right, rc->bottom))
			{
				return true;
			}
		}

		return false;
	}

	//�浹 �簢�� ��, �� �о��
	inline void pushCirtoRect(float nCirPosX, float nCirPosY, float nCirRadius,float& fAngle, LPCRECT rc) {

		//���μ��μ��� �浹
		if ((nCirPosX >= rc->left && nCirPosX <= rc->right) ||
			((nCirPosY >= rc->top && nCirPosY <= rc->bottom)))
		{
			//�簢���� ���� ������ ��ŭ Ȯ���Ų��
			RECT rcCollision;
			rcCollision.bottom = rc->bottom + (long)nCirRadius;
			rcCollision.top = rc->top - (long)nCirRadius;
			rcCollision.left = rc->left - (long)nCirRadius;
			rcCollision.right = rc->right + (long)nCirRadius;

			//���� �߽� �����͸� �����
			POINT ptTemp;
			ptTemp.x = (long)nCirPosX;
			ptTemp.y = (long)nCirPosY;

			//�����Ͱ� Ȯ�� �簢���� ������
			if (PtInRect(&rcCollision, ptTemp))
			{
				if (nCirPosX >= rc->left && nCirPosX <= rc->right)
				{
					fAngle = PI2 - fAngle;
				}
				else if (nCirPosY >= rc->top && nCirPosY <= rc->bottom) {
					fAngle = PI - fAngle;
				}
			}
		}
		else {
			//left-top
			if (IsCollisionCirtoPt((int)nCirPosX, (int)nCirPosY, (int)nCirRadius, rc->left, rc->top))
			{
				fAngle = PI + fAngle;
			}
			//right- top
			if (IsCollisionCirtoPt((int)nCirPosX, (int)nCirPosY, (int)nCirRadius, rc->right, rc->top))
			{
				fAngle = PI + fAngle;
			}
			//left - bottom
			if (IsCollisionCirtoPt((int)nCirPosX, (int)nCirPosY, (int)nCirRadius, rc->left, rc->bottom))
			{
				fAngle = PI + fAngle;
			}
			//right - bottom
			if (IsCollisionCirtoPt((int)nCirPosX, (int)nCirPosY, (int)nCirRadius, rc->right, rc->bottom))
			{
				fAngle = PI + fAngle;
			}
		}
	}


	//�簢�� �о��(�ϳ��� ����) dst�簢�� ���� x, y, ����, ����, src�簢��(����) ���� x, y, ����, ����
	inline void pushRect(int & nDstPosX, int & nDstPosY, int nDstWidth, int nDstHeight, const int nSrcPosX, const int nSrcPosY, const int nSrcWidth, const int nSrcHeight) {
		RECT rcDstRect = { nDstPosX - nDstWidth / 2,
							nDstPosY - nDstHeight / 2,
							nDstPosX + nDstWidth / 2,
							nDstPosY + nDstHeight / 2 };

		RECT rcSrcRect = { nSrcPosX - nSrcWidth / 2,
			nSrcPosY - nSrcHeight / 2,
			nSrcPosX + nSrcWidth / 2,
			nSrcPosY + nSrcHeight / 2 };

		RECT rcTemp;

		if (IntersectRect(&rcTemp, &rcDstRect, &rcSrcRect)) {
			
			//�浹�� �簢�� ������ ���α��̰� ���α��� ���� Ŭ��
			if (rcTemp.right - rcTemp.left > rcTemp.bottom - rcTemp.top)
			{
				//������ �浹
				if (rcTemp.top == rcSrcRect.top)
				{
					nDstPosY -= rcTemp.bottom - rcTemp.top;
				}
				//�Ʒ����� �浹
				else if (rcTemp.bottom == rcSrcRect.bottom) {
					nDstPosY += rcTemp.bottom - rcTemp.top;
				}
			}
			else if (rcTemp.right - rcTemp.left > rcTemp.bottom - rcTemp.top)
			{
				//�������� �浹
				if (rcTemp.left == rcSrcRect.left)
				{
					nDstPosX -= rcTemp.right - rcTemp.left;
				}
				//�������� �浹
				else if (rcTemp.right == rcSrcRect.right) {
					nDstPosX += rcTemp.right - rcTemp.left;
				}
			}
			else
			{
				//��Ȯ�� �𼭸� �浹
				//�»��浹
				if (rcTemp.top == rcSrcRect.top && rcTemp.left == rcSrcRect.left)
				{
					nDstPosY -= rcTemp.bottom - rcTemp.top;
					nDstPosX -= rcTemp.right - rcTemp.left;
				}//����浹
				else if (rcTemp.top == rcSrcRect.top && rcTemp.right == rcSrcRect.right) {
					nDstPosX += rcTemp.right - rcTemp.left;
					nDstPosY -= rcTemp.bottom - rcTemp.top;
				}//�����浹
				else if (rcTemp.bottom == rcSrcRect.bottom && rcTemp.left == rcSrcRect.left) {
					nDstPosY += rcTemp.bottom - rcTemp.top;
					nDstPosX -= rcTemp.right - rcTemp.left;
				}//�����浹
				else if (rcTemp.bottom == rcSrcRect.bottom && rcTemp.right == rcSrcRect.right) {
					nDstPosY += rcTemp.bottom - rcTemp.top;
					nDstPosX += rcTemp.right - rcTemp.left;
				}
			}
		}

	}

	//�簢�� �о��(�ϳ��� ����) dst�簢�� ���� x, y, ����, ����, src�簢��(����) ���� x, y, ����, ����
	inline void pushRects(float & nDstPosX, float & nDstPosY, int nDstWidth, int nDstHeight,  int nSrcPosX,  int nSrcPosY,  int nSrcWidth,  int nSrcHeight) {
		RECT rcDstRect = { (int)nDstPosX - nDstWidth / 2,
			(int)nDstPosY - nDstHeight / 2,
			(int)nDstPosX + nDstWidth / 2,
			(int)nDstPosY + nDstHeight / 2 };

		RECT rcSrcRect = { nSrcPosX - nSrcWidth / 2,
			nSrcPosY - nSrcHeight / 2,
			nSrcPosX + nSrcWidth / 2,
			nSrcPosY + nSrcHeight / 2 };

		RECT rcTemp;

		if (IntersectRect(&rcTemp, &rcDstRect, &rcSrcRect)) {

			//�浹�� �簢�� ������ ���α��̰� ���α��� ���� Ŭ��
			if (rcTemp.right - rcTemp.left >= rcTemp.bottom - rcTemp.top)
			{
				//������ �浹
				if (rcTemp.top == rcSrcRect.top)
				{
					nDstPosY -= rcTemp.bottom - rcTemp.top;
				}
				//�Ʒ����� �浹
				else if (rcTemp.bottom == rcSrcRect.bottom) {
					nDstPosY += rcTemp.bottom - rcTemp.top;
				}
			}
			else if (rcTemp.right - rcTemp.left > rcTemp.bottom - rcTemp.top)
			{
				//�������� �浹
				if (rcTemp.left == rcSrcRect.left)
				{
					nDstPosX -= rcTemp.right - rcTemp.left;
				}
				//�������� �浹
				else if (rcTemp.right == rcSrcRect.right) {
					nDstPosX += rcTemp.right - rcTemp.left;
				}
			}
			else
			{
				//��Ȯ�� �𼭸� �浹
				//�»��浹
				if (rcTemp.top == rcSrcRect.top && rcTemp.left == rcSrcRect.left)
				{
					nDstPosY -= rcTemp.bottom - rcTemp.top;
					nDstPosX -= rcTemp.right - rcTemp.left;
				}//����浹
				else if (rcTemp.top == rcSrcRect.top && rcTemp.right == rcSrcRect.right) {
					nDstPosX += rcTemp.right - rcTemp.left;
					nDstPosY -= rcTemp.bottom - rcTemp.top;
				}//�����浹
				else if (rcTemp.bottom == rcSrcRect.bottom && rcTemp.left == rcSrcRect.left) {
					nDstPosY += rcTemp.bottom - rcTemp.top;
					nDstPosX -= rcTemp.right - rcTemp.left;
				}//�����浹
				else if (rcTemp.bottom == rcSrcRect.bottom && rcTemp.right == rcSrcRect.right) {
					nDstPosY += rcTemp.bottom - rcTemp.top;
					nDstPosX += rcTemp.right - rcTemp.left;
				}
			}
		}

	}

	//�簢�� �о��(�ϳ��� ����) dst�簢�� ���� x, y, ����, ����, src�簢��(����) ���� x, y, ����, ����
	inline void pushRect(LPRECT pDstRect, const LPRECT pSrcRect) {
		
		RECT rcTemp;

		if (IntersectRect(&rcTemp, pDstRect, pSrcRect)) {

			//�浹�� �簢�� ������ ���α��̰� ���α��� ���� Ŭ��
			if (rcTemp.right - rcTemp.left > rcTemp.bottom - rcTemp.top)
			{
				//������ �浹
				if (rcTemp.top == pSrcRect->top)
				{
					pDstRect->top -= rcTemp.bottom - rcTemp.top;
					pDstRect->bottom -= rcTemp.bottom - rcTemp.top;

				}
				//�Ʒ����� �浹
				else if (rcTemp.bottom == pSrcRect->bottom) {
					pDstRect->top += rcTemp.bottom - rcTemp.top;
					pDstRect->bottom += rcTemp.bottom - rcTemp.top;
				}
			}
			else if (rcTemp.right - rcTemp.left > rcTemp.bottom - rcTemp.top)
			{
				//�������� �浹
				if (rcTemp.left == pSrcRect->left)
				{
					pDstRect->left -= rcTemp.right - rcTemp.left;
					pDstRect->right -= rcTemp.right - rcTemp.left;
				}
				//�������� �浹
				else if (rcTemp.right == pSrcRect->right) {
					pDstRect->left += rcTemp.right - rcTemp.left;
					pDstRect->right += rcTemp.right - rcTemp.left;
				}
			}
			else
			{
				//��Ȯ�� �𼭸� �浹
				//�»��浹
				if (rcTemp.top == pSrcRect->top && rcTemp.left == pSrcRect->left)
				{
					pDstRect->top -= rcTemp.bottom - rcTemp.top;
					pDstRect->bottom -= rcTemp.bottom - rcTemp.top;
					pDstRect->left -= rcTemp.right - rcTemp.left;
					pDstRect->right -= rcTemp.right - rcTemp.left;
				}//����浹
				else if (rcTemp.top == pSrcRect->top && rcTemp.right == pSrcRect->right) {
					pDstRect->left += rcTemp.right - rcTemp.left;
					pDstRect->right += rcTemp.right - rcTemp.left;
					pDstRect->top -= rcTemp.bottom - rcTemp.top;
					pDstRect->bottom -= rcTemp.bottom - rcTemp.top;
				}//�����浹
				else if (rcTemp.bottom == pSrcRect->bottom && rcTemp.left == pSrcRect->left) {
					pDstRect->top += rcTemp.bottom - rcTemp.top;
					pDstRect->bottom += rcTemp.bottom - rcTemp.top;
					pDstRect->left -= rcTemp.right - rcTemp.left;
					pDstRect->right -= rcTemp.right - rcTemp.left;
				}//�����浹
				else if (rcTemp.bottom == pSrcRect->bottom && rcTemp.right == pSrcRect->right) {
					pDstRect->top += rcTemp.bottom - rcTemp.top;
					pDstRect->bottom += rcTemp.bottom - rcTemp.top;
					pDstRect->left += rcTemp.right - rcTemp.left;
					pDstRect->right += rcTemp.right - rcTemp.left;
				}
			}
		}
	}

	inline float presentPowerY(float fAngle, float fSpeed) {
		return -sinf(fAngle) * fSpeed;
	}

	inline float presentPowerX(float fAngle, float fSpeed) {
		return cosf(fAngle) * fSpeed;
	}


	inline void FYshuffle(int* pDstArray, int nLength) {
		
		for (int i = nLength - 1; i > 0; i--)
		{
			int nTmpIndex = randomFunction::getSingleton()->getInt(i);
			int nTmp = pDstArray[i];
			pDstArray[i] = pDstArray[nTmpIndex];
			pDstArray[nTmpIndex] = nTmp;
		}

	}

	//360������ 10���� ������ ���� ������ ������ �˷��ش�. 
	// PI2 / 36.0f * ��ȯ��   
	inline int getNearAnglePI2(float fAngle) {
		int nResult(0);

		while (PI2 / 36.0f * static_cast<float>(nResult) < fAngle)
		{
			nResult++;
		}

		float fDst = PI2 / 36.0f * static_cast<float>(nResult);
		
		if (fabsf(fDst - fAngle) <= FLT_EPSILON || nResult == 0)
		{
			return nResult;
		}
		else {
			float fSrc = PI2 / 36.0f * static_cast<float>(nResult - 1);
			
			if (fabsf(fDst - fAngle) < fabsf(fSrc - fAngle))
			{
				return nResult;
			}
			else
			{
				return nResult - 1;
			}
		}

	}

	//360������ 10���� ������ ���� ������ ������ PI������ ��ȯ�ؼ� �˷��ش� 
	// PI2 / 36.0f * ��ȯ�� ��ȯ���� 18���� Ŭ ��� -18�ؼ� �ش�  
	inline int getNearAnglePI(float fAngle) {
		int nResult(0);

		while (PI2 / 36.0f * static_cast<float>(nResult) < fAngle)
		{
			nResult++;
		}

		float fDst = PI2 / 36.0f * static_cast<float>(nResult);

		if (fabsf(fDst - fAngle) <= FLT_EPSILON || nResult == 0)
		{
			if (nResult >= 18)
			{
				nResult -= 18;
			}
			return nResult;
		}
		else {
			float fSrc = PI2 / 36.0f * static_cast<float>(nResult - 1);

			if (fabsf(fDst - fAngle) < fabsf(fSrc - fAngle))
			{
				if (nResult >= 18)
				{
					nResult -= 18;
				}
			}
			else
			{
				if (nResult >= 19)
				{
					nResult -= 19;
				}
			}
			return nResult;
		}
	}


	inline int getNearAngleSBullet(float fAngle)
	{
		int nResult(0);

		while (fAngle > PI2)
		{
			fAngle = fAngle - PI2;
		}



		if (fAngle >= PI)
		{
			fAngle -= PI;
		}

		while (PI / 18.0f * static_cast<float>(nResult) < fAngle)
		{
			nResult++;
		}

		float fDst = PI / 18.0f * static_cast<float>(nResult);

		if (fabsf(fDst - fAngle) <= FLT_EPSILON)
		{
			if (nResult < 0)
			{
				nResult = 0;
			}
			if (nResult >= 18)
			{
				nResult = 0;
			}
			return nResult;
		}
		else {
			float fSrc = PI / 18.0f * static_cast<float>(nResult - 1);

			if (fabsf(fDst - fAngle) < fabsf(fSrc - fAngle))
			{
				if (nResult >= 18)
				{
					nResult = 0;
				}
				if (nResult < 0)
				{
					nResult = 0;
				}

				return nResult;
			}
			else
			{
				if (nResult >= 18)
				{
					nResult = 0;
				}
				if (nResult < 0)
				{
					nResult = 0;
				}
				return nResult;
			}

			if (nResult < 0)
			{
				nResult = 0;
			}
			return nResult;
		}

	}



	inline float getDoubleDistance(float fDstX, float fDstY, float fSrcX, float fSrcY) {
		return (fDstX - fSrcX) * (fDstX - fSrcX) + (fDstY - fSrcY) * (fDstY - fSrcY);
	}


	inline DWORD getMazenta() {
		DWORD dwColor;
		dwColor = ((COLORREF)(((BYTE)(0xff) | ((WORD)((BYTE)(0x00)) << 8)) | (((DWORD)(BYTE)(0xff)) << 16)));
		return dwColor;
	}


	inline float	getDoubleDis(float fDstX, float fDstY, float fSrcX, float fSrcY)
	{
		return (fDstX - fSrcX)*(fDstX - fSrcX) + (fDstY - fSrcY)*(fDstY - fSrcY);
	}


	//�簢�� �浹 (�簢��1 �߽� x , �߽� y, ����, ����, �簢��2 �߽�x, �߽�y, ����, ����)
	inline bool	isCollisionRectRect(int nDstX, int nDstY, int nDstWidth, int nDstHeight, int nSrcX, int nSrcY, int nSrcWidth, int nSrcHeight) {

		RECT rcDst = RectMakeCenter(nDstX, nDstY, nDstWidth, nDstHeight);
		RECT rcSrc = RectMakeCenter(nSrcX, nSrcY, nSrcWidth, nSrcHeight);

		RECT rcTmp;
		if (IntersectRect(&rcTmp,&rcDst,&rcSrc))
		{
			return true;
		}
		else {
			return false;
		}
	}


}


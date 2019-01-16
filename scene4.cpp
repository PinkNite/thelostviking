#include "stdafx.h"
#include "scene4.h"


SCENE4::SCENE4()
{
}

SCENE4::~SCENE4()
{
}

HRESULT SCENE4::init()
{

	_pImage = new image;
	_pImage = IMAGEMANAGER->findImage("��Ʈ�����");
	_y = -204;
	_alphaCount = 255;
	_jumpPower = 0;
	_gravity = 1;
	_jumpCount = 1;
	//Ƣ�� �̹����� ���ؼ� 176�� �������� 

	return S_OK;
}

void SCENE4::release()
{
}

void SCENE4::update()
{
	//action(14.0f, 18.0f);//���İ������鼭 ����?
	//��������
	if (TIMEMANAGER->getWorldTime() >= 17.0f&&_y <= 176)
	{
		_y -= _jumpPower;//�����Ŀ�
		_jumpPower -= _gravity;//�߷�����
	}

	if (_y >= 176)
	{
		switch (_jumpCount)//ī��Ʈ������ �ٸ��� �����ѹ��� ��Ű��
		{
		case 0:
			_y = 176;
			break;
		case 1:  //�����ؾ���
			_jumpCount--;
			_jumpPower = 10;

			break;

		}
	}


}
void SCENE4::render()
{
	_pImage->alphaRender(getMemDC(), 0, _y, _alphaCount);
}

void SCENE4::action(float numA, float numB, float numC)
{
	if (_alphaCount < 255 && TIMEMANAGER->getWorldTime() < numB
		&&TIMEMANAGER->getWorldTime() > numA)
	{

		_alphaCount += 5;
	}
	if (TIMEMANAGER->getWorldTime() >= numC)//12�ʳ����� ���İ� �ٿ��� �������
	{

		if (_alphaCount > 0)
		{
			_alphaCount -= 5;//�� �� ������ ������� �ϱ� ����
		}
	}
}

void SCENE4::action(float numA, float numB)
{
	if (_alphaCount < 255 && TIMEMANAGER->getWorldTime() < numB
		&&TIMEMANAGER->getWorldTime() > numA)
	{

		_alphaCount++;
	}
}

#include "stdafx.h"
#include "sceneStart.h"

SCENESTART::SCENESTART()
{
}

SCENESTART::~SCENESTART()
{
}

HRESULT SCENESTART::init()
{

	_pScene0 = new SCENE0;
	_pScene0->init();

	_pScene1 = new SCENE1;
	_pScene1->init();

	_pScene2 = new SCENE2;
	_pScene2->init();

	_pScene3 = new SCENE3;
	_pScene3->init();

	_pScene4 = new SCENE4;
	_pScene4->init();

	_pBlackBackGround = new BACKGROUND;
	_pBlackBackGround->init();
	_pPinkBackGround = new BACKGROUND2;
	_pPinkBackGround->init();

	_pBackGroundScene = _pBlackBackGround;//����ȭ�� �ʱ�ȭ



	_pScene = _pScene0;//���̹��� �ʱ�ȭ 0��

	_pSceneBoss = _pPinkBackGround;//��ũ��� �ʱ�ȭ


	return S_OK;
}

void SCENESTART::release()
{
}

void SCENESTART::update()
{

	//���⼭ ������ �ɸ� ���� �ٲ��.

	//��ó������ ����ȭ���̰�  2���� 1����Ʈ��ȭ��
	if (TIMEMANAGER->getWorldTime() < 3.0f&&TIMEMANAGER->getWorldTime() >= 2.0f)
	{
		_pScene = _pScene1;
	}
	//7�������������� 8���� 2���� ���
	if (TIMEMANAGER->getWorldTime() >= 9.0f&&TIMEMANAGER->getWorldTime() <= 10.0f)
	{
		_pScene = _pScene2;
	}
	//14�� ������ �ٸ� �̹����� ��ü
	if (TIMEMANAGER->getWorldTime() >= 14.0f&&TIMEMANAGER->getWorldTime() <= 15.0f)
	{
		_pScene = _pScene3;
	}
	//17�ʿ� ��ũ��� ����
	if (TIMEMANAGER->getWorldTime() >= 17.0f&&TIMEMANAGER->getWorldTime() <= 18.0f)
	{
		_pSceneBoss = _pScene4;
	}
	///////////////////////////////////���� ������ �÷��̾� Ű�Է����� �⺻������ ������ ȭ�� ///////////////////////////




	//////////////////////Ȯ�ο�//////////Ű

	/*if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_pScene = _pScene1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		_pScene = _pScene0;
	}*/

	// update()

	_pScene0->update();
	_pScene1->update();
	_pScene2->update();
	_pScene3->update();
	_pScene4->update();
}

void SCENESTART::render()
{
	//�׸��� ��ġ
	//���
	_pBackGroundScene->render();//�����̹���  

	_pScene->render();//�ٲ�� �̹���

	_pSceneBoss->render();//�����̴� �̹���
}

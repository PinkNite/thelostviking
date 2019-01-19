#include "stdafx.h"
#include "UI.h"


UI::UI()
{
}


UI::~UI()
{
}

HRESULT UI::init()
{
	//������
	_ui.pImage = new image;
	_ui.pImage = IMAGEMANAGER->findImage("UI");

	//������
	for (int i = 0; i < 9; i++)
	{
		_life[i].pImage = new image;
		_life[i].isAllive = true;
		_life[i].pImage = IMAGEMANAGER->findImage("life");
	}
	//������
	for (int i = 0; i < 3; i++)
	{
		_baleog[i].pImage = new image;
		_erik[i].pImage = new image;
		_olaf[i].pImage = new image;
		switch (i)
		{
		case 0:
			_baleog[i].pImage = IMAGEMANAGER->findImage("baleogOn");
			_olaf[i].pImage = IMAGEMANAGER->findImage("olafOn");
			_erik[i].pImage = IMAGEMANAGER->findImage("erikOn");
			break;
		case 1:
			_baleog[i].pImage = IMAGEMANAGER->findImage("baleogOff");
			_olaf[i].pImage = IMAGEMANAGER->findImage("olafOff");
			_erik[i].pImage = IMAGEMANAGER->findImage("erikOff");
			break;
		case 2:
			_baleog[i].pImage = IMAGEMANAGER->findImage("baleogDead");
			_olaf[i].pImage = IMAGEMANAGER->findImage("olafDead");
			_erik[i].pImage = IMAGEMANAGER->findImage("erikDead");
			break;
		}
		
	}
	_olafState=OLAF_OFF;
	_baleogState = BALEOG_OFF;
	_erikState = ERIK_ON;

	_trashCan.pImage = new image;
	_trashCan.pImage = IMAGEMANAGER->findImage("trashCan");
	_trashCan.alphaCount = 255;
	for (int i = 0; i < 3; i++)
	{
		_select[i].pImage = new image;
		_select[i].pImage = IMAGEMANAGER->findImage("selectYellow");
		_select[i].alphaCount = 255;		
	}
	for (int i = 0; i < 3; i++)
	{
		_selectState[i] = SELECT_LEFT_TOP;//�������� �ʱ�ȭ��

	}

	//�浹 �Ҷ� �����۵�
	_pItemMeat = new ITEMMEAT;
	for (int i = 0; i < 2; i++)
	{
		_pItemBoom[i] = new ITEMBOOM;
		_pItemFruit1[i] = new ITEMFRUIT1;
		_pItemFruit2[i] = new ITEMFRUIT2;
	}

	//ĳ������ ������ ������ �̳Ѱ�
	_erikItem = ITEM_0;
	_baleogItem = ITEM_0;
	_olafItem = ITEM_0;  //���� ���� 0

	return S_OK;
}

void UI::release()
{

	

}

void UI::update()
{
	//������Ʈ �ٲ㼭 �׽�Ʈ
	if (KEYMANAGER->isOnceKeyDown('Y'))
	{
		_baleogState = BALEOG_ON;
	}
	if (KEYMANAGER->isOnceKeyDown('U'))
	{
		_baleogState = BALEOG_OFF;
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_baleogState = BALEOG_DEAD;
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_erikState = ERIK_ON;
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_erikState = ERIK_OFF;
	}
	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_erikState = ERIK_DEAD;
	}
	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_olafState = OLAF_ON;
	}
	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		_olafState = OLAF_OFF;
	}
	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		_olafState = OLAF_DEAD;
	}

	//_life[0].isAllive = false;//�̷� �����
	selectMove();//��� Ư�� ���ǿ����� �Ǿ����
	getItem();
}

void UI::render()
{
	_ui.pImage->render(getMemDC(), 0, 362);
	_trashCan.pImage->alphaRender(getMemDC(), 564, 402, _trashCan.alphaCount);//����ǥ�� �������� ��?

	

	for (int i = 0; i< 3; i++)
	{
		switch (i)
		{
		case 0:
			_select[i].pImage->alphaRender(getMemDC(), _select[i].x, _select[i].y, _select[i].alphaCount);
			break;
		case 1:
			_select[i].pImage->alphaRender(getMemDC(), _select[i].x, _select[i].y, _select[i].alphaCount);
			break;
		case 2:
			_select[i].pImage->alphaRender(getMemDC(), _select[i].x, _select[i].y, _select[i].alphaCount);
			break;

		}
	
	}
	for (int i = 0; i < 9; i++)
	{
		switch (i)
		{
		case 0:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 40, 466);
			}
			break;
		case 1:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 40 + 20, 466);
			}
			break;
		case 2:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 60 + 20, 466);
			}
			break;
		case 3:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 220, 466);
			}
			break;
		case 4:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 220 + 20, 466);
			}
			break;
		case 5:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 240 + 20, 466);
			}
			break;
		case 6:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 400, 466);
			}
			break;
		case 7:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 400 + 20, 466);
			}
			break;
		case 8:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(getMemDC(), 420 + 20, 466);
			}
			break;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			if (_erikState == ERIK_ON)
			{
				_erik[i].pImage->render(getMemDC(), 40, 405);
				
			}
			if (_baleogState == BALEOG_ON)
			{
				
				_baleog[i].pImage->render(getMemDC(), 220, 405);
				
			}
			if (_olafState == OLAF_ON)
			{
				_olaf[i].pImage->render(getMemDC(), 400, 405);
				
			}
			break;
		case 1:
			if (_erikState == ERIK_OFF)
			{
				_erik[i].pImage->render(getMemDC(), 40, 405);
			}
			if (_baleogState == BALEOG_OFF)
			{
				_baleog[i].pImage->render(getMemDC(), 220, 405);
			}
			if (_olafState == OLAF_OFF)
			{
				_olaf[i].pImage->render(getMemDC(), 400, 405);
			}
			break;
		case 2:
			if (_erikState == ERIK_DEAD)
			{
				_erik[i].pImage->render(getMemDC(), 40, 405);
			}
			if (_baleogState == BALEOG_DEAD)
			{
				_baleog[i].pImage->render(getMemDC(), 220, 405);
			}
			if (_olafState == OLAF_DEAD)
			{
				_olaf[i].pImage->render(getMemDC(), 400, 405);
			}
			break;

		}
	}



	//������
	for (int i = 0; i < 2; i++)
	{
		if (_erikItem != ITEM_0 && _pItemBoom[i]->getIsAllive())
		{
			_pItemBoom[i]->render(getMemDC());//�����̴ϱ� �ٸ�
		}
		if (_erikItem != ITEM_0 && _pItemFruit1[i]->getIsAllive())
		{
			_pItemFruit1[i]->render(getMemDC());
		}
		if (_erikItem != ITEM_0 && _pItemFruit2[i]->getIsAllive())
		{
			_pItemFruit2[i]->render(getMemDC());
		}
		if (_erikItem != ITEM_0 && _pItemMeat->getIsAllive())
		{
			_pItemMeat->render(getMemDC());
		}
	}
	
}

void UI::selectMove()
{
	if (_erikState == ERIK_ON)
	{
		_select[0].alphaCount += 10;//���̸� ���İ� ����
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			switch (_selectState[0])
			{
			case SELECT_RIGHT_TOP:
				_selectState[0] = SELECT_LEFT_TOP;
				break;
			case SELECT_RIGHT_BOTTOM:
				_selectState[0] = SELECT_LEFT_BOTTOM;
				break;
			}	
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			switch (_selectState[0])
			{
			case SELECT_LEFT_TOP:
				_selectState[0] = SELECT_RIGHT_TOP;
				break;
			case SELECT_LEFT_BOTTOM:
				_selectState[0] = SELECT_RIGHT_BOTTOM;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			switch (_selectState[0])
			{
			case SELECT_LEFT_BOTTOM:
				_selectState[0] = SELECT_LEFT_TOP;
				break;
			case SELECT_RIGHT_BOTTOM:
				_selectState[0] = SELECT_RIGHT_TOP;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			switch (_selectState[0])
			{
			case SELECT_LEFT_TOP:
				_selectState[0] = SELECT_LEFT_BOTTOM;
				break;
			case SELECT_RIGHT_TOP:
				_selectState[0] = SELECT_RIGHT_BOTTOM;
				break;
			}
		}
	}
	else if (_baleogState == BALEOG_ON)
	{	
		_select[1].alphaCount += 10;
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			switch (_selectState[1])
			{
			case SELECT_RIGHT_TOP:
				_selectState[1] = SELECT_LEFT_TOP;
				break;
			case SELECT_RIGHT_BOTTOM:
				_selectState[1] = SELECT_LEFT_BOTTOM;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			switch (_selectState[1])
			{
			case SELECT_LEFT_TOP:
				_selectState[1] = SELECT_RIGHT_TOP;
				break;
			case SELECT_LEFT_BOTTOM:
				_selectState[1] = SELECT_RIGHT_BOTTOM;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			switch (_selectState[1])
			{
			case SELECT_LEFT_BOTTOM:
				_selectState[1] = SELECT_LEFT_TOP;
				break;
			case SELECT_RIGHT_BOTTOM:
				_selectState[1] = SELECT_RIGHT_TOP;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			switch (_selectState[1])
			{
			case SELECT_LEFT_TOP:
				_selectState[1] = SELECT_LEFT_BOTTOM;
				break;
			case SELECT_RIGHT_TOP:
				_selectState[1] = SELECT_RIGHT_BOTTOM;
				break;
			}
		}
	}
	else if (_olafState == OLAF_ON)
	{
		_select[2].alphaCount += 10;
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			switch (_selectState[2])
			{
			case SELECT_RIGHT_TOP:
				_selectState[2] = SELECT_LEFT_TOP;
				break;
			case SELECT_RIGHT_BOTTOM:
				_selectState[2] = SELECT_LEFT_BOTTOM;
				break;
			}

		}
		if (KEYMANAGER->isOnceKeyDown('D'))
		{
			switch (_selectState[2])
			{
			case SELECT_LEFT_TOP:
				_selectState[2] = SELECT_RIGHT_TOP;
				break;
			case SELECT_LEFT_BOTTOM:
				_selectState[2] = SELECT_RIGHT_BOTTOM;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('W'))
		{
			switch (_selectState[2])
			{
			case SELECT_LEFT_BOTTOM:
				_selectState[2] = SELECT_LEFT_TOP;
				break;
			case SELECT_RIGHT_BOTTOM:
				_selectState[2] = SELECT_RIGHT_TOP;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('S'))
		{
			switch (_selectState[2])
			{
			case SELECT_LEFT_TOP:
				_selectState[2] = SELECT_LEFT_BOTTOM;
				break;
			case SELECT_RIGHT_TOP:
				_selectState[2] = SELECT_RIGHT_BOTTOM;
				break;
			}
		}

	}
		/////////////////�̵��κ�
	for (int i = 0; i < 3; i++)
	{
		switch (i)//3���� �ٴٸ��� �ؾ���
		{
		case 0:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 120;
				_select[i].y = 402;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 120;
				_select[i].y = 442;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 160;
				_select[i].y = 402;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 160;
				_select[i].y = 442;
				break;
			}
			break;
		case 1:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 302;
				_select[i].y = 402;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 302;
				_select[i].y = 442;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 342;
				_select[i].y = 402;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 342;
				_select[i].y = 442;
				break;
			}
			break;
		case 2:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 482;
				_select[i].y = 402;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 482;
				_select[i].y = 442;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 522;
				_select[i].y = 402;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 522;
				_select[i].y = 442;
				break;
			}
			break;
		}
	}
}

void UI::getItem()
{
	//Ư�������� �Ǿ��� �׷� ��ǥ�� �����ְ�
	//if()erik�� �Ծ��� �׷� �������� ��ǥ����
	//����
	/*switch (_selectState[i])
	{
	case  SELECT_LEFT_TOP:
		_select[i].x = 120;
		_select[i].y = 402;
		break;
	case  SELECT_LEFT_BOTTOM:
		_select[i].x = 120;
		_select[i].y = 442;
		break;
	case  SELECT_RIGHT_TOP:
		_select[i].x = 160;
		_select[i].y = 402;
		break;
	case  SELECT_RIGHT_BOTTOM:
		_select[i].x = 160;
		_select[i].y = 442;
		break;
	}*/
	if (_erikItem == ITEM_0)
	{
		//��ź���浹�޴� �����۰����� ���̴�
		if (KEYMANAGER->isOnceKeyDown('Z'))//��������
		{
			itemBoom(120, 402, 40, 38,&_erikItem, ITEM_1, 0);	
		}
		if (KEYMANAGER->isOnceKeyDown('X'))//��������
		{
			itemFruit1(120, 402, 40, 38, &_erikItem, ITEM_1, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('C'))//��������
		{
			itemFruit2(120, 402, 40, 38, &_erikItem, ITEM_1, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('V'))//��������
		{
			itemMeat(120, 402, 40, 38, &_erikItem, ITEM_1);
		}
	}
}

void UI::itemBoom(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i)
{
	_pItemBoom[i]->init(x, y, width, height);
	*name = item;
}

void UI::itemFruit1(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i)
{
	_pItemFruit1[i]->init(x, y, width, height);
	*name = item;
}

void UI::itemFruit2(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i)
{
	_pItemFruit2[i]->init(x, y, width, height);
	*name = item;
}

void UI::itemMeat(int x, int y, int width, int height, itemMemory* name, itemMemory item)
{
	_pItemMeat->init(x, y, width, height);
	*name = item;
}

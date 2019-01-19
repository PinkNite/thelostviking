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

	_isCollision = false;
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

	getItem(&_erikItem,120,402,160,442);//�����κ��丮����
	getItem(&_baleogItem, 302, 402, 342, 442);
	getItem(&_olafItem, 482, 402, 522, 442);
	
	itemUpdate();
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
	//�κ��丮 ����
	itemRender(&_erikItem,&_baleogItem,&_olafItem);
	
	char str[128];
	sprintf_s(str, "%d", _iii);
	TextOut(getMemDC(), 500, 300, str, strlen(str));
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

void UI::getItem(itemMemory* name, int x, int y, int x1, int y1)
{
	//Ư�������� �Ǿ��� �׷� ��ǥ�� �����ְ�
	//if()erik�� �Ծ��� �׷� �������� ��ǥ����
	//����
	
	if (*name == ITEM_0)
	{
		//��ź���浹�޴� �����۰����� ���̴�
		if (KEYMANAGER->isOnceKeyDown('Z'))//��������//���߿� ���ľ���
		{
			
			itemBoom(x, y, 40, 38,name, ITEM_1, 0);	
			
		}
		if (KEYMANAGER->isOnceKeyDown('Q'))//��������
		{
			itemBoom(x, y, 40, 38, name, ITEM_1, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('X'))//��������
		{
			itemFruit1(x, y, 40, 38, name, ITEM_1, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('X'))//��������
		{
			itemFruit1(x, y, 40, 38, name, ITEM_1, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('C'))//��������
		{
			itemFruit2(x, y, 40, 38, name, ITEM_1, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('C'))//��������
		{
			itemFruit2(x, y, 40, 38, name, ITEM_1, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('V'))//��������
		{
			itemMeat(x, y, 40, 38, name, ITEM_1);
		}
	}
	if (*name == ITEM_1)
	{
		//��ź���浹�޴� �����۰����� 1�̴�
		if (KEYMANAGER->isOnceKeyDown('B'))//��������
		{
			itemBoom(x1, y, 40, 38, name, ITEM_2, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('B'))//��������
		{
			itemBoom(x1, y, 40, 38, name, ITEM_2, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('N'))//��������
		{
			itemFruit1(x1, y, 40, 38, name, ITEM_2, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('N'))//��������
		{
			itemFruit1(x1, y, 40, 38, name, ITEM_2, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('M'))//��������
		{
			itemFruit2(x1, y, 40, 38, name, ITEM_2, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('M'))//��������
		{
			itemFruit2(x1, y, 40, 38, name, ITEM_2, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('F'))//��������
		{
			itemMeat(x1, y, 40, 38, name, ITEM_2);
		}
	}
	if (*name == ITEM_2)
	{
		//��ź���浹�޴� �����۰����� 2�̴�
		if (KEYMANAGER->isOnceKeyDown('G'))//��������
		{
			itemBoom(x, y1, 40, 38, name, ITEM_3, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('G'))//��������
		{
			itemBoom(x, y1, 40, 38, name, ITEM_3, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('H'))//��������
		{
			itemFruit1(x, y1, 40, 38, name, ITEM_3, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('H'))//��������
		{
			itemFruit1(x, y1, 40, 38, name, ITEM_3, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('J'))//��������
		{
			itemFruit2(x, y1, 40, 38, name, ITEM_3, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('J'))//��������
		{
			itemFruit2(x, y1, 40, 38, name, ITEM_3, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('K'))//��������
		{
			itemMeat(x, y1, 40, 38, name, ITEM_3);
		}
	}
	if (*name == ITEM_3)
	{
		//��ź���浹�޴� �����۰����� 3�̴�
		if (KEYMANAGER->isOnceKeyDown('L'))//��������
		{
			itemBoom(x1, y1, 40, 38, name, ITEM_4, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('L'))//��������
		{
			itemBoom(x1, y1, 40, 38, name, ITEM_4, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('P'))//��������
		{
			itemFruit1(x1, y1, 40, 38, name, ITEM_4, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('P'))//��������
		{
			itemFruit1(x1, y1, 40, 38, name, ITEM_4, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('O'))//��������
		{
			itemFruit2(x1, y1, 40, 38, name, ITEM_4, 0);
		}
		if (KEYMANAGER->isOnceKeyDown('O'))//��������
		{
			itemFruit2(x1, y1, 40, 38, name, ITEM_4, 1);
		}
		if (KEYMANAGER->isOnceKeyDown('I'))//��������
		{
			itemMeat(x1, y1, 40, 38, name, ITEM_4);
		}
	}
	if( *name==ITEM_4)
	{
		*name = ITEM_MAX;
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

void UI::itemRender(itemMemory* name, itemMemory* name1, itemMemory* name2)
{
	for (int i = 0; i < 2; i++)
	{
		if (*name != ITEM_0&& *name1 != ITEM_0&& *name2 != ITEM_0 && _pItemBoom[i]->getIsAllive())
		{
			if (_isCollision)
			{
				
				_pItemBoom[i]->setAlphaCount(15);
			}
			_pItemBoom[i]->render(getMemDC());//�����̴ϱ� �ٸ�
		}
		if (*name != ITEM_0 && *name1 != ITEM_0 && *name2 != ITEM_0 && _pItemFruit1[i]->getIsAllive())
		{
			if (_isCollision)
			{
				_pItemFruit1[i]->setAlphaCount(15);
			}
			_pItemFruit1[i]->render(getMemDC());
		}
		if (*name != ITEM_0 && *name1 != ITEM_0 && *name2 != ITEM_0 && _pItemFruit2[i]->getIsAllive())
		{
			if (_isCollision)
			{
				_pItemFruit2[i]->setAlphaCount(15);
			}
			_pItemFruit2[i]->render(getMemDC());
		}
	}
	if (*name != ITEM_0 && *name1 != ITEM_0 && *name2 != ITEM_0 && _pItemMeat->getIsAllive())
	{
		if (_isCollision)
		{
			_pItemMeat->setAlphaCount(15);
		}
		_pItemMeat->render(getMemDC());
	}
}

void UI::selectCollision(int i, int x, int y)
{
	 _iii= getDistance(_select[i].x, _select[i].y, x, y);
	
	if (getDistance(_select[i].x, _select[i].y, x, y) <= 1)
	{
		
		_isCollision = true;
	}
	else
	{
		_isCollision = false;
	}
}

void UI::itemUpdate()
{
	/*_pItemBoom[2];
	_pItemFruit1[2];
	 _pItemFruit2[2];
	_pItemMeat;*/
	
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 2; i++)
		{
			if (_pItemBoom[i]->getIsAllive() )
			{
				selectCollision(j, _pItemBoom[i]->getX(), _pItemBoom[i]->getY());
			}
		}
		
	}
}

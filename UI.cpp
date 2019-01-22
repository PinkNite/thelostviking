#include "stdafx.h"
#include "UI.h"
#include "itemManager.h"
#include "player.h"
#include "inputMgr.h"

//다시 해야할것 아이템획득 효과추가


UI::UI()
{
}


UI::~UI()
{
}

HRESULT UI::init()
{
	//유아이
	_ui.pImage = new image;
	_ui.pImage = IMAGEMANAGER->findImage("UI");

	//라이프
	for (int i = 0; i < 9; i++)
	{
		_life[i].pImage = new image;
		_life[i].isAllive = true;
		_life[i].pImage = IMAGEMANAGER->findImage("life");
	}
	//삼형제
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
	_olafState = OLAF_OFF;
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
		_selectState[i] = SELECT_LEFT_TOP;//왼쪽위로 초기화함

	}

	//충돌 할때 아이템들
	for (int i = 0; i < 2; i++)
	{
		_pItemMeat[i] = new ITEMMEAT;
		_pItemBoom[i] = new ITEMBOOM;
		_pItemFruit1[i] = new ITEMFRUIT1;
		_pItemFruit2[i] = new ITEMFRUIT2;
	}

	//캐릭마다 아이템 공간의 이넘값
	_erikItem = ITEM_0;
	_baleogItem = ITEM_0;
	_olafItem = ITEM_0;  //현재 갯수 0


	//초기 셀렉트창 좌표 초기화
	
	/////////////////이동부분
	for (int i = 0; i < 3; i++)
	{
		switch (i)//3종류 다다르게 해야함
		{
		case 0:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 120;
				_select[i].y = 402+118;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 120;
				_select[i].y = 442+118;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 160;
				_select[i].y = 402+118;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 160;
				_select[i].y = 442+118;
				break;
			}
			break;
		case 1:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 302;
				_select[i].y = 402+118;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 302;
				_select[i].y = 442+118;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 342;
				_select[i].y = 402+118;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 342;
				_select[i].y = 442+118;
				break;
			}
			break;
		case 2:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 482;
				_select[i].y = 402+118;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 482;
				_select[i].y = 442+118;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 522;
				_select[i].y = 402+118;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 522;
				_select[i].y = 442+118;
				break;
			}
			break;
		}
	}


	_countNum = 0;
	_countLeft = 0;
	_countRight = 0;
	_isCountSelect = false;
	_countSelect = 0;
	_isCollision = 0;
	_trashCan.x = 564;
	_trashCan.y = 402 + 118;

	//_selectStateTemp[0] = SELECT_RIGHT_TOP;
	return S_OK;
}

void UI::release()
{



}

void UI::update()
{
	//플레이어 상태값 갱신되는것
	changePlayer();


	

	//_life[0].isAllive = false;//이럼 사라짐

	//인벤 접근키
	if (KEYMANAGER->isToggleKey(VK_F8))
	{
		selectMove();//얘는 특정 조건에서만 되어야함
		selectCollision();//충돌함수
		moveItem();
		//아이템이동함수
	}
	////////////////캐릭 선택필 수 조건
	
	if (_pPlayer->getCurrentViking() ==PLAYER::VIKINGNAME::ERIC )
	{
		getItem(&_erikItem, 120, 402+118, 160, 442+118);//에릭인벤토리세팅
	}
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::BALEOG)
	{
		getItem(&_baleogItem, 302, 402+118, 342, 442+118);
	}
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::OLAF)
	{
		getItem(&_olafItem, 482, 402+118, 522, 442+118);
	}
	
		
	
	

	//인벤에서 나오면 셀렉트 알파값 원상태복귀
	if (KEYMANAGER->isOnceKeyUp(VK_F8))//렌더 알파값
	{
		_select[0].alphaCount = 255;
		_select[1].alphaCount = 255;
		_select[2].alphaCount = 255;
		for (int i = 0; i < 2; i++)
		{
			_pItemBoom[i]->setAlphaCount(255);
			_pItemFruit1[i]->setAlphaCount(255);
			_pItemFruit2[i]->setAlphaCount(255);
			_pItemMeat[i]->setAlphaCount(255);
		}
	}

	if (isCollisionSelectRemove())
	{
		//system("pause");
		_trashCan.alphaCount += 15;
	}
	
}

void UI::render(HDC hdc)
{
	_ui.pImage->render(hdc, 0, WINSIZEY);
	_trashCan.pImage->alphaRender(hdc, _trashCan.x, _trashCan.y, _trashCan.alphaCount);//이좌표로 아이템이 들어감?

	

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			_select[i].pImage->alphaRender(hdc, _select[i].x, _select[i].y, _select[i].alphaCount);
			break;
		case 1:
			_select[i].pImage->alphaRender(hdc, _select[i].x, _select[i].y, _select[i].alphaCount);
			break;
		case 2:
			_select[i].pImage->alphaRender(hdc, _select[i].x, _select[i].y, _select[i].alphaCount);
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
				_life[i].pImage->render(hdc, 40, 466+118);
			}
			break;
		case 1:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 40 + 20, 466+118);
			}
			break;
		case 2:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 60 + 20, 466+118);
			}
			break;
		case 3:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 220, 466+118);
			}
			break;
		case 4:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 220 + 20, 466+118);
			}
			break;
		case 5:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 240 + 20, 466+118);
			}
			break;
		case 6:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 400, 466+118);
			}
			break;
		case 7:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 400 + 20, 466+118);
			}
			break;
		case 8:
			if (_life[i].isAllive)
			{
				_life[i].pImage->render(hdc, 420 + 20, 466+118);
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
				_erik[i].pImage->render(hdc, 40, 405+118);

			}
			if (_baleogState == BALEOG_ON)
			{

				_baleog[i].pImage->render(hdc, 220, 405+118);

			}
			if (_olafState == OLAF_ON)
			{
				_olaf[i].pImage->render(hdc, 400, 405+118);

			}
			break;
		case 1:
			if (_erikState == ERIK_OFF)
			{
				_erik[i].pImage->render(hdc, 40, 405+118);
			}
			if (_baleogState == BALEOG_OFF)
			{
				_baleog[i].pImage->render(hdc, 220, 405+118);
			}
			if (_olafState == OLAF_OFF)
			{
				_olaf[i].pImage->render(hdc, 400, 405+118);
			}
			break;
		case 2:
			if (_erikState == ERIK_DEAD)
			{
				_erik[i].pImage->render(hdc, 40, 405+118);
			}
			if (_baleogState == BALEOG_DEAD)
			{
				_baleog[i].pImage->render(hdc, 220, 405+118);
			}
			if (_olafState == OLAF_DEAD)
			{
				_olaf[i].pImage->render(hdc, 400, 405+118);
			}
			break;

		}
	}



	//아이템
	//인벤토리 렌더
	itemRender(hdc);

	char str[128];
	sprintf_s(str, "%d", _selectStateTemp[0]);
	TextOut(hdc, 400, 300, str, strlen(str));

}

void UI::selectMove()
{
	
	if (_erikState == ERIK_ON)
	{
		if (!_isCountSelect)
		{
			if (_pInputMG->getLeft() == true&& !_isCountSelect)
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
			if (_pInputMG->getRight() == true && !_isCountSelect)
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
			if (_pInputMG->getTop() == true && !_isCountSelect)
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
			if (_pInputMG->getBottom() == true && !_isCountSelect)
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
			_select[0].alphaCount += 10;//온이면 알파값 변함

		
	}
	
	else if (_baleogState == BALEOG_ON)
	{
		
		if (_pInputMG->getLeft() == true && !_isCountSelect)
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
		if (_pInputMG->getRight() == true && !_isCountSelect)
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
		if (_pInputMG->getTop() == true && !_isCountSelect)
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
		if (_pInputMG->getBottom() == true && !_isCountSelect)
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
		
			_select[1].alphaCount += 10;//온이면 알파값 변함
		
	}

	else if (_olafState == OLAF_ON)
	{
		
		if (_pInputMG->getLeft() == true && !_isCountSelect)
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
		if (_pInputMG->getRight() == true && !_isCountSelect)
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
		if (_pInputMG->getTop() == true && !_isCountSelect)
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
		if (_pInputMG->getBottom() == true && !_isCountSelect)//키가 안눌렸을때
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
		_select[2].alphaCount += 10;
		
	}
	if (_olafState != ERIK_ON)
	{
		_select[0].alphaCount = 255;
	}
	if (_olafState != BALEOG_ON)
	{
		_select[1].alphaCount = 255;
	}
	if (_olafState != OLAF_ON)
	{
		_select[2].alphaCount = 255;
	}
	
	/////////////////이동부분
	for (int i = 0; i < 3; i++)
	{
		switch (i)//3종류 다다르게 해야함
		{
		case 0:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 120;
				_select[i].y = 402 + 118;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 120;
				_select[i].y = 442 + 118;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 160;
				_select[i].y = 402 + 118;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 160;
				_select[i].y = 442 + 118;
				break;
			case SELECT_REMOVE:
				_select[i].x = 564;
				_select[i].y = 402 + 118;
				break;
			

			}
			break;
		case 1:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 302;
				_select[i].y = 402 + 118;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 302;
				_select[i].y = 442 + 118;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 342;
				_select[i].y = 402 + 118;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 342;
				_select[i].y = 442 + 118;
				break;
			case SELECT_REMOVE:
				_select[i].x = 564;
				_select[i].y = 402 + 118;
				break;
			
			}
			break;
		case 2:
			switch (_selectState[i])
			{
			case  SELECT_LEFT_TOP:
				_select[i].x = 482;
				_select[i].y = 402 + 118;
				break;
			case  SELECT_LEFT_BOTTOM:
				_select[i].x = 482;
				_select[i].y = 442 + 118;
				break;
			case  SELECT_RIGHT_TOP:
				_select[i].x = 522;
				_select[i].y = 402 + 118;
				break;
			case  SELECT_RIGHT_BOTTOM:
				_select[i].x = 522;
				_select[i].y = 442 + 118;
				break;
			case SELECT_REMOVE:
				_select[i].x = 564;
				_select[i].y = 402 + 118;
				break;
			
			}
			break;
		}
	}




}

void UI::getItem(itemMemory* name, int x, int y, int x1, int y1)
{
	//특정조건이 되었다 그럼 좌표를 정해주고
	//if()erik이 먹엇다 그럼 에릭에서 좌표세팅
	//에릭

	if (*name == ITEM_0)
	{
		//폭탄과충돌햇다 아이템공간이 영이다
		//_pItemMG.
		if (_pItemMG->getItemFalseBoomA() == 0 && _pItemMG->getItemCollisionBoomA() == 1)
		{
			itemBoom(x, y, 40, 38, name, ITEM_1, 0);
			_selectX=_itemBoom[0].x = x;
			_selectY=_itemBoom[0].y = y;
		}
		if (_pItemMG->getItemFalseBoomB() == 0 && _pItemMG->getItemCollisionBoomB() == 1)
		{
			itemBoom(x, y, 40, 38, name, ITEM_1, 1);
			_selectX = _itemBoom[1].x = x;
			_selectY = _itemBoom[1].y = y;
		}
		if (_pItemMG->getItemFalseFruit1A() == 0 && _pItemMG->getItemCollisionFruit1A() == 1)
		{
			itemFruit1(x, y, 40, 38, name, ITEM_1, 0);
			_selectX = _itemFruit1[0].x = x;
			_selectY= _itemFruit1[0].y = y;
		}
		if (_pItemMG->getItemFalseFruit1B() == 0 && _pItemMG->getItemCollisionFruit1B() == 1)
		{
			itemFruit1(x, y, 40, 38, name, ITEM_1, 1);
			_selectX = _itemFruit1[1].x = x;
			_selectY = _itemFruit1[1].y = y;
		}
		if (_pItemMG->getItemFalseFruit2A() == 0 && _pItemMG->getItemCollisionFruit2A() == 1)
		{
			itemFruit2(x, y, 40, 38, name, ITEM_1, 0);
			_selectX = _itemFruit2[0].x = x;
			_selectY = _itemFruit2[0].y = y;
		}
		if (_pItemMG->getItemFalseFruit2B() == 0 && _pItemMG->getItemCollisionFruit2B() == 1)
		{
			itemFruit2(x, y, 40, 38, name, ITEM_1, 1);
			_selectX = _itemFruit2[1].x = x;
			_selectY = _itemFruit2[1].y = y;
		}
		if (_pItemMG->getItemFalseMeatA() == 0 && _pItemMG->getItemCollisionMeatA() == 1)
		{
			itemMeat(x, y, 40, 38, name, ITEM_1,0);
			_selectX = _itemMeat[0].x = x;
			_selectY = _itemMeat[0].y = y;
		}
		if (_pItemMG->getItemFalseMeatB() == 0 && _pItemMG->getItemCollisionMeatB() == 1)
		{
			itemMeat(x, y, 40, 38, name, ITEM_1, 1);
			_selectX = _itemMeat[1].x = x;
			_selectY = _itemMeat[1].y = y;
		}
	}
	else if (*name == ITEM_1)
	{

		//폭탄과충돌햇다 아이템공간이 1이다
		if (_pItemMG->getItemFalseBoomA() == 0 && _pItemMG->getItemCollisionBoomA() == 1)
		{
			itemBoom(x1, y, 40, 38, name, ITEM_2, 0);
			_selectX = _itemBoom[0].x = x1;
			_selectY = _itemBoom[0].y = y;
		}
		if (_pItemMG->getItemFalseBoomB() == 0 && _pItemMG->getItemCollisionBoomB() == 1)
		{
			itemBoom(x1, y, 40, 38, name, ITEM_2, 1);
			_selectX = _itemBoom[1].x = x1;
			_selectY = _itemBoom[1].y = y;
		}
		if (_pItemMG->getItemFalseFruit1A() == 0 && _pItemMG->getItemCollisionFruit1A() == 1)
		{
			itemFruit1(x1, y, 40, 38, name, ITEM_2, 0);
			_selectX = _itemFruit1[0].x = x1;
			_selectY = _itemFruit1[0].y = y;
		}
		if (_pItemMG->getItemFalseFruit1B() == 0 && _pItemMG->getItemCollisionFruit1B() == 1)
		{
			itemFruit1(x1, y, 40, 38, name, ITEM_2, 1);
			_selectX = _itemFruit1[1].x = x1;
			_selectY = _itemFruit1[1].y = y;
		}
		if (_pItemMG->getItemFalseFruit2A() == 0 && _pItemMG->getItemCollisionFruit2A() == 1)
		{
			itemFruit2(x1, y, 40, 38, name, ITEM_2, 0);
			_selectX = _itemFruit2[0].x = x1;
			_selectY = _itemFruit2[0].y = y;
		}
		if (_pItemMG->getItemFalseFruit2B() == 0 && _pItemMG->getItemCollisionFruit2B() == 1)
		{
			itemFruit2(x1, y, 40, 38, name, ITEM_2, 1);
			_selectX = _itemFruit2[1].x = x1;
			_selectY = _itemFruit2[1].y = y;
		}
		if (_pItemMG->getItemFalseMeatA() == 0 && _pItemMG->getItemCollisionMeatA() == 1)
		{
			itemMeat(x1, y, 40, 38, name, ITEM_2, 0);
			_selectX = _itemMeat[0].x = x1;
			_selectY = _itemMeat[0].y = y;
		}
		if (_pItemMG->getItemFalseMeatB() == 0 && _pItemMG->getItemCollisionMeatB() == 1)
		{
			itemMeat(x1, y, 40, 38, name, ITEM_2, 1);
			_selectX = _itemMeat[1].x = x1;
			_selectY = _itemMeat[1].y = y;
		}
	}
	else if (*name == ITEM_2)
	{
		//폭탄과충돌햇다 아이템공간이 2이다
		if (_pItemMG->getItemFalseBoomA() == 0 && _pItemMG->getItemCollisionBoomA() == 1)
		{
			itemBoom(x, y1, 40, 38, name, ITEM_3, 0);
			_selectX = _itemBoom[0].x = x;
			_selectY = _itemBoom[0].y = y1;
		}
		if (_pItemMG->getItemFalseBoomB() == 0 && _pItemMG->getItemCollisionBoomB() == 1)
		{
			itemBoom(x, y1, 40, 38, name, ITEM_3, 1);
			_selectX = _itemBoom[1].x = x;
			_selectY = _itemBoom[1].y = y1;
		}
		if (_pItemMG->getItemFalseFruit1A() == 0 && _pItemMG->getItemCollisionFruit1A() == 1)
		{
			itemFruit1(x, y1, 40, 38, name, ITEM_3, 0);
			_selectX = _itemFruit1[0].x = x;
			_selectY = _itemFruit1[0].y = y1;
		}
		if (_pItemMG->getItemFalseFruit1B() == 0 && _pItemMG->getItemCollisionFruit1B() == 1)
		{
			itemFruit1(x, y1, 40, 38, name, ITEM_3, 1);
			_selectX = _itemFruit1[1].x = x;
			_selectY = _itemFruit1[1].y = y1;
		}
		if (_pItemMG->getItemFalseFruit2A() == 0 && _pItemMG->getItemCollisionFruit2A() == 1)
		{
			itemFruit2(x, y1, 40, 38, name, ITEM_3, 0);
			_selectX = _itemFruit2[0].x = x;
			_selectY = _itemFruit2[0].y = y1;
		}
		if (_pItemMG->getItemFalseFruit2B() == 0 && _pItemMG->getItemCollisionFruit2B() == 1)
		{
			itemFruit2(x, y1, 40, 38, name, ITEM_3, 1);
			_selectX = _itemFruit2[1].x = x;
			_selectY = _itemFruit2[1].y = y1;
		}
		if (_pItemMG->getItemFalseMeatA() == 0 && _pItemMG->getItemCollisionMeatA() == 1)
		{
			itemMeat(x, y1, 40, 38, name, ITEM_3, 0);
			_selectX = _itemMeat[0].x = x;
			_selectY = _itemMeat[0].y = y1;
		}
		if (_pItemMG->getItemFalseMeatB() == 0 && _pItemMG->getItemCollisionMeatB() == 1)
		{
			itemMeat(x, y1, 40, 38, name, ITEM_3, 1);
			_selectX = _itemMeat[1].x = x;
			_selectY = _itemMeat[1].y = y1;
		}
	}
	else if (*name == ITEM_3)
	{
		//폭탄과충돌햇다 아이템공간이 3이다
		if (_pItemMG->getItemFalseBoomA() == 0 && _pItemMG->getItemCollisionBoomA() == 1)
		{
			itemBoom(x1, y1, 40, 38, name, ITEM_4, 0);
			_selectX = _itemBoom[0].x = x1;
			_selectY = _itemBoom[0].y = y1;
		}
		if (_pItemMG->getItemFalseBoomB() == 0 && _pItemMG->getItemCollisionBoomB() == 1)
		{
			itemBoom(x1, y1, 40, 38, name, ITEM_4, 1);
			_selectX = _itemBoom[1].x = x1;
			_selectY = _itemBoom[1].y = y1;
		}
		if (_pItemMG->getItemFalseFruit1A() == 0 && _pItemMG->getItemCollisionFruit1A() == 1)
		{
			itemFruit1(x1, y1, 40, 38, name, ITEM_4, 0);
			_selectX = _itemFruit1[0].x = x1;
			_selectY = _itemFruit1[0].y = y1;
		}
		if (_pItemMG->getItemFalseFruit1B() == 0 && _pItemMG->getItemCollisionFruit1B() == 1)
		{
			itemFruit1(x1, y1, 40, 38, name, ITEM_4, 1);
			_selectX = _itemFruit1[1].x = x1;
			_selectY = _itemFruit1[1].y = y1;
		}
		if (_pItemMG->getItemFalseFruit2A() == 0 && _pItemMG->getItemCollisionFruit2A() == 1)
		{
			itemFruit2(x1, y1, 40, 38, name, ITEM_4, 0);
			_selectX = _itemFruit2[0].x = x1;
			_selectY = _itemFruit2[0].y = y1;
		}
		if (_pItemMG->getItemFalseFruit2B() == 0 && _pItemMG->getItemCollisionFruit2B() == 1)
		{
			itemFruit2(x1, y1, 40, 38, name, ITEM_4, 1);
			_selectX = _itemFruit2[1].x = x1;
			_selectY = _itemFruit2[1].y = y1;
		}
		if (_pItemMG->getItemFalseMeatA() == 0 && _pItemMG->getItemCollisionMeatA() == 1)
		{
			itemMeat(x1, y1, 40, 38, name, ITEM_4, 0);
			_selectX = _itemMeat[0].x = x1;
			_selectY = _itemMeat[0].y = y1;
		}
		if (_pItemMG->getItemFalseMeatB() == 0 && _pItemMG->getItemCollisionMeatB() == 1)
		{
			itemMeat(x1, y1, 40, 38, name, ITEM_4, 1);
			_selectX = _itemMeat[1].x = x1;
			_selectY = _itemMeat[1].y = y1;
		}
	}
	else if (*name == ITEM_4)
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

void UI::itemMeat(int x, int y, int width, int height, itemMemory* name, itemMemory item, int i)
{
	_pItemMeat[i]->init(x, y, width, height);
	*name = item;

}

void UI::itemRender(HDC hdc)
{
	for (int i = 0; i < 2; i++)
	{
		if (_pItemBoom[i]->getIsAllive())
		{
			_pItemBoom[i]->render(hdc);//고정이니까 겟멤
		}
		if (_pItemFruit1[i]->getIsAllive())
		{

			_pItemFruit1[i]->render(hdc);
		}
		if (_pItemFruit2[i]->getIsAllive())
		{

			_pItemFruit2[i]->render(hdc);
		}
		if (_pItemMeat[i]->getIsAllive())
		{

			_pItemMeat[i]->render(hdc);
		}
	}
	

	
}

void UI::selectCollision()//알파값 변하는 함수와 선택조건
{
	
		for (int i = 0; i < 3; i++)
		{

			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemBoom[0]->getX(), _pItemBoom[0]->getY(), 40, 40)&& _isCountSelect)
			{
				_pItemBoom[0]->setAlphaCountPlus(15);
				//들어왔따 그리고 키값이 있냐.
				_pItemBoom[0]->setMove(true);//사용으로 바꿔줌

				break;
			}
			else if (!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemBoom[0]->getX(), _pItemBoom[0]->getY(), 40, 40) && !_isCountSelect)
			{
				_pItemBoom[0]->setMove(false);
				_pItemBoom[0]->setAlphaCount(255);
				
			}
			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemBoom[1]->getX(), _pItemBoom[1]->getY(), 40, 40) && _isCountSelect)
			{
				_pItemBoom[1]->setAlphaCountPlus(15);
				_pItemBoom[1]->setMove(true);//사용으로 바꿔줌
				
			
				break;
			}
			else if(!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemBoom[1]->getX(), _pItemBoom[1]->getY(), 40, 40) && !_isCountSelect)
			{
			
				_pItemBoom[1]->setMove(false);
				_pItemBoom[1]->setAlphaCount(255);
				
			}
			//////////////////과일

			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit1[0]->getX(), _pItemFruit1[0]->getY(), 40, 40) && _isCountSelect)
			{
				_pItemFruit1[0]->setAlphaCountPlus(15);
				_pItemFruit1[0]->setMove(true);
				
				
				break;
			}
			else if (!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit1[0]->getX(), _pItemFruit1[0]->getY(), 40, 40) && !_isCountSelect)
			{
				_pItemFruit1[0]->setMove(false);
				_pItemFruit1[0]->setAlphaCount(255);
				
			}
			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit1[1]->getX(), _pItemFruit1[1]->getY(), 40, 40) && _isCountSelect)
			{
				_pItemFruit1[1]->setAlphaCountPlus(15);
				_pItemFruit1[1]->setMove(true);
				
				
				break;
			}
			else if (!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit1[1]->getX(), _pItemFruit1[1]->getY(), 40, 40) && !_isCountSelect)
			{
			
				_pItemFruit1[1]->setMove(false);
				_pItemFruit1[1]->setAlphaCount(255);
				
			}
			/////////////////////////////과일

			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit2[0]->getX(), _pItemFruit2[0]->getY(), 40, 40) && _isCountSelect)
			{

				_pItemFruit2[0]->setAlphaCountPlus(15);
				_pItemFruit2[0]->setMove(true);
				
				
				break;

			}
			else if (!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit2[0]->getX(), _pItemFruit2[0]->getY(), 40, 40) && !_isCountSelect)
			{
				_pItemFruit2[0]->setMove(false);
				_pItemFruit2[0]->setAlphaCount(255);
				
			}
			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit2[1]->getX(), _pItemFruit2[1]->getY(), 40, 40) && _isCountSelect)
			{
				_pItemFruit2[1]->setAlphaCountPlus(15);

				_pItemFruit2[1]->setMove(true);
				
				
				break;
			}
			else if (!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit2[1]->getX(), _pItemFruit2[1]->getY(), 40, 40) && !_isCountSelect)
			{
			
				_pItemFruit2[1]->setMove(false);
				_pItemFruit2[1]->setAlphaCount(255);
				
			}
			//고기
			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemMeat[0]->getX(), _pItemMeat[0]->getY(), 40, 40) && _isCountSelect)
			{
				_pItemMeat[0]->setAlphaCountPlus(15);
				_pItemMeat[0]->setMove(true);
				
				
				break;
			}
			else if (!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemMeat[0]->getX(), _pItemMeat[0]->getY(), 40, 40) && !_isCountSelect)
			{
			
				_pItemMeat[0]->setMove(false);
				_pItemMeat[0]->setAlphaCount(255);
				
			}
			if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemMeat[1]->getX(), _pItemMeat[1]->getY(), 40, 40) && _isCountSelect)
			{
				_pItemMeat[1]->setAlphaCountPlus(15);
				_pItemMeat[1]->setMove(true);
				
				
				break;
			}
			else if (!isCollision(_select[i].x, _select[i].y, 40, 40, _pItemMeat[1]->getX(), _pItemMeat[1]->getY(), 40, 40) && !_isCountSelect)
			{
			
				_pItemMeat[1]->setMove(false);
				_pItemMeat[1]->setAlphaCount(255);
				
			}


		}
		
}

void UI::changePlayer()
{
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::ERIC)
	{
		_erikState = ERIK_ON;
		_baleogState = BALEOG_OFF;
		_olafState = OLAF_OFF;

	}
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::BALEOG)
	{
		_erikState = ERIK_OFF;
		_baleogState = BALEOG_ON;
		_olafState = OLAF_OFF;
	}
	if (_pPlayer->getCurrentViking() == PLAYER::VIKINGNAME::OLAF)
	{
		_erikState = ERIK_OFF;
		_baleogState = BALEOG_OFF;
		_olafState = OLAF_ON;
	}
}

void UI::moveItem()
{
	
	//   아이템이랑 셀렉이랑 충돌상태다

			
			
	if (_erikState == ERIK_ON)
	{
		if (isCollisionSelectItem())//그상태에서 피를 누른다
		{

			if (KEYMANAGER->isOnceKeyDown('P'))
			{

		


				switch (_isCountSelect)
				{
				case 0:
					if (_selectState[0] != SELECT_REMOVE)
					{
						_selectStateTemp[0] = _selectState[0];
					}
					_isCountSelect = true;//키가 나누어져서 //트루펄스

					break;
				case 1:
					_isCountSelect = false;
					break;
				}

			}
		}
	}
	else if (_baleogState == BALEOG_ON)
	{
		if (isCollisionSelectItem())//그상태에서 피를 누른다
		{

			if (KEYMANAGER->isOnceKeyDown('P'))
			{

		


				switch (_isCountSelect)
				{
				case 0:
					if (_selectState[1] != SELECT_REMOVE)
					{
						_selectStateTemp[1] = _selectState[1];
					}
					_isCountSelect = true;//키가 나누어져서 //트루펄스

					break;
				case 1:
					_isCountSelect = false;
					break;
				}

			}
		}
	}
	else if (_baleogState == OLAF_ON)
	{
		if (isCollisionSelectItem())//그상태에서 피를 누른다
		{

			if (KEYMANAGER->isOnceKeyDown('P'))
			{

		


				switch (_isCountSelect)
				{
				case 0:
					if (_selectState[2] != SELECT_REMOVE)
					{
						_selectStateTemp[2] = _selectState[2];
					}
					_isCountSelect = true;//키가 나누어져서 //트루펄스

					break;
				case 1:
					_isCountSelect = false;
					break;
				}

			}
		}
	}
				
				
	
	if (_isCountSelect)//충돌상태일때 키가 눌리면 
	{
		
		
		if (_pInputMG->getLeft())//
		{
			_countLeft++;
		}
		else
		{
			_countLeft = 0;
		}
		if (_pInputMG->getRight())
		{
			_countRight++;
		}
		else
		{
			_countRight = 0;
		}


		if (_countLeft == 1 || _countRight == 1)
		{
			_countNum++;
		}

		
		switch (_countNum % 2)//아이템이 이동해서 쓰레기통으로 가냐 안가냐
		{
		case 0:
			if (_erikState == ERIK_ON)
			{
				moveItemTrashCan(0);
			}
			else if (_baleogState == BALEOG_ON)
			{
				moveItemTrashCan(1);
			}
			else if (_baleogState == OLAF_ON)
			{
				moveItemTrashCan(2);
			}
			

			break;
		case 1:
			if (_erikState == ERIK_ON)
			{
				moveTrashCanItem(0);
			}
			else if (_baleogState == BALEOG_ON)
			{
				moveTrashCanItem(1);
			}
			else if (_baleogState == OLAF_ON)
			{
				moveTrashCanItem(2);
			}
			//셀렉 좌표랑 아이템 좌표가 휴지통으로감
			

			break;
		}
	}
	/////////////////
	
	
	
	

	
}

bool UI::isCollisionSelectItem()
{
	for (int i = 0; i < 3; i++)
	{

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemBoom[0]->getX(), _pItemBoom[0]->getY(), 40, 40) )
		{
			
			return true;
		}
		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemBoom[1]->getX(), _pItemBoom[1]->getY(), 40, 40) )
		{
			return true;
		}

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit1[0]->getX(), _pItemFruit1[0]->getY(), 40, 40) )
		{
			return true;
		}

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit1[1]->getX(), _pItemFruit1[1]->getY(), 40, 40) )
		{
			return true;
		}

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit2[0]->getX(), _pItemFruit2[0]->getY(), 40, 40) )
		{
			return true;

		}

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemFruit2[1]->getX(), _pItemFruit2[1]->getY(), 40, 40) )
		{
			return true;
		}

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemMeat[0]->getX(), _pItemMeat[0]->getY(), 40, 40) )
		{
			return true;
		}

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _pItemMeat[1]->getX(), _pItemMeat[1]->getY(), 40, 40) )
		{
			return true;
		}



	}

	

	return false;
}

bool UI::isCollisionSelectRemove()
{
	for (int i = 0; i < 3; i++)
	{

		if (isCollision(_select[i].x, _select[i].y, 40, 40, _trashCan.x, _trashCan.y, 40, 40))
		{
			return true;
		}
		



	}
	return false;
}

void UI::moveItemTrashCan(int j)
{
	for (int i = 0; i < 2; i++)
	{
		

			if (_pItemFruit2[i]->getMove() == true)
			{
				_pItemFruit2[i]->setX(_itemFruit2[i].x);
				_pItemFruit2[i]->setY(_itemFruit2[i].y);

				
					_selectState[j] = _selectStateTemp[j];
				
				break;
			}
			else if (_pItemBoom[i]->getMove() == true)
			{
				_pItemBoom[i]->setX(_itemBoom[i].x);
				_pItemBoom[i]->setY(_itemBoom[i].y);
				
					_selectState[j] = _selectStateTemp[j];
				
				break;
			}
			else if (_pItemFruit1[i]->getMove() == true)
			{
				_pItemFruit1[i]->setX(_itemFruit1[i].x);
				_pItemFruit1[i]->setY(_itemFruit1[i].y);

				
					_selectState[j] = _selectStateTemp[j];
				
				break;
			}
			else if (_pItemMeat[i]->getMove() == true)
			{
				_pItemMeat[i]->setX(_itemMeat[i].x);
				_pItemMeat[i]->setY(_itemMeat[i].y);

				
					_selectState[j] = _selectStateTemp[j];
				
				break;
			}
		
	}
}

void UI::moveTrashCanItem(int j)
{
	for (int i = 0; i < 2; i++)
	{

		if (_pItemFruit2[i]->getMove() == true)
		{
			_selectState[j] = SELECT_REMOVE;

			_pItemFruit2[i]->setX(564);
			_pItemFruit2[i]->setY(402 + 118);


			//좌표 움직임
			break;
		}
		else if (_pItemBoom[i]->getMove() == true)
		{
			_selectState[j] = SELECT_REMOVE;
			_pItemBoom[i]->setX(564);
			_pItemBoom[i]->setY(402 + 118);

			break;
		}
		else if (_pItemFruit1[i]->getMove() == true)
		{
			_selectState[j] = SELECT_REMOVE;
			_pItemFruit1[i]->setX(564);
			_pItemFruit1[i]->setY(402 + 118);


			break;
		}
		else if (_pItemMeat[i]->getMove() == true)
		{
			_selectState[j] = SELECT_REMOVE;
			_pItemMeat[i]->setX(564);
			_pItemMeat[i]->setY(402 + 118);


			break;
		}

	}
}



inline bool UI::isCollision(int x, int y, int width, int height, int x1, int y1, int width1, int height1)
{
	RECT temp, rc, rc1;
	rc.left = x - width / 2;
	rc.right = x + width / 2;
	rc.top = y - height / 2;
	rc.bottom = y + height / 2;
	rc1.left = x1 - width1 / 2;
	rc1.right = x1 + width1 / 2;
	rc1.top = y1 - height1 / 2;
	rc1.bottom = y1 + height1 / 2;
	if (IntersectRect(&temp, &rc, &rc1))
	{

		return true;
	}


	return false;
}

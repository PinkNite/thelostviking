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
	_olafState=OLAF_OFF;
	_baleogState = BALEOG_OFF;
	_erikState = ERIK_ON;

	_trashCan.pImage = new image;
	_trashCan.pImage = IMAGEMANAGER->findImage("trashCan");
	_trashCan.alphaCount = 255;

	_select.pImage = new image;
	_select.pImage = IMAGEMANAGER->findImage("selectYellow");
	_select.alphaCount = 255;
	return S_OK;
}

void UI::release()
{

	

}

void UI::update()
{
	//스테이트 바꿔서 테스트
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
}

void UI::render()
{
	_ui.pImage->render(getMemDC(), 0, 362);
	_trashCan.pImage->render(getMemDC(), 564, 402);//이좌표로 아이템이 들어감?

	_select.pImage->render(getMemDC(), 120, 402);
	_select.pImage->render(getMemDC(), 302, 402);
	_select.pImage->render(getMemDC(), 482, 402);


	
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
}

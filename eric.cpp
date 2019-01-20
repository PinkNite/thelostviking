#include "stdafx.h"
#include "eric.h"

ERIC::ERIC()
{
}

ERIC::~ERIC()
{
}

void ERIC::init(int posX, int posY, int width, int height)
{
	VIKING::init(posX, posY, static_cast<int>(VIKING_WIDTH), static_cast<int>(VIKING_HEIGHT));
	for (int i = 0; i < 11; i++)
	{
		_arTmpFrame[i] = 0;
	}

	initKeyAnimation();
	_jumpingTime = 0.0f;
}

void ERIC::update()
{
	if (VIKING::_behavior == static_cast<int>(VIKING::ACTION::SKILL_TWO))
	{
		_jumpingTime += TIMEMANAGER->getElpasedTime();
	}

	if (_jumpingTime >= 2.0f)
	{

	}

	KEYANIMANAGER->update();
}

void ERIC::release()
{
}

void ERIC::render(HDC hdc)
{
	VIKING::getImage()->aniRender(hdc, VIKING::getPosX() - VIKING::getWidth() / 2, VIKING::getPosY() - VIKING::getHeight() / 2, _pAnimation);


}

void ERIC::skillOne()
{
}

void ERIC::skillTwo()
{
	_jumpingTime = 0.0f;
}

void ERIC::initKeyAnimation()
{
	VIKING::setImage(IMAGEMANAGER->findImage("eric"));
	KEYANIMANAGER->addObject("eric");
	VIKING::_pAnimation;


	//�ִϸ��̼� ����
	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::IDLE)][static_cast<int>(VIKING::IDLE::NORMAL)],
		0, 2, 1, true);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::IDLE)][static_cast<int>(VIKING::IDLE::NORMAL)],
		2, 2, 1, true);

	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::TELEPORT)],
		4, 7, 3, false);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::TELEPORT)],
		11, 7, 3, false);

	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		18, 3, 1, false);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		21, 3, 1, false);

	addRightAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		18, 3, 1, false);
	addLeftAliveAnimation(VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::DAMEGE)],
		21, 3, 1, false);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN),
		24, 8, 10, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::RUN),
		32, 8, 10, true);

	addRightAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE),
		40, 8, 10, true, false, callbackHading);
	addLeftAliveAnimationCoordinate(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_ONE),
		48, 8, 10, true, false, callbackHading);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN),
		56, 11, 10, false, callbackStun);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::STUN),
		67, 11, 10, false, callbackStun);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO),
		78, 4, 10, false, callbackJump);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::SKILL_TWO),
		82, 4, 10, false, callbackJump);

	addRightAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL),
		86, 3, 2, false, 3, callbackBreath);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::SPECIAL),
		89, 3, 2, false, 3, callbackBreath);

	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER),
		92, 4, 1, true);
	addRightAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER_OVER),
		96, 2, 1, true);

	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER),
		92, 4, 1, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::ON_LADDER_OVER),
		96, 2, 1, true);

	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH),
		98, 4, 5, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::PUSH),
		102, 4, 5, true);

	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::FAT),
		112, 3, 5, true);
	addLeftAliveAnimation(VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::FAT),
		115, 3, 5, true);

	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN),
		178, 1, 100, true);
	addLeftAliveAnimation(VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN),
		180, 1, 100, true);


	//KEYANIMANAGER->findAnimation("eric",
	//	addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
	//		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
	//		VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);

	//KEYANIMANAGER->findAnimation("eric",
	//	addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
	//		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
	//		VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER)]))->setClickRender(true);
	//
	//KEYANIMANAGER->findAnimation("eric",
	//	addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
	//		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
	//		VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setClickRender(true);

	//KEYANIMANAGER->findAnimation("eric",
	//	addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
	//		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
	//		VIKING::_vBehavior[static_cast<int>(VIKING::STATE::ACTION)][static_cast<int>(VIKING::ACTION::ON_LADDER_OVER)]))->setClickRender(true);




	//�ִϸ��̼��� ������ �ƴϰ�� �����Ǵ� �͵��
	//Ű�Է����� ���ϴ°��� �����ؾ��Ѵ�.


	setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));


	//�¿� �̵� ������ ���̵���¿����� ���̵�?
	//������ �׼��̾������� ���̵��̳� �׼�����
	//�ص� -> ���� -> ���̵�
	//�޸��� -> �Ѽ� or �ص�
	//���� -> ���̵� or �޸��� or ��������
	//�������� -> ���� -> ���̵�

}

string ERIC::addString(string direction, string live, string action)
{
	string strTmp = "";

	strTmp += direction;
	strTmp += "_";
	strTmp += live;
	strTmp += "_";
	strTmp += action;
	return strTmp;
}

void ERIC::addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(direction)], VIKING::_arLive[static_cast<int>(life)], action);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);

}

void ERIC::addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);
	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)], action);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)], action);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}
void ERIC::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop);
}

void ERIC::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);

}
void ERIC::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);
}
void ERIC::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);
}
void ERIC::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, pCallBack, this);
}
void ERIC::addLeftAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
}
void ERIC::addRightAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame[0], _arTmpFrame[length - 1], fps, isReverse, isLoop, pCallBack, this);
}

void ERIC::addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void ERIC::addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::ALIVE)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void ERIC::addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::LEFT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void ERIC::addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack)
{
	string strTmp = "";
	//Ű��Ʈ�� �����
	strTmp = addString(VIKING::_arDirection[static_cast<int>(VIKING::DIRECTION::RIGHT)],
		VIKING::_arLive[static_cast<int>(VIKING::LIFE::DEATH)],
		VIKING::_vBehavior[static_cast<int>(state)][behevior]);
	//�迭 ������ ���߾ �����
	settingAniArray(startFrame, length);

	KEYANIMANAGER->addArrayCoordinateFrameAnimation("eric", strTmp, "eric", _arTmpFrame, length, fps, isLoop, loopCount, pCallBack, this);
}

void ERIC::settingAniArray(int startFrame, int length)
{
	int frame = startFrame;
	for (int i = 0; i < length; i++)
	{
		_arTmpFrame[i] = frame;
		frame++;
	}
}

void ERIC::setFallOut()
{
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::ACTION, static_cast<int>(VIKING::ACTION::FALLDOWN));
	}
}

void ERIC::setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior)
{
	VIKING::_pAnimation = KEYANIMANAGER->findAnimation("eric",
		addString(VIKING::_arDirection[static_cast<int>(direction)],
			VIKING::_arLive[static_cast<int>(life)],
			VIKING::_vBehavior[static_cast<int>(state)][behavior]));

	VIKING::_pAnimation->start();
	VIKING::_direction = static_cast<int>(direction);
	VIKING::_life = static_cast<int>(life);
	VIKING::_state = static_cast<int>(state);
	VIKING::_behavior = behavior;
}

void ERIC::callbackRun(void *obj)
{
	//�ص�
	//���̵�
	//����
	//�Ѽ�
}

void ERIC::callbackJump(void *obj)
{

	ERIC* pEric = (ERIC*)obj;
	pEric->callbackEricJump();

}

void ERIC::callbackHading(void *obj)
{
	//����
	//�޸���
	//�Ѽ����̵�
}

void ERIC::callbackStun(void * obj)
{
	ERIC* pEric = (ERIC*)obj;
	pEric->callbackEricStun();
}

void ERIC::callbackBreath(void * obj)
{
	//�Ѽ����� ���̵� ����
	ERIC* pEric = (ERIC*)obj;
	pEric->callbackEricBreath();
}

void ERIC::callbackEricRun()
{
}

void ERIC::callbackEricJump()
{
	//�޸���
	//���̵�
	//��������
	//���̵�� �ٲٰ� �޸��� �Ѵ�?



}

void ERIC::callbackEricHading()
{
}

void ERIC::callbackEricStun()
{
	//������ ���̵�
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
}

void ERIC::callbackEricBreath()
{
	//������ ���̵�
	if (VIKING::_direction == static_cast<int>(VIKING::DIRECTION::LEFT))
	{
		setAnimation(VIKING::DIRECTION::LEFT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}
	else {
		setAnimation(VIKING::DIRECTION::RIGHT, VIKING::LIFE::ALIVE, VIKING::STATE::IDLE, static_cast<int>(VIKING::IDLE::NORMAL));
	}

}

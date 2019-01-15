#pragma once
#include "singletonBase.h"
#include "timer.h"

class timeManager : public singletonBase<timeManager>
{
private:
	timer* _timer;	//���� Ÿ�̸Ӹ� �����´�

public:
	timeManager();
	~timeManager();

	HRESULT init();
	void release();
	void update(float lockFPS = 0.0f);
	void render(HDC hdc);

	//cpu����ð��� �޾ƿ��� �Լ�
	inline float getElpasedTime() const { return _timer->getElapsedTime(); }
	
	//�� ����ð��� �޾ƿ��� �Լ�
	inline float getWorldTime() const { return _timer->getWorldTime(); }
};


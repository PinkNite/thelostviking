#pragma once
#include "singletonBase.h"
#include <time.h>

class randomFunction : public singletonBase<randomFunction>
{
public:
	randomFunction()
	{
		srand(GetTickCount());
	}
	~randomFunction()
	{}

	//int�� �������� �̾ƺ���
	inline int getInt(int num) { return rand() % num; }


	//������ ���ؼ� ������ �̾ƺ���
	                      //    5            10
	inline int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum) + fromNum;
	}

	inline float getFloat() { return (float)rand() / (float)RAND_MAX; }

	inline float getFloat(float num) { return ((float)rand() / (float)RAND_MAX) * num; }

	//������ �Ҽ��� �޾ƿ��� �Լ�
	inline float getFromFloatTo(float fromFloat, float toFloat)
	{
		float rnd = (float)rand() / (float)RAND_MAX;

		return (rnd * (toFloat - fromFloat) + fromFloat);
	}
};
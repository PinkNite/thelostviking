#include "stdafx.h"
#include "utils.h"


namespace BRAVO_UTIL
{

	//�Ÿ� ���ϴ� �Լ�
	float getDistance(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		return sqrtf(x * x + y * y);
	}

	float getAngle(float x1, float y1, float x2, float y2)
	{

		float x = x2 - x1;
		float y = y2 - y1;

		float distance = sqrtf(x * x + y * y);

		//��ź��
		//float angle = -atan2f(y, x);

		float angle = acosf(x / distance);

		//����ó�� �ʾ�
		if (y2 > y1)
		{
			angle = 2 * PI - angle;
			if (angle >= PI * 2) angle -= PI * 2;
		}


		return angle;
	}

}
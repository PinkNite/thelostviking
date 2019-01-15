#pragma once

#define PI 3.141592f
#define PI2 2 * PI

//������ �̹��� ȸ���� ���� ������
#define PI8		float(PI / 8.0f)
#define PI16	float(PI / 16.0f)
#define PI32	float(PI / 32.0f)
#define PI64	float(PI / 64.0f)
#define PI128	float(PI / 128.0f)

namespace BRAVO_UTIL
{
	float getDistance(float x1, float y1, float x2, float y2);

	float getAngle(float x1, float y1, float x2, float y2);
}
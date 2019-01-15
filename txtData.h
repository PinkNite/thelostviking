#pragma once
#include "singletonBase.h"
#include <vector>

class txtData : public singletonBase<txtData>
{
public:
	txtData();
	~txtData();

	HRESULT init();
	void release();

	//���� ���� �Լ�

	//txt�� ���������Լ� (���̺� ���� �̸�, ���ڿ� ����)
	void txtSave(const char* saveFileName, vector<string> vStr);
	//    �������տ� �Լ�(���ڿ� ����)
	char* vectorArrayCombine(vector<string> vArray);


	//�ҷ����� ���� �Լ�
	vector<string> txtLoad(const char* loadFileName);
	vector<string> charArraySeparation(char charArray[]);

};


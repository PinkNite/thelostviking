#pragma once
#include "gameNode.h"

//�ݹ��Լ� == �Լ�������
typedef void(*CALLBACK_FUNCTION)(void);

//���θ� �ϸ� �������� �־ �˷��帮�� �Խ��ϴ� ^^*
//<functional> �̶� ���̺귯���� �ִµ���
//���⿡ std::bind, std::move, std::Function ��� �� ������ �־��
//�̰��� ����ϸ� �ϹݸŰ������� �ݹ��Լ����� ����Ҽ� �־��

//����, �縸, ����, ġ��, ����, ��ȣ����, ������, ����, ����
//�� �ָ��� �������� �ؿ����� �ݵ�� '��(do it !sun)'�Ͷ�
//�׸��� ���ٽ��̶��� �ִµ� �̰Ŷ� ��� �ϸ� ���ƾƾ� �����ϴ�
//��Ǫ����Ʈ���� ������ ���ƿ�

//�� �� ������ ����� delegate ���� �־�� ���縦 �ؿ�����
//�ݹ��Լ��� ��������Ʈ�� ���̸� '����'�ϰ� ����� ���ڳ׿�
//���� �ָ��Ǽ��� *^^*

enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;	//��ư�� ���� �̳ѹ�

	const char* _imageName;
	image* _image;
	RECT _rc;

	float _x, _y;		//��ġ ��ǥ
	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	CALLBACK_FUNCTION _callbackFunction;

public:
	button();
	~button();

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);

	void release();
	void update();
	void render();
};


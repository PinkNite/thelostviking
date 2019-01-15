#pragma once
#include "gameNode.h"

class ship : public gameNode
{
protected:
	image* _image;	//���ּ� �̹���
	RECT _rc;		//��Ʈ
	float _x, _y;	//������ǥ
	float _angle;	//����
	float _speed;	//�ӵ�
	float _radius;	//������


public:
	ship();
	~ship();

	//					�� �̹���					������ġ
	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void draw();
	virtual void keyControl();
	virtual void move();

	

	void setAngle(float angle) { _angle = angle; }
	float getAngle() { return _angle; }
};


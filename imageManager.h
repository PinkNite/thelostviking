#pragma once

#include "singletonBase.h"
#include "image.h"
#include <map> //��� ���ص� �Ǵµ� �����غ� �� _��

class imageManager : public singletonBase<imageManager>
{
private:
	//map<string, image*> <-- �긦          mapImageList�� �θ��ڴ�.
	typedef map<string, image*>				mapImageList;
	typedef map<string, image*>::iterator	mapImageIter;

private:
	mapImageList _mImageList;


public:
	imageManager();
	~imageManager();

	HRESULT init();
	void release();

	image* addImage(string strKey, int width, int height);
	image* addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor);

	image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	image* addFrameImage(string strKey, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	//�̹����� ã�� �Լ�
	image* findImage(string strKey);

	//�̱���ȭ �Ǿ��ִ� �̹��� �����ִ� �ԝo
	BOOL deleteImage(string strKey);

	//�α׸�..
	BOOL deleteAll();

	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//���� ���� 1. �����ӷ��� �Լ��� �ϼ����Ѻ��� *^^* 3���ư���

	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY);
};


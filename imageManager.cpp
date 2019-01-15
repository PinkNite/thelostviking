#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init()
{

	return S_OK;
}

void imageManager::release()
{
	deleteAll();
}

image* imageManager::addImage(string strKey, int width, int height)
{
	image* img = findImage(strKey);

	//���࿡ ã������ �� �̹����� ������ �׳� �� �̹����� ��ȯ
	if (img) return img;

	//���� ���!
	img = new image;

	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}
	//map.insert(pair<first�ڷ���, second�ڷ���>(������1, ������2))
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addImage(string strKey, const char * fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//���࿡ ã������ �� �̹����� ������ �׳� �� �̹����� ��ȯ
	if (img) return img;

	//���� ���!
	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}
	//map.insert(pair<first�ڷ���, second�ڷ���>(������1, ������2))
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addImage(string strKey, const char * fileName, float x, float y, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//���࿡ ã������ �� �̹����� ������ �׳� �� �̹����� ��ȯ
	if (img) return img;

	//���� ���!
	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}
	//map.insert(pair<first�ڷ���, second�ڷ���>(������1, ������2))
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(string strKey, const char * fileName, float x, float y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//���࿡ ã������ �� �̹����� ������ �׳� �� �̹����� ��ȯ
	if (img) return img;

	//���� ���!
	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}
	//map.insert(pair<first�ڷ���, second�ڷ���>(������1, ������2))
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(string strKey, const char * fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//���࿡ ã������ �� �̹����� ������ �׳� �� �̹����� ��ȯ
	if (img) return img;

	//���� ���!
	img = new image;

	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);

		return nullptr;
	}
	//map.insert(pair<first�ڷ���, second�ڷ���>(������1, ������2))
	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::findImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		return key->second;
	}

	return nullptr;
}

BOOL imageManager::deleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//������� �̹����� Ű ���� ã������
	if (key != _mImageList.end())
	{
		//map<string, image*>
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}

BOOL imageManager::deleteAll()
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			iter->second->release();
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}

	_mImageList.clear();

	return true;
}

void imageManager::render(string strKey, HDC hdc)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY);
	
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offSetX, int offSetY)
{
	image* img = findImage(strKey);

	if (img) img->loopRender(hdc, drawArea, offSetX, offSetY);
}

#pragma once
#include "singletonBase.h"
#include <map>

class image;
class animation;


class keyAniManager : public singletonBase<keyAniManager>
{
private:
	typedef map<string, animation*>				arrAnimation;
	typedef map<string, animation*>::iterator	iterAnimation;

	typedef map<string, arrAnimation*>					arObjectAnimation;
	typedef map<string, arrAnimation*>::iterator		iterObjectAnimation;

private:

	arObjectAnimation _mmTotalAnimation;

public:
	keyAniManager();
	~keyAniManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//������Ʈ�� �߰����ش� ������Ʈ�� �߰����� ������ �ƹ��͵� ������.
	void addObject(string strObjectKey);
	//������Ʈ�� �����Ѵ�
	void deleteObject(string strObjectKey);
	void deleteAllObject();

	//����Ʈ �ִϸ��̼�
	void addDefaultFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int fps, bool reverse, bool loop);
	void addDefaultFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction);
	void addDefaultFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	//�迭 �ִϸ��̼�
	void addArrayFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop);
	void addArrayFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction);
	void addArrayFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop, void* cbFunction, void* obj);

	//�迭 ���� �ִϸ��̼�
	void addArrayCoordinateFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop, int loopCount);
	void addArrayCoordinateFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop, int loopCount, void* cbFunction);
	void addArrayCoordinateFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int* arr, int arrLen, int fps, bool loop, int loopCount, void* cbFunction, void* obj);



	//���� �ִϸ��̼�
	void addCoordinateFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int start, int end, int fps, bool reverse, bool loop);
	void addCoordinateFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction);
	void addCoordinateFrameAnimation(string strObjectKey, string animationKeyName, const char* imageKeyName, int start, int end, int fps, bool reverse, bool loop, void* cbFunction, void* obj);

	void start(string strObjectKey, string animationKeyName);
	void stop(string strObjectKey, string animationKeyName);
	void pause(string strObjectKey, string animationKeyName);
	void resume(string strObjectKey, string animationKeyName);

	animation* findAnimation(string strObjectKey, string animationKeyName);
};


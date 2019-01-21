#pragma once

#include "viking.h"



class ERIC :public VIKING {

private:
	int _arTmpFrame[11];

	float		_jumpingTime;
	float		_jumpPower;
	float		_jumpSpeed;

	//�ӽú��� ������ ����
	float		_saveY;
	bool		_isUsingSkillTwo;
public:
	ERIC();
	~ERIC();

public:
	void	init(int posX, int posY, int width, int height);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

	virtual void skillOne() override;
	virtual void skillTwo() override;
	virtual	void	setLadderAnimation(int noffset) override;

	
private:
	void	initKeyAnimation();
	string	addString(string direction, string live, string action);
	void	addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop);
	void	addLeftAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop);
	void	addRightAliveAnimation(string action, int startFrame, int length, int fps, bool isLoop);
	void	addLeftDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop);
	void	addRightDeathAnimation(string action, int startFrame, int length, int fps, bool isLoop);

	void	addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop);
	void	addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop);
	void	addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop);
	void	addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop);

	void	addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);
	void	addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);
	void	addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);
	void	addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);

	void	addLeftAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack);
	void	addRightAliveAnimationCoordinate(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack);

	void	addLeftAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);
	void	addRightAliveAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);
	void	addLeftDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);
	void	addRightDeathAnimation(VIKING::STATE state, int behevior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);

	void	settingAniArray(int startFrame, int length);


private:
	void	setFallOut();
	void	setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior);
	virtual void	setMovingAnimation(int direction) override;
	virtual	void	setStopAnimation() override;
	virtual	void	setSkillAnimation() override;

	
	void jump();

	void fallDown();

public:
	//�������� ���·� ���ϴ� �ֵ��� ���⼭ ó���Ѵ�.
	static void	callbackRun(void *obj);	//�޸��� ���� ������ ������ �͵�
	static void	callbackJump(void *obj);	//������ ������ ���� ����
	static void	callbackHading(void *obj);//�ص��� ���ü� �ִ� �͵�
	static void	callbackStun(void* obj);//������
	static void callbackBreath(void* obj);

	void	callbackEricRun();	//�޸��� ���� ������ ������ �͵�
	void	callbackEricJump();	//������ ������ ���� ����
	void	callbackEricHading();//�ص��� ���ü� �ִ� �͵�
	void	callbackEricStun();//������
	void	callbackEricBreath();
	void	callbackEricFallDown();



};
#pragma once

#include "viking.h"

class ARROW;

class BALEOG :public VIKING {

private:
	int _arTmpFrame[11];

	float		_jumpingTime;


	//임시변수 점프에 대한
	bool		_isUsingSkillTwo;
	bool		_isUsingSKillOne;

public:
	BALEOG();
	~BALEOG();

public:
	void	init(int posX, int posY, int width, int height);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

	virtual void skillOne() override;
	virtual void skillTwo() override;
	virtual	void setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight) override;
	virtual void	skillOneEnd() override;

	virtual bool	getUseSkillOne() override;
	virtual bool	getUseSkillTwo() override;



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
	virtual void	pressGravity() override;
	virtual void	falldownAnimation() override;

	virtual void	setSkillOneAni() override;
	virtual void	setSkillTwoAni() override;
	
	virtual void	setPushWallAni(bool isCollisionWall) override;




	void	updateArrow();


public:
	//여러가지 상태로 변하는 애들은 여기서 처리한다.
	static void	callbackSpecialIdle(void *obj);	//달리는 상태 종류후 나오는 것들
	static void callbackDeath(void *obj);


	void	callbackbaleogSpecialIdle();

	void callbackBaleogDeath();

};
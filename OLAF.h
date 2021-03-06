#pragma once
#include "viking.h"

class OLAF : public VIKING
{

private:
	int _arTmpFrame[11];
	const string _name = "olaf";

	OLAFSHIELD	_whereBlock;
	float	_fallingTime;
	bool	_isUsingSkillTwo;

public:
	OLAF();
	~OLAF();

	void	init(int posX, int posY, int width, int height);
	virtual void update()			override;
	virtual void release()			override;
	virtual void render(HDC hdc)	override;

	virtual void skillOne() override;
	virtual void skillTwo() override;
	virtual	void setLadderAnimation(int offset, bool isOverAni, int rcTmpHeight) override;

private: 
	void	initKeyAnimation();
	string	addString(string direction, string live, string action);
	string	addString(string shield, string direction, string live, string action);
	void	addKeyAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop);
	void	addKeyAnimation(VIKING::OLAFSHIELD shield, VIKING::DIRECTION direction, VIKING::LIFE life, string action, int startFrame, int length, int fps, bool isLoop);

	void	addLeftAliveAnimation(OLAF::OLAFSHIELD shield, VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop);
	void	addRightAliveAnimation(OLAF::OLAFSHIELD shield, VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop);

	void	addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop);
	void	addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop);
	void	addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop);
	void	addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop);

	void	addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);
	void	addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);
	void	addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);
	void	addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, void * pCallBack);

	void	addLeftAliveAnimationCoordinate(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack);
	void	addRightAliveAnimationCoordinate(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isReverse, bool isLoop, void * pCallBack);

	void	addLeftAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);
	void	addRightAliveAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);
	void	addLeftDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);
	void	addRightDeathAnimation(VIKING::STATE state, int behavior, int startFrame, int length, int fps, bool isLoop, int loopCount, void * pCallBack);

	void	settingAniArray(int startFrame, int length);

	void	setFallOut();
	void	setAnimation(VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior);
	void	setAnimation(VIKING::OLAFSHIELD shield, VIKING::DIRECTION direction, VIKING::LIFE life, VIKING::STATE state, int behavior);
	
	virtual void	setMovingAnimation(int direction) override;
	virtual void	setStopAnimation() override;
	virtual void	setSkillAnimation() override;
	virtual void	pressGravity() override;
	virtual void	falldownAnimation() override;
	virtual void	setPushWallAni(bool isCollisionWall) override;


public:

	static void callbackSpecialIdle(void * obj);
	static void callbackDeath(void *obj);

	void callbackOlafSpecialIdle();
	void callbackFallDown();

	void callbackOlafDeath();

};


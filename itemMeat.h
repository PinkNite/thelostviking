#pragma once

class ITEMMEAT
{
public:
	ITEMMEAT();
	~ITEMMEAT();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};



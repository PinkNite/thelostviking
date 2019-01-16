#pragma once


class ERIC;
class OBJECT;
class PLAYER
{
private:
	enum class VIKING {
		ERIC = 0,
		BALEOG,
		OLAF,
		MAX
	};

private:
	OBJECT* _pViking[static_cast<const int>(VIKING::MAX)];
	int		_nCurrentViking;

public:
	PLAYER();
	~PLAYER();

public:
	void	init();
	void update()			;
	void release()			;
	void render(HDC hdc)	;


};

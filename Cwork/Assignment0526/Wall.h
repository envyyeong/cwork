#pragma once
#include "int4.h"
#include "ConsoleScreen.h"
#include "Player.h"

class Wall
{
private:
	int4 Pos;
	Player Playerpos;
	bool alive = true;
	bool crash = false;
public:
	Wall()
		: Pos()
	{
	}
	int4 GetPos() const;
	void SetPos(const int4& _Pos);
	bool Getalive() const;
	void Setalive(bool _alive);
	bool Getcrashed() const;
	void Setcrashed(bool _crash);
	bool IsCrashed(const int4& _Pos) const;
};
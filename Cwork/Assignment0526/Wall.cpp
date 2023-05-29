#include "Wall.h"

int4 Wall::GetPos() const
{
	return Pos;
}

void Wall::SetPos(const int4& _Pos)
{
	Pos = _Pos;
}

bool Wall::Getalive() const
{
	return alive;
}

void Wall::Setalive(bool _alive)
{
	alive = _alive;
}

bool Wall::Getcrashed() const
{
	return crash;
}

void Wall::Setcrashed(bool _crash)
{
	crash = _crash;
}

bool Wall::IsCrashed(const int4& _Pos) const
{
	if (GetPos() == _Pos)
	{
		return true;
	}

    return false;
}

#include "Wall.h"

int4 Wall::GetPos() const  // int4형식 pos를 얻어라
{
	return Pos;  // pos값을 리턴해라
}

void Wall::SetPos(const int4& _Pos)  // pos를 세팅해라
{
	Pos = _Pos;  // 인자 pos를 받아 pos를 저장
}

bool Wall::Getalive() const  // alive값을 얻어라
{
	return alive;  // alive값을 리턴해라
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

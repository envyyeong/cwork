#include "Wall.h"

int4 Wall::GetPos() const  // int4���� pos�� ����
{
	return Pos;  // pos���� �����ض�
}

void Wall::SetPos(const int4& _Pos)  // pos�� �����ض�
{
	Pos = _Pos;  // ���� pos�� �޾� pos�� ����
}

bool Wall::Getalive() const  // alive���� ����
{
	return alive;  // alive���� �����ض�
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

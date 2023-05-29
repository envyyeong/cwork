#include "Bullet.h"
#include "Player.h"
#include <conio.h>

int4 Bullet::GetPos() const
{
	return Pos;
}

void Bullet::SetPos(const int4& _Pos)
{
	Pos = _Pos;
}

int4 Bullet::GetDirection()
{
	return Direction;
}

void Bullet::SetDirection(int4 _Direction)
{
	Direction = _Direction;
}

void Bullet::Create(const int4& _Pos)
{
	Pi = _Pos;
}

bool Bullet::Out(const int4& _Pos)
{
	if(0 > _Pos.X)
    {
        return true;
    }

    if (0 > _Pos.Y)
    {
        return true;
    }

    if (int4::XLine <= _Pos.X)
    {
        return true;
    }

    if (int4::YLine <= _Pos.Y)
    {
        return true;
    }

    return false;
}

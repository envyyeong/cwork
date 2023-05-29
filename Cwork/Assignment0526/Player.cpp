#include "Player.h"
#include "ConsoleScreen.h"
#include "int4.h"
#include "Bullet.h"
#include <iostream>
#include <conio.h>

int4 Player::GetPos() const  
{
    return Pos;
}

void Player::AddPos(const int4& _Pos)
{ 
    Pos += _Pos;
}

void Player::SetPos(const int4& _Pos)
{
    Pos = _Pos;
}

void Player::CreateBullet()
{
    PlayerBullet.SetPos(GetPos());
    PlayerBullet.SetDirection(Direction);
}

int4 Player::getBulletPos()
{
    return PlayerBullet.GetPos();
}

void Player::SetBulletPos()
{
    PlayerBullet.SetPos(getBulletPos() + PlayerBullet.GetDirection());
}

int4 Player::GetDirection()
{
    return Direction;
}

void Player::SetDirection(int4 _Direction)
{
    Direction = _Direction;
}

int4 Player::RevDirection()
{
    if (Direction == int4::Up)
    {
        Direction = { 0, 1 };
    }
    else if (Direction == int4::Left)
    {
        Direction = { 1, 0 };
    }
    else if (Direction == int4::Right)
    {
        Direction = { -1,0 };
    }
    else if (Direction == int4::Down)
    {
        Direction = { 0, -1 };
    }
    return Direction;
}


void Player::Input(ConsoleScreen* _Sreen)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = int4::Left;
        Direction = int4::Left;
        break;
    case 'd':
        MovePos = int4::Right;
        Direction = int4::Right;
        break;
    case 'w':
        MovePos = int4::Up;
        Direction = int4::Up;
        break;
    case 's':
        MovePos = int4::Down;
        Direction = int4::Down;
        break;
    case 'c':
        Fire = true;
        CreateBullet();
    default:
        break;
    }

    if (false == _Sreen->IsScreenOut(GetPos() + MovePos))
    {
        AddPos(MovePos);
    }
}
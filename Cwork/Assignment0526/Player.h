#pragma once
#include "int4.h"
#include "Bullet.h"
class ConsoleScreen;

class Player
{
private:
    int4 Pos;
    int4 Direction = { 0, 0 };
    Bullet PlayerBullet;

public:
    int4 GetPos() const;

    void AddPos(const int4& _Pos);

    void SetPos(const int4& _Pos);

    void CreateBullet();

    int4 getBulletPos();

    void SetBulletPos();

    int4 GetDirection();

    void SetDirection(int4 _Direction);

    int4 RevDirection();

    // 생성자에는 붙일수가 없다.
    Player()
        : Pos()
    {
    }

    Player(const Player&) = delete;

    void Input(ConsoleScreen* _Sreen);

    bool Fire = false;
};
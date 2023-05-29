#pragma once
#include "int4.h"

class Bullet
{
private:
	int4 Pos;
	int4 Pi;
	int4 Direction;
public:
	void Create(const int4& _Pos);
	bool Out(const int4& _Pos);
	int4 GetPos() const;
	void SetPos(const int4& _Pos);
	int4 GetDirection();
	void SetDirection(int4 _Direction);
};


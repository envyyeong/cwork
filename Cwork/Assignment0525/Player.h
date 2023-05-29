#pragma once
#include "nt4.h"

class Monstar;
class Player
{
public:
	Player();

	int GetAtt()
	{
		return Att;
	}

	
	void TestPlayer();

	void Fight(Monster* _Monster);

private:
	int Att;
	int Hp;
	int4 Direction;
};
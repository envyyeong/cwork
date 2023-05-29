#pragma once
class Player;

class Monster
{
public:
	Monster();

	void TestMonster();

	void Fight(Player* _Monster);

private:
	int Att;
	int Hp;
};
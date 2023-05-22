#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수
using namespace std;

// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// 오른쪽끝 -------

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
// 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
// 그냥 무식하게 생각해라.

// 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.


// 몬스터와 플레이어가 서로 한대씩 때리면서
// 한명이 죽으면 끝납니다.
// 지금 그걸 그래픽으로 표현할 방법이 없으니까.
// 글자로 표현하겠습니다

void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    int Bicount = 0;
    char Pn[40] = {};
    char Op[40] = {};

    for (int i = 0; i < 40; ++i)
    {
        if (_Name[i] != 0)
        {
            Pn[i] = _Name[i];
        }
        else if (_Name[i] == 0)
        {
            Pn[i] = '-';
        }
    }

    for (int i = 0; i < 40; ++i)
    {
        Op[i] = '45';
    }

    cout << Pn << '\n' << "공격력 : " << _Att << '\n' << "체  력 : " << _Hp << '\n' << Op << endl;
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;
}

int StringCount(char* _Arr)
{

    int Ccount = 0;

    while (true)
    {
        char i = *(_Arr + Ccount);

        if (0 == i)
        {
            break;
        }
        ++Ccount;
    }
    return Ccount;
}

int main()
{
    int PlayerHp = 100;
    int PlayerAtt = 10;
    char PlayerName[40] = "fasd";

    int MonsterHp = 100;
    int MonsterAtt = 10;
    char MonsterName[40] = "Monster";

    while (true)
    {
        system("cls");
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        _getch();

        system("cls");
        Damage(MonsterHp, PlayerAtt);
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        if (PlayerHp <= 0)
        {
            cout << "플레이어가 사망하였습니다." << endl;
            return 0;
        }

        else if (MonsterHp <= 0)
        {
            cout << "몬스터가 사망하였습니다." << endl;
            return 0;
        }

        _getch();
        system("cls");
        Damage(PlayerHp, MonsterAtt);
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);
        if (PlayerHp <= 0)
        {
            cout << "플레이어가 사망하였습니다." << endl;
            return 0;
        }

        else if (MonsterHp <= 0)
        {
            cout << "몬스터가 사망하였습니다." << endl;
            return 0;
        }
        _getch();
    }
}
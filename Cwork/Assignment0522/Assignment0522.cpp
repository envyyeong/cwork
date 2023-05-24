#include <iostream>
#include <conio.h> // Ű�� ���������� ��ٸ��� �Լ�
using namespace std;

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

    cout << Pn << '\n' << "���ݷ� : " << _Att << '\n' << "ü  �� : " << _Hp << '\n' << Op << endl;
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s�� %s�� �����߽��ϴ�.\n", _AttName, _DefName);
    printf_s("%s�� %d�� �������� �Ծ����ϴ�.\n", _DefName, _Att);
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
            cout << "�÷��̾ ����Ͽ����ϴ�." << endl;
            return ;
        }

        else if (MonsterHp <= 0)
        {
            cout << "���Ͱ� ����Ͽ����ϴ�." << endl;
            return ;
        }

        _getch();
        system("cls");
        Damage(PlayerHp, MonsterAtt);
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);
        if (PlayerHp <= 0)
        {
            cout << "�÷��̾ ����Ͽ����ϴ�." << endl;
            return 0;
        }

        else if (MonsterHp <= 0)
        {
            cout << "���Ͱ� ����Ͽ����ϴ�." << endl;
            return 0;
        }
        _getch();
    }
}
#include <iostream>
#include <conio.h>
using namespace std;

// ���� �÷��̾ ȭ�� �ٱ����� ������ ���ϰ� �ض�.

const int XLine = 20;
const int YLine = 10;


// �̳༮�� ĸ��ȭ�� Ŭ������� ���ٴ� �⺻�ڷ���
class int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

    void operator>=(const int4& _Other)
    {
        X >= _Other.X;
        Y >= _Other.Y;
        Z >= _Other.Z;
        W >= _Other.W;
    }
};

// ���� �̴ϼȶ�����
const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };

// Init('*')

// [*][*][0] \n
// [*][*][0] \n

class ConsoleScreen
{
public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh)
    {
        BaseCh = _BaseCh;
        Clear();
    }

    void SetPixel(const int4& _Pos, char _Ch)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

    void Clear()
    {
        system("cls");
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    }


    void Print()
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    }

protected:


private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};

class Player
{
public:
    // ���۷����� �⺻������ 8����Ʈ �����Դϴ�.
    // int4�� �׳� 16����Ʈ�Դϴ�.
    // int4&�� �׳� 8����Ʈ�Դϴ�.
    // int4*�� �׳� 8����Ʈ�Դϴ�.

    // ���� �������� ���ڰ� ���ļ� 8����Ʈ�� �Ѿ��
    // �װ� ����ü�� Ŭ������ ��� �������·� �ѱ�°� ��κ��� ��Ȳ����
    // ������ �̵��̴�.

    int4 GetPos()
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void SetPos(const int4& _Pos)
    {
        // ������ �׳� ���� �ȴ�.
        // => ���� �������.
        // => �����Ϸ��� �⺻�������� �����Ǿ� �ִ�.
        Pos = _Pos;
    }

    void Locpos(const int4& _Pos)
    {
        if (_Pos.Y >= Pos.Y)
            cout << "Out";
    }

    Player()
        : Pos()
    {
    }

    Player(const Player&) = delete;

    void Input()
    {
        char Select = (char)_getch();

        switch (Select)
        {
        case 'a':
            AddPos(Left);
            Locpos(Left);
            break;
        case 'd':
            AddPos(Right);
            Locpos(Right);
            break;
        case 'w':
            AddPos(Up);
            Locpos(Up);
            break;
        case 's':
            AddPos(Down);
            Locpos(Down);
            break;
        default:
            break;
        }
    }

protected:

private:



    int4 Pos;
};

// ���������� ���� �Լ��� ȣ��ǰ� �Լ��� �޸𸮸� �����
// �޸𸮸� �����ϴ� ����ڸ� ���ؾ��ϴ� ��Ģ�� �ִµ�.
// C++������ �װ� ���� �����ټ� �ִ� ������ �� �ִ°ž�.
// �����Ϸ��� ���� ������ �Լ�ȣ��Ծ��� �˾Ƽ� �����ݴϴ�.
void /*__cdecl*/ Function()
{

}

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    // Ŭ�����ǰ�쿡�� 
    MainPlayer.SetPos({ 10, 5 });

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');
        Screen.Print();

        MainPlayer.Input();
    }


}
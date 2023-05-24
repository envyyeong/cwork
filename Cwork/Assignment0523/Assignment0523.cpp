#include <iostream>
using namespace std;

class Test
{
public:
    int A;                
    __int64 B;
    char C;
    char D;
    short E; // 2바이트 정수입니다.
    int F;
};

// 4 8 1 1 2 4

class Player
{
    int HP;
    int ATT;
};

//  [H][H][H][H][][][][] //  [A][A][A][A][][][][]
void TestFunction(Player _Newplayer, int _Test)
{
    
}

int main()
{
    size_t Size = sizeof(Test);
    // [][][][][][][][] [][][][][][][][] [][][][][][][][]
    // 24

    Test NewTest;

    __int64 Address0 = (__int64)&NewTest.A;
    __int64 Address1 = (__int64)&NewTest.B;
    __int64 Address2 = (__int64)&NewTest.C;
    __int64 Address3 = (__int64)&NewTest.D;
    __int64 Address4 = (__int64)&NewTest.E;
    __int64 Address5 = (__int64)&NewTest.F;

    cout << Address0 << '\n' << Address1 << '\n' << Address2 << '\n' << Address3 << '\n' << Address4 << '\n' << Address5 << endl;
    // 4 8 1 1 2 4
    // A  302685878776 [A] [A] [A] [A] [ ] [ ] [ ] [ ] 
    // B  302685878784 [B] [B] [B] [B] [B] [B] [B] [B]
    // C  302685878792 [C] [D] [E] [E] [F] [F] [F] [F]
    // D  302685878793
    // E  302685878794
    // F  302685878796
    
    Player Player1;
    Player Player2;
    TestFunction(Player1, 20);
}
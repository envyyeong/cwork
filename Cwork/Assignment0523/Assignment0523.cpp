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

    Test NewTest;

    __int64 Address0 = (__int64)&NewTest.A;
    __int64 Address1 = (__int64)&NewTest.B;
    __int64 Address2 = (__int64)&NewTest.C;
    __int64 Address3 = (__int64)&NewTest.D;
    __int64 Address4 = (__int64)&NewTest.E;
    __int64 Address5 = (__int64)&NewTest.F;

    cout << Address0 << '\n' << Address1 << '\n' << Address2 << '\n' << Address3 << '\n' << Address4 << '\n' << Address5 << endl;

    // A  814264350552
    // B  186480851216
    // C  666149451576
    // D  540495838169
    // E  944590026682
    // F  844537133580
    
   // Player Player1;
   // Player Player2;
  //  TestFunction(Player1, 20);
}
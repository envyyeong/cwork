#include <iostream>
using namespace std;

int ChCount(const char* const _string, char Ch)
{
    if (nullptr == _string)
    {
        return -1;
    }

    int ChCount = 0, Count = 0;
    while (_string[ChCount] != 0)
    {
        if (Ch == _string[ChCount])
        {
            ++Count;
        }
        ++ChCount;
    }

    return Count;
}

void TrimDelete(char* _string)
{
    if (nullptr == _string)
    {
        return;
    }

    char Ch = ' ';
    int Chcount = 0;
    while(_string[Chcount])
    {
        if (Ch == _string[Chcount])
        {
            _string[Chcount] = '127'-'0';
        }
        ++Chcount;
    }

    return;
}

/*
int DigitsCount(int _Number)
{
    if (0 == _Number)
    {
        return;
    }

    
    while (true)
    {
        _Number;
    }

    return 0;
}
*/

void StrCopy(const char* const _Left, char* _Right)
{
    if (nullptr == _Left)
    {
        return;
    }

    int num = 0;
    while (_Left[num])
    {
        _Right[num] = _Left[num];
        num++;
    }

    return;
}

void NumberToString(int _Number, char* _Right)
{
    char itc = _Number + '48';
    _Right = &itc;
    return;
}


int main()
{
    {
        int Result = ChCount("ab aaac", 'a');
        cout << "1번 Chcount의 답 : " << Result << endl;
    }

    {
        char Arr[256] = "aa b  c d";
        TrimDelete(Arr);
        cout << "2번 TrimDelete의 답 : " << Arr << endl;
    }
    /*
    {
        // 8이 리턴되게 만들어라.
        int Number = 67876578;
        int Result = DigitsCount(Number);

        cout << "3번 DigitsCount의 답 : " << Result << endl;

    }
    */
    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);

        cout << "4번 StrCopy의 답 : " << ArrCopyText << endl;
    }

    {
        char Result[256] = {};

        // Result = "312312";

        NumberToString(3, Result);


        cout << "5번 NumberToString의 답 : " << Result << endl;
    }
}
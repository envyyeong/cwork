#include <iostream>
using namespace std;

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

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    int Ccount = 0;
    while (_Arr[Ccount])
    {
        if (_Arr[Ccount] == _PrevCh)
        {
            _Arr[Ccount] = _NextCh;
        }
        ++Ccount;
    }
}

int main()
{
 {
        {
            char Arr[100] = "31221";

            int Result = StringCount(Arr);
            cout << "1번 StringCount의 답 : " << Result;
        }
    }
 

    {
        char Arr[100] = "aaa bbb ccc";

        ChangeCh(Arr, 'c', 'd');
        cout << "2번 ChangeCh의 답 : " << Arr;
    }
}
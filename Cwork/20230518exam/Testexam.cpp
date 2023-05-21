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

int main()
{
    {
        char Arr[100] = "aaijo";

        int Result = StringCount(Arr);
        cout << Result;
    }
}
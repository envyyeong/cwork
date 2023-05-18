#include <iostream>

int StringCount(char* _Arr)
{
    char* C = 100;
    return 0;
}

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    return;
}

int main()
{
    // 한글 들어가지 않습니다.
    {
        char Arr[100] = "312312321";
        // 3이 나와야 합니다.
        int Result = StringCount(nullptr);

        int a = 0;
    }

    {
        char Arr[100] = "aaa bbb ccc";
        // 3이 나와야 합니다.
        // "aaa bbb ccc"; => "aaa bbb ddd";
        ChangeCh(Arr, 'c', 'd');

        int a = 0;
    }


}
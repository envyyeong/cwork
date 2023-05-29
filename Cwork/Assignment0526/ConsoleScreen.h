#pragma once
#include "int4.h"

class ConsoleScreen
{
private:
    char BaseCh = ' ';
    char ArrScreen[int4::YLine][int4::XLine + 1] = {};  

public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void Clear();

    bool IsScreenOut(const int4& _Pos) const;

    void Print() const;
};
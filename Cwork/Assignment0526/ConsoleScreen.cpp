#include "ConsoleScreen.h"
#include "int4.h"
#include <iostream>

void ConsoleScreen::Init(char _BaseCh)  
{
    BaseCh = _BaseCh;
    Clear();
}

void ConsoleScreen::SetPixel(const int4& _Pos, char _Ch)
{
    ArrScreen[_Pos.Y][_Pos.X] = _Ch;
}

void ConsoleScreen::Clear()
{
    system("cls");
    for (size_t y = 0; y < int4::YLine; y++)
    {
        for (size_t x = 0; x < int4::XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][int4::XLine] = 0;
    }
}

bool ConsoleScreen::IsScreenOut(const int4& _Pos) const
{
    if (0 > _Pos.X)
    {
        return true;
    }

    if (0 > _Pos.Y)
    {
        return true;
    }

    if (int4::XLine <= _Pos.X)
    {
        return true;
    }

    if (int4::YLine <= _Pos.Y)
    {
        return true;
    }

    return false;
}

void ConsoleScreen::Print() const
{
    for (size_t y = 0; y < int4::YLine; y++)
    {
        printf_s(ArrScreen[y]);
        printf_s("\n");
    }
}
#include "Console.h"


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
    for (size_t y = 0; y < YLine; y++)
    {
        for (size_t x = 0; x < XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][XLine] = 0;
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

    if (XLine <= _Pos.X)
    {
        return true;
    }

    if (YLine <= _Pos.Y)
    {
        return true;
    }

    return false;
}

bool ConsoleScreen::IsBarrier(const int4& _Pos) const
{
    for (size_t i = 0; i < 10; ++i)
    {
        if (this->Barriers[i] == _Pos)
        {
            return true;
        }
    }
     return false;

    
        
}

void ConsoleScreen::Print() const
{
    for (size_t y = 0; y < YLine; y++)
    {
        printf_s(ArrScreen[y]);
        printf_s("\n");
    }
}

void ConsoleScreen::SetBarrier(int4* Barriers)
{
    for (size_t i = 0; i < 10; ++i)
    {
        this->Barriers[i] = Barriers[i];
        SetPixel(Barriers[i], '0');
    }
}

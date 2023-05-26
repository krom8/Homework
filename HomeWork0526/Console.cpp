#include "Console.h"
#include "InitialClass.h"
#include "Player.h"


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
        if (Barriers[i] == _Pos)
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

void ConsoleScreen::SetBarrier()
{
    for (size_t i = 0; i < 10; ++i)
    {
        SetPixel(Barriers[i], '0');
    }
}

void ConsoleScreen::SetGun(Player& _Player)
{
    if (_Player.GetShoot() == true)
    {
        int4 GS = _Player.GetGunPos();
        if (GS.Y >= 0)
        {
            Destroy(_Player);
            SetPixel(GS, '^');
            GS.Y = GS.Y - 1;
            _Player.SetGunPos(GS);

        }
        if (GS.Y < 0)
        {
            GS = { -1, -1 };
            _Player.SetGunPos(GS);
            _Player.SetShoot(false);
        }

    }
}

void ConsoleScreen::Destroy(Player& _Player)
{
    int4 GS = _Player.GetGunPos();
    for (size_t i = 0; i < 10; ++i)
    {
        if (Barriers[i] == GS)
        {
            Barriers[i] = int4({ -1,-1 });
           break;
        }
    }
    
}
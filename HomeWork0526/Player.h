#pragma once

#include "InitialClass.h"
#include "Console.h"

class Player
{
public:
    void Input(ConsoleScreen* _Screen);

    int4 GetPos() const
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }



private:
    int4 Pos;
};
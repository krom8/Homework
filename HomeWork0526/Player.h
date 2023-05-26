#pragma once

#include "InitialClass.h"
#include "Console.h"

class ConsoleScreen;
class Player
{
public:
    void Input(ConsoleScreen* _Screen);
    void Move(ConsoleScreen* _Screen, int4 MovePos);
    void Shoot(ConsoleScreen* _Screen);


    int4 GetPos() const
    {
        return Pos;
    }

    bool GetShoot() const
    {
        return IsShoot;
    }

    int4 GetGunPos() const
    {
        if (IsShoot == true)
        {
            return GunPos;
        }
        else
        {
            int4 Return = { -1, -1 };
            return Return;
        }
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
    }


    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    void SetGunPos(const int4& _Pos)
    {
        GunPos = _Pos;
    }

    void SetShoot(bool Shoot)
    {
        IsShoot = Shoot;
    }


    


private:
    int4 Pos;
    int4 GunPos;
    bool IsShoot = false;
    const int4 Left = { -1, 0 };
    const int4 Right = { 1, 0 };
    const int4 Up = { 0, -1 };
    const int4 Down = { 0, 1 };
    

};
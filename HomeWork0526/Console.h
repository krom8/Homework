#pragma once

#include "InitialClass.h"
#include <iostream>

class Player;
class ConsoleScreen
{
public:

    void Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void SetBarrier();

    void SetGun(Player& _Player);

    void Clear();

    bool IsScreenOut(const int4& _Pos) const;
    
    bool IsBarrier(const int4& _Pos) const;

    void Print() const;

    void Destroy(Player& _Player);
private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
    int4 Barriers[10] = { {0,1}, {0,5}, {1,4}, {2,5}, {3,3}, {3,7}, {4,1}, {4,8}, {5,5}, {7,9} };
};


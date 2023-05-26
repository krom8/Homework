#pragma once
#include "InitialClass.h"
#include <iostream>
class ConsoleScreen
{
public:

    void Init(char _BaseCh);

    void SetPixel(const int4& _Pos, char _Ch);

    void SetBarrier(int4* Barriers);

    void Clear();

    bool IsScreenOut(const int4& _Pos) const;
    
    bool IsBarrier(const int4& _Pos) const;

    void Print() const;


private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
    int4 Barriers[10] = {};
};


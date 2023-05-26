#pragma once



class int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 0;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

    int4 operator+(const int4& _Other) const
    {
        int4 Return;
        Return.X = X + _Other.X;
        Return.Y = Y + _Other.Y;
        Return.Z = Z + _Other.Z;
        Return.W = W + _Other.W;
        return Return;
    }

    int* operator*()
    {
        return &X;
    }

    bool operator==(const int4& _Other) const
    {
        if (X == _Other.X && Y == _Other.Y && Z == _Other.Z && W == _Other.W)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

const int XLine = 20;
const int YLine = 10;


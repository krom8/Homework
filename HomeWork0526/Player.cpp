#include "Player.h"
#include "Console.h"
#include "InitialClass.h"
#include <conio.h>

void Player::Input(ConsoleScreen* _Screen)
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = Left;
        break;

    case 'd':
        MovePos = Right;
        break;

    case 'w':
        MovePos = Up;
        break;

    case 's':
        MovePos = Down;
        break;

    default:
        break;
    }

    if (false == _Screen->IsScreenOut(this->GetPos() + MovePos) && false == _Screen->IsBarrier(this->GetPos() + MovePos))
    {
        this->AddPos(MovePos);
    }
}

    
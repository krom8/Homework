#include "Player.h"
#include <conio.h>


void Player::Input(ConsoleScreen* _Screen)
{
    char Select = (char)_getch();
    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = Left;
        Move(_Screen, MovePos);
        break;

    case 'd':
        MovePos = Right;
        Move(_Screen, MovePos);
        break;

    case 'w':
        MovePos = Up;
        Move(_Screen, MovePos);
        break;

    case 's':
        MovePos = Down;
        Move(_Screen, MovePos);
        break;

    case 'p':
        Shoot(_Screen);
        break;
    default:
        break;
    }


}

void Player::Move(ConsoleScreen* _Screen, int4 MovePos)
{
    if (false == _Screen->IsScreenOut(GetPos() + MovePos) && false == _Screen->IsBarrier(GetPos() + MovePos))
    {
        AddPos(MovePos);
    }
}

void Player::Shoot(ConsoleScreen* _Screen)
{
    IsShoot = true;
    GunPos = GetPos();
    GunPos.Y -= 1;
    SetGunPos(GunPos);
}
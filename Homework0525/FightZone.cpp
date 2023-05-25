#include "FightZone.h"
#include "Monster.h"
#include "Player.h"
#include <iostream>
#include <conio.h>


void FightZone::Fight(Player& NewPlayer, Monster& NewMonster)
{
	while (true)
	{
		system("cls");

		// �ѹ��� �Լ��� ������̰�
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		_getch();

		system("cls");
		NewMonster.Damage(NewPlayer.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewMonster.DamagePrint(NewPlayer.GetName(), NewPlayer.GetAtt());
		_getch();

		if (true == NewMonster.IsDeath())
		{
			printf_s("%s�� �׾����ϴ�.\n", NewMonster.GetName());
			printf_s("%s�� �¸��Դϴ�.\n", NewPlayer.GetName());
			_getch();
			return;
		}

		system("cls");
		NewPlayer.Damage(NewMonster.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewMonster.DamagePrint(NewPlayer.GetName(), NewPlayer.GetAtt());
		NewPlayer.DamagePrint(NewMonster.GetName(), NewMonster.GetAtt());
		_getch();

		if (true == NewPlayer.IsDeath())
		{
			printf_s("%s�� �׾����ϴ�.\n", NewPlayer.GetName());
			printf_s("%s�� �¸��Դϴ�.\n", NewMonster.GetName());
			_getch();
			return;
		}
	}
}

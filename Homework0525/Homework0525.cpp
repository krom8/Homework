// HomeWork0524.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include "Monster.h"
#include "Player.h"
#include "FightZone.h"





// 문법은 왜 발전했다? 인간이 코드를, 덜치기 위해서 발전했습니다.
int main()
{
	// 객체지향이라고 한다.
	Player NewPlayer;
	Monster NewMonster;
	FightZone FZone;
	FZone.Fight(NewPlayer, NewMonster);

}


// class에 관해서만 다룬거 같은데 함수나 변수같은 경우를 분리해서 쓰고 싶으면 어떡해야하냐
// 그냥 class 만들듯이 만들면 어디에서 온건지 구분이 안가는데 그래서 namespace가 필요한거이고 이게 어느정도 스탠다드가 맞나????
#include "Monster.h"
#include "StringCount.h"
#include "iostream" 

const int LineCount = 40;


void Monster::StatusRender()
{
	int Count = 0;

	Count = StringCount(Name);

	// 40개로 맞춰오세요.

	// 줄바꿈이 안되고 있습니다.
	printf_s("%s", Name);

	for (size_t i = 0; i < LineCount - Count; i++)
	{
		printf_s("-");
	}
	printf_s("\n");

	printf_s("공격력 : %d\n", Att);
	printf_s("체  력 : %d\n", Hp);
	for (size_t i = 0; i < LineCount; i++)
	{
		printf_s("-");
	}

	printf_s("\n");

}

// c++에서는 함수에도 그걸 만든 프로그래머의 의도를 부여할수가 있습니다.



void Monster::DamagePrint(const char* const _AttName, int _Att)
{
	printf_s("%s가 %s를 공격했습니다.\n", _AttName, Name);
	printf_s("%s는 %d의 데미지를 입었습니다.\n", Name, _Att);
}

void Monster::Damage(int _Att)
{
	Hp -= _Att;
}

const char* Monster::GetName()
{
	return Name;
}

int Monster::GetAtt()
{
	return Att;
}

bool Monster::IsDeath()
{
	return Hp <= 0;
}

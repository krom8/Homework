#include "Monster.h"
#include "StringCount.h"
#include "iostream" 

const int LineCount = 40;


void Monster::StatusRender()
{
	int Count = 0;

	Count = StringCount(Name);

	// 40���� ���������.

	// �ٹٲ��� �ȵǰ� �ֽ��ϴ�.
	printf_s("%s", Name);

	for (size_t i = 0; i < LineCount - Count; i++)
	{
		printf_s("-");
	}
	printf_s("\n");

	printf_s("���ݷ� : %d\n", Att);
	printf_s("ü  �� : %d\n", Hp);
	for (size_t i = 0; i < LineCount; i++)
	{
		printf_s("-");
	}

	printf_s("\n");

}

// c++������ �Լ����� �װ� ���� ���α׷����� �ǵ��� �ο��Ҽ��� �ֽ��ϴ�.



void Monster::DamagePrint(const char* const _AttName, int _Att)
{
	printf_s("%s�� %s�� �����߽��ϴ�.\n", _AttName, Name);
	printf_s("%s�� %d�� �������� �Ծ����ϴ�.\n", Name, _Att);
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

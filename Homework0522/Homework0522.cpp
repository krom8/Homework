// HomeWork0520.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h> // 키를 누를때까지 기다리는 함수

int PlayerHp = 200;
int PlayerAtt = 10;
char PlayerName[40] = "fasdhjkfasdhjkfasdhjfklasdhjkfasdhjfk";

int MonsterHp = 100;
int MonsterAtt = 15;
char MonsterName[40] = "Monster";

// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// fasdhjkfasdhjfkasd--------
// Monster-------------------
// 위와같이 UI의 끝부분이 맞게 만들어라.

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
// 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
// 그냥 무식하게 생각해라.

// 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.

// 몬스터와 플레이어가 서로 한대씩 때리면서
// 한명이 죽으면 끝납니다.
// 지금 그걸 그래픽으로 표현할 방법이 없으니까.
// 글자로 표현하겠습니다.


int StringCount(const char* _Arr)
{
    int count = 0;
    if (_Arr == nullptr)
    {
        return 0;
    }

    char temp = _Arr[count];
    while (temp != 0)
    {
        ++count;
        temp = _Arr[count];
    }
    return count;

}

void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 40개로 맞춰오세요.

    // 줄바꿈이 안되고 있습니다.
    int name_count = StringCount(_Name);
    char print_name[40] = {};
    for (size_t i=0; i<39; ++i)

        if (i < name_count)
        {
            print_name[i] = _Name[i];
        }
        else
        {
            print_name[i] = '-';
        }


    printf_s("%s-\n", print_name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);
    printf_s("----------------------------------------\n");
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    system("cls");
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;
}

// 내일꼭 break continue

int main()
{
    // 절차지향 코딩이라고 부르고 
    // 함수와 변수를 개념에 묶지 않고 데이터로만 보고 처리하는 방식입니다.

    // 컴퓨터 입장에서 본다면
    // 플레이어의 hp => 인간적인 머릿속에 그린 개념이다.
    // 컴퓨터적인 측면에서 void Damage(int& _Hp, int _Att)
    // 플레이어가 몬스터를 때린다.
    // => 컴퓨터가 보면 그냥 int나 2개 내놔.

    // 콘솔창을 모조리 지우는 함수
    system("cls");

    // 한번에 함수로 만든것이고
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
    StatusRender(MonsterName, MonsterAtt, MonsterHp);

    while (true)
    {


        _getch();

        // 아무키나 입력할때까지 기다리는 함수

        Damage(MonsterHp, PlayerAtt);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        if (MonsterHp <= 0)
        {
            printf_s("플레이어가 승리했습니다. 종료하려면 아무키나 누르세요");
            _getch();
            return -1;
        }

        // MonsterHp -= PlayerAtt;

        _getch();

        Damage(PlayerHp, MonsterAtt);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);

        if (PlayerHp <= 0)
        {
            printf_s("몬스터가 승리했습니다. 종료하려면 아무키나 누르세요");
            _getch();
            return -1;
        }


        //if (조건 만족시)
        //{
        //    return;
        //}


    }
}

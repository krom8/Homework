// HomeWork0523.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Test
{
public:
    // 100
    int A;
    // ?????
    __int64 B;
    char C;
    char D;
    short E; // 2바이트 정수입니다.
    int F;

    void PrintFunc()
    {
        __int64 y = (_int64)this; //196109925144
        __int64 z = (_int64)&A; //196109925144
        __int64 x = (_int64)&B; //196109925152
        int a = 0;
    }
};

// 1 2 4 8

class Player
{
    int HP;
    int ATT;

};

//  [H][H][H][H][][][][] //  [A][A][A][A][][][][]
void TestFunction(Test test, Player _Newplayer, int _Test, int _Test2)
{
    size_t st = sizeof(test);
    __int64 Address = (__int64)&test; //910580514208
    __int64 Address0 = (__int64)&_Newplayer; // 910580513576            632차이
    __int64 Address1 = (__int64)&_Test; // 910580513584
    __int64 Address2 = (__int64)&_Test2; // 910580513592
    int a = 1;
}

int main()
{
    size_t Size = sizeof(Test);
    size_t size_int = sizeof(int);
    // [A][A][A][A][A][A][A][A] [B][B][B][B][B][B][B][B] [C][D][E][E][F][F][F][F]

    Test NewTest;

 
    __int64 Address0 = (__int64)&NewTest; // 857822328216
    __int64 Address1 = (__int64)&NewTest.A; // 857822328216
    __int64 Address2 = (__int64)&NewTest.B; // 857822328224
    __int64 Address3 = (__int64)&NewTest.C; // 857822328232
    __int64 Address4 = (__int64)&NewTest.D; // 857822328233
    __int64 Address5 = (__int64)&NewTest.E; // 857822328234
    __int64 Address6 = (__int64)&NewTest.F; // 857822328236


    NewTest.PrintFunc();

    int a = 0;

    Player NewPlayer = Player();
    TestFunction(NewTest, NewPlayer, 20, 30);
}


//질문사항 632차이의 정체 -> 신경쓰는건 범위를 넘었나..?
// 생성자에서 
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
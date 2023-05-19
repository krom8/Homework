// HomeWork0519.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//int ChCount = 0;
//while (_string[ChCount])
//{
//    ++ChCount;
//}


int ChCount(const char* const _string, char Ch)
{
    if (_string == nullptr)
    {
        return -1;
    }
        
    int ChCount = 0;
    int Result = 0;
    while (_string[ChCount])
    {
        if (_string[ChCount] == Ch)
        {
            Result += 1;
        }
        ++ChCount;
    }


    // for문을 돌리는건 당연한거야.

    // Ch와 같은 문자가 몇개들어있는지 세어서 리턴해주는 함수
    return Result;
}

void TrimDelete(char* _string)
{
    if (_string == nullptr)
    {
        return;
    }
    int count = 0;

    while (_string[count] != 0)
    {
        while (_string[count] == ' ')
        {
            int space_count = count;
            while (_string[space_count] != 0)
            {
                _string[space_count] = _string[space_count + 1];
                ++space_count;

            }

        }
        ++count;
    }
    

    return;
}


int DigitsCount(int _Number)
{
    int divide_number = 10;
    int count = 1;
    while (_Number > 10)
    {
        _Number /= divide_number;
        count += 1;
    }
    return count;
}

void StrCopy(const char* const _Left, char* _Right)
{
    if (_Left == nullptr)
    {
        return;
    }
    if (_Right == nullptr)
    {
        return;
    }
    for (size_t i = 0; _Left[i] != 0; ++i)
    {
        _Right[i] = _Left[i];
    }
    return;
}

// 가장 어려운 숙제
void NumberToString(int _Number, char* _Right)
{
    if (_Right == nullptr)
    {
        return;
    }
    int NumLen = DigitsCount(_Number);
    int MaxNum = 1;
    bool done = false;
    int count = 0;
    for (size_t i = 0; i < NumLen; ++i)
    {
        MaxNum *= 10;
    }
    while (MaxNum > 9)
    {
        MaxNum /= 10;
        if (_Number > MaxNum)
        { 
            int Digit = _Number / MaxNum;
            _Number %= MaxNum;
            _Right[count] = Digit + 48;


        }
        else
        {
            _Right[count] = '0';
        }
        ++count;

        

    }
    _Right[count + 1] = 0;

    return;
}


int main()
{
    // 4가 리턴되어야 합니다.
    // 문자열의 마지막에 들어가는 0은 글자로 치지 않습니다.
    {
        int Result = ChCount("ab aaa ccc ddd eee", 'e');
        int a = 0;
    }

    {
        char Arr[256] = "aa  b  c dd ee";

        TrimDelete(Arr);

        // Arr "aabcddee"
        int a = 0;
    }

    {
        // 8이 리턴되게 만들어라.
        int Result = DigitsCount(87687678);

        int a = 0;
    }

    {
        char ArrCopyText[256] = {};

        StrCopy("aaaa bbb ccc", ArrCopyText);

        int a = 0;
    }

    {
        char Result[256] = {};

        // Result = "312312";

        NumberToString(312, Result);

        char Ch = '0';

        int Value = 7;

        char ChConvert = Value + 48;

        int a = 0;
    }

    std::cout << "Hello World!\n";
}

//  ArrCopyText 어려웠던점 _Right = _Left;이 불가능한 이유
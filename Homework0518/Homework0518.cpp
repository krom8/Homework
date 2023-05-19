// HomeWork0518.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int NullCheck(char* _Arr)
{
    int NullValue = 0;
    if (sizeof(_Arr) == 0)
    {
        NullValue = 1;
    }
    return NullValue;
}

int StringCount(char* _Arr)
{
    int nc = NullCheck(_Arr);
    int count = 0;
    bool done = false;
    if (nc == 1)
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

void ChangeCh(char* _Arr, char _PrevCh, char _NextCh)
{
    int nc = NullCheck(_Arr);
    if (nc == 1)
    {
        return;
    }
    else
    {
        int len = StringCount(_Arr);
        for (int i = 0; i < len; ++i)
        {
            char temp = _Arr[i];
            if (temp == _PrevCh)
            {
                _Arr[i] = _NextCh;
            }
        }

    }

    return;
}

int main()
{
    // 한글 들어가지 않습니다.
    {
        char Arr[100] = "312312321";
        // 3이 나와야 합니다.
        int Result = StringCount(Arr);
        int temp = Result;
    }

    {
        char Arr[100] = "aaa bbb ccc";
        // 3이 나와야 합니다.
        // "aaa bbb ccc"; => "aaa bbb ddd";
        ChangeCh(Arr, 'c', 'd');
        Arr;
        int a = 0;
    }


}

// 어려웠던 점: [] index가 완되어서 이걸 처리하는 방법, char temp를 한다음 그걸 index 처음만 집어넣는게 좋은 방법인가"?
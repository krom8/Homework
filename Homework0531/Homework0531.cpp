#include <iostream>
#include <vector>


// 숙제0 => HVector의 leck을 없애와라
//         대입연산자를 사용하면 터지는걸 정상으로 돌려놔라.
//         이미 보여준 코드 이미 array에서 해결은 한거에요.

// 숙제1 => 템플릿으로 바꾸세요.

template<typename DataType>

class HVector
{
public:

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void operator=(HVector& _Other)
	{
		reserve(_Other.capacity());
		Copy(_Other);
	}

	size_t size()
	{
		return sizeValue;
	}



	size_t capacity()
	{
		return capacityValue;
	}

	void push_back(const DataType& _Data)
	{

		if (sizeValue + 1 > capacityValue)
		{
			reserve((int)((capacityValue * 1.5) + 1));
		}

		ArrPtr[sizeValue] = _Data;
		sizeValue += 1;
	}

	void reserve(size_t _capacity)
	{
		DataType* PrevPtr = ArrPtr;

		// 1회의 new가 일어났다면 1회의 delete가 어딘가에 존재해야 한다.
		ArrPtr = new DataType[_capacity];

		// 최초에 한번은 내가 nullptr 이었을것이다.
		if (nullptr != PrevPtr)
		{
			for (size_t i = 0; i < sizeValue; i++)
			{
				ArrPtr[i] = PrevPtr[i];
			}
		}
		delete PrevPtr;
		PrevPtr = nullptr;
		capacityValue = _capacity;
	}

	void Copy(HVector& _Other)
	{

		size_t SmallSize = size() <= _Other.size() ? size() : _Other.size();

		for (size_t i = 0; i < SmallSize; i++)
		{
			ArrPtr[i] = _Other[i];
		}
	}

	~HVector()
	{
		if (nullptr != ArrPtr)
		{
			delete ArrPtr;
			ArrPtr = nullptr;
		}
	}

private:
	int sizeValue = 0;
	int capacityValue = 0;
	DataType* ArrPtr = nullptr;
};




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	{
		HVector<int> Arr;
		for (int i = 0; i < 10; i++)
		{
			Arr.push_back(i);
		}

		for (int i = 0; i < Arr.size(); i++)
		{
			std::cout << Arr[i] << std::endl;
		}


		HVector<int> Arr0;
		Arr0 = Arr;

		for (int i = 0; i < Arr0.size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}

	}



}

// 현재는 문제가 명확한 상황. 그런데 그렇지 않다는 상황을 가정하고 스택상에서 문제는 destructor에서 생겼는데 실질적인
// 문제는 operator=에 있는 상황. 이럴때 어떻게 대처를 해줘야하는지 모르겠다.
// 첨에는 포인터 처리를 어떻게 해야하나
// leak을 해결후 왜 에러가 났는지 잘 모르겠다. Default operator=가 어떻게 역할을 하는가?


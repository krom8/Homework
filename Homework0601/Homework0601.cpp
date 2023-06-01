// List.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <vector>
#include <assert.h>

// 1. Push_front를 만들어보세요.
// 2. leack 잡으세요

// 벡터에는 왜 push_front

using DataType = int;

class HList
{
private:
	class ListNode
	{
	public:
		DataType Value;
		ListNode* Prev = nullptr;
		ListNode* Next = nullptr;
	};


public:
	class iterator
	{
		friend HList;

	private:
		ListNode* CurNode = nullptr;

	public:
		iterator()
		{

		}

		iterator(ListNode* _Node)
			: CurNode(_Node)
		{

		}

		bool operator !=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		bool operator ==(const iterator& _Other)
		{
			return CurNode == _Other.CurNode;
		}

		iterator& operator ++()
		{
			CurNode = CurNode->Next;
			return *this;
		}

		DataType& operator*()
		{
			return CurNode->Value;
		}
	};

	HList()
	{
		StartNode = new ListNode();
		EndNode = new ListNode();

		// 이게 더미 노드 방식
		StartNode->Next = EndNode;
		EndNode->Prev = StartNode;
	}

	// void Push_front를 만들어보세요.
	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* PrevNode = EndNode->Prev;

		PrevNode->Next = NewNode;
		EndNode->Prev = NewNode;

		NewNode->Next = EndNode;
		NewNode->Prev = PrevNode;
	}

	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* AfterNode = StartNode->Next;

		AfterNode->Prev = NewNode;
		StartNode->Next = NewNode;

		NewNode->Next = AfterNode;
		NewNode->Prev = StartNode;

	}

	iterator erase(const iterator& _Iter)
	{

		ListNode* Node = _Iter.CurNode;
		Node;
		EndNode;

		// 터져야 한다.
		if (StartNode == Node
			|| EndNode == Node)
		{
			assert(false);
			return iterator(EndNode);
		}

		ListNode* NextNode = Node->Next;
		ListNode* PrevNode = Node->Prev;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		if (nullptr != Node)
		{
			delete Node;
			Node = nullptr;
		}
		NextNode;
		return iterator(NextNode);
	}

	iterator begin()
	{
		return iterator(StartNode->Next);
	}

	iterator end()
	{
		return iterator(EndNode);
	}


	~HList()
	{

		iterator EndIter = end();
		iterator EraseIter = begin();

		for (; EraseIter.operator!=(EndIter);)
		{
			EraseIter;
			EndIter;

			EraseIter = erase(EraseIter);
		}

		delete StartNode;
		StartNode = nullptr;

		delete EndNode;
		EndNode = nullptr;

	}



private:
	ListNode* StartNode;
	ListNode* EndNode;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	{
		// 노드형 시퀀스 자료구조
		HList NewList;
		// 프로그래밍에서는
		// 어떤 클래스가 있을때 그걸 사용하는 모든 방법
		// NewList.push_back
		//HList a = NewList;
		for (int i = 0; i < 10; i++)
		{
			NewList.push_back(i);
		}

		for (int i = 10; i < 20; i++)
		{
			NewList.push_front(i);
		}

		

		// 내가 5번째부터 시작한다
		// 불가능

		HList::iterator StartIter = NewList.begin();
		HList::iterator EndIter = NewList.end();

		HList::iterator EraseIter = NewList.begin();

		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;

		EraseIter = NewList.erase(EraseIter);


		for (; StartIter != EndIter; ++StartIter)
		{
			// 순회를 하면서 모든 인자를 도는 와중에 삭제를 합니다.
			std::cout << (*StartIter) << std::endl;
		}
	}

}


// Leak 난걸 잘 읽는 방법이 있냐?
// ++EraseIter를 붙여가지고 두개씩 건너뛰었네
// HList a = NewList;를 함으로써 ~HList를 할때 begin을 호출했음. StartNode에 NextNode가 nullptr이니까 당연히 에러. 
// <- 이런건 어떻게 예방을 하면 좋은가. begin과 같은 함수에서도 null처리? -> 합리적인 방법이 있는가? 선언만 하지 않는 습관?
// 생성자는 함수를 호출하면 자동으로 호출되는가. HList NewList로 선언만 했을때는 호출 안되는거 같은데. 
// HList NewList를 굳이 쓰는 이유가 있나? 써야하는 상황이 있나? 없으면 그냥 생성자 호출하면서 만들고 싶은데.

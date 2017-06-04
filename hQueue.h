#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "Contact_list.h"
#define  maxqueue 10


template <class t>
class hQueue
{
public:

	/* @brief  생성자*/
	hQueue();
	/* @brief  소멸자*/
	~hQueue();
	/* @brief  queue가 꽉 찼는지 확인한다.*/
	bool IsFull() const;
	/* @brief  queue가 비었는지 확인한다.*/
	bool IsEmpty() const;
	/* @brief  queue를 비게 만든다.*/
	void MakeEmpty();
	/* @brief  current pointer를 -1로 만든다.*/
	void reset();
	int getlength(){ return length; }
	/* @brief  아이템타입을 추가한다.*/
	void Enqueue(t item);
	/* @brief  가장 먼저들어온 아이템타입을 삭제한다.*/
	void DeQuene();
	/* @brief  최근에 들어온 아이템타입부터 출력한다.*/
	//void Print();

	void GetNextItem(t &data);
	/* @brief  주소로 아이템타입을 비교해서 같으면 1 아니면 0을 return 한다.*/
	int IsltlnQueue(t key);
	/* @brief  입력받은 대상과 똑같은 아이템타입은 삭제한다..*/
	int DeleteItem(t key);
private:
	int front; // 가장 먼저 들어온 변수를 가리키는 index
	int rear; // 가장 나중에 들어온 변수를 가리키는 index
	int length; //item의 총 갯수
	int currentpointer;//현재 가리키고 있는 대상의 index
	t* items;	///< Pointer for a queue.
};

//생성자
template <class t>
hQueue<t>::hQueue()
{
	items = new t[maxqueue];
	front = maxqueue - 1;
	rear = maxqueue - 1;
	length = 0;
	currentpointer = rear;
}


//소멸자, 동적할당을 해제한다. 
template <class t>
hQueue<t>::~hQueue()
{
	delete[] items;
}

template <class t>
void hQueue<t>::GetNextItem(t &data)
{
	data = items[currentpointer];
	currentpointer = (currentpointer - 1) % maxqueue;
}
template <class t>
bool hQueue<t>::IsEmpty() const
{
	if (front == rear)
		return true;
	else
		return false;
}
/**
*	@brief	큐 안에 아이템이 maxqueue이상 저장되어있는지 판별
*	@pre
*	@post	그 이상 저장되어있으면 true를 아니면 false 를 돌려준다.
*/
template <class t>
bool hQueue<t>::IsFull() const
{
	if (length == maxqueue)
		return true;
	else if ((rear + 1) % maxqueue == front)
		return true;
	else
		return false;
}
/**
*	@brief	큐 안에 아이템을 모두 없앤다
*	@pre
*	@post	front, rear를 생성자상태로 돌려준다. 
*/
template <class t>
void hQueue<t>::MakeEmpty()
{
	front = maxqueue - 1;
	rear = maxqueue - 1;
}
/**
*	@brief	큐에 새로운 아이템을 추가시키는 함수
*	@pre	아이템이 꽉 차있으면 안된다. 
*	@post	rear를 추가시킨다.  .
*/
template <class t>
void hQueue<t>::Enqueue(t newItem)
{
	if (IsFull() == true)//item들이 다 저장되어있는 경우 
	{
		DeQuene() ;
	}
	rear = (rear + 1) % maxqueue;
	items[rear] = newItem;
	length++;

}
/**
*	@brief	큐에 새로운 아이템을 삭제시키는 함수
*	@pre	아이템이 저장되어있어야한다. 
*	@post	front만 값을 하나 증가시킨다.  .
*/
template<class t>
void hQueue<t>::DeQuene()
{
	if (IsEmpty()) 
	{
		cout<<"queue 가 비어있습니다. "<<endl ;
	}

	else
	{
		length--;
		front = (front + 1) % maxqueue;
	}
}
/**
*	@brief	아이템중 이름과 주소로 대상을 검색한다
*	@pre	비어있으면 안된다. 
*	@post	대상을 찾을 경우 1 , 아닐경우 0을 돌려준다.
*/

template <class t>
int hQueue<t>::IsltlnQueue(t key)
{
	currentpointer=-1 ;
	int k = rear;
	if (front > rear)
		k = rear + maxqueue;
	for (int i = (front + 1) % maxqueue; i <= k; i++)
	{
		if (key==items[i%maxqueue])
		{
			cout<<endl ;
			currentpointer = i%maxqueue;
			cout<<"찾으시는 학생의 정보입니다. "<<endl ;
			items[i%maxqueue].DisplayRecordOnScreen();
			break ;
		}
	}
	if(currentpointer==-1)
	{	
	return 0;
	}
	else
		return 1 ;
}
/**
*	@brief	아이템중 이름과 주소를 입력받아 삭제한다.
*	@pre	비어있으면 안된다.
*	@post	대상을 찾았을 경우 1 , 아닐경우 0을 돌려준다.
*/
template <class t>
int hQueue<t>::DeleteItem(t key)
{
	if (currentpointer!=-1)
	{
		length--;
		int k = rear;
		if (rear < currentpointer)
			k = rear + maxqueue;
		for (int i = currentpointer; i < k; i++)
			items[i%maxqueue] = items[(i + 1)%maxqueue];
		rear = (rear - 1) % maxqueue;
		return 1;
	}
	else
		cout << "그러한 대상을 찾지 못했습니다." << endl;
	return 0;
}
/**
*	@brief	current poiter를 초기화시킨다.
*	@pre	
*	@post	
*/
template <class t>
void hQueue<t>::reset()
{
	currentpointer = rear;
}

////모든 아이템을 출력한다. 
//template <class t>
//void hQueue<t>::Print()
//{
//	if (IsEmpty() == true)
//		cout << "큐가 비었습니다." << endl;
//	else
//	{
//		int m = 1;
//		int k = rear;
//		if (front > rear)
//			k = rear + maxqueue;
//		for (int i = k - 1; i >= front; i--)
//		{
//			
//			if (items[(i + 1) % maxqueue].addressa() == 0)//이름이 없는 경우 주소만 출력하기위한 예외처리를 해주었다. 
//			{
//				cout << m<<". ";
//				items[(i + 1) % maxqueue].DisplayAddressOnScreen();
//				m++;
//			}
//			else
//			{
//				cout << m << ". ";
//				items[(i + 1) % maxqueue].DisplayRecordOnScreen();
//				m++;
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//}


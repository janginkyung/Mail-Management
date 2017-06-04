#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


template <typename T>
struct NodeType
{
	T data;	//노드의 정보
	NodeType* next;	//노드의 다음 노드를 가리키는 주소
};

/* @brief  정렬된 리스트*/
template <typename T>
class LinkedList
{
public:

	LinkedList();//생성자

	~LinkedList();//소멸자


	/**
	*  @brief	:  리스트를 비워있게 만들어준다
	*  @pre		:
	*  @post	: 어떤 정보도 저장되어 있지 않다. 
	*/
	void MakeEmpty();
	/**
	*  @brief	: 리스트의 갯수를 얻는다.
	*  @pre		:
	*  @post	: 리스트의 갯수를 반환한다.
	*/
	int GetLength() const;
	/**
	*  @brief	:리스트에 노드를 추가시킨다
	*  @pre		:리스트가 꽉 차있으면 안된다.
	*  @post	:아이템이 정열된 상태로 리스트에 들어가서 들어가면 1, 아니면 0을 리턴한다.
	*/
	int Add(T item);
	/**
	*  @brief	: 키로 리스트에서 아이템을 찾아주는 역할이다. 
	*  @pre		: 키멤버가 초기화가 되어있어야 한다
	*  @post	: 찾으면 1 과 아이템에 정보를 넣어서 리턴하면 아닌경우 0을 리턴한다.
	*/

	int Get(T& item);
	/**
	*  @brief	: 지시자를 리셋시킨다.
	*  @pre		: 
	*  @post	: 현재 지시자가 리스트의 맨 처음을 가리키게 된다.
	*/
	void ResetList();
	/**
	*  @brief	: 아이템과 리스트중 아이템이 같으면 1 아니면 0을 출력한다.
	*  @pre		: 키멤버가 초기화가 되어있어야 한다
	*  @post	:
	*/
	int searchitem(T item);
	/**
	*	@brief  지시자를 통해서 리스트의 다음 아이템을 가리킨다. 
	*	@pre	지시자가 처음시작전에 리셋이 되어있어야한다. 
	*	@post	
	*/
	void GetNextItem(T& item);
	/**
	*  @brief	:아이템을 찾아서 삭제시킨다.
	*  @pre		:
	*  @post	:그 아이템을 넣어서 돌려준다.
	*/
	int Delete (T& item);
private:
	NodeType<T>* m_pList;	//첫번쨰 노드의 포인터
	NodeType<T>* m_pCurPointer;	///지시자로 현재 가리키고 있는 노드 
	int m_nLength;	//리스트에 있는 노드의 갯수 
};


// Class constructor
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// 순서대로 아이템을 저장한다. 
template <typename T>
int LinkedList<T>::Add(T item)
{// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *predoc;
	NodeType<T> * location;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
		m_nLength++;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 포인터 초기화 
		predoc = NULL;
		location = m_pList;
		//반복문을 돌려서 아이템들을 비교한다
		for (int i = 0; i < m_nLength; i++)
		{
			if (node->data  < location->data || node->data  == location->data)
			{	//찾앗을 경우 사이에 집어넣어줘야 한다
				if (predoc == NULL)
				{
					node->next = m_pList;
					m_pList = node;
				}
				else
				{
					i--;
					predoc->next = node;//node의 next에는 그 전 아이템이 가리키는 주소를 집어넣는다
					node->next = location;//그 전 아이템이 가리키는 곳을 새로운 아이템으로 지정한다
				}

				break;
			}
			else
			{
				predoc = location;
				location = location->next;

			}
		}
		m_nLength++;
		if (node->next == NULL)
			predoc->next = node;
	}
	
	return 1;

}

//아이템을 찾는 경우 
template <typename T>
int LinkedList<T>::Get(T& item)
{
	bool moreToSearch, found;
	NodeType<T>* location;

	location = m_pList;
	found = false;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (item == location->data)
		{
			found = true;
			item = location->data;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}

	if (found)
		return 1;
	else
		return 0;
}
// 지시자를 리셋한다. 
template <typename T>
void LinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}
// 리스트에서 그다음 노드를 가리킨다. 
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else 
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}
/*아이템과 같은 것을 찾을경우1 아니면 0을 리턴한다. 
template <typename T>
int LinkedList<T>::searchitem(T item)
{
	ResetList();
	T dummy;
	while (1)
	{
		GetNextItem(dummy);
		if (dummy == item)
		{
			dummy.DisplayRecordOnScreen();//제네릭하지 못한 부분
			return 1;
		}
		if (m_pCurPointer == NULL)
			return 0;
	}

}
*/

template <typename T>
int LinkedList<T>::Delete(T& item)
{
	bool moreToSearch, found;

	NodeType<T>* pre = NULL;	
	m_pCurPointer = m_pList;

	moreToSearch = (m_pCurPointer != NULL);
	found = false;

	while (moreToSearch && !found)
	{
		if (item == m_pCurPointer->data)	
		{
			found = true;	
			if (pre == NULL)// pre가 null인 경우는 따로 예외처리
				m_pList = m_pCurPointer->next;	//현재 가리키는 애를 삭제하기 위해 m_plist를 새롭게 초기화 
			else
			{
				pre->next = m_pCurPointer->next;
			}	
			delete m_pCurPointer;
			m_nLength--;	
		}
		else//아이템을 찾지 못했을 경우에는 다음 노드를 가리켜야 한다. 
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);//가리키는 대상이 null이 아닐때까지 시행한다는 의미
		}	
	}

	if (found)//찾았을 경우 1을 돌려주고
		return 1;
	else//찾지 못했을 경우 0을 돌려준다. 
		return 0;	
}
#endif	// LINKED_LIST
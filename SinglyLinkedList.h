#ifndef _SINGLYLINKED_LIST_H
#define _SINGLYLINKED_LIST_H

#include "QltemType.h"
/**
*	Structure for NodeType to use in Linked structure.
*/
template <typename T>
struct NodeType
{
	T data;	///< A data for each node.
	NodeType* next;	///< A node pointer to point succeed node.
};


/**
*	Simple unsorted list class for managing items.
*/
template <typename T>
class SinglyLinkedList
{
public:
	/**
	*	default constructor.
	*/
	SinglyLinkedList();

	/**
	*	destructor.
	*/
	~SinglyLinkedList();
	/**
	*	@brief	linked list를 비어있게 만들어준다
	*	@pre	
	*	@post	
	*/
	void MakeEmpty();
	/**
	*	@brief	저장되어있는 갯수를 돌려준다
	*	@pre	
	*	@post	
	*/
	int GetLength() const;

	/**
	*	@brief	노드를 저장시키는데 맨앞에 추가시킨다.
	*	@pre
	*	@post
	*/
	int Add(T item);

	/**
	*	@brief	저장되어있는 리스트와 들어온 아이템과 같은지아닌지를 판별
	*	@pre	리스트에 저장이 되어있어야한다
	*	@post
	*/
	int Get(T& item);
	/**
	*	@brief	m_pCurPointer를 -1로 초기화시킨다
	*	@pre
	*	@post
	*/
	void ResetList();
	/**
	*	@brief	처음부터 시작해서 노드를 끝까지 가리킨다.
	*	@pre	poiner가 리셋되어야한다. 
	*	@post
	*/
	void GetNextItem(T& item);
	/**
	*	@brief	current pointer이용해서 처음부터 끝까지 노드를 가리켜 출력한다.
	*	@pre	poiner가 리셋되어야한다. 
	*	@post
	*/
	void Print();
	/**
	*	@brief	앞에서부터 노드를 1개 삭제한다
	*	@pre	리스트가 비어있으면 안된다
	*	@post	
	*/
	int deleteitem(T& item);
	/**
	*	@brief 노드의 아이템들중 이름 또는 주소가 같은 것을 찾는다.
	*	@pre	
	*	@post	같으면 1 아니면 0을 리턴한다
	*/
	int searchitem(T item);
	

private:
	NodeType<T>* m_pList;	///< Pointer for pointing a first node.
	NodeType<T>* m_pCurPointer;	///< Node pointer for pointing current node to use iteration.
	int m_nLength;	///< Number of node in the list.
};


// Class constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Class destructor
template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}


// 링크드리스트를 비어있게만든다.
template <typename T>
void SinglyLinkedList<T>::MakeEmpty()
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


// 링크드 리스트의 갯수를 리턴한다.
template <typename T>
int SinglyLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// 맨 뒤에 노드를 추가한다.
template <typename T>
int SinglyLinkedList<T>::Add(T item)
{
	// 리스트 초기화
	ResetList();

	// 리스트에 추가할 새로운 node 객체와 이전 노드를 가리킬 포인터 선언
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;

	// node 객체에 입력받은 데이터 설정 및 초기화
	node->data = item;
	node->next = NULL;

	// list 에 node 가 존재하지 않는 경우
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list 에 node 가 하나 이상 존재하는 경우
	else
	{
		// 가장 마지막 node 로 이동 후 삽입
		while (1)
		{
			// 이전 노드를 가리키는 포인터 갱신
			pre = m_pCurPointer;

			// iteration 을 이용해 node 포인터 갱신.
			GetNextItem(dummy);

			// node 포인터가 마지막 node 를 가리키면 그 뒤에 새로운 node 삽입.
			if (m_pCurPointer->next == NULL)
			{
				// 마지막 node 와 새로운 node 연결
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}
// 들어온 아이템과 똑같은걸 리스트에서발견하면 1 아니면 0을 리턴한다
template <typename T>
int SinglyLinkedList<T>::Get(T& item)
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
void SinglyLinkedList<T>::ResetList()
{
	// current pointer 초기화
	m_pCurPointer = NULL;
}

// 리스트에서 다음 노드를 가리킨다. 
template <typename T>
void SinglyLinkedList<T>::GetNextItem(T& item)
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
// 리스트 전체의 노드를 출력한다. 
template <typename T>
void SinglyLinkedList<T>::Print()
{
	//리스트를 리셋한다
	ResetList();
	T dummy;
	while (1)
	{
		if (m_nLength == 0)
		{
			cout << "list is empty " << endl;
			break ;
		}
		GetNextItem(dummy);
		// node 포인터가 마지막 node 를 가리키면 그만 출력한다.
		dummy.DisplayRecordOnScreen();
		cout << endl;
		if (m_pCurPointer->next == NULL)//가리키는 대상이 없는 경우 그만둔다.
		{
			break;
		}
	}
	return; 
}
// 노드랑 같은 아이템을 찾아내서 있으면 1, 아니면 0을 리턴한다.찾을때마다 출력해준다. 
template <typename T>
int SinglyLinkedList<T>::searchitem(T item)
{
	ResetList();
	T dummy;
	while (1)
	{
		GetNextItem(dummy);
		if (dummy == item)
		{
			dummy.DisplayRecordOnScreen();
			return 1;
		}
		if (m_pCurPointer == NULL)
			return 0;
	}

}
// 아이템이랑 똑같은 아이가 있으면 삭제한다. 
template <typename T>
int SinglyLinkedList<T>::deleteitem(T& item)
{// 리스트 초기화
	NodeType<T>* preloc;
	NodeType<T>* curloc;
	NodeType<T>* temptr;
	preloc = NULL ,curloc = m_pList , temptr = NULL;

	if (searchitem(item) != 0)// 아이템이랑 똑같은 노드를 찾은 경우 
	{
		for (int i = 0; i < m_nLength; i++)
		{
			if (curloc->data == item)//똑같은 아이를 지워주기 위해서 
			{
				temptr = curloc;
				preloc->next = curloc->next;
				curloc = curloc->next;
				delete temptr;
				break;
			}
			else
			{
				preloc = curloc;
				curloc = curloc->next;
			}
		}
		m_nLength--;
	}
	else// 아이템이랑 똑같은 노드를 찾지 못한경우 
	{
		cout << "그러한 대상을 찾지 못했습니다 " << endl;
	}
	return 0;
}

#endif	// LINKED_LIST
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
	*	@brief	linked list�� ����ְ� ������ش�
	*	@pre	
	*	@post	
	*/
	void MakeEmpty();
	/**
	*	@brief	����Ǿ��ִ� ������ �����ش�
	*	@pre	
	*	@post	
	*/
	int GetLength() const;

	/**
	*	@brief	��带 �����Ű�µ� �Ǿտ� �߰���Ų��.
	*	@pre
	*	@post
	*/
	int Add(T item);

	/**
	*	@brief	����Ǿ��ִ� ����Ʈ�� ���� �����۰� �������ƴ����� �Ǻ�
	*	@pre	����Ʈ�� ������ �Ǿ��־���Ѵ�
	*	@post
	*/
	int Get(T& item);
	/**
	*	@brief	m_pCurPointer�� -1�� �ʱ�ȭ��Ų��
	*	@pre
	*	@post
	*/
	void ResetList();
	/**
	*	@brief	ó������ �����ؼ� ��带 ������ ����Ų��.
	*	@pre	poiner�� ���µǾ���Ѵ�. 
	*	@post
	*/
	void GetNextItem(T& item);
	/**
	*	@brief	current pointer�̿��ؼ� ó������ ������ ��带 ������ ����Ѵ�.
	*	@pre	poiner�� ���µǾ���Ѵ�. 
	*	@post
	*/
	void Print();
	/**
	*	@brief	�տ������� ��带 1�� �����Ѵ�
	*	@pre	����Ʈ�� ��������� �ȵȴ�
	*	@post	
	*/
	int deleteitem(T& item);
	/**
	*	@brief ����� �����۵��� �̸� �Ǵ� �ּҰ� ���� ���� ã�´�.
	*	@pre	
	*	@post	������ 1 �ƴϸ� 0�� �����Ѵ�
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
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// ��ũ�帮��Ʈ�� ����ְԸ����.
template <typename T>
void SinglyLinkedList<T>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;

	while (m_pList != NULL)
	{
		tempPtr = m_pList;
		m_pList = m_pList->next;
		delete tempPtr;
	}

	m_nLength = 0;
}


// ��ũ�� ����Ʈ�� ������ �����Ѵ�.
template <typename T>
int SinglyLinkedList<T>::GetLength() const
{
	return m_nLength;
}

// �� �ڿ� ��带 �߰��Ѵ�.
template <typename T>
int SinglyLinkedList<T>::Add(T item)
{
	// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *pre;
	T dummy;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ���� ������ node �� �̵� �� ����
		while (1)
		{
			// ���� ��带 ����Ű�� ������ ����
			pre = m_pCurPointer;

			// iteration �� �̿��� node ������ ����.
			GetNextItem(dummy);

			// node �����Ͱ� ������ node �� ����Ű�� �� �ڿ� ���ο� node ����.
			if (m_pCurPointer->next == NULL)
			{
				// ������ node �� ���ο� node ����
				m_pCurPointer->next = node;
				break;
			}
		}
	}

	m_nLength++;

	return 1;
}
// ���� �����۰� �Ȱ����� ����Ʈ�����߰��ϸ� 1 �ƴϸ� 0�� �����Ѵ�
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


// �����ڸ� �����Ѵ�.
template <typename T>
void SinglyLinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}

// ����Ʈ���� ���� ��带 ����Ų��. 
template <typename T>
void SinglyLinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}
// ����Ʈ ��ü�� ��带 ����Ѵ�. 
template <typename T>
void SinglyLinkedList<T>::Print()
{
	//����Ʈ�� �����Ѵ�
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
		// node �����Ͱ� ������ node �� ����Ű�� �׸� ����Ѵ�.
		dummy.DisplayRecordOnScreen();
		cout << endl;
		if (m_pCurPointer->next == NULL)//����Ű�� ����� ���� ��� �׸��д�.
		{
			break;
		}
	}
	return; 
}
// ���� ���� �������� ã�Ƴ��� ������ 1, �ƴϸ� 0�� �����Ѵ�.ã�������� ������ش�. 
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
// �������̶� �Ȱ��� ���̰� ������ �����Ѵ�. 
template <typename T>
int SinglyLinkedList<T>::deleteitem(T& item)
{// ����Ʈ �ʱ�ȭ
	NodeType<T>* preloc;
	NodeType<T>* curloc;
	NodeType<T>* temptr;
	preloc = NULL ,curloc = m_pList , temptr = NULL;

	if (searchitem(item) != 0)// �������̶� �Ȱ��� ��带 ã�� ��� 
	{
		for (int i = 0; i < m_nLength; i++)
		{
			if (curloc->data == item)//�Ȱ��� ���̸� �����ֱ� ���ؼ� 
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
	else// �������̶� �Ȱ��� ��带 ã�� ���Ѱ�� 
	{
		cout << "�׷��� ����� ã�� ���߽��ϴ� " << endl;
	}
	return 0;
}

#endif	// LINKED_LIST
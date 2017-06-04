#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;


template <typename T>
struct NodeType
{
	T data;	//����� ����
	NodeType* next;	//����� ���� ��带 ����Ű�� �ּ�
};

/* @brief  ���ĵ� ����Ʈ*/
template <typename T>
class LinkedList
{
public:

	LinkedList();//������

	~LinkedList();//�Ҹ���


	/**
	*  @brief	:  ����Ʈ�� ����ְ� ������ش�
	*  @pre		:
	*  @post	: � ������ ����Ǿ� ���� �ʴ�. 
	*/
	void MakeEmpty();
	/**
	*  @brief	: ����Ʈ�� ������ ��´�.
	*  @pre		:
	*  @post	: ����Ʈ�� ������ ��ȯ�Ѵ�.
	*/
	int GetLength() const;
	/**
	*  @brief	:����Ʈ�� ��带 �߰���Ų��
	*  @pre		:����Ʈ�� �� �������� �ȵȴ�.
	*  @post	:�������� ������ ���·� ����Ʈ�� ���� ���� 1, �ƴϸ� 0�� �����Ѵ�.
	*/
	int Add(T item);
	/**
	*  @brief	: Ű�� ����Ʈ���� �������� ã���ִ� �����̴�. 
	*  @pre		: Ű����� �ʱ�ȭ�� �Ǿ��־�� �Ѵ�
	*  @post	: ã���� 1 �� �����ۿ� ������ �־ �����ϸ� �ƴѰ�� 0�� �����Ѵ�.
	*/

	int Get(T& item);
	/**
	*  @brief	: �����ڸ� ���½�Ų��.
	*  @pre		: 
	*  @post	: ���� �����ڰ� ����Ʈ�� �� ó���� ����Ű�� �ȴ�.
	*/
	void ResetList();
	/**
	*  @brief	: �����۰� ����Ʈ�� �������� ������ 1 �ƴϸ� 0�� ����Ѵ�.
	*  @pre		: Ű����� �ʱ�ȭ�� �Ǿ��־�� �Ѵ�
	*  @post	:
	*/
	int searchitem(T item);
	/**
	*	@brief  �����ڸ� ���ؼ� ����Ʈ�� ���� �������� ����Ų��. 
	*	@pre	�����ڰ� ó���������� ������ �Ǿ��־���Ѵ�. 
	*	@post	
	*/
	void GetNextItem(T& item);
	/**
	*  @brief	:�������� ã�Ƽ� ������Ų��.
	*  @pre		:
	*  @post	:�� �������� �־ �����ش�.
	*/
	int Delete (T& item);
private:
	NodeType<T>* m_pList;	//ù���� ����� ������
	NodeType<T>* m_pCurPointer;	///�����ڷ� ���� ����Ű�� �ִ� ��� 
	int m_nLength;	//����Ʈ�� �ִ� ����� ���� 
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
	//����Ʈ���� ��� node ����
	MakeEmpty();
}


// Initialize list to empty state.
template <typename T>
void LinkedList<T>::MakeEmpty()
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


// Get number of elements in the list.
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// ������� �������� �����Ѵ�. 
template <typename T>
int LinkedList<T>::Add(T item)
{// ����Ʈ �ʱ�ȭ
	ResetList();

	// ����Ʈ�� �߰��� ���ο� node ��ü�� ���� ��带 ����ų ������ ����
	NodeType<T> *node = new NodeType<T>;
	NodeType<T> *predoc;
	NodeType<T> * location;

	// node ��ü�� �Է¹��� ������ ���� �� �ʱ�ȭ
	node->data = item;
	node->next = NULL;

	// list �� node �� �������� �ʴ� ���
	if (!m_nLength)
	{
		m_pList = node;
		m_nLength++;
	}
	// list �� node �� �ϳ� �̻� �����ϴ� ���
	else
	{
		// ������ �ʱ�ȭ 
		predoc = NULL;
		location = m_pList;
		//�ݺ����� ������ �����۵��� ���Ѵ�
		for (int i = 0; i < m_nLength; i++)
		{
			if (node->data  < location->data || node->data  == location->data)
			{	//ã���� ��� ���̿� ����־���� �Ѵ�
				if (predoc == NULL)
				{
					node->next = m_pList;
					m_pList = node;
				}
				else
				{
					i--;
					predoc->next = node;//node�� next���� �� �� �������� ����Ű�� �ּҸ� ����ִ´�
					node->next = location;//�� �� �������� ����Ű�� ���� ���ο� ���������� �����Ѵ�
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

//�������� ã�� ��� 
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
// �����ڸ� �����Ѵ�. 
template <typename T>
void LinkedList<T>::ResetList()
{
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}
// ����Ʈ���� �״��� ��带 ����Ų��. 
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
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
/*�����۰� ���� ���� ã�����1 �ƴϸ� 0�� �����Ѵ�. 
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
			dummy.DisplayRecordOnScreen();//���׸����� ���� �κ�
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
			if (pre == NULL)// pre�� null�� ���� ���� ����ó��
				m_pList = m_pCurPointer->next;	//���� ����Ű�� �ָ� �����ϱ� ���� m_plist�� ���Ӱ� �ʱ�ȭ 
			else
			{
				pre->next = m_pCurPointer->next;
			}	
			delete m_pCurPointer;
			m_nLength--;	
		}
		else//�������� ã�� ������ ��쿡�� ���� ��带 �����Ѿ� �Ѵ�. 
		{
			pre = m_pCurPointer;
			m_pCurPointer = m_pCurPointer->next;
			moreToSearch = (m_pCurPointer != NULL);//����Ű�� ����� null�� �ƴҶ����� �����Ѵٴ� �ǹ�
		}	
	}

	if (found)//ã���� ��� 1�� �����ְ�
		return 1;
	else//ã�� ������ ��� 0�� �����ش�. 
		return 0;	
}
#endif	// LINKED_LIST
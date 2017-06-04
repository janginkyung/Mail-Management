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

	/* @brief  ������*/
	hQueue();
	/* @brief  �Ҹ���*/
	~hQueue();
	/* @brief  queue�� �� á���� Ȯ���Ѵ�.*/
	bool IsFull() const;
	/* @brief  queue�� ������� Ȯ���Ѵ�.*/
	bool IsEmpty() const;
	/* @brief  queue�� ��� �����.*/
	void MakeEmpty();
	/* @brief  current pointer�� -1�� �����.*/
	void reset();
	int getlength(){ return length; }
	/* @brief  ������Ÿ���� �߰��Ѵ�.*/
	void Enqueue(t item);
	/* @brief  ���� �������� ������Ÿ���� �����Ѵ�.*/
	void DeQuene();
	/* @brief  �ֱٿ� ���� ������Ÿ�Ժ��� ����Ѵ�.*/
	//void Print();

	void GetNextItem(t &data);
	/* @brief  �ּҷ� ������Ÿ���� ���ؼ� ������ 1 �ƴϸ� 0�� return �Ѵ�.*/
	int IsltlnQueue(t key);
	/* @brief  �Է¹��� ���� �Ȱ��� ������Ÿ���� �����Ѵ�..*/
	int DeleteItem(t key);
private:
	int front; // ���� ���� ���� ������ ����Ű�� index
	int rear; // ���� ���߿� ���� ������ ����Ű�� index
	int length; //item�� �� ����
	int currentpointer;//���� ����Ű�� �ִ� ����� index
	t* items;	///< Pointer for a queue.
};

//������
template <class t>
hQueue<t>::hQueue()
{
	items = new t[maxqueue];
	front = maxqueue - 1;
	rear = maxqueue - 1;
	length = 0;
	currentpointer = rear;
}


//�Ҹ���, �����Ҵ��� �����Ѵ�. 
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
*	@brief	ť �ȿ� �������� maxqueue�̻� ����Ǿ��ִ��� �Ǻ�
*	@pre
*	@post	�� �̻� ����Ǿ������� true�� �ƴϸ� false �� �����ش�.
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
*	@brief	ť �ȿ� �������� ��� ���ش�
*	@pre
*	@post	front, rear�� �����ڻ��·� �����ش�. 
*/
template <class t>
void hQueue<t>::MakeEmpty()
{
	front = maxqueue - 1;
	rear = maxqueue - 1;
}
/**
*	@brief	ť�� ���ο� �������� �߰���Ű�� �Լ�
*	@pre	�������� �� �������� �ȵȴ�. 
*	@post	rear�� �߰���Ų��.  .
*/
template <class t>
void hQueue<t>::Enqueue(t newItem)
{
	if (IsFull() == true)//item���� �� ����Ǿ��ִ� ��� 
	{
		DeQuene() ;
	}
	rear = (rear + 1) % maxqueue;
	items[rear] = newItem;
	length++;

}
/**
*	@brief	ť�� ���ο� �������� ������Ű�� �Լ�
*	@pre	�������� ����Ǿ��־���Ѵ�. 
*	@post	front�� ���� �ϳ� ������Ų��.  .
*/
template<class t>
void hQueue<t>::DeQuene()
{
	if (IsEmpty()) 
	{
		cout<<"queue �� ����ֽ��ϴ�. "<<endl ;
	}

	else
	{
		length--;
		front = (front + 1) % maxqueue;
	}
}
/**
*	@brief	�������� �̸��� �ּҷ� ����� �˻��Ѵ�
*	@pre	��������� �ȵȴ�. 
*	@post	����� ã�� ��� 1 , �ƴҰ�� 0�� �����ش�.
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
			cout<<"ã���ô� �л��� �����Դϴ�. "<<endl ;
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
*	@brief	�������� �̸��� �ּҸ� �Է¹޾� �����Ѵ�.
*	@pre	��������� �ȵȴ�.
*	@post	����� ã���� ��� 1 , �ƴҰ�� 0�� �����ش�.
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
		cout << "�׷��� ����� ã�� ���߽��ϴ�." << endl;
	return 0;
}
/**
*	@brief	current poiter�� �ʱ�ȭ��Ų��.
*	@pre	
*	@post	
*/
template <class t>
void hQueue<t>::reset()
{
	currentpointer = rear;
}

////��� �������� ����Ѵ�. 
//template <class t>
//void hQueue<t>::Print()
//{
//	if (IsEmpty() == true)
//		cout << "ť�� ������ϴ�." << endl;
//	else
//	{
//		int m = 1;
//		int k = rear;
//		if (front > rear)
//			k = rear + maxqueue;
//		for (int i = k - 1; i >= front; i--)
//		{
//			
//			if (items[(i + 1) % maxqueue].addressa() == 0)//�̸��� ���� ��� �ּҸ� ����ϱ����� ����ó���� ���־���. 
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


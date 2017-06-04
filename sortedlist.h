
#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"
/*
	@brief ���ĵ� �迭�ν� �߰�, ����, ã��� ����� �ִ�. 
*/
template <class T>
class sortedlist
{
public:
	/**
	*	default constructor.
	*/
	sortedlist()
	{
		m_Length = 0;
		ResetList();
		m_Array = new ItemType[3];
	}

	/**
	*	destructor.
	*/
	~sortedlist()	{}

	/* @brief  list�� ������� Ȯ���Ѵ�*/
	void MakeEmpty();
	//@brief	���̸� �����ش�.
	int GetLength();
	/* @brief  ���ο� ������Ÿ���� �߰��Ѵ�*/
	int Add(ItemType data);
	//current pointer�� �ʱ�ȭ��Ų��. 
	void ResetList();
	/* @brief  ��� ������Ÿ���� ����Ѵ�*/
	void print();
	//brief list iterator �� ������ �̵����Ѽ� ����list�� �ִ� �ν��Ͻ��� ����Ų��.
	int GetNextItem(ItemType& data);
	//primary key�� ����� ã�� list���� ������Ų��. 
	int Delete(ItemType& data1, ItemType& data2);
	
	//data1,data2���� ����� ã�� �Լ�
	int Get(ItemType& data1, ItemType& data2);

private:
	T* m_Array;  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

template <class T>
void sortedlist<T>::MakeEmpty()
{
	m_Length = 0;

}
/**
*	@brief	���� ����Ʈ�� ������ ��ȯ�Ѵ�.
*	@pre
*	@post
*/
template <class T>
int sortedlist<T>::GetLength(){ return m_Length; }
/**
*	@brief	�������� ���̸� �Ҵ��� ���ο� ������ �迭�� �߰��Ѵ�
*	@pre	
*	@post	���̰� 1 �����Ѵ�.
*/
template <class T>
int sortedlist<T>::Add(ItemType data)
{
	ItemType* ptr = new ItemType[m_Length + 1];//�����Ҵ��� 1 ũ�� ���ش�.
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i]>data)//�迭���� �� ������ ã�� ��� 
		{
			ptr[i] = data;
			for (int k = i; k < m_Length; k++)
				ptr[k + 1] = m_Array[k];
			delete[] m_Array;//������ ���� �޸��� ����� ���δ�
			m_Array = ptr;
			m_Length++;
			return 0;
		}
		else
			ptr[i] = m_Array[i];//�� ������ ��ã�� ��� �����Ҵ��� �迭�� ����־��ֱ�
	}
	ptr[m_Length] = data;
	m_Length++;
	delete[]m_Array;
	m_Array = ptr;
	return 1;
}
/**
*	@brief	�迭���� ����Ű�� �ִ� �����ڸ� �ʱ�ȭ��Ų��.
*	@pre
*	@post	
*/
template <class T>
void sortedlist<T>::ResetList()
{
	m_CurPointer = -1;//�迭�� 1��°���Ҹ� ����ų�� 0�� �����Ѿ��ϹǷ� �׺��� ���� -1�� �����Ѵ�.
}

/**
*	@brief	�迭�� ��� �������� ����Ѵ�.
*	@pre
*	@post
*/
template <class T>
void sortedlist<T>::print()
{
	if (m_Length == 0)
		cout << "����Ʈ�� ����ֽ��ϴ�. " << endl;
	else
	{
		ResetList();
		ItemType t;

		for (int i = 0; i < m_Length; i++)
		{
			GetNextItem(t);
			t.DisplayRecordOnScreen();
			cout << endl;
		}
	}
}
/**
*	@brief	poiner�� ���� �迭���� ���� �������� ����Ű�� �����.
*	@pre	ó���� ����� resetlist�� �������־�� �Ѵ�
*	@post	pointer1����
*/
template <class T>
int sortedlist<T>::GetNextItem(ItemType& data)
{
	m_CurPointer++;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}
/**
*	@brief	2���� �ð����̿� �ִ� ��� ��ü�� ã�Ƴ���. 
*	@pre	���۰� ���ð��� �Է¹޾ƾ��Ѵ�.
*	@post	ã���� 1 ���н� 0�� �����ش�
*/
template <class T>
int sortedlist<T>::Get(ItemType& data1, ItemType& data2)
{
	ResetList();
	ItemType test;	//iterator �ʱ�ȭ
	//ù������ ������
	while (m_CurPointer<m_Length)	//ó������ ������
	{
		GetNextItem(test);
		if (test>data1 &&test<data2)//�Է� �����۰� ���� �������� ��
			return 1;
		else if (test==data1 &&test==data2)//�Է� �����۰� ���� �������� ��
			return 1;
	}
	return 0; //���н�0

}
/**
*	@brief	2���� �ð����̿� �ִ� ��� ��ü�� �������Ѵ�. 
*	@pre	���۰� ���ð��� �Է¹޾ƾ��Ѵ�.
*	@post	ã���� 1 ���н� 0�� �����ش�
*/
template <class T>
int sortedlist<T>::Delete(ItemType& data1, ItemType& data2)
{
	int a = 0;
	ResetList();//iterator�� �ʱ�ȭ��Ų��. 
	ItemType test;
	for (int i = 0; i < m_Length; i++)	//ó������ ������
	{
		GetNextItem(test);
		if (test>data1 &&test<data2)//���۰� ���ð� ���̿��ִ� ������ ��� 
		{
			a++;
			for (int j = m_CurPointer; j < m_Length - 1; j++)
				m_Array[j] = m_Array[j + 1];//�ش��ϴ� ��°�� list�� �ش��°���� 1 ������ list�� �������. 
			m_Length--,i--;//���̸� ���̰� m_current pointer�� ����Ű�� ����� �޶󠺱⿡ 1���� ���δ�. 
		}
		//�Է� �����۰� ���� �������� ��
		else if (test==data1 ||test==data2)//���۶Ǵ� ���� ������� 
		{
			a++;
			for (int j = m_CurPointer; j< m_Length - 1; j++)
				m_Array[j] = m_Array[j + 1];
			m_Length--, i--;//���̸� ���̰� m_current pointer�� ����Ű�� ����� �޶󠺱⿡ 1���� ���δ�. 
		}
	}

	if (a == 0)//����ó���� ���� a�� 0�ϰ�� ������ ����� ���� ��� 
		return 0;
	else//���Ű� �̷���� ��� 
		return 1;
}

#endif	// _UNSORTEDLIST_H#include "ItemType.h"
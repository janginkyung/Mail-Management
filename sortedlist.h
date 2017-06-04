
#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"
/*
	@brief 정렬된 배열로써 추가, 삭제, 찾기등 기능이 있다. 
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

	/* @brief  list가 비었는지 확인한다*/
	void MakeEmpty();
	//@brief	길이를 돌려준다.
	int GetLength();
	/* @brief  새로운 아이템타입을 추가한다*/
	int Add(ItemType data);
	//current pointer을 초기화시킨다. 
	void ResetList();
	/* @brief  모든 아이템타입을 출력한다*/
	void print();
	//brief list iterator 를 옆으로 이동시켜서 다음list에 있는 인스턴스를 가리킨다.
	int GetNextItem(ItemType& data);
	//primary key로 대상을 찾아 list에서 삭제시킨다. 
	int Delete(ItemType& data1, ItemType& data2);
	
	//data1,data2에서 대상을 찾는 함수
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
*	@brief	현재 리스트에 갯수를 반환한다.
*	@pre
*	@post
*/
template <class T>
int sortedlist<T>::GetLength(){ return m_Length; }
/**
*	@brief	동적으로 길이를 할당해 새로운 메일을 배열에 추가한다
*	@pre	
*	@post	길이가 1 증가한다.
*/
template <class T>
int sortedlist<T>::Add(ItemType data)
{
	ItemType* ptr = new ItemType[m_Length + 1];//동적할당을 1 크게 해준다.
	for (int i = 0; i < m_Length; i++)
	{
		if (m_Array[i]>data)//배열에서 들어갈 순서를 찾은 경우 
		{
			ptr[i] = data;
			for (int k = i; k < m_Length; k++)
				ptr[k + 1] = m_Array[k];
			delete[] m_Array;//해제를 통해 메모리의 사용을 줄인다
			m_Array = ptr;
			m_Length++;
			return 0;
		}
		else
			ptr[i] = m_Array[i];//들어갈 순서를 못찾은 경우 동적할당한 배열에 집어넣어주기
	}
	ptr[m_Length] = data;
	m_Length++;
	delete[]m_Array;
	m_Array = ptr;
	return 1;
}
/**
*	@brief	배열에서 가리키고 있는 지시자를 초기화시킨다.
*	@pre
*	@post	
*/
template <class T>
void sortedlist<T>::ResetList()
{
	m_CurPointer = -1;//배열의 1번째원소를 가리킬때 0을 가리켜야하므로 그보다 작은 -1로 시작한다.
}

/**
*	@brief	배열의 모든 아이템을 출력한다.
*	@pre
*	@post
*/
template <class T>
void sortedlist<T>::print()
{
	if (m_Length == 0)
		cout << "리스트가 비어있습니다. " << endl;
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
*	@brief	poiner를 통해 배열에서 다음 아이템을 가리키게 만든다.
*	@pre	처음에 실행시 resetlist를 실행해주어야 한다
*	@post	pointer1증가
*/
template <class T>
int sortedlist<T>::GetNextItem(ItemType& data)
{
	m_CurPointer++;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}
/**
*	@brief	2개의 시간사이에 있는 모든 객체를 찾아낸다. 
*	@pre	시작과 끝시간을 입력받아야한다.
*	@post	찾으면 1 실패시 0을 돌려준다
*/
template <class T>
int sortedlist<T>::Get(ItemType& data1, ItemType& data2)
{
	ResetList();
	ItemType test;	//iterator 초기화
	//첫아이템 가져옴
	while (m_CurPointer<m_Length)	//처음부터 끝까지
	{
		GetNextItem(test);
		if (test>data1 &&test<data2)//입력 아이템과 현재 아이템을 비교
			return 1;
		else if (test==data1 &&test==data2)//입력 아이템과 현재 아이템을 비교
			return 1;
	}
	return 0; //실패시0

}
/**
*	@brief	2개의 시간사이에 있는 모든 객체를 지워야한다. 
*	@pre	시작과 끝시간을 입력받아야한다.
*	@post	찾으면 1 실패시 0을 돌려준다
*/
template <class T>
int sortedlist<T>::Delete(ItemType& data1, ItemType& data2)
{
	int a = 0;
	ResetList();//iterator를 초기화시킨다. 
	ItemType test;
	for (int i = 0; i < m_Length; i++)	//처음부터 끝까지
	{
		GetNextItem(test);
		if (test>data1 &&test<data2)//시작과 끝시간 사이에있는 메일의 경우 
		{
			a++;
			for (int j = m_CurPointer; j < m_Length - 1; j++)
				m_Array[j] = m_Array[j + 1];//해당하는 번째의 list에 해당번째보다 1 높여서 list에 덮씌운다. 
			m_Length--,i--;//길이를 줄이고 m_current pointer가 가리키는 대상이 달라졋기에 1개를 줄인다. 
		}
		//입력 아이템과 현재 아이템을 비교
		else if (test==data1 ||test==data2)//시작또는 끝과 같을경우 
		{
			a++;
			for (int j = m_CurPointer; j< m_Length - 1; j++)
				m_Array[j] = m_Array[j + 1];
			m_Length--, i--;//길이를 줄이고 m_current pointer가 가리키는 대상이 달라졋기에 1개를 줄인다. 
		}
	}

	if (a == 0)//예외처리를 위해 a가 0일경우 제거할 대상이 없는 경우 
		return 0;
	else//제거가 이루어진 경우 
		return 1;
}

#endif	// _UNSORTEDLIST_H#include "ItemType.h"
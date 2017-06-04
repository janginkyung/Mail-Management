
#pragma once
#include "DoublySortedLinkedList.h"
#include "Sorted_List.h"
#include "Mail.h"
#include "User.h"
#include <direct.h>

class MyFolder
{
public:
	MyFolder( );//������
	~MyFolder();//�Ҹ��� 
	/**
	*  @brief	: ������ �̸��� �����ش�
	*  @pre		:
	*  @post	:
	*/
	string Getfilename() { return file_name; }
	/**
	*  @brief	: ������ �̸��� �����Ѵ�
	*  @pre		: ���ڿ��� ���� �޾ƾ��Ѵ�
	*  @post	:
	*/
	void Setfilename(string name){
		file_name = name;
	}
	/**
	*  @brief	: 
	*  @pre		:
	*  @post	:
	*/
	void Setfolder(DoublySortedLinkedList<MyFolder> another);

	/**
	*  @brief	: ������ �߰���Ų��
	*  @pre		: ������ ���� �����Ǿ� �־���Ѵ�.
	*  @post	:
	*/
	void Setmails(DoublySortedLinkedList<ItemType> another);
	/**
	*  @brief	: ������ ����Ʈ�� �����ش�. 
	*  @pre		:
	*  @post	:
	*/
	DoublySortedLinkedList<ItemType> Getmails();
	/**
	*  @brief	: ���� �ȿ� �����ϴ� ���ϰ� ���������� ����ϴ� ����� �Ѵ�. 
	*  @pre		: �����ڰ� reset�Ǿ� �־���Ѵ�. 
	*  @post	:
	*/
	void Displayall();
	/**
	*  @brief	: ������ �߰��Ѵ�.
	*  @pre		: ������ �ʱ�ȭ�� �Ǿ��־���Ѵ�. 
	*  @post	:
	*/
	void Add_mail(ItemType test);
	/**
	*  @brief	: ���� �ȿ��� ���������� �����.
	*  @pre		: ���������� ������ ������ �Ǿ��־�� �Ѵ�. 
	*  @post	:
	*/
	void Add_subfolder(MyFolder subfolder);

	/**
	*  @brief	: ������ ����Ѵ�. 
	*  @pre		: ������ ����Ű�� �����ڰ� reset�Ǿ���Ѵ�. 
	*  @post	:
	*/
	void PrintMail();
	/**
	*  @brief	: ������ ����Ѵ�
	*  @pre		: ������ ����Ű�� �����ڰ� reset�Ǿ�� �Ѵ�. 
	*  @post	:
	*/
	void PrintFolder();
	/**
	*  @brief	: ���� ������� �Ѵ�. 
	*  @pre		:
	*  @post	:
	*/
	int ReadDataFromFile(ifstream& fin);
	/**
	*  @brief	: ������ �̸����� ���ϴ� ������ �����ε�
	*  @pre		:
	*  @post	: this��ü�� �����̸��� Ŭ��� true�� �ƴϸ� false�� �����Ѵ�. 
	*/
	bool operator > (MyFolder t1);
	/**
	*  @brief	: ���� ��ü�� �Ȱ��� ���� ������ ������ִ� ������ �����ε��̴�.
	*  @pre		: t1�� ��ü�� �ʱ�ȭ�� �Ǿ��־���Ѵ�
	*  @post	: ��������� ��� t1�� ���� ���� ���´�. 
	*/
	void operator =(MyFolder t1);
	/**
	*  @brief	: ������ �̸����� ���ϴ� ������ �����ε�
	*  @pre		: ������ �̸��� t1,�� ������ �Ǿ��־���Ѵ�.
	*  @post	: �̸��� ������ true�� �ƴϸ� false�� �����Ѵ�. 
	*/
	/* @brief ��¥�� ������ �� ������ ���� �����ش� */
	bool operator == (MyFolder t1);
	/**
	*  @brief	: ������ �̸����� ���ϴ� ������ �����ε�
	*  @pre		: ������ �̸��� t1,�� ������ �Ǿ��־���Ѵ�
	*  @post	: �̸��� t1�� �� ũ�� true�� �ƴϸ� false�� �����Ѵ�. 
	*/
	bool operator < (MyFolder t1);

	DoublySortedLinkedList<MyFolder> *fos; //���� �ȿ��� ���������� �������ؼ� �����ϴ� ���� 
	DoublySortedLinkedList<ItemType> Mails;//����ڿ� ���� �Ű����� ����
private:
	
	string file_name; //���� ������ �̸�
	

};



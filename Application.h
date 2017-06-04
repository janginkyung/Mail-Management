#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Shlwapi.h>
#include < stdio.h >
#pragma comment(lib, "Shlwapi.lib")
using namespace std;


#include "MyFolder.h"
#include "hQueue.h"
#include "Sorted_List.h"
#include "DoublySortedLinkedList.h"
#include "Mail.h"
#include "BinarySearchTree.h"
#include <direct.h>

#include <conio.h>
#include <io.h>

#include "User.h"

/*
	@brief application class�� ���� ���� �ڷḦ ���� ������ �����ϴ� �Լ����� �����.
	*/



class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
		for (int i = 0; i < 100; i++) {
			arr[i] = true, arr2[i] = true;
		}
		for (int i = 0; i < 26; i++)
			number[i] = 0;
		for (int i = 0; i < 26; i++)
		{
			Mail_Name[i] = new ItemType[1000];
			for (int j = 0; j < 1000; j++)
				Mail_Name[i][j] = ItemType();
		}
	}

	/**
	*	destructor.
	*/
	~Application()	
	{
		for (int i = 0; i < 26; i++)
		{
			delete[] Mail_Name[i];
		}
		delete[] Mail_Name;
	}
	/**
	*  @brief	: ȸ������,�α���,���̵��й�ȣã���� ������� ���� �Է¹޴´�.
	*  @pre		:
	*  @post	:
	*/
	void LogIn();
	/**
	*  @brief	: ȸ�������ϴ� �Լ� 
	*  @pre		:
	*  @post	: ���̵�� ���� ����
	*/
	void registerin();
	/**
	*  @brief	: ���̵�� �н����带 �Է¹޴� �Լ�
	*  @pre		: txt�� ���̵�� ��й�ȣ�� �ԷµǾ��־���Ѵ�.
	*  @post	: �ٸ��ÿ� �ٽ� �Է¹ް� �´� ��� ����������� ����ȴ�
	*/
	void idpw();
	/**
	*  @brief	: txt���Ͽ� �ִ� �������� �� �ε��Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void load_user();
	/**
	*  @brief	: ���̵�� ��й�ȣ�� ã�� ���� �����Ѵ�.
	*  @pre		: txt�� ���� �Է��� �Ǿ��־���Ѵ�
	*  @post	: 
	*/
	void Found_idpw();
	/**
	*  @brief	: ���̵� ã���ִ� �Լ��̴�
	*  @pre		: txt�� ���� �Է��� �Ǿ��־���Ѵ�
	*  @post	: �̸������� ���̵� ����Ѵ�
	*/
	void Found_id();
	/**
	*  @brief	: ��й�ȣ�� ã���ִ� �Լ��̴�
	*  @pre		: txt�� ���� �Է��� �Ǿ��־���Ѵ�
	*  @post	: �̸��� ���̵� ���� ��й�ȣ�� ����Ѵ�
	*/
	void Found_pw();
	/**
	*  @brief	: �������� �����Ѵ�.
	*  @pre		: �α����� ���� �Ǿ���Ѵ�
	*  @post	: ���� ���������� ����.
	*/
	void select_mail_forder();
	/**
	*  @brief	: ���� ���������� ����.
	*  @pre		:
	*  @post	:
	*/
	void received_mail_folder();
	/**
	*  @brief	: �������������� ����
	*  @pre		:
	*  @post	:
	*/
	void send_mail_folder();
	/**
	*  @brief	: �ּҷ����� ����
	*  @pre		:
	*  @post	:
	*/

	void contact_folder();
	/**
	*  @brief	:������ ���� ����
	*  @pre		:
	*  @post	:
	*/
	void garbage_mail_folder();
	/**
	*  @brief	:���������ϴ� �޴��� ����.
	*  @pre		:
	*  @post	:
	*/
	void make_folder();
	/**
	*  @brief	: �����ּ��Է� �� �ൿ�� �Է¹޴´�
	*  @pre		:
	*  @post	: ����ڰ� ������ �Ѱ����� �����Ѱ��� �����ش�.
	*/
	int received_mail_command();
	/**
	*  @brief	: �������������� ���� �ൿ�� �Է¹޴´�
	*  @pre		:
	*  @post	: ����ڰ� ������ �Ѱ����� �����Ѱ��� �����ش�.
	*/
	int send_mail_command();
	/**
	*  @brief	:�ּҷ����� �� �ൿ�� �Է¹޴´� 
	*  @pre		:
	*  @post	: ����ڰ� ������ �Ѱ����� �����Ѱ��� �����ش�.
	*/
	int contact_folder_command();
	/**
	*  @brief	: ���������� �� �ൿ�� �Է¹޴´�
	*  @pre		:
	*  @post	: ����ڰ� ������ �Ѱ����� �����Ѱ��� �����ش�.
	*/
	int  garbage_mail_folder_command();
	/**
	*  @brief	: ������������ �� �ൿ�� �Է¹޴´�
	*  @pre		:
	*  @post	: ����ڰ� ������ �Ѱ����� �����Ѱ��� �����ش�.
	*/
	int  make_folder_command();
	/**
	*  @brief	: ���� �����Կ��� ������ �����Ѵ�
	*  @pre		: ����� ������ �־���Ѵ�
	*  @post	: ���ͷ� �����ϰ� �����̽��ٷ� �����Ѵ�. 
	*/
	void deletereceivedmail();
	/**
	*  @brief	: ���д� �����߿��� �����ּҷ� ã�´�
	*  @pre		:
	*  @post	: ã�� ����� ����Ѵ�
	*/
	void findmail_name();
	/**
	*  @brief	: ������ ������ ��������.
	*  @pre		:
	*  @post	:
	*/
	void findmail_read();
	/**
	*  @brief	: ������ ���� �߿� �̸����� ã�´�.
	*  @pre		:
	*  @post	: 
	*/
	void findmail_read_name();
	/**
	*  @brief	:���� �����Կ��� �����ּҷ� ã�´�
	*  @pre		:
	*  @post	:
	*/
	void findmailbyaddress(); 
	/**
	*  @brief	: �����뿡 �ִ� ������ ����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void printgarbagemail();
	/**
	*  @brief	: �����뿡�� �������������� ������ ������
	*  @pre		:
	*  @post	: ������ �����ؼ� �������������� ����. 
	*/
	void Gobacktosendmail();
	/**
	*  @brief	: �����뿡�� ������ �����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void deletegarbagemail();
	/**
	*  @brief	: ����Ű�� �����ϱ� ���ؼ� ���� �Լ��̴�
	*  @pre		:
	*  @post	: ��ǥ����� �װ��� ����Ѵ�. 
	*/
	void gotoXY(int, int);
	/**
	*  @brief	: ������ ������
	*  @pre		: 
	*  @post	: ���������Կ� �߰��ȴ�
	*/
	int Send_Mail();
	/**
	*  @brief	: ���������Կ��� ����ڿ� �Է¹޾� �����Ѵ�.
	*  @pre		:
	*  @post	: 
	*/
	void Delete_Mail_Select();
	/**
	*  @brief	: ������������ ����Ѵ�.
	*  @pre		:
	*  @post	:
	*/
	void Display_Send_Mail();
	/**
	*  @brief	: ���ϻ����� �����ϴ� �� �����ϴ� �迭�� reset�Ѵ�
	*  @pre		:
	*  @post	: �迭�� ��� true�� �ʱ�ȭ �ȴ� 
	*/
	void Make_empty_arr();

	/**
	*  @brief	: ���������Կ��� ���� ������ ���
	*  @pre		:
	*  @post	: ���������Կ��� ���������� ������ �Ѱ��ִ� �Լ��� ������ ������ �� �Ͼ��
	*/
	void Gotogabage();
	/**
	*  @brief	: ���������Կ��� ������ ����Ѵ�.
	*  @pre		:
	*  @post	:
	*/
	void Displayrecentadress();

	/**
	*  @brief	: �ּҷϿ��� ���ο� ����� �Է¹ް� �߰��Ѵ�
	*  @pre		:
	*  @post	:
	*/

	void conatactadd();
	/**
	*  @brief	: �ּҷϿ��� ����� �����Ѵ�
	*  @pre		: 
	*  @post	: Ű���� ���� �Է¹��� �ʾƵ��ȴ�.
	*/
	void conatactdelete();
	/**
	*  @brief	: �ּҷϿ��� ����� ã�´�
	*  @pre		:
	*  @post	: ã������� ����Ѵ�. 
	*/
	void conatactsearch();
	/**
	*  @brief	: �ּҷϿ� ����� �����۵��� ��� ����Ѵ�. 
	*  @pre		:
	*  @post	:
	*/
	void printcontact();
	/**
	*  @brief	: �ֱ� ����� �ּҿ� ���ؼ� ������ ���� �����ϴ� �Լ� �̴�. 
	*  @pre		:
	*  @post	: �����ְų� �����ϴ� �ൿ�� �ϳ��� �����Ѵ�.
	*/
	void select_recent_address();
	/**
	*  @brief	:�ּҷϿ��� �ֱ� ����� �ּҸ� ����Ѵ�
	*  @pre		:
	*  @post	:�ֱٻ���ּҰ� ���� ��� 1 , ���� ��� 0�� �����ش�. 
	*/
	int printrecentaddress();
	/**
	*  @brief	: /�ֱٻ���� �ּҿ��� �ּҷ����� �����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void savecontactlist();
	/**
	*  @brief	: ���ϳ������� ������ ã�������� Ȯ���ϱ� ���ؼ� ����� �Լ�
	*  @pre		:
	*  @post	: ã���� true,�ƴϸ� false�� �����Ѵ�.
	*/
	bool IsThereFind(std::string data, std::string item);
	/**
	*  @brief	: ������ �����Ѵ�
	*  @pre		:
	*  @post	: ����ڿ� �Է¹��� �̸����� ������ �����ȴ�.
	*/
	void Make_folder();
	/**
	*  @brief	: ������ ����Ѵ�
	*  @pre		:
	*  @post	: ��� ���������� ����Ѵ�
	*/
	void Display_folder();
	/**
	*  @brief	: ������ �����Ѵ�
	*  @pre		:
	*  @post	: ����ڿ��� �Է¹��� �̸��� ������ �����Ѵ�
	*/
	void Delete_folder();
	/**
	*  @brief	: �������� ������ ��θ� �̵��Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void move_folder_path();
	/**
	*  @brief	: ������ ã�� �� ������ �Է¹޴´�
	*  @pre		:
	*  @post	: ã�� ��������� ����Ѵ�. 
	*/
	void find_mail_content();

	void take_mail_folder();


	/**
	*  @brief	:
	*  @pre		:
	*  @post	:
	*/
	void Load_Folder_List(MyFolder &temp);
	/**
	*  @brief	: �������� ã���� �ε����� �����ش�
	*  @pre		: �������� ���� �Է¹޴´�
	*  @post	: �ε������� ����������� ���� ���ϰ��� ���� �ǹ��Ѵ�
	*/
	int GetBinarySearch(string target, int& index);

	/**
	*  @brief	: ������ �̵��Ѵ�
	*  @pre		:
	*  @post	: ���� �����Կ��� ������ �����ؼ� ������ �̵���Ų��
	*/
	void Move_mail();
	/**
	*  @brief	: ������ �̵��Ѵ�.
	*  @pre		:
	*  @post	:
	*/
	void formoveMailList();
	/**
	*  @brief	: ������ �̵��Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void move_mail_path();

	/**
	*  @brief	: 2���� �迭�� �� ������ �����Ѵ�
	*  @pre		:
	*  @post	: �̸������� ���ĵ� ������ ����.
	*/
	void bubblesort();
private:


	hQueue<QltemType> m_hqueue;	//�ֱٻ���� �ּҸ� ������ ���� 
	BinarySearchTree<QltemType> contactlist;//�ּҷϿ��� ������ ���� 

	int m_Command;			///< current command number.

	LinkedList<ItemType> m_list; //������������ �����ϴ� ���� 

	LinkedList<ItemType> receivedmail; //������������ �����ϴ� ���� 
	LinkedList<ItemType> m_garbagmail;// �������� ������ �����ϴ� ����
	LinkedList<ItemType> deleteTempList_receive; // ����������, ���������� �����ϴ°� �ӽ÷� �����ϴ� ����

	DoublySortedLinkedList<ItemType> mail_temp_list;
	
	LinkedList<ItemType> receivedmail_temp1; //������������ �� �� ���� �ָ� ������ ���� 

	bool arr[100];// ���������Կ��� �����Ҹ����� ������ ���� 
	bool arr2[100];
	User currentUser;
	DoublySortedLinkedList<User> array_user;
	DoublySortedLinkedList<MyFolder> currentfolder;
	MyFolder allFolder;

	int number[26];
	ItemType* Mail_Name[26];
	int count = 0;

};

#endif	// _APPLICATION_H
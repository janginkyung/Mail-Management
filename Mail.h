#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublySortedLinkedList.h"
enum RelationType { LESS, GREATER, EQUAL };


/* @brief  ������ ������ Ÿ��*/
class ItemType
{

public:
	
	ItemType()//������
	{
		m_rec_Address = "";
		m_sContents = "";
		m_sDate = "";
		m_sLabel = "";
		m_sTitle = "";
		m_read_or_not = "";
		
	}


	~ItemType()//�Ҹ���
	{
		m_send_Address.MakeEmpty();
		reference_Address.MakeEmpty();
	}


	/**
	*  @brief	: ���������Կ����� �޴»���ּҸ� �޴� �����Կ����� ��������� �����ּҸ� �����޴´�
	*  @pre		: 
	*  @post	: 
	*/
	DoublySortedLinkedList<string> GetSendAddress();

	/**
	*  @brief	: ���������Կ����� �����ּҸ� �޴� �����Կ����� ���������ּҸ� �����޴´�
	*  @pre		: 
	*  @post	: 
	*/
	string GetRecAddress();

	/**
	*  @brief	: ������ ������ �����ش�.
	*  @pre		: ������ ������ �����Ǿ� �־�� �Ѵ�
	*  @post	: 
	*/
	string GetContents();

	/**
	*  @brief	: ������ ������ �����ش�.
	*  @pre		: ������ ������ �����Ǿ� �־�� �Ѵ�
	*  @post	:
	*/
	string GetDate();

	/**
	*  @brief	: ������ ���� �����ش�.
	*  @pre		: ������ ���� �����Ǿ� �־�� �Ѵ�
	*  @post	:
	*/
	string GetLabel();
	/**
	*  @brief	: ������ ������ �����ش�.
	*  @pre		: ������ ������ �����Ǿ� �־�� �Ѵ�
	*  @post	:
	*/
	string GetTitle();
	/**
	*  @brief	: ������ �о����� �ƴ��� �����ش�.
	*  @pre		: ������ ����ǥ�ð� �����Ǿ� �־�� �Ѵ�
	*  @post	:
	*/
	string GetReadornot(){ 
		return m_read_or_not; }
	/**
	*  @brief	: ������ �������� �����ش�
	*  @pre		: 
	*  @post	:�������� �����ϰ� �ִ� ����Ʈ�� �����ش�. 
	*/
	DoublySortedLinkedList<string> GetRefersendAddress();
	/**
	*  @brief	: ���������Կ����� �޴»���ּҸ� �޴� �����Կ����� ��������� �����ּҸ� �����Ѵ�
	*  @pre		: ��Ʈ������ �޾����� �Ѵ�
	*  @post	: ���ڿ��� �޸��� �����ؼ� ����Ʈ�� ������ �� �־�� �Ѵ�. 
	*/
	// @brief	��������� �ּҸ� ����
	void SetsendAddress(string a);
	/**
	*  @brief	: ���������Կ����� ��������� �ּҸ� �޴� �����Կ����� �޴»���� �����ּҸ� �����Ѵ�
	*  @pre		: ���ڿ����� �޾����� �Ѵ�
	*  @post	:
	*/
	void SetrecAddress(string a){ m_rec_Address = a; }
	/**
	*  @brief	: ������ ������ �����Ѵ�
	*  @pre		: ���ڿ����� �޾����� �Ѵ�
	*  @post	: �����̽���, Ư�����ڸ� ���� �� �ֵ��� �����ߴ�. 
	*/
	void SetContents(string a);
	/**
	*  @brief	: ������ ������¥�� �����Ѵ�
	*  @pre		: ���ڿ����� �޾����� �Ѵ�
	*  @post	: 
	*/
	void SetDate(string a);
	/**
	*  @brief	: ������ �������� �����ϴ� �Լ�
	*  @pre		: ���ڿ��� ���� �޾ƿ;� �Ѵ�
	*  @post	: �޸��� �����ؼ� ���ڸ� ����Ʈ�� ����Ǿ� ����. 
	*/
	void SetRefersendAddress(string  a);
	/**
	*  @brief	: ������ ���� �����Ѵ�.
	*  @pre		: 
	*  @post	:
	*/
	void SetLabel(string a);
	/**
	*  @brief	: ������ ������ �����ϴ� �Լ�
	*  @pre		: ���ڿ��� ���� �޾ƿ;� �Ѵ�
	*  @post	: 
	*/
	void SetTitle(string a);
	/**
	*  @brief	: ���������Կ����� ��������� �ּҸ� �޴� �����Կ����� �޴»���� �����ּҸ� ����Ѵ�. 
	*  @pre		: ����Ʈ�� ������ �Ǿ��־���Ѵ�. 
	*  @post	: ��ĭ���� �����ؼ� �������ΰ�� �����Ͽ� ����Ѵ� 
	*/
	void DisplaysAddressOnScreen();
	/**
	*  @brief	: ���������Կ����� ������ ���ϰ� �������� ����ϱ� ���� �Լ��� ������ ������ ����Ѵ� .
	*  @pre		: 
	*  @post	: 
	*/

	void Displaysimlplemail_send();
	/**
	*  @brief	: ������ ������¥ ����Ѵ�
	*  @pre		: 
	*  @post	: 
	*/
	void DisplayDateOnScreen();
	/**
	*  @brief	: ������ ������ ����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void DisplayContentsOnScreen();
	/**
	*  @brief	: ������ ���� ����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void DisplayLabelOnScreen();
	/**
	*  @brief	: ������ ������ ��� �Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void DisplayTitleOnScreen();
	/**
	*  @brief	: ������ �������� ����Ѵ�
	*  @pre		:
	*  @post	: ����Ʈ�� �� �������� ����Ѵ�
	*/
	
	void DisplayReferaddress();
	/**
	*  @brief	: ������ ����ǥ�ø� ����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void  DisplayReadornot(){ cout << "���� : " << m_read_or_not; }
	/**
	*  @brief	: ���������Կ��� ������ ������ ����ϴ� �Լ�
	*  @pre		:
	*  @post	: ���� ǥ�ÿ� ���������, ������ ª�� ��µȴ�. 
	*/
	void DisplayRecordOnDeleteScreen();
	/**
	*  @brief	: ������ ������ ���� ����Ѵ�. 
	*  @pre		:
	*  @post	:
	*/
	void DisplayRecordOnScreen();
	/**
	*  @brief	: ������ ������ ������ ����Ѵ�.
	*  @pre		:
	*  @post	:���� ǥ�ÿ� ������ ���, ��¥, ������ ������ �����ش�. 
	*/
	void Displaysimlplemail();
	/**
	*  @brief	: ������ ��������� �����Ѵ�
	*  @pre		:
	*  @post	: ������, �޴»��, ����ǥ��, ����� ��� �����ȴ�. 
	*/
	void SetRecord(string readornot, string a1, string a2, string a3, string a4, string a5, string referaddress);

	/**
	*  @brief	: ������ ����ǥ�ø� �����Ѵ�
	*  @pre		:
	*  @post	: 
	*/
	void Setread(string a);

	/**
	*  @brief	: ������ �������� Ű����κ��� �Է¹޾� �����Ѵ�
	*  @pre		:
	*  @post	: ���ڿ��� �Է¹޾� �޸��������� �ڸ����� ����Ʈ�� �����Ѵ�.
	*/
	void Setreferaddress_FromKB();

	/**
	*  @brief	: Ű����κ��� �����»�� �ּ� �����Ѵ�
	*  @pre		:
	*  @post	: ���ڿ��� �Է¹޾� �޸��������� �ڸ����� ����Ʈ�� �����Ѵ�.
	*/
	void SetsAddress_send_folder_FromKB();
	/**
	*  @brief	: Ű����κ��� �޴»�� �ּ� �����Ѵ�
	*  @pre		:
	*  @post	: 
	*/
	void SetsAddress_rec_folder_FromKB();
	/**
	*  @brief	: Ű����κ��� ������¥ ���� �Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void SetDateFromKB();
	/**
	*  @brief	: Ű����κ��� ���ϳ��� ���� �Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void SetContentsFromKB();
	/**
	*  @brief	: Ű����κ��� �� ���� �Ѵ�
	*  @pre		:
	*  @post	:
	*/

	void SetLabelFromKB();
	/**
	*  @brief	: Ű����κ��� ���� ���� �Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void SetTitleFromKB();
	/**
	*  @brief	: Ű����κ��� ��� ��������� ����
	*  @pre		:
	*  @post	:
	*/
	void SetRecordFromKB();
	/**
	*  @brief	: ���ϰ� ���Ҷ� ��¥�� �������� ���� ������ �����ε�
	*  @pre		: ������ ��¥�� �����Ǿ��־�� �񱳰���
	*  @post	: ū��� true, �ƴѰ�� false�� ����
	*/
	/* @brief  ��¥�� ���Ͽ� Ŭ��� . */
	bool operator > (ItemType t1);
	/**
	*  @brief	: ���ϰ� ���Ҷ� ��¥�� �������� ���� ������ �����ε�
	*  @pre		: ������ ��¥�� �����Ǿ��־�� �񱳰���
	*  @post	: ū��� true, �ƴѰ�� false�� ����
	*/
	/* @brief  ���� ��ü�� �Ȱ��� ���� ������ ������ش�. */
	void operator =(ItemType t1);
	/**
	*  @brief	: ������ ������ �ٸ� ��ü�� �־��ִ� ������ �����ε�
	*  @pre		: 
	*  @post	: �ڱ��ڽ��� ��������� �缳��
	*/
	bool operator == (ItemType t1);
	/**
	*  @brief	: ���ϰ� ���Ҷ� ��¥�� �������� ���� ������ �����ε�
	*  @pre		: ������ ��¥�� �����Ǿ��־�� �񱳰���
	*  @post	: ������� true, �ƴѰ�� false�� ����
	*/

	bool operator < (ItemType t1);






	/**
	*  @brief	: ���ϰ� ���Ҷ� ��¥�� �������� ���� ������ �����ε�
	*  @pre		: ������ ��¥�� �����Ǿ��־�� �񱳰���
	*  @post	: ������� true, �ƴѰ�� false�� ����
	*/


	void CopyRecord(ItemType data);








	/**
	*  @brief	: �ڷᱸ���� ���׸��ϰ� ����ϱ� ���ؼ� <<�����ڸ� �����ε�
	*  @pre		: 
	*  @post	: <<�� ���ؼ� ����ϴ� ���� �����ϴ�. 
	*/
	friend ostream& operator << (ostream&os, ItemType &item);

	/**
	*  @brief	: �������� �������� ��� ������� ����Ʈ�� �����ϴ¿���
	*  @pre		: ���ڿ��� �޾����� �Ѵ�
	*  @post	: ���ڿ��� �߶� �������� ����Ʈ�� �����Ѵ�. 
	*/
	void cutstring_referaddress(string sendaddress, int length);

	/**
	*  @brief	: �ּҰ� �������� ��� ����� ���� ī��Ʈ�ϴ� �Լ��̴�
	*  @pre		: ���ڿ��� �޾����� �Ѵ�
	*  @post	: ���ڿ��� �߶� �������� ����Ʈ�� �����Ѵ�.
	*/
	void cutstring_sendaddress(string sendaddress, int length);

	/**
	*  @brief	: ����� �޸��� ���еǾ� ������ �������� ��� ����� ���� ī��Ʈ�ϴ� �Լ��̴�
	*  @pre		: ���ڿ��� �޾����� �Ѵ�
	*  @post	: ���ڿ��� �߶� ������ �����Ѵ�
	*/
	int countaddress(string sendaddress);

protected:
	string m_sDate;		//���� ����Ͻð��ð�
	string m_rec_Address;//�޴»���� �����ּ�
	string m_sLabel; //label��
	string m_sTitle;//��������
	string m_sContents;//���ϳ���
	string m_read_or_not;//���� ǥ�� 
	DoublySortedLinkedList<string> m_send_Address;	//��������� �����ּ�
	DoublySortedLinkedList<string> reference_Address; //������ 
};

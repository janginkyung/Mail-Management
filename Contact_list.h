
#pragma once
#include <iostream>
#include <string>
using namespace std;

class QltemType
{
private:
	string name;//�̸�
	string address;//�ּ�
public:
	QltemType(){ name = " ";
	address = " ";
	}
	~QltemType(){} 

	/**
	*  @brief	: �̸��� �����Ѵ�
	*  @pre		: �̸��� �����Ǿ� �־�� �Ѵ�. 
	*  @post	:
	*/
	string Getname();
	/**
	*  @brief	: �ּҸ� �����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	string GetAddress();
	/**
	*  @brief	:Ű����κ��� ������� �����Ѵ�.
	*  @pre		:
	*  @post	:
	*/
	void SetFromKB();
	/**
	*  @brief	: �ּҸ� Ű����κ��� ����
	*  @pre		:
	*  @post	:
	*/
	void SetaddressFromKB();
	/**
	*  @brief	: Ű����κ��� �̸��� �����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void SetnameFromKB();
	/**
	*  @brief	: �ּҸ� ����Ѵ�.
	*  @pre		:
	*  @post	:
	*/
	void DisplayRecord_address_OnScreen();
	/**
	*  @brief	: ���� ���ڿ��� �ּҸ� �����Ѵ�.
	*  @pre		: ���ڿ��� �޾ƾ��Ѵ� 
	*  @post	:
	*/
	void setadress(string a);

	/**
	*  @brief	: ���� ���ڿ��� �̸��� �����Ѵ�
	*  @pre		: ���ڿ��� �޾ƾ��Ѵ� 
	*  @post	:
	*/
	void setName(string b);

	/**
	*  @brief	: ��� ��������� ����Ѵ�
	*  @pre		: ���� ����������� �����Ǿ� �־���Ѵ�. 
	*  @post	:
	*/
	void DisplayRecordOnScreen();





	/**
	*  @brief	: �ּҸ� ����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void DisplayAddressOnScreen();







	/**
	*  @brief	: �̸��� �ּҸ� ����Ѵ�. 
	*  @pre		:
	*  @post	:
	*/
	void DisplayRecord_recent_OnScreen();
	/**
	*	@brief  �̸��� ���ų� �ּҰ� ������ ==�϶� ���������� �Ǵ��Ѵ�
	*	@pre	� Ű�� ���ϴ��� ���ؾ��Ѵ�
	*	@post	������ true, �ƴϸ� false�� �����Ѵ�. 
	*/
	bool operator == (QltemType t1);
	/**
	*	@brief	��ü�� �����Ѵ�
	*	@pre	� Ű�� ���ϴ��� ���ؾ��Ѵ�
	*	@post	this�� ��ü�� ���� t1�� �Ȱ��� ���� ������
	*/
	void  operator =(QltemType t1);

	/**
	*  @brief	: ��ü�� �̸����� ���Ѵ�
	*  @pre		: � Ű�� ���ϴ��� ���ؾ��Ѵ� 
	*  @post	: this�� ��ü�� ���� t1���� ���� ��� true, �ƴѰ�� false�� �����Ѵ� 
	*/
	bool operator <(QltemType t1);

	/**
	*  @brief	: ��ü�� �̸����� ���Ѵ�
	*  @pre		: � Ű�� ���ϴ��� ���ؾ��Ѵ�
	*  @post	: this�� ��ü�� ���� t1���� ū ��� true, �ƴѰ�� false�� �����Ѵ� 
	*/
	bool operator >(QltemType t1);

	/**
	*  @brief	: <<�� �����ڿ� ���� �����ε�
	*  @pre		:
	*  @post	: �������� ����Ѵ�. 
	*/
	friend ostream& operator << (ostream&os, QltemType &item);
	};
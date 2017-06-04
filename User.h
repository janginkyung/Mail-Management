#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {

public:
	User(void){};//������
	~User(void){};//�Ҹ���
	/**
	*  @brief	: ��ü�� �ʱ�ȭ ��Ų��
	*  @pre		:
	*  @post	: �ʱ�ȯ ��ü�� �����ش�
	*/
	User(string _id, string _pw, string _name){

	};
	/**
	*  @brief	: ������ id�� �����ش�
	*  @pre		:
	*  @post	:
	*/
	string get_userId(){ return email; }
	/**
	*  @brief	: ������ ��й�ȣ�� �����ش�
	*  @pre		:
	*  @post	:
	*/	
	string get_userPw(){ return password; }	
	/**
	*  @brief	: �̸� ����
	*  @pre		:
	*  @post	:
	*/
	string get_userName(){ return name; }	
	/**
	*  @brief	: �ּ��� ������ �����ش�
	*  @pre		:
	*  @post	:
	*/
	int get_addressNum() { return addressNum; }
	/**
	*  @brief	: �ּҸ� �����ش�
	*  @pre		:
	*  @post	:
	*/
	string get_address(int i) { return addressList[i]; }
	
	/**
	*  @brief	: ���̵� �����Ѵ�
	*  @pre		: ���̵� ���� �Է¹޾ƾ��Ѵ�
	*  @post	:
	*/
	void set_userId(string _id){ email = _id; };	
	/**
	*  @brief	: ��й�ȣ�� �����Ѵ�
	*  @pre		: ��й�ȣ�� ���� �����ؾ��Ѵ�
	*  @post	:
	*/
	void set_userPw(string _password){ password = _password; };	
	/**
	*  @brief	: �̸��� �Է¹޾ƾ��Ѵ�
	*  @pre		: �̸��� ���� �Է¹޾ƾ��Ѵ�
	*  @post	:
	*/
	void set_userName(string _name){ name = _name; };	
	/**
	*  @brief	: �ּ��� ������ �����Ѵ�
	*  @pre		: ������ ���� �����Ǿ���Ѵ�
	*  @post	:
	*/
	void set_addressNum(int _addressNum) { addressNum = _addressNum; }
	/**
	*  @brief	: �ּҸ� �����Ѵ�
	*  @pre		:
	*  @post	:
	*/
	void set_address(int i, string address) { addressList[i] = address; }
	/**
	*  @brief	: �̸����� ������ �����ε�
	*  @pre		:
	*  @post	: ���� �̸��� �� ũ�� true,�ƴѰ�� false�̴�.
	*/
	bool operator>(User t)
	{	
		if (name.compare(t.get_userName()) < 0)
				return true;
			else
				return false;

	}
	/**
	*  @brief	: �̸����� ������ �����ε�
	*  @pre		:
	*  @post	: ���� �̸��� ������ true,�ƴѰ�� false�̴�.
	*/
	bool operator==(User t){
		if ((this->email == t.email && this->password == t.password) || this->name.compare(t.name) == 0)
		{
			if (t.get_userId() == "")
				return true;
			else
			{
				if (this->email == t.email)
					return true;
				else
					return false;
			}
		}
		else
			return false;
	}
	/**
	*  @brief	: ���� ��ü�� ������ �ʱ�ȭ�Ѵ�
	*  @pre		: ��ü�� �ʱ�ȭ�Ǿ��־���Ѵ�
	*  @post	: this��ü�� ���°�ü�� ���� ������ ������
	*/
	User operator=(User t)
	{
		this->email = t.get_userId();
		this->password = t.get_userPw();
		this->name = t.get_userName();
		this->addressNum = t.get_addressNum();
		for (int i = 0; i < addressNum; i++) {
			this->addressList[i] = t.get_address(i);
		}
		return *this;
	}

private:
	string email;// ���̵�
	string password;//��й�ȣ
	string name;//�̸�
	int addressNum;//�ּ��ǰ���
	string addressList[15];//�ּ�

};
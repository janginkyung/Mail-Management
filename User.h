#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {

public:
	User(void){};//생성자
	~User(void){};//소멸자
	/**
	*  @brief	: 객체를 초기화 시킨다
	*  @pre		:
	*  @post	: 초기환 객체를 돌려준다
	*/
	User(string _id, string _pw, string _name){

	};
	/**
	*  @brief	: 유저의 id를 돌려준다
	*  @pre		:
	*  @post	:
	*/
	string get_userId(){ return email; }
	/**
	*  @brief	: 유저의 비밀번호를 돌려준다
	*  @pre		:
	*  @post	:
	*/	
	string get_userPw(){ return password; }	
	/**
	*  @brief	: 이름 리턴
	*  @pre		:
	*  @post	:
	*/
	string get_userName(){ return name; }	
	/**
	*  @brief	: 주소의 갯수를 돌려준다
	*  @pre		:
	*  @post	:
	*/
	int get_addressNum() { return addressNum; }
	/**
	*  @brief	: 주소를 돌려준다
	*  @pre		:
	*  @post	:
	*/
	string get_address(int i) { return addressList[i]; }
	
	/**
	*  @brief	: 아이디를 설정한다
	*  @pre		: 아이디를 먼저 입력받아야한다
	*  @post	:
	*/
	void set_userId(string _id){ email = _id; };	
	/**
	*  @brief	: 비밀번호를 설정한다
	*  @pre		: 비밀번호를 먼저 설정해야한다
	*  @post	:
	*/
	void set_userPw(string _password){ password = _password; };	
	/**
	*  @brief	: 이름을 입력받아야한다
	*  @pre		: 이름을 먼저 입력받아야한다
	*  @post	:
	*/
	void set_userName(string _name){ name = _name; };	
	/**
	*  @brief	: 주소의 갯수를 설정한다
	*  @pre		: 갯수가 먼저 설정되어야한다
	*  @post	:
	*/
	void set_addressNum(int _addressNum) { addressNum = _addressNum; }
	/**
	*  @brief	: 주소를 설정한다
	*  @pre		:
	*  @post	:
	*/
	void set_address(int i, string address) { addressList[i] = address; }
	/**
	*  @brief	: 이름으로 연산자 오버로딩
	*  @pre		:
	*  @post	: 나의 이름이 더 크면 true,아닌경우 false이다.
	*/
	bool operator>(User t)
	{	
		if (name.compare(t.get_userName()) < 0)
				return true;
			else
				return false;

	}
	/**
	*  @brief	: 이름으로 연산자 오버로딩
	*  @pre		:
	*  @post	: 나의 이름과 같으면 true,아닌경우 false이다.
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
	*  @brief	: 들어온 객체의 정보로 초기화한다
	*  @pre		: 객체가 초기화되어있어야한다
	*  @post	: this객체가 들어온객체와 같은 정보를 가진다
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
	string email;// 아이디
	string password;//비밀번호
	string name;//이름
	int addressNum;//주소의갯수
	string addressList[15];//주소

};

#pragma once
#include <iostream>
#include <string>
using namespace std;

class QltemType
{
private:
	string name;//이름
	string address;//주소
public:
	QltemType(){ name = " ";
	address = " ";
	}
	~QltemType(){} 

	/**
	*  @brief	: 이름을 리턴한다
	*  @pre		: 이름이 설정되어 있어야 한다. 
	*  @post	:
	*/
	string Getname();
	/**
	*  @brief	: 주소를 리턴한다
	*  @pre		:
	*  @post	:
	*/
	string GetAddress();
	/**
	*  @brief	:키보드로부터 멤버변수 설정한다.
	*  @pre		:
	*  @post	:
	*/
	void SetFromKB();
	/**
	*  @brief	: 주소를 키보드로부터 설정
	*  @pre		:
	*  @post	:
	*/
	void SetaddressFromKB();
	/**
	*  @brief	: 키보드로부터 이름을 설정한다
	*  @pre		:
	*  @post	:
	*/
	void SetnameFromKB();
	/**
	*  @brief	: 주소만 출력한다.
	*  @pre		:
	*  @post	:
	*/
	void DisplayRecord_address_OnScreen();
	/**
	*  @brief	: 받은 문자열로 주소를 설정한다.
	*  @pre		: 문자열을 받아야한다 
	*  @post	:
	*/
	void setadress(string a);

	/**
	*  @brief	: 받은 문자열로 이름을 설정한다
	*  @pre		: 문자열을 받아야한다 
	*  @post	:
	*/
	void setName(string b);

	/**
	*  @brief	: 모든 멤버변수를 출력한다
	*  @pre		: 먼저 멤버변수들이 설정되어 있어야한다. 
	*  @post	:
	*/
	void DisplayRecordOnScreen();





	/**
	*  @brief	: 주소를 출력한다
	*  @pre		:
	*  @post	:
	*/
	void DisplayAddressOnScreen();







	/**
	*  @brief	: 이름과 주소를 출력한다. 
	*  @pre		:
	*  @post	:
	*/
	void DisplayRecord_recent_OnScreen();
	/**
	*	@brief  이름이 같거나 주소가 같으면 ==일때 같은것으로 판단한다
	*	@pre	어떤 키로 비교하는지 정해야한다
	*	@post	같으면 true, 아니면 false를 리턴한다. 
	*/
	bool operator == (QltemType t1);
	/**
	*	@brief	객체를 복사한다
	*	@pre	어떤 키로 비교하는지 정해야한다
	*	@post	this의 객체가 들어온 t1랑 똑같은 값을 가진다
	*/
	void  operator =(QltemType t1);

	/**
	*  @brief	: 객체를 이름으로 비교한다
	*  @pre		: 어떤 키로 비교하는지 정해야한다 
	*  @post	: this의 객체가 들어온 t1보다 작을 경우 true, 아닌경우 false를 리턴한다 
	*/
	bool operator <(QltemType t1);

	/**
	*  @brief	: 객체를 이름으로 비교한다
	*  @pre		: 어떤 키로 비교하는지 정해야한다
	*  @post	: this의 객체가 들어온 t1보다 큰 경우 true, 아닌경우 false를 리턴한다 
	*/
	bool operator >(QltemType t1);

	/**
	*  @brief	: <<의 연산자에 대한 오버로딩
	*  @pre		:
	*  @post	: 아이템을 출력한다. 
	*/
	friend ostream& operator << (ostream&os, QltemType &item);
	};
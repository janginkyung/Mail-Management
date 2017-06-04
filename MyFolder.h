
#pragma once
#include "DoublySortedLinkedList.h"
#include "Sorted_List.h"
#include "Mail.h"
#include "User.h"
#include <direct.h>

class MyFolder
{
public:
	MyFolder( );//생성자
	~MyFolder();//소멸자 
	/**
	*  @brief	: 폴더의 이름을 돌려준다
	*  @pre		:
	*  @post	:
	*/
	string Getfilename() { return file_name; }
	/**
	*  @brief	: 폴더의 이름을 지정한다
	*  @pre		: 문자열을 먼저 받아야한다
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
	*  @brief	: 메일을 추가시킨다
	*  @pre		: 메일이 먼저 설정되어 있어야한다.
	*  @post	:
	*/
	void Setmails(DoublySortedLinkedList<ItemType> another);
	/**
	*  @brief	: 메일의 리스트를 돌려준다. 
	*  @pre		:
	*  @post	:
	*/
	DoublySortedLinkedList<ItemType> Getmails();
	/**
	*  @brief	: 폴더 안에 존재하는 메일과 서브폴더를 출력하는 기능을 한다. 
	*  @pre		: 지시자가 reset되어 있어야한다. 
	*  @post	:
	*/
	void Displayall();
	/**
	*  @brief	: 메일을 추가한다.
	*  @pre		: 메일이 초기화가 되어있어야한다. 
	*  @post	:
	*/
	void Add_mail(ItemType test);
	/**
	*  @brief	: 폴더 안에서 서브폴더를 만든다.
	*  @pre		: 서브폴더의 내용이 설정이 되어있어야 한다. 
	*  @post	:
	*/
	void Add_subfolder(MyFolder subfolder);

	/**
	*  @brief	: 메일을 출력한다. 
	*  @pre		: 메일을 가리키는 지시자가 reset되어야한다. 
	*  @post	:
	*/
	void PrintMail();
	/**
	*  @brief	: 폴더를 출력한다
	*  @pre		: 폴더를 가리키는 지시자가 reset되어야 한다. 
	*  @post	:
	*/
	void PrintFolder();
	/**
	*  @brief	: 파일 입출력을 한다. 
	*  @pre		:
	*  @post	:
	*/
	int ReadDataFromFile(ifstream& fin);
	/**
	*  @brief	: 폴더의 이름으로 비교하는 연산자 오버로딩
	*  @pre		:
	*  @post	: this객체의 폴더이름이 클경우 true를 아니면 false를 리턴한다. 
	*/
	bool operator > (MyFolder t1);
	/**
	*  @brief	: 들어온 객체랑 똑같은 값을 갖도록 만들어주는 연산자 오버로딩이다.
	*  @pre		: t1의 객체가 초기화가 되어있어야한다
	*  @post	: 멤버변수가 모두 t1과 같은 값을 갖는다. 
	*/
	void operator =(MyFolder t1);
	/**
	*  @brief	: 폴더의 이름으로 비교하는 연산자 오버로딩
	*  @pre		: 폴더의 이름이 t1,이 지정이 되어있어야한다.
	*  @post	: 이름이 같으면 true를 아니면 false를 리턴한다. 
	*/
	/* @brief 날짜로 비교했을 떄 같으면 참을 돌려준다 */
	bool operator == (MyFolder t1);
	/**
	*  @brief	: 폴더의 이름으로 비교하는 연산자 오버로딩
	*  @pre		: 폴더의 이름이 t1,이 지정이 되어있어야한다
	*  @post	: 이름이 t1이 더 크면 true를 아니면 false를 리턴한다. 
	*/
	bool operator < (MyFolder t1);

	DoublySortedLinkedList<MyFolder> *fos; //폴더 안에서 서브폴더를 갖기위해서 저장하는 변수 
	DoublySortedLinkedList<ItemType> Mails;//사용자에 의해 옮겨지는 메일
private:
	
	string file_name; //지금 폴더의 이름
	

};



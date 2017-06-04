#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

#include "DoublySortedLinkedList.h"
enum RelationType { LESS, GREATER, EQUAL };


/* @brief  메일의 아이템 타입*/
class ItemType
{

public:
	
	ItemType()//생성자
	{
		m_rec_Address = "";
		m_sContents = "";
		m_sDate = "";
		m_sLabel = "";
		m_sTitle = "";
		m_read_or_not = "";
		
	}


	~ItemType()//소멸자
	{
		m_send_Address.MakeEmpty();
		reference_Address.MakeEmpty();
	}


	/**
	*  @brief	: 보낸메일함에서는 받는사람주소를 받는 메일함에서는 보낸사람의 메일주소를 돌려받는다
	*  @pre		: 
	*  @post	: 
	*/
	DoublySortedLinkedList<string> GetSendAddress();

	/**
	*  @brief	: 보낸메일함에서는 보낸주소를 받는 메일함에서는 받은메일주소를 돌려받는다
	*  @pre		: 
	*  @post	: 
	*/
	string GetRecAddress();

	/**
	*  @brief	: 메일의 내용을 돌려준다.
	*  @pre		: 메일의 내용이 설정되어 있어야 한다
	*  @post	: 
	*/
	string GetContents();

	/**
	*  @brief	: 메일의 내용을 돌려준다.
	*  @pre		: 메일의 내용이 설정되어 있어야 한다
	*  @post	:
	*/
	string GetDate();

	/**
	*  @brief	: 메일의 라벨을 돌려준다.
	*  @pre		: 메일의 라벨이 설정되어 있어야 한다
	*  @post	:
	*/
	string GetLabel();
	/**
	*  @brief	: 메일의 제목을 돌려준다.
	*  @pre		: 메일의 제목이 설정되어 있어야 한다
	*  @post	:
	*/
	string GetTitle();
	/**
	*  @brief	: 메일의 읽었는지 아닌지 돌려준다.
	*  @pre		: 메일의 읽음표시가 설정되어 있어야 한다
	*  @post	:
	*/
	string GetReadornot(){ 
		return m_read_or_not; }
	/**
	*  @brief	: 메일의 참조인을 돌려준다
	*  @pre		: 
	*  @post	:참조인을 저장하고 있는 리스트로 돌려준다. 
	*/
	DoublySortedLinkedList<string> GetRefersendAddress();
	/**
	*  @brief	: 보낸메일함에서는 받는사람주소를 받는 메일함에서는 보낸사람의 메일주소를 설정한다
	*  @pre		: 스트링으로 받아져야 한다
	*  @post	: 문자열을 콤마로 구분해서 리스트에 저장할 수 있어야 한다. 
	*/
	// @brief	보낸사람의 주소를 설정
	void SetsendAddress(string a);
	/**
	*  @brief	: 보낸메일함에서는 보낸사람의 주소를 받는 메일함에서는 받는사람의 메일주소를 설정한다
	*  @pre		: 문자열으로 받아져야 한다
	*  @post	:
	*/
	void SetrecAddress(string a){ m_rec_Address = a; }
	/**
	*  @brief	: 메일의 내용을 설정한다
	*  @pre		: 문자열으로 받아져야 한다
	*  @post	: 스페이스바, 특수문자를 받을 수 있도로 설계했다. 
	*/
	void SetContents(string a);
	/**
	*  @brief	: 메일의 받은날짜를 설정한다
	*  @pre		: 문자열으로 받아져야 한다
	*  @post	: 
	*/
	void SetDate(string a);
	/**
	*  @brief	: 메일의 참조인을 설정하는 함수
	*  @pre		: 문자열을 먼저 받아와야 한다
	*  @post	: 콤마로 구분해서 문자를 리스트에 저장되어 진다. 
	*/
	void SetRefersendAddress(string  a);
	/**
	*  @brief	: 메일의 라벨을 설정한다.
	*  @pre		: 
	*  @post	:
	*/
	void SetLabel(string a);
	/**
	*  @brief	: 메일의 제목을 설정하는 함수
	*  @pre		: 문자열을 먼저 받아와야 한다
	*  @post	: 
	*/
	void SetTitle(string a);
	/**
	*  @brief	: 보낸메일함에서는 보낸사람의 주소를 받는 메일함에서는 받는사람의 메일주소를 출력한다. 
	*  @pre		: 리스트에 저장이 되어있어야한다. 
	*  @post	: 빈칸으로 구분해서 여러명인경우 구분하여 출력한다 
	*/
	void DisplaysAddressOnScreen();
	/**
	*  @brief	: 보낸메일함에서는 메일을 상세하게 보기전에 출력하기 위한 함수로 간단한 내용을 출력한다 .
	*  @pre		: 
	*  @post	: 
	*/

	void Displaysimlplemail_send();
	/**
	*  @brief	: 메일의 받은날짜 출력한다
	*  @pre		: 
	*  @post	: 
	*/
	void DisplayDateOnScreen();
	/**
	*  @brief	: 메일의 내용을 출력한다
	*  @pre		:
	*  @post	:
	*/
	void DisplayContentsOnScreen();
	/**
	*  @brief	: 메일의 라벨을 출력한다
	*  @pre		:
	*  @post	:
	*/
	void DisplayLabelOnScreen();
	/**
	*  @brief	: 메일의 제목을 출력 한다
	*  @pre		:
	*  @post	:
	*/
	void DisplayTitleOnScreen();
	/**
	*  @brief	: 메일의 참조인을 출력한다
	*  @pre		:
	*  @post	: 리스트로 된 참조인을 출력한다
	*/
	
	void DisplayReferaddress();
	/**
	*  @brief	: 메일의 읽음표시를 출력한다
	*  @pre		:
	*  @post	:
	*/
	void  DisplayReadornot(){ cout << "읽음 : " << m_read_or_not; }
	/**
	*  @brief	: 보낸메일함에서 삭제할 메일을 출력하는 함수
	*  @pre		:
	*  @post	: 읽음 표시와 보낸사람및, 내용이 짧게 출력된다. 
	*/
	void DisplayRecordOnDeleteScreen();
	/**
	*  @brief	: 메일의 내용을 상세히 출력한다. 
	*  @pre		:
	*  @post	:
	*/
	void DisplayRecordOnScreen();
	/**
	*  @brief	: 메일의 내용을 간략히 출력한다.
	*  @pre		:
	*  @post	:읽음 표시와 보내는 사람, 날짜, 간략한 내용을 보여준다. 
	*/
	void Displaysimlplemail();
	/**
	*  @brief	: 메일의 멤버변수를 설정한다
	*  @pre		:
	*  @post	: 참조인, 받는사람, 읽음표시, 등등이 모두 설정된다. 
	*/
	void SetRecord(string readornot, string a1, string a2, string a3, string a4, string a5, string referaddress);

	/**
	*  @brief	: 메일의 읽음표시를 설정한다
	*  @pre		:
	*  @post	: 
	*/
	void Setread(string a);

	/**
	*  @brief	: 메일의 참조인을 키보드로부터 입력받아 설정한다
	*  @pre		:
	*  @post	: 문자열을 입력받아 콤마기준으로 자른다음 리스트에 저장한다.
	*/
	void Setreferaddress_FromKB();

	/**
	*  @brief	: 키보드로부터 보내는사람 주소 설정한다
	*  @pre		:
	*  @post	: 문자열을 입력받아 콤마기준으로 자른다음 리스트에 저장한다.
	*/
	void SetsAddress_send_folder_FromKB();
	/**
	*  @brief	: 키보드로부터 받는사람 주소 설정한다
	*  @pre		:
	*  @post	: 
	*/
	void SetsAddress_rec_folder_FromKB();
	/**
	*  @brief	: 키보드로부터 받은날짜 설정 한다
	*  @pre		:
	*  @post	:
	*/
	void SetDateFromKB();
	/**
	*  @brief	: 키보드로부터 메일내용 설정 한다
	*  @pre		:
	*  @post	:
	*/
	void SetContentsFromKB();
	/**
	*  @brief	: 키보드로부터 라벨 설정 한다
	*  @pre		:
	*  @post	:
	*/

	void SetLabelFromKB();
	/**
	*  @brief	: 키보드로부터 제목 설정 한다
	*  @pre		:
	*  @post	:
	*/
	void SetTitleFromKB();
	/**
	*  @brief	: 키보드로부터 모든 멤버변수를 설정
	*  @pre		:
	*  @post	:
	*/
	void SetRecordFromKB();
	/**
	*  @brief	: 메일간 비교할때 날짜를 기준으로 비교한 연산자 오버로딩
	*  @pre		: 메일의 날짜가 설정되어있어야 비교가능
	*  @post	: 큰경우 true, 아닌경우 false를 리턴
	*/
	/* @brief  날짜로 비교하여 클경우 . */
	bool operator > (ItemType t1);
	/**
	*  @brief	: 메일간 비교할때 날짜를 기준으로 비교한 연산자 오버로딩
	*  @pre		: 메일의 날짜가 설정되어있어야 비교가능
	*  @post	: 큰경우 true, 아닌경우 false를 리턴
	*/
	/* @brief  들어온 객체랑 똑같은 값을 갖도록 만들어준다. */
	void operator =(ItemType t1);
	/**
	*  @brief	: 메일을 복사해 다른 객체에 넣어주는 연산자 오버로딩
	*  @pre		: 
	*  @post	: 자기자신의 멤버변수가 재설정
	*/
	bool operator == (ItemType t1);
	/**
	*  @brief	: 메일간 비교할때 날짜를 기준으로 비교한 연산자 오버로딩
	*  @pre		: 메일의 날짜가 설정되어있어야 비교가능
	*  @post	: 작은경우 true, 아닌경우 false를 리턴
	*/

	bool operator < (ItemType t1);






	/**
	*  @brief	: 메일간 비교할때 날짜를 기준으로 비교한 연산자 오버로딩
	*  @pre		: 메일의 날짜가 설정되어있어야 비교가능
	*  @post	: 같은경우 true, 아닌경우 false를 리턴
	*/


	void CopyRecord(ItemType data);








	/**
	*  @brief	: 자료구조에 제네릭하게 사용하기 위해서 <<연산자를 오버로딩
	*  @pre		: 
	*  @post	: <<를 통해서 출력하는 것이 가능하다. 
	*/
	friend ostream& operator << (ostream&os, ItemType &item);

	/**
	*  @brief	: 참조인이 여려명일 경우 사람마다 리스트에 저장하는역할
	*  @pre		: 문자열이 받아저야 한다
	*  @post	: 문자열을 잘라서 참조인의 리스트에 저장한다. 
	*/
	void cutstring_referaddress(string sendaddress, int length);

	/**
	*  @brief	: 주소가 여려명일 경우 사람의 수를 카운트하는 함수이다
	*  @pre		: 문자열이 받아저야 한다
	*  @post	: 문자열을 잘라서 참조인의 리스트에 저장한다.
	*/
	void cutstring_sendaddress(string sendaddress, int length);

	/**
	*  @brief	: 사람이 콤마로 구분되어 있을때 여려명일 경우 사람의 수를 카운트하는 함수이다
	*  @pre		: 문자열이 받아저야 한다
	*  @post	: 문자열을 잘라서 갯수를 리턴한다
	*/
	int countaddress(string sendaddress);

protected:
	string m_sDate;		//받은 년월일시간시간
	string m_rec_Address;//받는사람의 메일주소
	string m_sLabel; //label명
	string m_sTitle;//메일제목
	string m_sContents;//메일내용
	string m_read_or_not;//읽음 표시 
	DoublySortedLinkedList<string> m_send_Address;	//보낸사람의 메일주소
	DoublySortedLinkedList<string> reference_Address; //참조인 
};

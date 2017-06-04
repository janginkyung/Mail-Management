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
	@brief application class를 통해 앞의 자료를 통해 동작을 수행하는 함수들을 만든다.
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
	*  @brief	: 회원가입,로그인,아이디비밀번호찾기중 어느것을 할지 입력받는다.
	*  @pre		:
	*  @post	:
	*/
	void LogIn();
	/**
	*  @brief	: 회원가입하는 함수 
	*  @pre		:
	*  @post	: 아이디로 폴더 생성
	*/
	void registerin();
	/**
	*  @brief	: 아이디와 패스워드를 입력받는 함수
	*  @pre		: txt에 아이디와 비밀번호가 입력되어있어야한다.
	*  @post	: 다를시에 다시 입력받고 맞는 경우 파일입출력이 실행된다
	*/
	void idpw();
	/**
	*  @brief	: txt파일에 있는 유저들을 다 로드한다
	*  @pre		:
	*  @post	:
	*/
	void load_user();
	/**
	*  @brief	: 아이디와 비밀번호중 찾을 것을 선택한다.
	*  @pre		: txt에 먼저 입력이 되어있어야한다
	*  @post	: 
	*/
	void Found_idpw();
	/**
	*  @brief	: 아이디를 찾아주는 함수이다
	*  @pre		: txt에 먼저 입력이 되어있어야한다
	*  @post	: 이름에따른 아이디를 출력한다
	*/
	void Found_id();
	/**
	*  @brief	: 비밀번호를 찾아주는 함수이다
	*  @pre		: txt에 먼저 입력이 되어있어야한다
	*  @post	: 이름과 아이디에 따른 비밀번호를 출력한다
	*/
	void Found_pw();
	/**
	*  @brief	: 메일함을 선택한다.
	*  @pre		: 로그인이 먼저 되어야한다
	*  @post	: 선택 폴더함으로 들어간다.
	*/
	void select_mail_forder();
	/**
	*  @brief	: 받은 메일함으로 들어간다.
	*  @pre		:
	*  @post	:
	*/
	void received_mail_folder();
	/**
	*  @brief	: 보낸메일함으로 들어간다
	*  @pre		:
	*  @post	:
	*/
	void send_mail_folder();
	/**
	*  @brief	: 주소록으로 들어간다
	*  @pre		:
	*  @post	:
	*/

	void contact_folder();
	/**
	*  @brief	:휴지통 으로 들어간다
	*  @pre		:
	*  @post	:
	*/
	void garbage_mail_folder();
	/**
	*  @brief	:폴더생성하는 메뉴로 들어간다.
	*  @pre		:
	*  @post	:
	*/
	void make_folder();
	/**
	*  @brief	: 보낸주소함로 들어가 행동을 입력받는다
	*  @pre		:
	*  @post	: 사용자가 정수로 한가지를 선택한것을 돌려준다.
	*/
	int received_mail_command();
	/**
	*  @brief	: 보낸메일함으로 들어가서 행동을 입력받는다
	*  @pre		:
	*  @post	: 사용자가 정수로 한가지를 선택한것을 돌려준다.
	*/
	int send_mail_command();
	/**
	*  @brief	:주소록으로 들어가 행동을 입력받는다 
	*  @pre		:
	*  @post	: 사용자가 정수로 한가지를 선택한것을 돌려준다.
	*/
	int contact_folder_command();
	/**
	*  @brief	: 휴지통으로 들어가 행동을 입력받는다
	*  @pre		:
	*  @post	: 사용자가 정수로 한가지를 선택한것을 돌려준다.
	*/
	int  garbage_mail_folder_command();
	/**
	*  @brief	: 폴더생성으로 들어가 행동을 입력받는다
	*  @pre		:
	*  @post	: 사용자가 정수로 한가지를 선택한것을 돌려준다.
	*/
	int  make_folder_command();
	/**
	*  @brief	: 받은 메일함에서 메일을 삭제한다
	*  @pre		: 저장된 메일이 있어야한다
	*  @post	: 엔터로 선택하고 스페이스바로 삭제한다. 
	*/
	void deletereceivedmail();
	/**
	*  @brief	: 안읽는 메일중에서 보낸주소로 찾는다
	*  @pre		:
	*  @post	: 찾은 결과를 출력한다
	*/
	void findmail_name();
	/**
	*  @brief	: 안읽은 메일을 가려낸다.
	*  @pre		:
	*  @post	:
	*/
	void findmail_read();
	/**
	*  @brief	: 안읽은 메일 중에 이름으로 찾는다.
	*  @pre		:
	*  @post	: 
	*/
	void findmail_read_name();
	/**
	*  @brief	:받은 메일함에서 보낸주소로 찾는다
	*  @pre		:
	*  @post	:
	*/
	void findmailbyaddress(); 
	/**
	*  @brief	: 휴지통에 있는 메일을 출력한다
	*  @pre		:
	*  @post	:
	*/
	void printgarbagemail();
	/**
	*  @brief	: 휴지통에서 보낸메일함으로 메일을 보낸다
	*  @pre		:
	*  @post	: 메일을 선택해서 보낸메일함으로 들어간다. 
	*/
	void Gobacktosendmail();
	/**
	*  @brief	: 휴지통에서 메일을 삭제한다
	*  @pre		:
	*  @post	:
	*/
	void deletegarbagemail();
	/**
	*  @brief	: 방향키로 조절하기 위해서 쓰는 함수이다
	*  @pre		:
	*  @post	: 좌표를찍어 그곳에 출력한다. 
	*/
	void gotoXY(int, int);
	/**
	*  @brief	: 메일을 보낸다
	*  @pre		: 
	*  @post	: 보낸메일함에 추가된다
	*/
	int Send_Mail();
	/**
	*  @brief	: 보낸메일함에서 사용자에 입력받아 삭제한다.
	*  @pre		:
	*  @post	: 
	*/
	void Delete_Mail_Select();
	/**
	*  @brief	: 보낸메일함을 출력한다.
	*  @pre		:
	*  @post	:
	*/
	void Display_Send_Mail();
	/**
	*  @brief	: 메일삭제시 선택하는 걸 결정하는 배열을 reset한다
	*  @pre		:
	*  @post	: 배열이 모두 true로 초기화 된다 
	*/
	void Make_empty_arr();

	/**
	*  @brief	: 보낸메일함에서 메일 삭제시 사용
	*  @pre		:
	*  @post	: 보낸메일함에서 휴지통으로 메일을 넘겨주는 함수로 메일을 삭제할 떄 일어난다
	*/
	void Gotogabage();
	/**
	*  @brief	: 받은메일함에서 메일을 출력한다.
	*  @pre		:
	*  @post	:
	*/
	void Displayrecentadress();

	/**
	*  @brief	: 주소록에서 새로운 사람을 입력받고 추가한다
	*  @pre		:
	*  @post	:
	*/

	void conatactadd();
	/**
	*  @brief	: 주소록에서 사람을 삭제한다
	*  @pre		: 
	*  @post	: 키값은 따로 입력받지 않아도된다.
	*/
	void conatactdelete();
	/**
	*  @brief	: 주소록에서 사람을 찾는다
	*  @pre		:
	*  @post	: 찾은결과를 출력한다. 
	*/
	void conatactsearch();
	/**
	*  @brief	: 주소록에 저장된 아이템들을 모두 출력한다. 
	*  @pre		:
	*  @post	:
	*/
	void printcontact();
	/**
	*  @brief	: 최근 사용한 주소에 대해서 무엇을 할지 실행하는 함수 이다. 
	*  @pre		:
	*  @post	: 보여주거나 저장하는 행동중 하나를 선택한다.
	*/
	void select_recent_address();
	/**
	*  @brief	:주소록에서 최근 사용한 주소를 출력한다
	*  @pre		:
	*  @post	:최근사용주소가 없을 경우 1 , 있을 경우 0을 돌려준다. 
	*/
	int printrecentaddress();
	/**
	*  @brief	: /최근사용한 주소에서 주소록으로 저장한다
	*  @pre		:
	*  @post	:
	*/
	void savecontactlist();
	/**
	*  @brief	: 메일내용으로 메일이 찾아지는지 확인하기 위해서 사용할 함수
	*  @pre		:
	*  @post	: 찾으면 true,아니면 false를 리턴한다.
	*/
	bool IsThereFind(std::string data, std::string item);
	/**
	*  @brief	: 폴더를 생성한다
	*  @pre		:
	*  @post	: 사용자에 입력받은 이름으로 폴더가 생성된다.
	*/
	void Make_folder();
	/**
	*  @brief	: 폴더를 출력한다
	*  @pre		:
	*  @post	: 모든 서브폴더를 출력한다
	*/
	void Display_folder();
	/**
	*  @brief	: 폴더를 삭제한다
	*  @pre		:
	*  @post	: 사용자에게 입력받은 이름의 폴더를 삭제한다
	*/
	void Delete_folder();
	/**
	*  @brief	: 폴더에서 폴더로 경로를 이동한다
	*  @pre		:
	*  @post	:
	*/
	void move_folder_path();
	/**
	*  @brief	: 메일을 찾을 때 내용을 입력받는다
	*  @pre		:
	*  @post	: 찾은 결과에따라 출력한다. 
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
	*  @brief	: 아이템을 찾으면 인덱스를 돌려준다
	*  @pre		: 아이템을 먼저 입력받는다
	*  @post	: 인덱스에는 이차원행렬의 행이 리턴값은 열을 의미한다
	*/
	int GetBinarySearch(string target, int& index);

	/**
	*  @brief	: 메일을 이동한다
	*  @pre		:
	*  @post	: 받은 메일함에서 메일을 선택해서 폴더로 이동시킨다
	*/
	void Move_mail();
	/**
	*  @brief	: 메일을 이동한다.
	*  @pre		:
	*  @post	:
	*/
	void formoveMailList();
	/**
	*  @brief	: 폴더를 이동한다
	*  @pre		:
	*  @post	:
	*/
	void move_mail_path();

	/**
	*  @brief	: 2차원 배열에 들어갈 메일을 정렬한다
	*  @pre		:
	*  @post	: 이름순으로 정렬된 메일이 들어간다.
	*/
	void bubblesort();
private:


	hQueue<QltemType> m_hqueue;	//최근사용한 주소를 저장할 변수 
	BinarySearchTree<QltemType> contactlist;//주소록에서 저장할 변수 

	int m_Command;			///< current command number.

	LinkedList<ItemType> m_list; //보낸메일함을 관리하는 변수 

	LinkedList<ItemType> receivedmail; //받은메일함을 관리하는 변수 
	LinkedList<ItemType> m_garbagmail;// 휴지통의 메일을 저장하는 변수
	LinkedList<ItemType> deleteTempList_receive; // 보낸메일함, 받은메일함 삭제하는거 임시로 저장하는 변수

	DoublySortedLinkedList<ItemType> mail_temp_list;
	
	LinkedList<ItemType> receivedmail_temp1; //받은메일함을 중 안 읽은 애를 관리할 변수 

	bool arr[100];// 받은메일함에서 삭제할메일을 저장할 변수 
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
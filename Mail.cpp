#include "Mail.h"
#include "string.h"
using namespace std;
//반환값으로 돌려주는 함수
DoublySortedLinkedList<string> ItemType::GetSendAddress()
{

	return m_send_Address;
}
string ItemType::GetRecAddress()
{
	return  m_rec_Address;
}
//내용을 돌려준다.
string ItemType::GetContents()
{
	return m_sContents;
}
DoublySortedLinkedList<string> ItemType::GetRefersendAddress()
{
	return reference_Address;
}
//날짜를 돌려준다.
string ItemType::GetDate()
{
	return m_sDate;
}
//라벨을 돌려준다.
string ItemType::GetLabel()
{
	return m_sLabel;
}
//제목을돌려준다.
string ItemType::GetTitle()
{
	return m_sTitle;
}
//설정하는 함수 
void ItemType::SetsendAddress(string a)
{
	int length = countaddress(a);
	cutstring_sendaddress(a, length);
}
void ItemType::SetRefersendAddress(string a)
{
	int length = countaddress(a);
	cutstring_referaddress(a, length);
}
//내용을 설정한다.
void ItemType::SetContents(string a)
{
	if (a.size()>256)
		a.resize(256);
	m_sContents = a;
}

//날짜를 설정한다.
void ItemType::SetDate(string a)
{
	m_sDate = a;
}

//라벨을 설정한다,
void ItemType::SetLabel(string a)
{
	m_sLabel = a;
}
//제목을 설정한다.
void ItemType::SetTitle(string a)
{
	m_sTitle = a;
}

//모든멤버변수를 설정한다.
void ItemType::SetRecord(string readornot, string a1, string a2, string a3, string a4, string a5, string referaddress)
{
	Setread(readornot);
	SetsendAddress(a1);
	SetRefersendAddress(referaddress);
	m_sContents = a2;
	m_sDate = a3;
	m_sLabel = a4;
	m_sTitle = a5;

}
//읽음 표시를 설정하는 함수이다. 
void ItemType::Setread(string a)
{
	m_read_or_not = a;

}

//받은 메일함에서 출력하기 위해서 사용하는 함수로 읽음 표시를 표현한다.
void ItemType::Displaysimlplemail()
{
	string a, sendaddress, referaddress;
	a = m_sContents.substr(0, 10);
	if (m_sContents.size()>10)
		a = a + "....";// 내용이 더 남아있다는 것을 알려주기 위해 사용한다. 
	m_send_Address.ResetItem();
	reference_Address.ResetItem();
	int length = m_send_Address.GetLength();
	int length2 = reference_Address.GetLength();
	m_send_Address.GetNextItem(sendaddress);//보내는 사람의 처음 주소를 가지고 있다.
	reference_Address.GetNextItem(referaddress);//참조인의 처음주소를 가지고 있다. 
	if (length != 1)// 보내는사람이 1명이 아닌경우 
	{
		string number = to_string(length - 1);// int를 string으로 바꿔주는 함수
		sendaddress = sendaddress + "외 " + number+"명";//간략하게 보여주는 창에서는 모든 주소를 출력하지 않고 외 몇명이라고 출력
	}
	if (length2 != 1)
	{
		string number = to_string(length2 - 1);// int를 string으로 바꿔주는 함수
		referaddress = referaddress + "외 " + number + "명";//간략하게 보여주는 창에서는 모든 주소를 출력하지 않고 외 몇명이라고 출력
	}
	cout << "\t       " << m_read_or_not << "    " << setw(15) << sendaddress << setw(20) << referaddress << setw(15) << m_sDate << setw(20) << a << endl;

}

//보낸메일함에서 출력할 함수이다.
void ItemType::Displaysimlplemail_send()
{
	string a, sendaddress, referaddress;
	a = m_sContents.substr(0, 10);
	if (m_sContents.size()>10)
		a = a + "....";// 내용이 더 남아있다는 것을 알려주기 위해 사용한다. 
	m_send_Address.ResetItem();
	reference_Address.ResetItem();
	int length = m_send_Address.GetLength();
	int length2 = reference_Address.GetLength();
	m_send_Address.GetNextItem(sendaddress);//보내는 사람의 처음 주소를 가지고 있다.
	reference_Address.GetNextItem(referaddress);//참조인의 처음주소를 가지고 있다. 
	if (length != 1)// 보내는사람이 1명이 아닌경우 
	{
		string number = to_string(length - 1);// int를 string으로 바꿔주는 함수
		sendaddress = sendaddress + "외 " + number + "명";//간략하게 보여주는 창에서는 모든 주소를 출력하지 않고 외 몇명이라고 출력
	}
	if (length2 != 1)
	{
		string number = to_string(length2 - 1);// int를 string으로 바꿔주는 함수
		referaddress = referaddress + "외 " + number + "명";//간략하게 보여주는 창에서는 모든 주소를 출력하지 않고 외 몇명이라고 출력
	}
	cout << setw(22)<<sendaddress << setw(23) << referaddress << setw(18) << m_sDate << setw(22) << a << endl;

}
//삭제하는 창에서 출력할 함수이다. 
void ItemType::DisplayRecordOnDeleteScreen()
{
	string a, sendaddress,referaddress ;
	a = m_sContents.substr(0, 10);
	if (m_sContents.size()>10)
		a = a + "....";// 내용이 더 남아있다는 것을 알려주기 위해 사용한다. 
	m_send_Address.ResetItem();
	reference_Address.ResetItem();
	int length = m_send_Address.GetLength();
	int length2 = reference_Address.GetLength();
	m_send_Address.GetNextItem(sendaddress);//보내는 사람의 처음 주소를 가지고 있다.
	reference_Address.GetNextItem(referaddress);//참조인의 처음주소를 가지고 있다. 
	if (length != 1)// 보내는사람이 1명이 아닌경우 
		{
			string number1 = to_string( length-1);// int를 string으로 바꿔주는 함수
			sendaddress = sendaddress + "외 " + number1 + "명";//간략하게 보여주는 창에서는 모든 주소를 출력하지 않고 외 몇명이라고 출력
		}
	if (length2 != 1)
		{
			string number2 = to_string( length2 -1);// int를 string으로 바꿔주는 함수
			referaddress = referaddress + "외 " + number2 + "명";//간략하게 보여주는 창에서는 모든 주소를 출력하지 않고 외 몇명이라고 출력
		}
	cout << m_read_or_not << "    " << setw(20) << sendaddress << setw(20 )<<referaddress<< setw(15) << m_sDate << setw(20) << a << endl;
}
//학번을 출력한다.
//	@brief	보내는사람의 주소를 출력
void ItemType::DisplaysAddressOnScreen()
{
	int length = m_send_Address.GetLength();
	cout << "\t            보낸주소 : ";
	string address;
	m_send_Address.ResetItem();
	for (int i = 0; i < length; i++)
	{
		m_send_Address.GetNextItem(address);
		cout << address << "   ";
	}
	cout << endl;
}
void ItemType::DisplayReferaddress()
{
	int length = reference_Address.GetLength();
	cout << "\t            참조인 : ";
	string address;
	reference_Address.ResetItem();
	for (int i = 0; i < length; i++)
	{
		reference_Address.GetNextItem(address);
		cout << address << "   ";
	}
	cout << endl;
}
//	@brief	받은날짜 출력
void ItemType::DisplayDateOnScreen()
{
	cout << "\t    날짜 : " << m_sDate << endl;
}
//	@brief	내용을 출력
void ItemType::DisplayContentsOnScreen()
{
	cout << "\t    내용 : " << m_sContents << endl;
}
//	@brief	라벨을 출력
void ItemType::DisplayLabelOnScreen()
{
	cout << "\t    분류 : " << m_sLabel << endl;
}
//	@brief	제목을 출력 
void ItemType::DisplayTitleOnScreen()
{
	cout << "\t    제목 : " << m_sTitle << endl;
}

//	@brief	모든 멤버변수를 출력 
void ItemType::DisplayRecordOnScreen()
{
	cout << endl << endl;
	cout << "\t            분류 : " << m_sLabel << endl;
	DisplaysAddressOnScreen();
	DisplayReferaddress();
	cout << "\t            제목 : " << m_sTitle << endl;
	cout << "\t            시간 : " << m_sDate << endl;
	cout << "\t            내용 : " << m_sContents << endl;
}


//키보드로부터 보내는사람 주소 설정 
void ItemType::SetsAddress_send_folder_FromKB()
{
	cout << "\t    보낸주소(1명이상에게 보내는 경우 ,로 구분하여주세요) : ";
	string address;
	cin >> address;
	int length = countaddress(address);
	cutstring_sendaddress(address, length);
}
//사용자로부터 키보드로 참조인의 주소를 입력받는다. 
void ItemType::Setreferaddress_FromKB()
{
	cout << "\t    참조인 주소(1명이상에게 보내는 경우 ,로 구분하여주세요) : ";
	string address;
	cin >> address;
	int length = countaddress(address);
	cutstring_referaddress(address, length);
}
//키보드로부터 보내는사람 주소 설정 
void ItemType::SetsAddress_rec_folder_FromKB()
{
	cout << "\t    받는주소(1명이상에게 보내는 경우 ,로 구분하여주세요) : ";
	string address;
	cin >> address;
	int length = countaddress(address);
	cutstring_sendaddress(address, length);
}

// ,를 기준으로 string을 짤라 총 몇개의 주소가 있는지 돌려주는 함수이다. 
int ItemType::countaddress(string sendaddress)
{

	int firstpos = 0;
	int count = 0;
	firstpos = sendaddress.find(',', 0);
	while (1)
	{
		if (firstpos != string::npos)// 콤마를 찾았을 경우 카운트를 증가한다 
			count++;
		else
			break;

		firstpos = sendaddress.find(',', firstpos + 1);
	}
	return count+1;

}
// 문자가 들어왔을 때 참조인에 문자를 콤마로 잘라서 저장하는 역할을 한다. 
void ItemType::cutstring_referaddress(string sendaddress, int length)
{

	int pre_firstpos = 0;// 문자를 자를 처음부분을 가리킨다
	int curlpos = 0;// 문자를 자를 마지막부분을 가리킨다 
	curlpos = sendaddress.find(',', 0);

	if (curlpos == string::npos)
	{

		reference_Address.Add(sendaddress);
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			reference_Address.Add(sendaddress.substr(pre_firstpos, curlpos - pre_firstpos ));
			pre_firstpos = curlpos + 1;
			curlpos = sendaddress.find(',', curlpos + 1);
		}
	}
}
// 문자가 들어왔을 때 보내는사람주소에 문자를 콤마로 잘라서 저장하는 역할을 한다. 
void ItemType::cutstring_sendaddress(string sendaddress, int length)
{

	int pre_firstpos = 0;// 문자를 자를 처음부분을 가리킨다
	int curlpos = 0;// 문자를 자를 마지막부분을 가리킨다 
	curlpos = sendaddress.find(',', 0);
	if (curlpos == string::npos)
	{

		m_send_Address.Add(sendaddress);
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			m_send_Address.Add(sendaddress.substr(pre_firstpos, curlpos - pre_firstpos ));
			pre_firstpos = curlpos + 1;
			curlpos = sendaddress.find(',', curlpos + 1);
		}
	}
}



//키보드로부터 받은날짜 설정 
void ItemType::SetDateFromKB()
{
	cout << "\t    시간: ";
	cin >> m_sDate;
}
//키보드로부터 메일내용 설정 
void ItemType::SetContentsFromKB()
{
	string a;
	cout << "\t    내용: ";
	cin.ignore(255, '\n');
	getline(cin, a);
	if (a.size()>256)
		a.resize(256);
	m_sContents = a;
}
//키보드로부터 라벨 설정 
void ItemType::SetLabelFromKB()
{
	cout << "\t    분류: ";
	cin >> m_sLabel;

}
//키보드로부터 제목 설정 
void ItemType::SetTitleFromKB()
{
	cout << "\t    제목: " ;
	cin >> m_sTitle;
}

//키보드로부터 모든 멤버변수를 설정 
void ItemType::SetRecordFromKB()
{
	SetsAddress_rec_folder_FromKB();
	Setreferaddress_FromKB();
	SetLabelFromKB();
	SetDateFromKB();
	SetTitleFromKB();
	SetContentsFromKB();
}


//data의 정보를 복사하는 역할을 한다. 
void ItemType::CopyRecord(ItemType data)
{
	m_send_Address = data.GetSendAddress();
	reference_Address = data.GetRefersendAddress();
	m_sContents = data.GetContents();
	m_sDate = data.GetDate();
	m_sLabel = data.GetLabel();
	m_sTitle = data.GetTitle();
}


//	@brief 들어온 객체랑 똑같은 값을 갖는 객체로 만들어준다. 
void ItemType:: operator =(ItemType t1)
{
	this->m_read_or_not = t1.GetReadornot();
	this->m_sDate = t1.GetDate();
	this->m_send_Address = t1.GetSendAddress();
	this->reference_Address = t1.GetRefersendAddress();
	this->m_sLabel = t1.GetLabel();
	this->m_sTitle = t1.GetTitle();
	this->m_sContents = t1.GetContents();

}
//	@brief 날짜와 주소로 비교해서 같을 때 true 를 리턴한다. 
bool  ItemType::operator == (ItemType t1)
{
	if (t1.GetDate().compare(m_sDate) == 0 )
		return true;
	else
		return false;
}
//	@brief 날짜로 비교해서 작을 경우 true를 리턴
bool  ItemType::operator < (ItemType t1)
{
	if (t1.GetDate().compare(m_sDate)>0)
	{
		if (t1.GetLabel()< m_sLabel)
			return false;
		else
			return true;
	}
		
	else
		return false;
}
//	@brief 날짜로 비교해서 클경우 true를 리턴
bool ItemType::operator > (ItemType t1)
{
	if (t1.GetDate().compare(m_sDate) < 0)
	{
		if (t1.GetLabel() > m_sLabel)
			return false;
		else
			return true;
	}
	else
		return false;
}
// 제네릭하기 위해서 필요한 함수로 <<에 대한 오버로딩
ostream& operator << (ostream&os, ItemType &item)
{
	item.DisplayRecordOnScreen();
	return os;
}

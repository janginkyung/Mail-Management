#include "Contact_list.h"
/**
*	@brief	
*	@pre	이름이 설정되어있어야한다. 
*	@post	이름을 돌려준다
*/
string QltemType::Getname()
{
	return name;
}

/**
*	@brief   주소를 돌려준다.
*	@pre	주소가 설정
*	@post
*/
string QltemType::GetAddress()
{
	return address;
}

/**
*	@brief
*	@pre	주소를 설정되어있어야한다.
*	@post	주소를 돌려준다
*/
void QltemType::DisplayAddressOnScreen()
{
	
	cout << "\t        주소 : " << address << endl;
}


/**
*	@brief   주소를 설정한다.
*	@pre	string으로 주소가 넘겨져야한다.
*	@post
*/
void QltemType::setadress(string a)
{
	address = a;
}

void QltemType::setName(string b)
{
	name = b;
}




/**
*	@brief   키보드로부터 멤버변수를 설정한다.
*	@pre
*	@post	이름과 주소가 설정
*/
void QltemType::SetFromKB()
{
	cout << "\t        이름 : ";
	cin >> name;
	cout << "\t        주소 : ";
	cin >> address;
}
/**
*	@brief   주소를 키보드로부터 설정한다
*	@pre	
*	@post
*/
void QltemType::SetaddressFromKB()
	{
	cout << "\t        주소: ";
	cin >> address;
}
/**
*	@brief   이름을 키보드로부터 설정
*	@pre	
*	@post
*/
void QltemType::SetnameFromKB()
{
	cout << "\t        이름 : ";
	cin >> name;
}



/**
*	@brief	이름과 주소를 출력한다. 
*	@pre	
*	@post	
*/
void QltemType::DisplayRecordOnScreen()
{
		cout << "\t        이름 : " << name << endl;
		cout << "\t        주소 : " << address << endl;
}
void QltemType::DisplayRecord_recent_OnScreen()
{
	cout << "이름 : " << name << endl;
	cout << "\t            주소 : " << address << endl;
}

void QltemType::DisplayRecord_address_OnScreen()
{
	cout << "주소 : " << address << endl;
}

bool  QltemType::operator == (QltemType t1)
{

	if (name.compare(t1.Getname()) ==0 || address.compare(t1.GetAddress()) == 0)
		return true;
	else
		return false;

}
/**
*	@brief   =연산자를 정의하며 복사하는 함수를 사용한다.
*	@pre	
*	@post
*/
void   QltemType::operator =(QltemType t1)
{
	name = t1.Getname();
	address = t1.GetAddress();
}


bool QltemType::operator <(QltemType t1)
{
	if (name.compare(t1.Getname()) < 0)
		return true;
	else
		return false;
}
bool  QltemType::operator >(QltemType t1)
{
	if (name.compare(t1.Getname()) > 0)
		return true;
	else
		return false;
}

ostream& operator << (ostream&os, QltemType &item)
{
	if (item.Getname() == " ")
	{
		cout << "\t        ";
		item.DisplayRecord_address_OnScreen();
	}
		
	else
	{	
		item.DisplayRecordOnScreen();
	}
	cout << endl;
	return os;
}

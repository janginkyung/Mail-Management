#include "Contact_list.h"
/**
*	@brief	
*	@pre	�̸��� �����Ǿ��־���Ѵ�. 
*	@post	�̸��� �����ش�
*/
string QltemType::Getname()
{
	return name;
}

/**
*	@brief   �ּҸ� �����ش�.
*	@pre	�ּҰ� ����
*	@post
*/
string QltemType::GetAddress()
{
	return address;
}

/**
*	@brief
*	@pre	�ּҸ� �����Ǿ��־���Ѵ�.
*	@post	�ּҸ� �����ش�
*/
void QltemType::DisplayAddressOnScreen()
{
	
	cout << "\t        �ּ� : " << address << endl;
}


/**
*	@brief   �ּҸ� �����Ѵ�.
*	@pre	string���� �ּҰ� �Ѱ������Ѵ�.
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
*	@brief   Ű����κ��� ��������� �����Ѵ�.
*	@pre
*	@post	�̸��� �ּҰ� ����
*/
void QltemType::SetFromKB()
{
	cout << "\t        �̸� : ";
	cin >> name;
	cout << "\t        �ּ� : ";
	cin >> address;
}
/**
*	@brief   �ּҸ� Ű����κ��� �����Ѵ�
*	@pre	
*	@post
*/
void QltemType::SetaddressFromKB()
	{
	cout << "\t        �ּ�: ";
	cin >> address;
}
/**
*	@brief   �̸��� Ű����κ��� ����
*	@pre	
*	@post
*/
void QltemType::SetnameFromKB()
{
	cout << "\t        �̸� : ";
	cin >> name;
}



/**
*	@brief	�̸��� �ּҸ� ����Ѵ�. 
*	@pre	
*	@post	
*/
void QltemType::DisplayRecordOnScreen()
{
		cout << "\t        �̸� : " << name << endl;
		cout << "\t        �ּ� : " << address << endl;
}
void QltemType::DisplayRecord_recent_OnScreen()
{
	cout << "�̸� : " << name << endl;
	cout << "\t            �ּ� : " << address << endl;
}

void QltemType::DisplayRecord_address_OnScreen()
{
	cout << "�ּ� : " << address << endl;
}

bool  QltemType::operator == (QltemType t1)
{

	if (name.compare(t1.Getname()) ==0 || address.compare(t1.GetAddress()) == 0)
		return true;
	else
		return false;

}
/**
*	@brief   =�����ڸ� �����ϸ� �����ϴ� �Լ��� ����Ѵ�.
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

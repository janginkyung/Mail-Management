#include "Mail.h"
#include "string.h"
using namespace std;
//��ȯ������ �����ִ� �Լ�
DoublySortedLinkedList<string> ItemType::GetSendAddress()
{

	return m_send_Address;
}
string ItemType::GetRecAddress()
{
	return  m_rec_Address;
}
//������ �����ش�.
string ItemType::GetContents()
{
	return m_sContents;
}
DoublySortedLinkedList<string> ItemType::GetRefersendAddress()
{
	return reference_Address;
}
//��¥�� �����ش�.
string ItemType::GetDate()
{
	return m_sDate;
}
//���� �����ش�.
string ItemType::GetLabel()
{
	return m_sLabel;
}
//�����������ش�.
string ItemType::GetTitle()
{
	return m_sTitle;
}
//�����ϴ� �Լ� 
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
//������ �����Ѵ�.
void ItemType::SetContents(string a)
{
	if (a.size()>256)
		a.resize(256);
	m_sContents = a;
}

//��¥�� �����Ѵ�.
void ItemType::SetDate(string a)
{
	m_sDate = a;
}

//���� �����Ѵ�,
void ItemType::SetLabel(string a)
{
	m_sLabel = a;
}
//������ �����Ѵ�.
void ItemType::SetTitle(string a)
{
	m_sTitle = a;
}

//����������� �����Ѵ�.
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
//���� ǥ�ø� �����ϴ� �Լ��̴�. 
void ItemType::Setread(string a)
{
	m_read_or_not = a;

}

//���� �����Կ��� ����ϱ� ���ؼ� ����ϴ� �Լ��� ���� ǥ�ø� ǥ���Ѵ�.
void ItemType::Displaysimlplemail()
{
	string a, sendaddress, referaddress;
	a = m_sContents.substr(0, 10);
	if (m_sContents.size()>10)
		a = a + "....";// ������ �� �����ִٴ� ���� �˷��ֱ� ���� ����Ѵ�. 
	m_send_Address.ResetItem();
	reference_Address.ResetItem();
	int length = m_send_Address.GetLength();
	int length2 = reference_Address.GetLength();
	m_send_Address.GetNextItem(sendaddress);//������ ����� ó�� �ּҸ� ������ �ִ�.
	reference_Address.GetNextItem(referaddress);//�������� ó���ּҸ� ������ �ִ�. 
	if (length != 1)// �����»���� 1���� �ƴѰ�� 
	{
		string number = to_string(length - 1);// int�� string���� �ٲ��ִ� �Լ�
		sendaddress = sendaddress + "�� " + number+"��";//�����ϰ� �����ִ� â������ ��� �ּҸ� ������� �ʰ� �� ����̶�� ���
	}
	if (length2 != 1)
	{
		string number = to_string(length2 - 1);// int�� string���� �ٲ��ִ� �Լ�
		referaddress = referaddress + "�� " + number + "��";//�����ϰ� �����ִ� â������ ��� �ּҸ� ������� �ʰ� �� ����̶�� ���
	}
	cout << "\t       " << m_read_or_not << "    " << setw(15) << sendaddress << setw(20) << referaddress << setw(15) << m_sDate << setw(20) << a << endl;

}

//���������Կ��� ����� �Լ��̴�.
void ItemType::Displaysimlplemail_send()
{
	string a, sendaddress, referaddress;
	a = m_sContents.substr(0, 10);
	if (m_sContents.size()>10)
		a = a + "....";// ������ �� �����ִٴ� ���� �˷��ֱ� ���� ����Ѵ�. 
	m_send_Address.ResetItem();
	reference_Address.ResetItem();
	int length = m_send_Address.GetLength();
	int length2 = reference_Address.GetLength();
	m_send_Address.GetNextItem(sendaddress);//������ ����� ó�� �ּҸ� ������ �ִ�.
	reference_Address.GetNextItem(referaddress);//�������� ó���ּҸ� ������ �ִ�. 
	if (length != 1)// �����»���� 1���� �ƴѰ�� 
	{
		string number = to_string(length - 1);// int�� string���� �ٲ��ִ� �Լ�
		sendaddress = sendaddress + "�� " + number + "��";//�����ϰ� �����ִ� â������ ��� �ּҸ� ������� �ʰ� �� ����̶�� ���
	}
	if (length2 != 1)
	{
		string number = to_string(length2 - 1);// int�� string���� �ٲ��ִ� �Լ�
		referaddress = referaddress + "�� " + number + "��";//�����ϰ� �����ִ� â������ ��� �ּҸ� ������� �ʰ� �� ����̶�� ���
	}
	cout << setw(22)<<sendaddress << setw(23) << referaddress << setw(18) << m_sDate << setw(22) << a << endl;

}
//�����ϴ� â���� ����� �Լ��̴�. 
void ItemType::DisplayRecordOnDeleteScreen()
{
	string a, sendaddress,referaddress ;
	a = m_sContents.substr(0, 10);
	if (m_sContents.size()>10)
		a = a + "....";// ������ �� �����ִٴ� ���� �˷��ֱ� ���� ����Ѵ�. 
	m_send_Address.ResetItem();
	reference_Address.ResetItem();
	int length = m_send_Address.GetLength();
	int length2 = reference_Address.GetLength();
	m_send_Address.GetNextItem(sendaddress);//������ ����� ó�� �ּҸ� ������ �ִ�.
	reference_Address.GetNextItem(referaddress);//�������� ó���ּҸ� ������ �ִ�. 
	if (length != 1)// �����»���� 1���� �ƴѰ�� 
		{
			string number1 = to_string( length-1);// int�� string���� �ٲ��ִ� �Լ�
			sendaddress = sendaddress + "�� " + number1 + "��";//�����ϰ� �����ִ� â������ ��� �ּҸ� ������� �ʰ� �� ����̶�� ���
		}
	if (length2 != 1)
		{
			string number2 = to_string( length2 -1);// int�� string���� �ٲ��ִ� �Լ�
			referaddress = referaddress + "�� " + number2 + "��";//�����ϰ� �����ִ� â������ ��� �ּҸ� ������� �ʰ� �� ����̶�� ���
		}
	cout << m_read_or_not << "    " << setw(20) << sendaddress << setw(20 )<<referaddress<< setw(15) << m_sDate << setw(20) << a << endl;
}
//�й��� ����Ѵ�.
//	@brief	�����»���� �ּҸ� ���
void ItemType::DisplaysAddressOnScreen()
{
	int length = m_send_Address.GetLength();
	cout << "\t            �����ּ� : ";
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
	cout << "\t            ������ : ";
	string address;
	reference_Address.ResetItem();
	for (int i = 0; i < length; i++)
	{
		reference_Address.GetNextItem(address);
		cout << address << "   ";
	}
	cout << endl;
}
//	@brief	������¥ ���
void ItemType::DisplayDateOnScreen()
{
	cout << "\t    ��¥ : " << m_sDate << endl;
}
//	@brief	������ ���
void ItemType::DisplayContentsOnScreen()
{
	cout << "\t    ���� : " << m_sContents << endl;
}
//	@brief	���� ���
void ItemType::DisplayLabelOnScreen()
{
	cout << "\t    �з� : " << m_sLabel << endl;
}
//	@brief	������ ��� 
void ItemType::DisplayTitleOnScreen()
{
	cout << "\t    ���� : " << m_sTitle << endl;
}

//	@brief	��� ��������� ��� 
void ItemType::DisplayRecordOnScreen()
{
	cout << endl << endl;
	cout << "\t            �з� : " << m_sLabel << endl;
	DisplaysAddressOnScreen();
	DisplayReferaddress();
	cout << "\t            ���� : " << m_sTitle << endl;
	cout << "\t            �ð� : " << m_sDate << endl;
	cout << "\t            ���� : " << m_sContents << endl;
}


//Ű����κ��� �����»�� �ּ� ���� 
void ItemType::SetsAddress_send_folder_FromKB()
{
	cout << "\t    �����ּ�(1���̻󿡰� ������ ��� ,�� �����Ͽ��ּ���) : ";
	string address;
	cin >> address;
	int length = countaddress(address);
	cutstring_sendaddress(address, length);
}
//����ڷκ��� Ű����� �������� �ּҸ� �Է¹޴´�. 
void ItemType::Setreferaddress_FromKB()
{
	cout << "\t    ������ �ּ�(1���̻󿡰� ������ ��� ,�� �����Ͽ��ּ���) : ";
	string address;
	cin >> address;
	int length = countaddress(address);
	cutstring_referaddress(address, length);
}
//Ű����κ��� �����»�� �ּ� ���� 
void ItemType::SetsAddress_rec_folder_FromKB()
{
	cout << "\t    �޴��ּ�(1���̻󿡰� ������ ��� ,�� �����Ͽ��ּ���) : ";
	string address;
	cin >> address;
	int length = countaddress(address);
	cutstring_sendaddress(address, length);
}

// ,�� �������� string�� ©�� �� ��� �ּҰ� �ִ��� �����ִ� �Լ��̴�. 
int ItemType::countaddress(string sendaddress)
{

	int firstpos = 0;
	int count = 0;
	firstpos = sendaddress.find(',', 0);
	while (1)
	{
		if (firstpos != string::npos)// �޸��� ã���� ��� ī��Ʈ�� �����Ѵ� 
			count++;
		else
			break;

		firstpos = sendaddress.find(',', firstpos + 1);
	}
	return count+1;

}
// ���ڰ� ������ �� �����ο� ���ڸ� �޸��� �߶� �����ϴ� ������ �Ѵ�. 
void ItemType::cutstring_referaddress(string sendaddress, int length)
{

	int pre_firstpos = 0;// ���ڸ� �ڸ� ó���κ��� ����Ų��
	int curlpos = 0;// ���ڸ� �ڸ� �������κ��� ����Ų�� 
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
// ���ڰ� ������ �� �����»���ּҿ� ���ڸ� �޸��� �߶� �����ϴ� ������ �Ѵ�. 
void ItemType::cutstring_sendaddress(string sendaddress, int length)
{

	int pre_firstpos = 0;// ���ڸ� �ڸ� ó���κ��� ����Ų��
	int curlpos = 0;// ���ڸ� �ڸ� �������κ��� ����Ų�� 
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



//Ű����κ��� ������¥ ���� 
void ItemType::SetDateFromKB()
{
	cout << "\t    �ð�: ";
	cin >> m_sDate;
}
//Ű����κ��� ���ϳ��� ���� 
void ItemType::SetContentsFromKB()
{
	string a;
	cout << "\t    ����: ";
	cin.ignore(255, '\n');
	getline(cin, a);
	if (a.size()>256)
		a.resize(256);
	m_sContents = a;
}
//Ű����κ��� �� ���� 
void ItemType::SetLabelFromKB()
{
	cout << "\t    �з�: ";
	cin >> m_sLabel;

}
//Ű����κ��� ���� ���� 
void ItemType::SetTitleFromKB()
{
	cout << "\t    ����: " ;
	cin >> m_sTitle;
}

//Ű����κ��� ��� ��������� ���� 
void ItemType::SetRecordFromKB()
{
	SetsAddress_rec_folder_FromKB();
	Setreferaddress_FromKB();
	SetLabelFromKB();
	SetDateFromKB();
	SetTitleFromKB();
	SetContentsFromKB();
}


//data�� ������ �����ϴ� ������ �Ѵ�. 
void ItemType::CopyRecord(ItemType data)
{
	m_send_Address = data.GetSendAddress();
	reference_Address = data.GetRefersendAddress();
	m_sContents = data.GetContents();
	m_sDate = data.GetDate();
	m_sLabel = data.GetLabel();
	m_sTitle = data.GetTitle();
}


//	@brief ���� ��ü�� �Ȱ��� ���� ���� ��ü�� ������ش�. 
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
//	@brief ��¥�� �ּҷ� ���ؼ� ���� �� true �� �����Ѵ�. 
bool  ItemType::operator == (ItemType t1)
{
	if (t1.GetDate().compare(m_sDate) == 0 )
		return true;
	else
		return false;
}
//	@brief ��¥�� ���ؼ� ���� ��� true�� ����
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
//	@brief ��¥�� ���ؼ� Ŭ��� true�� ����
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
// ���׸��ϱ� ���ؼ� �ʿ��� �Լ��� <<�� ���� �����ε�
ostream& operator << (ostream&os, ItemType &item)
{
	item.DisplayRecordOnScreen();
	return os;
}

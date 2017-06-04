
#include "MyFolder.h"


MyFolder::MyFolder()
{
	fos = NULL;
}


MyFolder::~MyFolder()
{
}

void MyFolder::Setfolder(DoublySortedLinkedList<MyFolder> another)
{
	MyFolder folder;
	fos = new DoublySortedLinkedList<MyFolder>;
	
	int folder_length = another.GetLength();
	another.ResetItem();
	
	for (int i = 0; i < folder_length; i++)
	{
		another.GetNextItem(folder);
		fos->Add(folder);
	}

}
void MyFolder::Setmails(DoublySortedLinkedList<ItemType> another)
{
	Mails = another;
}

DoublySortedLinkedList<ItemType>MyFolder::Getmails()
{
	return Mails;
}
//���� �ȿ��� ���������� ����� ��� �����Ѵ�. 

//���� �ȿ� �����ϴ� ������ ����ϴ� ����� �Ѵ�. 
void MyFolder::Displayall()
{
	PrintMail();
	PrintFolder();
}

void MyFolder::Add_mail(ItemType test)
{
	Mails.Add(test);
}
void MyFolder::Add_subfolder(MyFolder subfolder)
{
	(*fos).Add(subfolder);
}
void MyFolder::PrintMail()
{
	cout << "���� ���� �Դϴ� " << endl;
	Mails.ResetItem();
	int length = Mails.GetLength();
	ItemType test;
	for (int i = 0; i < length; i++)
	{
		Mails.GetNextItem(test);
		test.DisplayRecordOnDeleteScreen();
	}
}
void MyFolder::PrintFolder()
{
	cout << "���� ���� �Դϴ� " << endl;
	fos->ResetItem();
	int length = fos->GetLength();
	MyFolder test;
	for (int i = 0; i < length; i++)
	{
		fos->GetNextItem(test);
		cout << test.Getfilename() << endl;
	}
}

int MyFolder::ReadDataFromFile(ifstream& fin)
{
	if (!fin)//������ �߸������� ��� ���� ���
	{
		cout << "���� ���� �����߽��ϴ�." << endl;
		return 0;
	}

	else//������ ����� ������ ��� 
	{
		fin >> file_name;
		return 1;
	}
}
/* @brief  ��¥�� ���Ͽ� Ŭ��� . */
bool MyFolder::operator > (MyFolder t1)
{
	if (t1.Getfilename().compare(file_name) > 0)
		return false;
	else
		return true;
}
/* @brief  ���� ��ü�� �Ȱ��� ���� ������ ������ش�. */
void MyFolder::operator =(MyFolder t1)
{
	MyFolder folder;

	if (t1.fos == NULL)
		t1.fos = new DoublySortedLinkedList<MyFolder>;
	else {

		int folder_length = t1.fos->GetLength();
		t1.fos->ResetItem();

		if (fos == NULL) {
			fos = new DoublySortedLinkedList<MyFolder>;
		}
		for (int i = 0; i < folder_length; i++)
		{
			t1.fos->GetNextItem(folder);
			fos->Add(folder);
		}
		
	}
	file_name = t1.Getfilename();
	t1.Mails.ResetItem();
	for (int i = 0; i < t1.Mails.GetLength(); i++) {
		ItemType mailTemp;
		t1.Mails.GetNextItem(mailTemp);
		Mails.Add(mailTemp);
	}

}
/* @brief ��¥�� ������ �� ������ ���� �����ش� */
bool MyFolder::operator == (MyFolder t1)
{
	if (t1.Getfilename().compare(file_name) == 0)
		return  true;
	else
		return false;
}
/* @brief  ��¥�� ���ؼ� �������  */
bool MyFolder::operator < (MyFolder t1)
{
	if (t1.Getfilename().compare(file_name) > 0)
		return  true;
	else
		return false;
}


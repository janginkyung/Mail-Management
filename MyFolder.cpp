
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
//폴더 안에서 서브폴더를 만드는 경우 저장한다. 

//폴더 안에 존재하는 메일을 출력하는 기능을 한다. 
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
	cout << "메일 정보 입니다 " << endl;
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
	cout << "폴더 정보 입니다 " << endl;
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
	if (!fin)//파일이 잘못열렸을 경우 오류 출력
	{
		cout << "파일 열기 실패했습니다." << endl;
		return 0;
	}

	else//파일이 제대로 열렸을 경우 
	{
		fin >> file_name;
		return 1;
	}
}
/* @brief  날짜로 비교하여 클경우 . */
bool MyFolder::operator > (MyFolder t1)
{
	if (t1.Getfilename().compare(file_name) > 0)
		return false;
	else
		return true;
}
/* @brief  들어온 객체랑 똑같은 값을 갖도록 만들어준다. */
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
/* @brief 날짜로 비교했을 떄 같으면 참을 돌려준다 */
bool MyFolder::operator == (MyFolder t1)
{
	if (t1.Getfilename().compare(file_name) == 0)
		return  true;
	else
		return false;
}
/* @brief  날짜로 비교해서 작을경우  */
bool MyFolder::operator < (MyFolder t1)
{
	if (t1.Getfilename().compare(file_name) > 0)
		return  true;
	else
		return false;
}


#include "Application.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

// 메일을 삭제할때 위아래로 선택하기 위해서 사용하는 함수 
void Application::gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
void Application::Make_empty_arr()
{
	for (int i = 0; i < 100; i++) {
		arr[i] = true, arr2[i] = true;
	}
}

void Application::LogIn()
{
	int c;
	cout << endl << endl;
	cout << "\t    ┌──────◎환영합니다◎────────┐" << endl;
	cout << "\t    │  1  회원가입                             │" << endl;
	cout << "\t    │  2  Log-In                               │" << endl;
	cout << "\t    │  3  아이디, 비밀번호 찾기                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;

	cout << endl << "\t    골라주세요 --> ";
	cin >> c;
	if (c == 1)
		registerin();
	else if (c == 2)
		idpw();
	else
		Found_idpw();
}

void Application::Found_idpw()
{
	int c;
	system("cls");
	cout << endl << endl;
	cout << "\t    ┌───◎아이디,비밀번호 찾기◎───────┐" << endl;
	cout << "\t    │  1  아이디 찾기                            │" << endl;
	cout << "\t    │  2  비밀번호 찾기                          │" << endl;
	cout << "\t    └──────────────────────┘" << endl << endl;

	cout << endl << "\t    골라주세요 --> ";
	cin >> c;
	if (c == 1)
		Found_id();
	else if (c == 2)
		Found_pw();
}
void Application::Found_id()
{
	string name, id;
	system("cls");
	cout << endl << endl;
	cout << "\t    ┌───────◎아이디찾기◎────────┐" << endl;
	cout << "\t    │   1 : 이름을 입력하세요 : ";
	cin >> name;

	load_user();
	for (int i = 0; i < count; i++)
	{

		User tempUser;
		tempUser.set_userName(name);

		if (array_user.search(tempUser))
		{
			id = tempUser.get_userId();
			break;
		}
	}
	cout << "\t    │   ->  아이디는 " << id << " 입니다. "<<endl;
	cout << "\t    │                                            │" << endl;
	cout << "\t    └──────────────────────┘" << endl << endl;

	LogIn();
}
void Application::Found_pw()
{
	string name,  id;
	string password= "";
	system("cls");
	cout << endl << endl;
	cout << "\t    ┌───────◎비밀번호찾기◎────────┐" << endl;
	cout << "\t    │   1 : 이름을 입력하세요 : ";
	cin >> name;
	cout << "\t    │   2 : ID를 입력하세요 : ";
	cin >> id;
	load_user();
	for (int i = 0; i < count; i++)
	{
		User tempUser;
		tempUser.set_userName(name);
		tempUser.set_userId(id);
		if (array_user.search(tempUser))
		{
			password = tempUser.get_userPw();
			break;
		}
	}
		if (password == "")
		{
			cout << "\t    │   그러한 정보는 없습니다 .                   │ " << endl;
			cout << "\t    └───────────────────────┘" << endl << endl;
		}
	else
	{
		cout << "\t    │   ->  비밀번호는 " << password << " 입니다. " << endl;
		cout << "\t    │                                              │" << endl;
		cout << "\t    └───────────────────────┘" << endl << endl;
	}
	LogIn();
}
void Application::registerin()
{
	system("cls");
	string id, pass, name;
	cout << endl << endl;
	cout << "\t    ┌────────회원가입─────────┐" << endl;
	cout << "\t    │  1 : ID를 입력하세요 : ";
	cin >> id;
	cout << "\t    │  2 : PassWord를 입력하세요  : ";

	cin >> pass;
	cout << "\t    │  3 : 이름을 입력하세요  : ";
	cin >> name;
	cout << "\t    │                         .                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;
	ofstream of;
	of.open("user.txt", ios::app);
	of << id << " " << pass << " " << name << " " << 0 << endl;
	_mkdir(id.c_str());
	of.close();

	LogIn();

}
void Application::idpw()
{
	system("cls");
	load_user();
	string id;
	string pass;
	cout << endl << endl;
	cout << "\t    ┌─────────로그인─────────┐" << endl;
	cout << "\t    │  1 : ID  : ";
	cin >> id;
	cout << "\t    │  2 : PassWord  : ";
	cin >> pass;
	cout << "\t    │                         .                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;
	bool found = false;
	for (int i = 0; i < count; i++)
	{

		User tempUser;
		tempUser.set_userId(id);
		tempUser.set_userPw(pass);

		if (array_user.search(tempUser))
		{
			found = true;
			currentUser = tempUser;
			break;
		}

	}


	if (found == true)
	{
			char tempPath[256];
			string currentPath = _getcwd(tempPath, 256);
			string sendEmailFileName = currentPath + "\\" + string(currentUser.get_userId()) + "\\" + "sendEmail.txt";
			//string temp = "C:\\Users\\InKyung\\Desktop\\6\\receiveEmail.txt";
			//cout << temp;

			string receivceEmailFileName = currentPath + "\\" + string(currentUser.get_userId()) + "\\" + "receiveEmail.txt";
			string trashEmailFileName = currentPath + "\\" + string(currentUser.get_userId()) + "\\" + "trash.txt";
			string contactListFileName = currentPath + "\\" + string(currentUser.get_userId()) + "\\" + "contact.txt";
			//cout << sendEmailFileName << endl;

			ifstream fin1;
			fin1.open(sendEmailFileName);

			ifstream fin2;
			fin2.open(receivceEmailFileName);
			ifstream fin3;
			fin3.open(trashEmailFileName);

			ifstream fin4;
			fin4.open(contactListFileName);

			string read;
			string receiverName;
			string refernseName;
			string title;
			string description;
			string senderName;
			string date;
			string label;
			string contact_name;
			string contact_address;

			while (!fin1.eof()) {
				fin1 >> title >> description
					>> senderName >> date >> label >> receiverName >> refernseName;
				ItemType itemType;
				itemType.SetTitle(title);
				itemType.SetContents(description);
				itemType.SetrecAddress(senderName);
				itemType.SetDate(date);
				itemType.SetLabel(label);
				itemType.SetsendAddress(receiverName);
				itemType.SetRefersendAddress(refernseName);
				m_list.Add(itemType);

			}


			while (!fin2.eof()) {
				fin2 >> read >> receiverName >> title >> description
					>> senderName >> date >> label >> refernseName;

				ItemType itemType;
				itemType.Setread(read);
				itemType.SetsendAddress(receiverName);
				itemType.SetRefersendAddress(refernseName);
				itemType.SetTitle(title);
				itemType.SetContents(description);
				itemType.SetrecAddress(senderName);
				itemType.SetDate(date);
				itemType.SetLabel(label);

				receivedmail.Add(itemType);

			}

			while (!fin3.eof()) {
				fin3 >> read >> receiverName >> title >> description
					>> senderName >> date >> label >> refernseName;

				ItemType itemType;
				itemType.Setread(read);
				itemType.SetsendAddress(receiverName);
				itemType.SetRefersendAddress(refernseName);
				itemType.SetTitle(title);
				itemType.SetContents(description);
				itemType.SetrecAddress(senderName);
				itemType.SetDate(date);
				itemType.SetLabel(label);

				m_garbagmail.Add(itemType);

			}

			while (!fin4.eof()) {
				fin4 >> contact_name >> contact_address;

				QltemType contact;
				contact.setadress(contact_address);
				contact.setName(contact_name);

				contactlist.Additem(contact);

			}


			fin1.close();
			fin2.close();
			fin3.close();
			fin4.close();
			select_mail_forder();

	}
	else
	{
		cout << "\t    ┌────────로그인──────────┐" << endl;
		cout << "\t    │                         .                │" << endl;
		cout << "\t    │          로그인 정보가 틀렸습니다.       │" << endl;
		cout << "\t    │          다시 입력해주세요 ㅠ.ㅠ         │" << endl;
		cout << "\t    │                                          │" << endl;
		cout << "\t    └─────────────────────┘" << endl << endl;
		LogIn();
	}

	
}


void Application::load_user() {

	ifstream fin;
	fin.open("user.txt");

	string id;
	string pass;
	string name;
	int addressNum;

	while (!fin.eof()) {

		User *user = new User;

		fin >> id >> pass >> name >> addressNum;
		user->set_userId(id);
		user->set_userPw(pass);
		user->set_userName(name);
		user->set_addressNum(addressNum);

		string *arrayAddress = new string[addressNum];
		for (int i = 0; i < addressNum; i++) {
			string tempAddress;
			fin >> tempAddress;
			user->set_address(i, tempAddress);
		}

		count++;
		array_user.Add(*user);

	}

	fin.close();
	fin.clear();

}

void Application::select_mail_forder()
{
	int c;
	system("cls");
	cout << endl << endl;
	cout << "\t    ┌────────메일함──────────┐" << endl;
	cout << "\t    │  1 : 받은메일함                          │" << endl;
	cout << "\t    │  2 : 보낸메일함                          │" << endl;
	cout << "\t    │  3 : 주소록                              │" << endl;
	cout << "\t    │  4 : 휴지통                              │" << endl;
	cout << "\t    │  5 : 폴더 관리                           │" << endl;
	cout << "\t    │  0 : 나가기             .                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;
	cout << endl << "\t       골라주세요 --> ";

	cin >> c;
	switch (c)
	{
	case 1:
		received_mail_folder();
		break;
	case 2:
		send_mail_folder();
		break;
	case 3:
		contact_folder();
		break;
	case 4:
		garbage_mail_folder();
		break;

	case 5:
		make_folder();
		break;

	case 0:
		return;
	default:
		cout << "\t    다시골라주세요!!!!\n";
		break;
	}
}


int Application::received_mail_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    ┌───────받은메일함─────────┐" << endl;
	cout << "\t    │  1 : 메일 보여주기                       │" << endl;
	cout << "\t    │  2 : 메일 삭제                           │" << endl;
	cout << "\t    │  3 : 읽지 않은 메일 중 이름으로 찾기     │" << endl;
	cout << "\t    │  4 : 주소로 검색                         │" << endl;
	cout << "\t    │  0 : 폴더함으로 돌아간다.                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;
	cout << endl << "\t       골라주세요 --> ";
	cin >> command;
	cout << endl;

	return command;
}

void Application::received_mail_folder()
{
	QltemType key;
	system("cls");
	while (1)
	{
		m_Command = received_mail_command();

		switch (m_Command)
		{
		case 1:		// 아이템을 삭제한다
			Displayrecentadress();
			break;
		case 2:		// Print all the elements in the queue.
			deletereceivedmail();
			break;
		case 3:		// Dequeue Element by searching
			findmail_read_name();
			break;
		case 4:		// Dequeue Element by searching
			findmailbyaddress();
			break;

		case 0:
			select_mail_forder();
			break;
		default:
			cout << "\t       다시골라주세요!!!!\n";
			break;
		}
	}
}

void Application::Displayrecentadress()
{
	system("cls");
	cout << endl << endl;
	cout << "\t       ※받은메일함※ " << endl;
	gotoXY(16, 4); cout <<"   읽음" << setw(22) << "보낸사람의 주소 " << setw(18) << "참조인 " << setw(15) << "날짜 " <<setw(18) << "내용 " << endl;
	gotoXY(16, 6); cout << "->";

	int k = receivedmail.GetLength();
	ItemType test;
	int menu_item = 0;
	int run = 0;
	int x = 6;
	bool running = true;
	bool found = false;
	bool love = true;

	while (running)
	{
		while (_kbhit()) _getch();

		//int length = receivedmail_templist.GetLength();
		receivedmail.ResetList();

		for (int i = 0; i < k; i++)
		{
			gotoXY(20, i + 6);
			receivedmail.GetNextItem(test);
			test.DisplayRecordOnDeleteScreen();
		}

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 5+k) //down button pressed
		{
			gotoXY(16, x); cout << "  ";
			x++;
			gotoXY(16, x); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 6) //up button pressed
		{
			gotoXY(16, x); cout << "  ";
			x--;
			gotoXY(16, x); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{ // Enter key pressed
			receivedmail.ResetList();
			ItemType lovegyusu;
			for (int i = 0; i < menu_item+1; i++)
			{
				receivedmail.GetNextItem(lovegyusu);
			}
			receivedmail.Delete(lovegyusu);//읽음 표시를 해주기 위해서 삭제한 다음 다시 추가한다.
			lovegyusu.Setread("◆");//읽음 표시를 해준다음 
			receivedmail.Add(lovegyusu);//다시 추가를해준다. 
			lovegyusu.DisplayRecordOnScreen();
			break;
		}	

	}
}
//받은메일함에서 사용되는 함수 

void Application::formoveMailList() {

	system("cls");
	Make_empty_arr();
	cout << endl << endl;
	cout << "\t       ※이동할 메일을 골라주세요※ " << endl;
	int k = receivedmail.GetLength();
	ItemType test;


	int menu_item = 0, run = 0, x = 11;
	bool running = true;
	bool found = false;

	gotoXY(16, 5); cout << "받은메일함";
	gotoXY(16, 7); cout << "선택은 엔터 모두 선택하고 선택완료시에 스페이스바";
	gotoXY(16, 9); cout << "   선택  " << " 읽음" << setw(22) << "보낸사람의 주소 " << setw(18) << "참조인 " << setw(15) << "날짜 " << setw(18) << "내용 " << endl;
	gotoXY(16, 11); cout << "->";


	while (running)
	{
		while (_kbhit()) _getch();
		k = receivedmail.GetLength();
		if (k == 0)
		{
			cout << "\t       이동할 메일이 없습니다. " << endl;
			break;
		}
		//int length = receivedmail_templist.GetLength();
		receivedmail.ResetList();

		for (int i = 0; i < k; i++)
		{
			gotoXY(20, i + 11);
			receivedmail.GetNextItem(test);

			if (!arr[i]) cout << "■    ";
			else cout << "□    ";

			test.DisplayRecordOnDeleteScreen();

		}

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 10 + k) //down button pressed
		{
			gotoXY(16, x); cout << "  ";
			x++;
			gotoXY(16, x); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 11) //up button pressed
		{
			gotoXY(16, x); cout << "  ";
			x--;
			gotoXY(16, x); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{ // Enter key pressed
			arr[menu_item] = false;
			continue;
		}

		if (GetAsyncKeyState(VK_SPACE)) {
			int i = 0;
			while (1)
			{
				if (arr[i] == false)
					break;
				else if (i == k - 1)
					return;
				i++;
			}


			receivedmail.ResetList();
			ItemType lovegyusu;
			for (int i = 0; i < k; i++) {
				receivedmail.GetNextItem(lovegyusu);
				if (!arr[i]) {
					mail_temp_list.Add(lovegyusu);
				}	
			}

		
			for (int i = 0; i < 100; i++)
			{
				arr[i] = true;
			}

			break;

		}

	}


}

void Application::deletereceivedmail()
{
	system("cls");
	Make_empty_arr();
	cout << endl << endl;
	cout << "\t       ※삭제할 메일을 골라주세요※ " << endl;
	int k = receivedmail.GetLength();
	ItemType test;


	int menu_item = 0, run = 0, x = 11;
	bool running = true;
	bool found = false;

	gotoXY(16, 5); cout << "받은메일함";
	gotoXY(16, 7); cout << "선택은 엔터 모두 선택하고 삭제시에 스페이스바";
	gotoXY(16, 9); cout << "   선택  " <<" 읽음" << setw(22) << "보낸사람의 주소 " << setw(18) << "참조인 " << setw(15) << "날짜 " << setw(18) << "내용 " << endl;
	gotoXY(16, 11); cout << "->";


	while (running)
	{
		while (_kbhit()) _getch();
		k = receivedmail.GetLength();
		if (k == 0)
		{
			cout << "\t        삭제할 메일이 없습니다. " << endl;
			break; 
		}
		//int length = receivedmail_templist.GetLength();
		receivedmail.ResetList();
		
		for (int i = 0; i < k; i++)
		{
			gotoXY(20, i + 11);
			receivedmail.GetNextItem(test);

			if (!arr[i]) cout << "■    ";
			else cout << "□    ";

			test.DisplayRecordOnDeleteScreen();

		}

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 10+k) //down button pressed
		{
			gotoXY(16, x); cout << "  ";
			x++;
			gotoXY(16, x); cout << "->";
			menu_item++;
			continue;

		}

		if (GetAsyncKeyState(VK_UP) && x != 11) //up button pressed
		{
			gotoXY(16, x); cout << "  ";
			x--;
			gotoXY(16, x); cout << "->";
			menu_item--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{ // Enter key pressed
			arr[menu_item] = false;
			continue;
		}

		if (GetAsyncKeyState(VK_SPACE)) {
			int i = 0;
			while (1)
			{
				if (arr[i] == false)
					break;
				else if (i == k - 1)
					return;
				i++;
			}
			receivedmail.ResetList();
			ItemType lovegyusu;	
			for (int i = 0; i < k; i++) {
				receivedmail.GetNextItem(lovegyusu);
				if (arr[i]) {
					deleteTempList_receive.Add(lovegyusu);
				}
				else
					m_garbagmail.Add(lovegyusu);
			}
			receivedmail.MakeEmpty();
			int length = deleteTempList_receive.GetLength();
			deleteTempList_receive.ResetList();
			for (int i = 0; i < length; i++) {
				deleteTempList_receive.GetNextItem(lovegyusu);
				receivedmail.Add(lovegyusu);
			}
			deleteTempList_receive.MakeEmpty();
			for (int i = 0; i < 100; i++)
			{
				arr[i] = true;
			}
			
			break;

		}

	}


}
void Application::findmail_read_name()
{
	
	findmail_read();
}
void Application::findmail_read()
{
	ItemType data;
	int k = receivedmail.GetLength();
	string address, first;
	receivedmail.ResetList();
	for (int i = 0; i < k; i++)
	{

		receivedmail.GetNextItem(data);
		if (data.GetReadornot() == "◇")
		{
			receivedmail_temp1.Add(data);
			data.GetSendAddress().ResetItem();
			data.GetSendAddress().GetNextItem(address);
			data.GetSendAddress().GetNextItem(address);
			first = address.substr(0, 1);
			const char * cstr = first.c_str();
			char head = *cstr;
			int asci = (int)head;
			asci = asci - 97;
			Mail_Name[asci][number[asci]] = data;
			number[asci]++;

		}
	}
	bubblesort();

	cout << endl;
	cout << "\t    ※읽지 않은 총 메일※ " << endl;
	int length = receivedmail_temp1.GetLength();
	if (length == 0)
		cout << "\t      읽지 않은 메일이 없습니다. " << endl;

	findmail_name();
	/*else
	{
		receivedmail_temp1.ResetList();

		for (int i = 0; i < length; i++)
		{
			receivedmail_temp1.GetNextItem(data);
			data.DisplayRecordOnDeleteScreen();
		}
	}
	*/
	/*
	string address2, target;

	//findmail_name();
	// list 에서 탐색하기 위해 만든 함수 
	cout << "입력 ";
	cin >> target;
	DWORD start;
	DWORD end;

	start = GetTickCount();
	receivedmail_temp1.ResetList();
	for (int i = 0; i < length; i++)
	{
		receivedmail_temp1.GetNextItem(data);
		data.GetSendAddress().ResetItem();
		data.GetSendAddress().GetNextItem(address2);
		data.GetSendAddress().GetNextItem(address2);
		if (target.compare(address2) == 0)
			data.DisplayRecordOnScreen();
	}

	end = GetTickCount();

	printf("\n실행시간 : %lf \n", (end - start) / (double)1000);
	*/

}
void Application::bubblesort()
{
	string  data1, data2;
	for (int k = 0; k < 26; k++)
	{
		if (number[k] != 0)
		{
			for (int i = 1; i < number[k]; ++i)
			{
				for (int j = 0; j < (number[k] - i); ++j)
				{
					ItemType temp;
					Mail_Name[k][j].GetSendAddress().ResetItem();
					Mail_Name[k][j].GetSendAddress().GetNextItem(data1);
					Mail_Name[k][j].GetSendAddress().GetNextItem(data1);

					Mail_Name[k][j + 1].GetSendAddress().ResetItem();
					Mail_Name[k][j + 1].GetSendAddress().GetNextItem(data2);
					Mail_Name[k][j + 1].GetSendAddress().GetNextItem(data2);

					if (data1.compare(data2) > 0)   //a[j]>a[j + 1])
					{
						temp = Mail_Name[k][j];
						Mail_Name[k][j] = Mail_Name[k][j + 1];
						Mail_Name[k][j + 1] = temp;
					}
				}
			}
		}
	}
}
void Application::findmail_name()
{
	int index = 0;
	cout << endl << endl;
	bool found;
	string address;
		cout << "\t      찾는 주소를 입력하세요 : ";
		cin >> address;
		int key = GetBinarySearch(address, index);
		if (key == -1)
			cout << "\t      찾는 대상이 없습니다. " << endl;
		else
		{
			cout << "\t      찾았다." << endl;
			Mail_Name[index][key].DisplayRecordOnScreen();
		}

}
void Application::findmailbyaddress()
{
	int k = receivedmail.GetLength();
	ItemType  test;
	string target,address;
	cout << "\t    보낸주소 : ";
	cin >> target;
	receivedmail.ResetList();
	cout << endl;
	cout << "\t    ※주소로 찾은 결과※ " << endl;
	bool found = false;
	for (int i = 0; i < k; i++)
	{
		receivedmail.GetNextItem(test);
		int length=test.GetSendAddress().GetLength();
		test.GetSendAddress().ResetItem();
		for (int i = 0; i < length;i++)
		{
			test.GetSendAddress().GetNextItem(address);
			if (target == address){
				test.DisplayRecordOnScreen();
				found = true;
			}
		}
	}
	if (found == false)
		cout << "\t      존재하지 않습니다ㅜ. " << endl;
}



int Application::send_mail_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    ┌───────보낸메일함─────────┐" << endl;
	cout << "\t    │  1 : 메일 보내기                         │" << endl;
	cout << "\t    │  2 : 보낸메일함 보기                     │" << endl;
	cout << "\t    │  3 : 메일 삭제                           │" << endl;
	cout << "\t    │  4 : 내용으로 검색                       │" << endl;
	cout << "\t    │  0 : 폴더함으로 돌아간다.                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;
	cout << endl << "\t       골라주세요 --> ";
	cin >> command;
	cout << endl;

	return command;
}


void Application::send_mail_folder()
{
	ItemType test;
	system("cls");
	while (1)
	{
		m_Command = send_mail_command();

		switch (m_Command)
		{
		case 1:		// read a record and add to list.
			Send_Mail();
			break;
		case 2:		// display all the records in list on screen.
			Display_Send_Mail();
			break;
		case 3:
			Delete_Mail_Select();
			break;
		case 4:		// save list data into a file.
			find_mail_content();
			break;
		case 0:
			select_mail_forder();
			break;
		default:
			cout << "\t    다시골라주세요!!!!\n";
			break;
		}
	}
}
// 보낸 메일함에서 사용하는 함수 

int Application::Send_Mail()
{
	ItemType mail;
	mail.SetRecordFromKB();
	int length= mail.GetSendAddress().GetLength();
	DoublySortedLinkedList <string> temp = mail.GetSendAddress();
	temp.ResetItem();
	string address;
	QltemType contact;
	for (int i = 0; i < length; i++)
	{
		temp.GetNextItem(address);
		contact.setadress(address);
		m_hqueue.Enqueue(contact);
	}
	m_list.Add(mail);
	return 1;
}

void Application::Display_Send_Mail()
{
	int k = m_list.GetLength();
	system("cls");
	cout << endl << endl;
	cout << "\t       ※보낸메일함 ※ " << endl;
	if (k == 0)
		cout << "\t    메일함이 비었습니다. ㅜㅜ " << endl;
	else
	{
		gotoXY(16, 4); cout << setw(23) << "받는사람 주소 " << setw(23) << "참조인 " << setw(18) << "날짜" << setw(20) << "내용 " << endl;
		gotoXY(16, 6); cout << "->";

		ItemType test;
		int menu_item = 0;
		int run = 0;
		int x = 6;
		bool running = true;
		bool found = false;

		while (running)
		{
			while (_kbhit()) _getch();

			//int length = receivedmail_templist.GetLength();
			m_list.ResetList();

			for (int i = 0; i < k; i++)
			{
				gotoXY(20, i + 6);
				m_list.GetNextItem(test);
				test.Displaysimlplemail_send();
			}

			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 5+k) //down button pressed
			{
				gotoXY(16, x); cout << "  ";
				x++;
				gotoXY(16, x); cout << "->";
				menu_item++;
				continue;

			}

			if (GetAsyncKeyState(VK_UP) && x != 6) //up button pressed
			{
				gotoXY(16, x); cout << "  ";
				x--;
				gotoXY(16, x); cout << "->";
				menu_item--;
				continue;
			}

			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{ // Enter key pressed
				m_list.ResetList();
				ItemType lovegyusu;
				for (int i = 0; i < menu_item + 1; i++)
				{
					m_list.GetNextItem(lovegyusu);
				}
				lovegyusu.DisplayRecordOnScreen();
				break;
			}

		}
	}
	
}


void Application::Delete_Mail_Select()
{
	int k = m_list.GetLength();
	Make_empty_arr();

	system("cls");
	cout << endl << endl;
	cout << "\t       ※삭제할 메일을 골라주세요※ " << endl;
	if (k == 0)
		cout << "\t    메일함이 비었습니다. ㅜㅜ " << endl;
	else
	{
		k = m_list.GetLength();
		ItemType test;
		int menu_item = 0;
		int run = 0;
		int x = 11;
		bool running = true;
		gotoXY(16, 5); cout << "보낸메일함";
		gotoXY(16, 7); cout << "선택은 엔터 모두 선택하고 삭제시에 스페이스바";
		gotoXY(16, 9); cout << "   선택  " << "받는사람 주소 " << setw(13) << "  참조인 "<<setw(17) << "날짜 " <<setw(15) << "내용 " << endl;
		gotoXY(16, 11); cout << "->";

		while (running)
		{
			while (_kbhit()) _getch();

			//int length = receivedmail_templist.GetLength();
			m_list.ResetList();

			for (int i = 0; i < k; i++)
			{
				gotoXY(20, i + 11);
				m_list.GetNextItem(test);
				if (!arr2[i]) cout << "■    ";
				else cout << "□    ";
				test.Displaysimlplemail_send();
			}

			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 10 + k) //down button pressed
			{
				gotoXY(16, x); cout << "  ";
				x++;
				gotoXY(16, x); cout << "->";
				menu_item++;
				continue;

			}

			if (GetAsyncKeyState(VK_UP) && x != 11) //up button pressed
			{
				gotoXY(16, x); cout << "  ";
				x--;
				gotoXY(16, x); cout << "->";
				menu_item--;
				continue;
			}


			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{ // Enter key pressed
				arr2[menu_item] = false;
				continue;
			}

			if (GetAsyncKeyState(VK_SPACE))
			{
				int i = 0;
				while (1)
				{
					if (arr2[i] == false)//선택한 것이 있다는 것은 삭제할 것이 있으므로 아래를 수행
						break;
					else if (i == k - 1)//만약 어떤 것도 선택하지 않은 경우에는 아무 것도 하지 않고 return한다. 
						return;
					i++;
				}

				m_list.ResetList();
				ItemType lovegyusu;
				for (int i = 0; i < k; i++) {
					m_list.GetNextItem(lovegyusu);
					if (arr2[i]) {
						deleteTempList_receive.Add(lovegyusu);
					}
					else
						m_garbagmail.Add(lovegyusu);
				}
				m_list.MakeEmpty();
				int length = deleteTempList_receive.GetLength();
				deleteTempList_receive.ResetList();
				for (int i = 0; i < length; i++) {
					deleteTempList_receive.GetNextItem(lovegyusu);
					m_list.Add(lovegyusu);
				}
				deleteTempList_receive.MakeEmpty();
				for (int i = 0; i < 100; i++)
				{
					arr2[i] = true;
				}
				break;

			}

		}
	}

}


//내용으로 메일을 찾기 위해서 새로운 변수를 설정하고 시간대별로 찾아주는 역할을 한다. 
void Application::find_mail_content()
{
	string key , contents;
	cout << "\t       ※찾고 싶은 내용을 입력해주세요※" << endl;
	cout << "\t          -> ";
	cin >> key;
	ItemType test;
	bool found = false;
	int length = m_list.GetLength();
	m_list.ResetList();
	for (int i = 0; i < length; i++)//총길이동안 
	{
		m_list.GetNextItem(test);
		contents = test.GetContents();
		if (IsThereFind(contents, key) == true)//
		{
			test.DisplayRecordOnScreen();
			found = true;
		}

	}
	if (found == false)
		cout <<endl<< "\t           찾은 결과가 없습니다. " << endl;
}

int Application::contact_folder_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    ┌────────주소록──────────┐" << endl;
	cout << "\t    │  1 : 저장하기                            │" << endl;
	cout << "\t    │  2 : 삭제하기                            │" << endl;
	cout << "\t    │  3 : 이름으로 찾기                       │" << endl;
	cout << "\t    │  4 : 보여주기                            │" << endl;
	cout << "\t    │  5 : 메일에서 사용한 주소 보기           │" << endl;
	cout << "\t    │  0 : 폴더함으로 돌아간다.                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;
	cout << endl << "\t       골라주세요 --> ";
	cin >> command;
	cout << endl;

	return command;
}
void Application::contact_folder()
{
	QltemType key;
	system("cls");
	while (1)
	{
		m_Command = contact_folder_command();


		switch (m_Command)
		{
		case 1:		// 아이템을 추가한다
			conatactadd();
			break;
		case 2:		// 아이템을 삭제한다
			conatactdelete();
			break;
		case 3:
			conatactsearch();
			break;
		case 4:
			printcontact();
			break;
		case 5:
			select_recent_address();
			break;
		case 0:
			select_mail_forder();
			break;
		default:
			cout << "\t    다시골라주세요!!!!\n";
			break;
		}
	}
}

//주소록에 아이템을 추가하는 함수이다.  
void Application::conatactadd()
{
	cout << "\t       ※저장할 사람 입력" << endl;
	QltemType data;
	cout << endl;
	data.SetFromKB();
	contactlist.Additem(data);
}
//주소록에서 이름으로 정보를 찾아서 삭제하는 역할을 한다. 
void Application::conatactdelete()
{
	printcontact();
	cout << "\t       ※삭제할 사람 고르기 " << endl;
	QltemType data;
	data.SetnameFromKB();
	contactlist.Deleteitem(data);
	printcontact();
}
//주소록에서 이름으로 정보를 찾아서 출력해준다. 
void Application::conatactsearch()
{
	bool found;
	cout << "\t        ※찾을 사람의 정보를 입력해주세요 " << endl;
	QltemType data;
	data.SetnameFromKB();
	contactlist.Retrieveitem(data, found);
	if (found== false)
		cout << "\t       찾지 못했습니다. " << endl;
	else
	{
		cout << endl << "\t        짜잔" << endl;
		data.DisplayRecordOnScreen();
	}

	return;
}
//주소록에서 아이템을 출력한다. 
void Application::printcontact()
{
	cout << endl << endl;
	cout << "\t       ※주소록 " << endl;
	if (contactlist.GetLength() == 0)
		cout << "\t       비어있습니다.ㅜㅜ" << endl;
	else
		contactlist.PrintTree(cout);
}

void Application::select_recent_address()
{
	system("cls");
	while (1)
	{
		int command;
		
		cout << endl << endl;
		cout << "\t    ┌────메일에서 최근 사용한 주소────┐" << endl;
		cout << "\t    │  1 : 보여주기                            │" << endl;
		cout << "\t    │  2 : 저장하기                            │" << endl;
		cout << "\t    │  3 : 주소록으로 돌아가기                 │" << endl;
		cout << "\t    └─────────────────────┘" << endl << endl;
		cout << endl << "\t       골라주세요 --> ";
		cin >> command;

		m_Command = command;
		switch (m_Command)
		{
		case 1:		// 아이템을 추가한다
			printrecentaddress();
			break;
		case 2:		// 아이템을 삭제한다
			savecontactlist();
			break;
		case 3:
			contact_folder();
			break;
		default:
			cout << "\t    다시골라주세요!!!!\n";
			break;
		}
	}


}
//최근 사용한 주소를 출력해준다. 
int  Application::printrecentaddress()
{
	cout << endl;
	cout << "\t        ※메일에서 최근 사용한 주소" << endl;
	m_hqueue.reset();
	QltemType test;
	cout << endl << endl;
	int length = m_hqueue.getlength();
	if (length == 0)
	{
		cout << "\t          메일에서 사용한 최근 주소가 없습니다. " << endl;
		return 1;
	}
	else
	{
		m_hqueue.reset();
		for (int i = 0; i < length; i++)
		{
			cout << "\t          " << i + 1 << " ";
			m_hqueue.GetNextItem(test);
			test.DisplayRecord_address_OnScreen();
			cout << endl;
		}
	}
	return 0;
}

void Application::savecontactlist()
{
	QltemType data;
	bool finish = true;
	int length = m_hqueue.getlength();
	cout << endl;
	if (length == 0)
	{
		cout << "\t          메일에서 사용한 최근 주소가 없어서 저장할 수 없습니다. " << endl;
		return ;
	}
	else{
		printrecentaddress();
		while (finish)
		{
			cout << endl;
			cout << "\t        ※저장하고 싶은 주소를 골라주세요--> ";
			int c, name;
			cin >> c;
			cout << endl;
			cout << "\t        ※이름도 함께 저장하시겠습니까?(yes:1, no:0) --> ";
			cin >> name;
			int length = m_hqueue.getlength();
			cout << endl;
			if (c > length)
			{
				cout << "\t          범위 안에 있는 주소를 선택해주세요ㅜ" << endl;
			}
			else
			{
				if (name == 0)
				{
					m_hqueue.reset();
					for (int i = 0; i < c; i++)
					{
						m_hqueue.GetNextItem(data);
					}
					m_hqueue.DeleteItem(data);
					contactlist.Additem(data);
					cout << "\t          저장되었습니다!";
					finish = false;
				}
				else
				{
					m_hqueue.reset();
					for (int i = 0; i < c; i++)
					{
						m_hqueue.GetNextItem(data);
					}
					m_hqueue.DeleteItem(data);
					data.SetnameFromKB();
					contactlist.Additem(data);
					cout << "\t          저장되었습니다!";
					finish = false;
				}
			}
		}
	}
}






//휴지통에서 그에따른 코맨드입력문
int Application::garbage_mail_folder_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    ┌────────휴지통──────────┐" << endl;
	cout << "\t    │  1 : 보여주기                            │" << endl;
	cout << "\t    │  2 : 보낸메일함으로 보내기               │" << endl;
	cout << "\t    │  3 : 삭제하기                            │" << endl;
	cout << "\t    │  0 : 폴더함으로 돌아간다.                │" << endl;
	cout << "\t    └─────────────────────┘" << endl << endl;
	cout << endl << "\t    골라주세요 --> ";
	cin >> command;
	cout << endl;

	return command;
}
// 휴지통에서 command에서 입력받는 경우를 말한다. 
void Application::garbage_mail_folder()
{
	QltemType key;
	system("cls");
	while (1)
	{

		m_Command = garbage_mail_folder_command();

		switch (m_Command)
		{
		case 1:		// 아이템을 추가한다
			printgarbagemail();
			break;
		case 2:		// 아이템을 삭제한다
			Gobacktosendmail();
			break;
		case 3:		// 아이템을 삭제한다
			deletegarbagemail();
			break;
		case 0:
			select_mail_forder();
			break;
		default:
			cout << "\t    다시골라주세요!!!!\n";
			break;
		}
	}
}

//휴지통에서 메일을 출력한다. 
void Application::printgarbagemail()
{
	ItemType t1;
	int m = m_garbagmail.GetLength();
	m_garbagmail.ResetList();
	cout << "\t        ※휴지통 메일함" << endl;
	if (m == 0)
		cout << "\t        휴지통이 비었습니다." << endl;
	else
	{
		cout << endl;
		cout << "\t       " << "읽음" << setw(20) << "보낸사람의 주소 " << setw(15)<<"참조인" << setw(15) << "날짜 " << "   " << setw(18) << "내용 " << endl;
		for (int i = 0; i < m; i++)
		{
			cout << endl;
			m_garbagmail.GetNextItem(t1);
			t1.Displaysimlplemail();
		}
	}
}

//휴지통에서 메일을 삭제하는 함수 
void Application::deletegarbagemail()
{
	int length = m_garbagmail.GetLength();
	system("cls");
	cout << endl << endl;
	cout << "\t       ※삭제할 메일을 골라주세요※ " << endl;
	if (length == 0)
		cout << "\t    메일함이 비었습니다. ㅜㅜ " << endl;
	else
	{
		cout << "\t       ->전체 삭제 하실건가요?(맞으면 0 아니면 1)  ";
		int select;
		cin >> select;
		if (select == 0)
		{
			m_garbagmail.MakeEmpty();
			return;
		}                                         
		length = m_garbagmail.GetLength();
		ItemType test;
		int menu_item = 0;
		int run = 0;
		int x = 11;
		bool running = true;
		gotoXY(16, 5); cout << "휴지통";
		gotoXY(16, 7); cout << "선택은 엔터 모두 선택하고 삭제시에 스페이스바";
		gotoXY(16, 9); cout << "   선택  " << "받는사람 주소 " << setw(13) << "  참조인 " << setw(17) << "날짜 " << setw(15) << "내용 " << endl;
		gotoXY(16, 11); cout << "->";

		while (running)
		{
			while (_kbhit()) _getch();

			//int length = receivedmail_templist.GetLength();
			m_garbagmail.ResetList();

			for (int i = 0; i < length; i++)
			{
				gotoXY(20, i + 11);
				m_garbagmail.GetNextItem(test);
				if (!arr2[i]) cout << "■    ";
				else cout << "□    ";
				test.Displaysimlplemail_send();
			}

			system("pause>nul"); // the >nul bit causes it the print no message

			if (GetAsyncKeyState(VK_DOWN) && x != 10 + length) //down button pressed
			{
				gotoXY(16, x); cout << "  ";
				x++;
				gotoXY(16, x); cout << "->";
				menu_item++;
				continue;

			}

			if (GetAsyncKeyState(VK_UP) && x != 11) //up button pressed
			{
				gotoXY(16, x); cout << "  ";
				x--;
				gotoXY(16, x); cout << "->";
				menu_item--;
				continue;
			}


			if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			{ // Enter key pressed
				arr2[menu_item] = false;
				continue;
			}

			if (GetAsyncKeyState(VK_SPACE))
			{
				int i = 0;
				while (1)
				{
					if (arr2[i] == false)//선택한 것이 있다는 것은 삭제할 것이 있으므로 아래를 수행
						break;
					else if (i == length - 1)//만약 어떤 것도 선택하지 않은 경우에는 아무 것도 하지 않고 return한다. 
						return;
					i++;
				}
				int count = 0;
				m_garbagmail.ResetList();
				ItemType lovegyusu;
				for (int i = 0; i < length; i++) {
					m_garbagmail.GetNextItem(lovegyusu);
					if (arr2[i] == false) {
						m_garbagmail.Delete(lovegyusu);
						m_garbagmail.ResetList();
						for (int j = 0; j < i - count; j++) {
							m_garbagmail.GetNextItem(lovegyusu);
						}
						count++;
					}
				}

				for (int i = 0; i < 100; i++)
				{
					arr2[i] = true;
				}
				break;

			}

		}
	}

}


//휴지통에서 다시 보낸메일함으로 가는 경우 
void Application::Gobacktosendmail()
{
	ItemType data1, data2, test;
	string keytime;
	cout << "\t        ※보낸메일함으로 보낼메일을 선택해주세요 . " << endl;
	cout << endl;

	cout << "\t        시작 시간을 입력(년도 월 일 시 분 초 ) ";
	cin >> keytime;
	data1.SetDate(keytime);
	cout << endl;
	cout << "\t        끝 시간을 입력(년도 월 일 시 분 초 ) ";
	cin >> keytime;


	//휴지통에서 그 메일을 찾아주기 위해 지시자를 리셋한다 .
	m_garbagmail.ResetList();
	int length = m_garbagmail.GetLength();
	for (int i = 0; i < length; i++)//총길이동안 
	{
		m_garbagmail.GetNextItem(test);
		if ((test>data1&&test < data2) || test == data1 || test == data2)//시작과 끝시간 사이에있는 메일의 경우 
		{
			m_list.Add(test);
			m_garbagmail.Delete(test);
		}
	}
}


int Application::make_folder_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    ┌─────────폴더관리─────────┐" << endl;
	cout << "\t    │  1 : 새로운 폴더 만들기                    │" << endl;
	cout << "\t    │  2 : 현재 있는 폴더 보여주기               │" << endl;
	cout << "\t    │  3 : 폴더 이동하기                         │" << endl;
	cout << "\t    │  4 : 폴더 삭제하기                         │" << endl;
	cout << "\t    │  5 : 메일을 이동한다.                      │" << endl;
	cout << "\t    │  0 : 폴더함으로 돌아간다.                  │" << endl;
	cout << "\t    └──────────────────────┘" << endl << endl;
	cout << endl << "\t    골라주세요 --> ";
	cin >> command;
	cout << endl;

	return command;

}
void Application::take_mail_folder()
{


}
void Application::make_folder()
{
	system("cls");

	char strBuffer[_MAX_PATH] = { 0, };

	_finddata_t fd;
	long handle;
	int result = 1;

	char tempPath[256];
	string currentPath = _getcwd(tempPath, 256);
	currentPath = currentPath + "\\" + currentUser.get_userId();

	int nResult = _chdir(currentPath.c_str());

	if (nResult == 0)
	{
		printf("이동 성공");
	}
	else if (nResult == -1)
	{
		perror("이동 실패 - ");
	}
	allFolder.Setfilename(currentPath.c_str());

	Load_Folder_List(allFolder);

	while (1)
	{
		m_Command = make_folder_command();

		switch (m_Command)
		{
		case 1:		// 아이템을 추가한다
			Make_folder();
			break;
		case 2:		// 폴더리스트를 보여준다.
			Display_folder();
			break;

		case 3: // 폴더를 이동한다.
			move_folder_path();
			break;
		case 4:		// 아이템을 삭제한다
			Delete_folder();
			break;
		case 5:
			Move_mail();
			break;
		case 0:
			select_mail_forder();
			break;
		default:
			cout << "\t    다시골라주세요!!!!\n";
			break;
		}
	}
}



void Application::Move_mail() {

	
	// 선택해서 리스트 가져오는거
	formoveMailList();

	system("cls");

	cout << " 선택된 메일 리스트 " << endl << endl;

	mail_temp_list.ResetItem();
	for (int i = 0; i < mail_temp_list.GetLength(); i++){
		ItemType temp;
		mail_temp_list.GetNextItem(temp);
		temp.DisplayRecordOnDeleteScreen();
	}

	cout << endl << "이동할 폴더를 입력하세요 " << endl << endl;
	cout << "-------------------------------------------------" << endl << endl;
	move_mail_path();

	// 이동할 폴더 입력


	// 그 폴더로 이동해서 그 폴더안에 있는 메일리스트에 입력받은 메일을 추가

}



void Application::move_mail_path() {
	Display_folder();
	cout << endl;
	cout << "\t        ※어느 폴더로 가시겠습니까 ?  ";
	string name;
	cin >> name;

	int nResult = _chdir(name.c_str());

	int length = allFolder.fos->GetLength();
	allFolder.fos->ResetItem();
	MyFolder folder;
	for (int i = 0; i < length; i++)
	{
		allFolder.fos->GetNextItem(folder);
		if (folder.Getfilename() == name)
		{
			mail_temp_list.ResetItem();
			for (int i = 0; i < mail_temp_list.GetLength(); i++){
				ItemType temp;
				mail_temp_list.GetNextItem(temp);
				folder.Add_mail(temp);
			}	
			Load_Folder_List(folder);
			allFolder.fos->update(folder);
		}
	
	}

	folder.Mails.ResetItem();
	for (int i = 0; i < folder.Getmails().GetLength(); i++) {
		ItemType itemType;
		folder.Mails.GetNextItem(itemType);
		itemType.DisplayRecordOnDeleteScreen();
	}
	cout << endl << endl;
	Display_folder();

	if (nResult == 0)
	{
		printf("\t        폴더 이동 성공");
	}
	else if (nResult == -1)
	{
		perror("\t        폴더 이동 실패 - 폴더 안에 파일이 있거나 사용중\n");
		printf("\t        errorno : %d", errno);
	}

	return;

}

void Application::move_folder_path() {
	Display_folder();
	cout << endl;
	cout << "\t        ※어느 폴더로 가시겠습니까 ?  ";
	string name;
	cin >> name;

	int nResult = _chdir(name.c_str());

	int length = allFolder.fos->GetLength();
	allFolder.fos->ResetItem();
	MyFolder folder;
	for (int i = 0; i < length; i++)
	{
		allFolder.fos->GetNextItem(folder);
		if (folder.Getfilename() == name)
		{
			Load_Folder_List(folder);
			allFolder.fos->update(folder);		
		}	
	}

	if (nResult == 0)
	{
		printf("\t        폴더 이동 성공");
	}
	else if (nResult == -1)
	{
		perror("\t        폴더 이동 실패 - 폴더 안에 파일이 있거나 사용중\n");
		printf("\t        errorno : %d", errno);
	}

	return;

}


void Application::Make_folder() // 폴더생성
{
	string name;
	cin >> name;

	int nResult = _mkdir(name.c_str());
	if (nResult == 0)
	{
		printf("\t        폴더 생성 성공");
	}
	else if (nResult == -1)
	{
		perror("\t        폴더 생성 실패 - 폴더가 이미 있거나 부정확함\n");
		printf("\t        errorno : %d", errno);
	}


//Folder test;
//cout << "새로운 폴더 만들기" << endl;
//int length = folder.GetLength();
//if (length == 0)
//{
//	test.Setfoldername_fron_kb();
//	folder.Add(test);
//}
//else
//{
//	folder.ResetItem();
//	for (int i = 0; i < length; i++)
//	{
//		cout << i + 1 << "번째 ";
//		folder.GetNextItem(test);
//	}
//}
}
void Application::Display_folder()
{
	cout << "\t        ※현재 있는 폴더 보여주기" << endl;
	cout << endl;
	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);  //현재 폴더 내 모든 파일을 찾는다.

	intptr_t hFile;

	if (handle == -1)
	{
		printf("\t        폴더가 없습니다.\n");
		return;
	}

	while (result != -1)
	{
		if (fd.attrib & _A_SUBDIR )// 디렉토리일시
		{
			if (strcmp(fd.name, ".") == 0 || strcmp(fd.name, "..") == 0) {
				
			}
			else {
				printf("\t        폴더: %s\n", fd.name);

			}
		}
		
		result = _findnext(handle, &fd);
	}

	_findclose(handle);
	return;	
}

void Application::Load_Folder_List(MyFolder &currentFolder) {

	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);  //현재 폴더 내 모든 파일을 찾는다.
	
	DoublySortedLinkedList<MyFolder> myFolderList;
	myFolderList.ResetItem();
	intptr_t hFile;

	if (handle == -1)
	{
		printf("\t        폴더가 없습니다.\n");
		return;
	}

	while (result != -1)
	{
		if (fd.attrib & _A_SUBDIR)// 디렉토리일시
		{
			if (strcmp(fd.name, ".") == 0 || strcmp(fd.name, "..") == 0) {

			}
			else {
				MyFolder tempFolder;
				tempFolder.Setfilename(fd.name);
				myFolderList.Add(tempFolder);
			}
		}
		
		result = _findnext(handle, &fd);
	}

	currentFolder.Setfolder(myFolderList);

	currentfolder = myFolderList;

	_findclose(handle);
	return;

}
void Application::Delete_folder()
{
	cout << "\t        ※폴더 삭제하기 " << endl;

	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);  //현재 폴더 내 모든 파일을 찾는다.

	if (handle == -1)
	{
		printf("There were no files.\n");
		return;
	}
	result = _findnext(handle, &fd);
	result = _findnext(handle, &fd);
	while (result != -1)
	{
		printf("\t        Folder: %s\n", fd.name);
		result = _findnext(handle, &fd);
	}

	_findclose(handle);

	cout << "\t         삭제할 폴더의 이름을 입력하세요 :" ;
	string name;
	cin >> name;

	int nResult = _rmdir(name.c_str());

	if (nResult == 0)
	{
		printf("\t        폴더 삭제 성공");
	}
	else if (nResult == -1)
	{
		perror("\t        폴더 삭제 실패 - 폴더 안에 파일이 있거나 사용중\n");
		printf("errorno : %d", errno);
	}

	return;


}

//내용 같은 것을 찾기위해 사용하는 함수 
bool Application::IsThereFind(std::string data, std::string item)
{
	// data string 에 item 이 존재하는지 안하는지 boolean value를 리턴한다.
	if (data.find(item) != std::string::npos)
	{
		// 존재하면 
		return true;
	}
	else
	{
		return false;
	}
}


int  Application::GetBinarySearch(string target,int& index)
{
	target.substr(0, 1);
	const char * cstr = target.c_str();
	char head = *cstr;

	int asci = (int)head;
	asci = asci - 97;
	index = asci;

	bool found = false;
	int mid[3] = { 0, (number[asci]-1)/2, number[asci] };
	int temp = -2;

	string address;

	/*
	DWORD start;
	DWORD end;

	start = GetTickCount();
	*/
	while (temp != mid[1])
	{
		Mail_Name[asci][mid[1]].GetSendAddress().ResetItem();
		Mail_Name[asci][mid[1]].GetSendAddress().GetNextItem(address);
		Mail_Name[asci][mid[1]].GetSendAddress().GetNextItem(address);
		if (address.compare(target) == 0)
		{
			found = true;
			break;

		}
		else if (address.compare(target) <0)
		{
			temp = mid[1];
			mid[0] = mid[1];
			mid[1] = (mid[1] + mid[2]) / 2;
		}
		else
		{
			temp = mid[1];
			mid[2] = mid[1];
			mid[1] = (mid[1] + mid[0]) / 2;

		}

	}
	//end = GetTickCount();

	//printf("\n실행시간 : %lf \n", (end - start) / (double)1000);
	if (found == true)
		return mid[1];
	else
		return -1;
}

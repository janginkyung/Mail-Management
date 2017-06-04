#include "Application.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

// ������ �����Ҷ� ���Ʒ��� �����ϱ� ���ؼ� ����ϴ� �Լ� 
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
	cout << "\t    ����������������ȯ���մϴ١ݦ�����������������" << endl;
	cout << "\t    ��  1  ȸ������                             ��" << endl;
	cout << "\t    ��  2  Log-In                               ��" << endl;
	cout << "\t    ��  3  ���̵�, ��й�ȣ ã��                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;

	cout << endl << "\t    ����ּ��� --> ";
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
	cout << "\t    ���������ݾ��̵�,��й�ȣ ã��ݦ���������������" << endl;
	cout << "\t    ��  1  ���̵� ã��                            ��" << endl;
	cout << "\t    ��  2  ��й�ȣ ã��                          ��" << endl;
	cout << "\t    ������������������������������������������������" << endl << endl;

	cout << endl << "\t    ����ּ��� --> ";
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
	cout << "\t    �����������������ݾ��̵�ã��ݦ�����������������" << endl;
	cout << "\t    ��   1 : �̸��� �Է��ϼ��� : ";
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
	cout << "\t    ��   ->  ���̵�� " << id << " �Դϴ�. "<<endl;
	cout << "\t    ��                                            ��" << endl;
	cout << "\t    ������������������������������������������������" << endl << endl;

	LogIn();
}
void Application::Found_pw()
{
	string name,  id;
	string password= "";
	system("cls");
	cout << endl << endl;
	cout << "\t    �����������������ݺ�й�ȣã��ݦ�����������������" << endl;
	cout << "\t    ��   1 : �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << "\t    ��   2 : ID�� �Է��ϼ��� : ";
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
			cout << "\t    ��   �׷��� ������ �����ϴ� .                   �� " << endl;
			cout << "\t    ��������������������������������������������������" << endl << endl;
		}
	else
	{
		cout << "\t    ��   ->  ��й�ȣ�� " << password << " �Դϴ�. " << endl;
		cout << "\t    ��                                              ��" << endl;
		cout << "\t    ��������������������������������������������������" << endl << endl;
	}
	LogIn();
}
void Application::registerin()
{
	system("cls");
	string id, pass, name;
	cout << endl << endl;
	cout << "\t    ������������������ȸ�����Ԧ�������������������" << endl;
	cout << "\t    ��  1 : ID�� �Է��ϼ��� : ";
	cin >> id;
	cout << "\t    ��  2 : PassWord�� �Է��ϼ���  : ";

	cin >> pass;
	cout << "\t    ��  3 : �̸��� �Է��ϼ���  : ";
	cin >> name;
	cout << "\t    ��                         .                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;
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
	cout << "\t    ���������������������α��Φ�������������������" << endl;
	cout << "\t    ��  1 : ID  : ";
	cin >> id;
	cout << "\t    ��  2 : PassWord  : ";
	cin >> pass;
	cout << "\t    ��                         .                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;
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
		cout << "\t    �������������������α��Φ���������������������" << endl;
		cout << "\t    ��                         .                ��" << endl;
		cout << "\t    ��          �α��� ������ Ʋ�Ƚ��ϴ�.       ��" << endl;
		cout << "\t    ��          �ٽ� �Է����ּ��� ��.��         ��" << endl;
		cout << "\t    ��                                          ��" << endl;
		cout << "\t    ����������������������������������������������" << endl << endl;
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
	cout << "\t    �����������������������Ԧ���������������������" << endl;
	cout << "\t    ��  1 : ����������                          ��" << endl;
	cout << "\t    ��  2 : ����������                          ��" << endl;
	cout << "\t    ��  3 : �ּҷ�                              ��" << endl;
	cout << "\t    ��  4 : ������                              ��" << endl;
	cout << "\t    ��  5 : ���� ����                           ��" << endl;
	cout << "\t    ��  0 : ������             .                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;
	cout << endl << "\t       ����ּ��� --> ";

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
		cout << "\t    �ٽð���ּ���!!!!\n";
		break;
	}
}


int Application::received_mail_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    �������������������������Ԧ�������������������" << endl;
	cout << "\t    ��  1 : ���� �����ֱ�                       ��" << endl;
	cout << "\t    ��  2 : ���� ����                           ��" << endl;
	cout << "\t    ��  3 : ���� ���� ���� �� �̸����� ã��     ��" << endl;
	cout << "\t    ��  4 : �ּҷ� �˻�                         ��" << endl;
	cout << "\t    ��  0 : ���������� ���ư���.                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;
	cout << endl << "\t       ����ּ��� --> ";
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
		case 1:		// �������� �����Ѵ�
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
			cout << "\t       �ٽð���ּ���!!!!\n";
			break;
		}
	}
}

void Application::Displayrecentadress()
{
	system("cls");
	cout << endl << endl;
	cout << "\t       �ع��������ԡ� " << endl;
	gotoXY(16, 4); cout <<"   ����" << setw(22) << "��������� �ּ� " << setw(18) << "������ " << setw(15) << "��¥ " <<setw(18) << "���� " << endl;
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
			receivedmail.Delete(lovegyusu);//���� ǥ�ø� ���ֱ� ���ؼ� ������ ���� �ٽ� �߰��Ѵ�.
			lovegyusu.Setread("��");//���� ǥ�ø� ���ش��� 
			receivedmail.Add(lovegyusu);//�ٽ� �߰������ش�. 
			lovegyusu.DisplayRecordOnScreen();
			break;
		}	

	}
}
//���������Կ��� ���Ǵ� �Լ� 

void Application::formoveMailList() {

	system("cls");
	Make_empty_arr();
	cout << endl << endl;
	cout << "\t       ���̵��� ������ ����ּ���� " << endl;
	int k = receivedmail.GetLength();
	ItemType test;


	int menu_item = 0, run = 0, x = 11;
	bool running = true;
	bool found = false;

	gotoXY(16, 5); cout << "����������";
	gotoXY(16, 7); cout << "������ ���� ��� �����ϰ� ���ÿϷ�ÿ� �����̽���";
	gotoXY(16, 9); cout << "   ����  " << " ����" << setw(22) << "��������� �ּ� " << setw(18) << "������ " << setw(15) << "��¥ " << setw(18) << "���� " << endl;
	gotoXY(16, 11); cout << "->";


	while (running)
	{
		while (_kbhit()) _getch();
		k = receivedmail.GetLength();
		if (k == 0)
		{
			cout << "\t       �̵��� ������ �����ϴ�. " << endl;
			break;
		}
		//int length = receivedmail_templist.GetLength();
		receivedmail.ResetList();

		for (int i = 0; i < k; i++)
		{
			gotoXY(20, i + 11);
			receivedmail.GetNextItem(test);

			if (!arr[i]) cout << "��    ";
			else cout << "��    ";

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
	cout << "\t       �ػ����� ������ ����ּ���� " << endl;
	int k = receivedmail.GetLength();
	ItemType test;


	int menu_item = 0, run = 0, x = 11;
	bool running = true;
	bool found = false;

	gotoXY(16, 5); cout << "����������";
	gotoXY(16, 7); cout << "������ ���� ��� �����ϰ� �����ÿ� �����̽���";
	gotoXY(16, 9); cout << "   ����  " <<" ����" << setw(22) << "��������� �ּ� " << setw(18) << "������ " << setw(15) << "��¥ " << setw(18) << "���� " << endl;
	gotoXY(16, 11); cout << "->";


	while (running)
	{
		while (_kbhit()) _getch();
		k = receivedmail.GetLength();
		if (k == 0)
		{
			cout << "\t        ������ ������ �����ϴ�. " << endl;
			break; 
		}
		//int length = receivedmail_templist.GetLength();
		receivedmail.ResetList();
		
		for (int i = 0; i < k; i++)
		{
			gotoXY(20, i + 11);
			receivedmail.GetNextItem(test);

			if (!arr[i]) cout << "��    ";
			else cout << "��    ";

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
		if (data.GetReadornot() == "��")
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
	cout << "\t    ������ ���� �� ���ϡ� " << endl;
	int length = receivedmail_temp1.GetLength();
	if (length == 0)
		cout << "\t      ���� ���� ������ �����ϴ�. " << endl;

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
	// list ���� Ž���ϱ� ���� ���� �Լ� 
	cout << "�Է� ";
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

	printf("\n����ð� : %lf \n", (end - start) / (double)1000);
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
		cout << "\t      ã�� �ּҸ� �Է��ϼ��� : ";
		cin >> address;
		int key = GetBinarySearch(address, index);
		if (key == -1)
			cout << "\t      ã�� ����� �����ϴ�. " << endl;
		else
		{
			cout << "\t      ã�Ҵ�." << endl;
			Mail_Name[index][key].DisplayRecordOnScreen();
		}

}
void Application::findmailbyaddress()
{
	int k = receivedmail.GetLength();
	ItemType  test;
	string target,address;
	cout << "\t    �����ּ� : ";
	cin >> target;
	receivedmail.ResetList();
	cout << endl;
	cout << "\t    ���ּҷ� ã�� ����� " << endl;
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
		cout << "\t      �������� �ʽ��ϴ٤�. " << endl;
}



int Application::send_mail_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    �������������������������Ԧ�������������������" << endl;
	cout << "\t    ��  1 : ���� ������                         ��" << endl;
	cout << "\t    ��  2 : ���������� ����                     ��" << endl;
	cout << "\t    ��  3 : ���� ����                           ��" << endl;
	cout << "\t    ��  4 : �������� �˻�                       ��" << endl;
	cout << "\t    ��  0 : ���������� ���ư���.                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;
	cout << endl << "\t       ����ּ��� --> ";
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
			cout << "\t    �ٽð���ּ���!!!!\n";
			break;
		}
	}
}
// ���� �����Կ��� ����ϴ� �Լ� 

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
	cout << "\t       �غ��������� �� " << endl;
	if (k == 0)
		cout << "\t    �������� ������ϴ�. �̤� " << endl;
	else
	{
		gotoXY(16, 4); cout << setw(23) << "�޴»�� �ּ� " << setw(23) << "������ " << setw(18) << "��¥" << setw(20) << "���� " << endl;
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
	cout << "\t       �ػ����� ������ ����ּ���� " << endl;
	if (k == 0)
		cout << "\t    �������� ������ϴ�. �̤� " << endl;
	else
	{
		k = m_list.GetLength();
		ItemType test;
		int menu_item = 0;
		int run = 0;
		int x = 11;
		bool running = true;
		gotoXY(16, 5); cout << "����������";
		gotoXY(16, 7); cout << "������ ���� ��� �����ϰ� �����ÿ� �����̽���";
		gotoXY(16, 9); cout << "   ����  " << "�޴»�� �ּ� " << setw(13) << "  ������ "<<setw(17) << "��¥ " <<setw(15) << "���� " << endl;
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
				if (!arr2[i]) cout << "��    ";
				else cout << "��    ";
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
					if (arr2[i] == false)//������ ���� �ִٴ� ���� ������ ���� �����Ƿ� �Ʒ��� ����
						break;
					else if (i == k - 1)//���� � �͵� �������� ���� ��쿡�� �ƹ� �͵� ���� �ʰ� return�Ѵ�. 
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


//�������� ������ ã�� ���ؼ� ���ο� ������ �����ϰ� �ð��뺰�� ã���ִ� ������ �Ѵ�. 
void Application::find_mail_content()
{
	string key , contents;
	cout << "\t       ��ã�� ���� ������ �Է����ּ����" << endl;
	cout << "\t          -> ";
	cin >> key;
	ItemType test;
	bool found = false;
	int length = m_list.GetLength();
	m_list.ResetList();
	for (int i = 0; i < length; i++)//�ѱ��̵��� 
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
		cout <<endl<< "\t           ã�� ����� �����ϴ�. " << endl;
}

int Application::contact_folder_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    �������������������ּҷϦ���������������������" << endl;
	cout << "\t    ��  1 : �����ϱ�                            ��" << endl;
	cout << "\t    ��  2 : �����ϱ�                            ��" << endl;
	cout << "\t    ��  3 : �̸����� ã��                       ��" << endl;
	cout << "\t    ��  4 : �����ֱ�                            ��" << endl;
	cout << "\t    ��  5 : ���Ͽ��� ����� �ּ� ����           ��" << endl;
	cout << "\t    ��  0 : ���������� ���ư���.                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;
	cout << endl << "\t       ����ּ��� --> ";
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
		case 1:		// �������� �߰��Ѵ�
			conatactadd();
			break;
		case 2:		// �������� �����Ѵ�
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
			cout << "\t    �ٽð���ּ���!!!!\n";
			break;
		}
	}
}

//�ּҷϿ� �������� �߰��ϴ� �Լ��̴�.  
void Application::conatactadd()
{
	cout << "\t       �������� ��� �Է�" << endl;
	QltemType data;
	cout << endl;
	data.SetFromKB();
	contactlist.Additem(data);
}
//�ּҷϿ��� �̸����� ������ ã�Ƽ� �����ϴ� ������ �Ѵ�. 
void Application::conatactdelete()
{
	printcontact();
	cout << "\t       �ػ����� ��� ���� " << endl;
	QltemType data;
	data.SetnameFromKB();
	contactlist.Deleteitem(data);
	printcontact();
}
//�ּҷϿ��� �̸����� ������ ã�Ƽ� ������ش�. 
void Application::conatactsearch()
{
	bool found;
	cout << "\t        ��ã�� ����� ������ �Է����ּ��� " << endl;
	QltemType data;
	data.SetnameFromKB();
	contactlist.Retrieveitem(data, found);
	if (found== false)
		cout << "\t       ã�� ���߽��ϴ�. " << endl;
	else
	{
		cout << endl << "\t        ¥��" << endl;
		data.DisplayRecordOnScreen();
	}

	return;
}
//�ּҷϿ��� �������� ����Ѵ�. 
void Application::printcontact()
{
	cout << endl << endl;
	cout << "\t       ���ּҷ� " << endl;
	if (contactlist.GetLength() == 0)
		cout << "\t       ����ֽ��ϴ�.�̤�" << endl;
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
		cout << "\t    �������������Ͽ��� �ֱ� ����� �ּҦ���������" << endl;
		cout << "\t    ��  1 : �����ֱ�                            ��" << endl;
		cout << "\t    ��  2 : �����ϱ�                            ��" << endl;
		cout << "\t    ��  3 : �ּҷ����� ���ư���                 ��" << endl;
		cout << "\t    ����������������������������������������������" << endl << endl;
		cout << endl << "\t       ����ּ��� --> ";
		cin >> command;

		m_Command = command;
		switch (m_Command)
		{
		case 1:		// �������� �߰��Ѵ�
			printrecentaddress();
			break;
		case 2:		// �������� �����Ѵ�
			savecontactlist();
			break;
		case 3:
			contact_folder();
			break;
		default:
			cout << "\t    �ٽð���ּ���!!!!\n";
			break;
		}
	}


}
//�ֱ� ����� �ּҸ� ������ش�. 
int  Application::printrecentaddress()
{
	cout << endl;
	cout << "\t        �ظ��Ͽ��� �ֱ� ����� �ּ�" << endl;
	m_hqueue.reset();
	QltemType test;
	cout << endl << endl;
	int length = m_hqueue.getlength();
	if (length == 0)
	{
		cout << "\t          ���Ͽ��� ����� �ֱ� �ּҰ� �����ϴ�. " << endl;
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
		cout << "\t          ���Ͽ��� ����� �ֱ� �ּҰ� ��� ������ �� �����ϴ�. " << endl;
		return ;
	}
	else{
		printrecentaddress();
		while (finish)
		{
			cout << endl;
			cout << "\t        �������ϰ� ���� �ּҸ� ����ּ���--> ";
			int c, name;
			cin >> c;
			cout << endl;
			cout << "\t        ���̸��� �Բ� �����Ͻðڽ��ϱ�?(yes:1, no:0) --> ";
			cin >> name;
			int length = m_hqueue.getlength();
			cout << endl;
			if (c > length)
			{
				cout << "\t          ���� �ȿ� �ִ� �ּҸ� �������ּ����" << endl;
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
					cout << "\t          ����Ǿ����ϴ�!";
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
					cout << "\t          ����Ǿ����ϴ�!";
					finish = false;
				}
			}
		}
	}
}






//�����뿡�� �׿����� �ڸǵ��Է¹�
int Application::garbage_mail_folder_command()
{
	int command;
	cout << endl << endl;
	cout << "\t    �����������������������릡��������������������" << endl;
	cout << "\t    ��  1 : �����ֱ�                            ��" << endl;
	cout << "\t    ��  2 : �������������� ������               ��" << endl;
	cout << "\t    ��  3 : �����ϱ�                            ��" << endl;
	cout << "\t    ��  0 : ���������� ���ư���.                ��" << endl;
	cout << "\t    ����������������������������������������������" << endl << endl;
	cout << endl << "\t    ����ּ��� --> ";
	cin >> command;
	cout << endl;

	return command;
}
// �����뿡�� command���� �Է¹޴� ��츦 ���Ѵ�. 
void Application::garbage_mail_folder()
{
	QltemType key;
	system("cls");
	while (1)
	{

		m_Command = garbage_mail_folder_command();

		switch (m_Command)
		{
		case 1:		// �������� �߰��Ѵ�
			printgarbagemail();
			break;
		case 2:		// �������� �����Ѵ�
			Gobacktosendmail();
			break;
		case 3:		// �������� �����Ѵ�
			deletegarbagemail();
			break;
		case 0:
			select_mail_forder();
			break;
		default:
			cout << "\t    �ٽð���ּ���!!!!\n";
			break;
		}
	}
}

//�����뿡�� ������ ����Ѵ�. 
void Application::printgarbagemail()
{
	ItemType t1;
	int m = m_garbagmail.GetLength();
	m_garbagmail.ResetList();
	cout << "\t        �������� ������" << endl;
	if (m == 0)
		cout << "\t        �������� ������ϴ�." << endl;
	else
	{
		cout << endl;
		cout << "\t       " << "����" << setw(20) << "��������� �ּ� " << setw(15)<<"������" << setw(15) << "��¥ " << "   " << setw(18) << "���� " << endl;
		for (int i = 0; i < m; i++)
		{
			cout << endl;
			m_garbagmail.GetNextItem(t1);
			t1.Displaysimlplemail();
		}
	}
}

//�����뿡�� ������ �����ϴ� �Լ� 
void Application::deletegarbagemail()
{
	int length = m_garbagmail.GetLength();
	system("cls");
	cout << endl << endl;
	cout << "\t       �ػ����� ������ ����ּ���� " << endl;
	if (length == 0)
		cout << "\t    �������� ������ϴ�. �̤� " << endl;
	else
	{
		cout << "\t       ->��ü ���� �Ͻǰǰ���?(������ 0 �ƴϸ� 1)  ";
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
		gotoXY(16, 5); cout << "������";
		gotoXY(16, 7); cout << "������ ���� ��� �����ϰ� �����ÿ� �����̽���";
		gotoXY(16, 9); cout << "   ����  " << "�޴»�� �ּ� " << setw(13) << "  ������ " << setw(17) << "��¥ " << setw(15) << "���� " << endl;
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
				if (!arr2[i]) cout << "��    ";
				else cout << "��    ";
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
					if (arr2[i] == false)//������ ���� �ִٴ� ���� ������ ���� �����Ƿ� �Ʒ��� ����
						break;
					else if (i == length - 1)//���� � �͵� �������� ���� ��쿡�� �ƹ� �͵� ���� �ʰ� return�Ѵ�. 
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


//�����뿡�� �ٽ� �������������� ���� ��� 
void Application::Gobacktosendmail()
{
	ItemType data1, data2, test;
	string keytime;
	cout << "\t        �غ������������� ���������� �������ּ��� . " << endl;
	cout << endl;

	cout << "\t        ���� �ð��� �Է�(�⵵ �� �� �� �� �� ) ";
	cin >> keytime;
	data1.SetDate(keytime);
	cout << endl;
	cout << "\t        �� �ð��� �Է�(�⵵ �� �� �� �� �� ) ";
	cin >> keytime;


	//�����뿡�� �� ������ ã���ֱ� ���� �����ڸ� �����Ѵ� .
	m_garbagmail.ResetList();
	int length = m_garbagmail.GetLength();
	for (int i = 0; i < length; i++)//�ѱ��̵��� 
	{
		m_garbagmail.GetNextItem(test);
		if ((test>data1&&test < data2) || test == data1 || test == data2)//���۰� ���ð� ���̿��ִ� ������ ��� 
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
	cout << "\t    ������������������������������������������������" << endl;
	cout << "\t    ��  1 : ���ο� ���� �����                    ��" << endl;
	cout << "\t    ��  2 : ���� �ִ� ���� �����ֱ�               ��" << endl;
	cout << "\t    ��  3 : ���� �̵��ϱ�                         ��" << endl;
	cout << "\t    ��  4 : ���� �����ϱ�                         ��" << endl;
	cout << "\t    ��  5 : ������ �̵��Ѵ�.                      ��" << endl;
	cout << "\t    ��  0 : ���������� ���ư���.                  ��" << endl;
	cout << "\t    ������������������������������������������������" << endl << endl;
	cout << endl << "\t    ����ּ��� --> ";
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
		printf("�̵� ����");
	}
	else if (nResult == -1)
	{
		perror("�̵� ���� - ");
	}
	allFolder.Setfilename(currentPath.c_str());

	Load_Folder_List(allFolder);

	while (1)
	{
		m_Command = make_folder_command();

		switch (m_Command)
		{
		case 1:		// �������� �߰��Ѵ�
			Make_folder();
			break;
		case 2:		// ��������Ʈ�� �����ش�.
			Display_folder();
			break;

		case 3: // ������ �̵��Ѵ�.
			move_folder_path();
			break;
		case 4:		// �������� �����Ѵ�
			Delete_folder();
			break;
		case 5:
			Move_mail();
			break;
		case 0:
			select_mail_forder();
			break;
		default:
			cout << "\t    �ٽð���ּ���!!!!\n";
			break;
		}
	}
}



void Application::Move_mail() {

	
	// �����ؼ� ����Ʈ �������°�
	formoveMailList();

	system("cls");

	cout << " ���õ� ���� ����Ʈ " << endl << endl;

	mail_temp_list.ResetItem();
	for (int i = 0; i < mail_temp_list.GetLength(); i++){
		ItemType temp;
		mail_temp_list.GetNextItem(temp);
		temp.DisplayRecordOnDeleteScreen();
	}

	cout << endl << "�̵��� ������ �Է��ϼ��� " << endl << endl;
	cout << "-------------------------------------------------" << endl << endl;
	move_mail_path();

	// �̵��� ���� �Է�


	// �� ������ �̵��ؼ� �� �����ȿ� �ִ� ���ϸ���Ʈ�� �Է¹��� ������ �߰�

}



void Application::move_mail_path() {
	Display_folder();
	cout << endl;
	cout << "\t        �ؾ�� ������ ���ðڽ��ϱ� ?  ";
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
		printf("\t        ���� �̵� ����");
	}
	else if (nResult == -1)
	{
		perror("\t        ���� �̵� ���� - ���� �ȿ� ������ �ְų� �����\n");
		printf("\t        errorno : %d", errno);
	}

	return;

}

void Application::move_folder_path() {
	Display_folder();
	cout << endl;
	cout << "\t        �ؾ�� ������ ���ðڽ��ϱ� ?  ";
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
		printf("\t        ���� �̵� ����");
	}
	else if (nResult == -1)
	{
		perror("\t        ���� �̵� ���� - ���� �ȿ� ������ �ְų� �����\n");
		printf("\t        errorno : %d", errno);
	}

	return;

}


void Application::Make_folder() // ��������
{
	string name;
	cin >> name;

	int nResult = _mkdir(name.c_str());
	if (nResult == 0)
	{
		printf("\t        ���� ���� ����");
	}
	else if (nResult == -1)
	{
		perror("\t        ���� ���� ���� - ������ �̹� �ְų� ����Ȯ��\n");
		printf("\t        errorno : %d", errno);
	}


//Folder test;
//cout << "���ο� ���� �����" << endl;
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
//		cout << i + 1 << "��° ";
//		folder.GetNextItem(test);
//	}
//}
}
void Application::Display_folder()
{
	cout << "\t        ������ �ִ� ���� �����ֱ�" << endl;
	cout << endl;
	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);  //���� ���� �� ��� ������ ã�´�.

	intptr_t hFile;

	if (handle == -1)
	{
		printf("\t        ������ �����ϴ�.\n");
		return;
	}

	while (result != -1)
	{
		if (fd.attrib & _A_SUBDIR )// ���丮�Ͻ�
		{
			if (strcmp(fd.name, ".") == 0 || strcmp(fd.name, "..") == 0) {
				
			}
			else {
				printf("\t        ����: %s\n", fd.name);

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
	handle = _findfirst(".\\*.*", &fd);  //���� ���� �� ��� ������ ã�´�.
	
	DoublySortedLinkedList<MyFolder> myFolderList;
	myFolderList.ResetItem();
	intptr_t hFile;

	if (handle == -1)
	{
		printf("\t        ������ �����ϴ�.\n");
		return;
	}

	while (result != -1)
	{
		if (fd.attrib & _A_SUBDIR)// ���丮�Ͻ�
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
	cout << "\t        ������ �����ϱ� " << endl;

	_finddata_t fd;
	long handle;
	int result = 1;
	handle = _findfirst(".\\*.*", &fd);  //���� ���� �� ��� ������ ã�´�.

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

	cout << "\t         ������ ������ �̸��� �Է��ϼ��� :" ;
	string name;
	cin >> name;

	int nResult = _rmdir(name.c_str());

	if (nResult == 0)
	{
		printf("\t        ���� ���� ����");
	}
	else if (nResult == -1)
	{
		perror("\t        ���� ���� ���� - ���� �ȿ� ������ �ְų� �����\n");
		printf("errorno : %d", errno);
	}

	return;


}

//���� ���� ���� ã������ ����ϴ� �Լ� 
bool Application::IsThereFind(std::string data, std::string item)
{
	// data string �� item �� �����ϴ��� ���ϴ��� boolean value�� �����Ѵ�.
	if (data.find(item) != std::string::npos)
	{
		// �����ϸ� 
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

	//printf("\n����ð� : %lf \n", (end - start) / (double)1000);
	if (found == true)
		return mid[1];
	else
		return -1;
}

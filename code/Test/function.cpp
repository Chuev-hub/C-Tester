#include "lib.h"
#include "function.h"
#include "class.h"
#include "struct.h"


void preview_input_str(string str, vector<string> data_,  console &cons,int i )
{
	if (i != 15)
	{
		cons.item_color();
		for (int j = 0; j < i; j++)
			cout << "\n";
		cout << "\t\t\t      Input " << str << ": ";
		cons.main_color();
	}
	else
	{

		if (str == "login")
		{
			cons.item_color();
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cout << "\t\t\t      Input login: ";

		}
		else if (str == "password")
		{
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cons.back_color();
			cout << "\t\t\t      Input login: " << data_[0] << endl;
			cons.item_color();
			cout << "\t\t\t      Input password: ";
		}
		else if (str == "name")
		{
			cons.back_color();
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cout << "\t\t\t      Input login: " << data_[0] << endl;
			cout << "\t\t\t      Input password: ";
			for (int j = 0; j < data_[1].size(); j++)
				cout << '*';
			cout << endl;
			cons.item_color();
			cout << "\t\t\t      Input name: ";
		}
		else if (str == "surname")
		{
			cons.back_color();
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cout << "\t\t\t      Input login: " << data_[0] << endl;
			cout << "\t\t\t      Input password: ";
			for (int j = 0; j < data_[1].size(); j++)
				cout << '*';
			cout << endl;
			cout << "\t\t\t      Input name: " << data_[2] << endl;
			cons.item_color();
			cout << "\t\t\t      Input surname: ";
		}
		else if (str == "patronymic")
		{
			cons.back_color();
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cout << "\t\t\t      Input login: " << data_[0] << endl;
			cout << "\t\t\t      Input password: ";
			for (int j = 0; j < data_[1].size(); j++)
				cout << '*';
			cout << endl;
			cout << "\t\t\t      Input name: " << data_[2] << endl;
			cout << "\t\t\t      Input surname: " << data_[3] << endl;
			cons.item_color();
			cout << "\t\t\t      Input patronymic: ";
		}
		else if (str == "address")
		{
			cons.back_color();
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cout << "\t\t\t      Input login: " << data_[0] << endl;
			cout << "\t\t\t      Input password: ";
			for (int j = 0; j < data_[1].size(); j++)
				cout << '*';
			cout << endl;
			cout << "\t\t\t      Input name: " << data_[2] << endl;
			cout << "\t\t\t      Input surname: " << data_[3] << endl;
			cout << "\t\t\t      Input patronymic: " << data_[4] << endl;
			cons.item_color();
			cout << "\t\t\t      Input address: ";
		}
		else if (str == "phone number")
		{
			cons.back_color();
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cout << "\t\t\t      Input login: " << data_[0] << endl;
			cout << "\t\t\t      Input password: ";
			for (int j = 0; j < data_[1].size(); j++)
				cout << '*';
			cout << endl;
			cout << "\t\t\t      Input name: " << data_[2] << endl;
			cout << "\t\t\t      Input surname: " << data_[3] << endl;
			cout << "\t\t\t      Input patronymic: " << data_[4] << endl;
			cout << "\t\t\t      Input address: " << data_[5] << endl;
			cons.item_color();
			cout << "\t\t\t      Input phone number: ";
		}
		else if (str == "all")
		{
			cons.item_color();
			for (int j = 0; j < 10; j++)
				cout << "\n";
			cout << "\t\t\t      Input login: " << data_[0] << endl;
			cout << "\t\t\t      Input password: ";
			for (int j = 0; j < data_[1].size(); j++)
				cout << '*';
			cout << endl;
			cout << "\t\t\t      Input name: " << data_[2] << endl;
			cout << "\t\t\t      Input surname: " << data_[3] << endl;
			cout << "\t\t\t      Input patronymic: " << data_[4] << endl;
			cout << "\t\t\t      Input address: " << data_[5] << endl;
			cout << "\t\t\t      Input phone number: " << data_[6] << endl;
		}
		cons.main_color();
	}
}

bool check_string(string str, string ver)
{
	if (str.size() != 0)
	{

		if (ver == "password")
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str.size() >= 8)
				{
					if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123) || (str[i] > 47 && str[i] < 58)){}
					else
						return true;
				}
				else
					return true;
			}
			return false;
		}
		if (ver == "Quantity")
		{
			if(str.size()==1&&str[0]=='0') return true;
			for (int i = 0; i < str.size(); i++)
			{
				if (str.size()<3)
				{
					if (str[i] > 47 && str[i] < 58){}
					else
						return true;
				}
				else
					return true;
			}
			return false;
		}
		if (ver == "admin password")
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str.size() >= 5)
				{
					if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123) || (str[i] > 47 && str[i] < 58))
					{}
					else
						return true;
				}
				else
					return true;
			}
			return false;
		}
		if (ver == "login")
		{
		
			for (int i = 0; i < str.size(); i++)
			{
				if (str.size() >= 8)
				{

					if ((str[i] > 64 && str[i] < 91) || (str[i] == 95) || (str[i] > 96 && str[i] < 123) || (str[i] > 47 && str[i] < 58))
					{}
					else
						return true;
				}
				else
					return true;
			}
			return false;
		}
		if (ver == "name")
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str.size() >= 2)
				{
					if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
					{}
					else
						return true;
				}
				else
					return true;
			}
			return false;
		}
		if (ver == "address")
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str.size() >= 2)
				{
					if ((str[i] > 64 && str[i] < 91) || (str[i] == 95) || (str[i] == 32) || (str[i] > 96 && str[i] < 123) || (str[i] > 43 && str[i] < 58))
					{ }
					else
						return true;
				}
				else
					return true;
			}
			return false;
			for (int i = 0; i < str.size(); i++)
				if ((str[i] < 65 && str[i] > 90) || (str[i] < 97 && str[i] > 122) || (str[i] < 48 && str[i] > 57))
					return false;
		}
		if (ver == "telephone")
		{
			for (int i = 0; i < str.size(); i++)
			{
				if (str.size() == 10)
				{
					if (str[i] > 47 && str[i] < 58)
					{ }
					else
						return true;
				}
				else
					return true;
			}
			return false;
		}
		return true;

	}
	else return true;
}
void hashing(string&str)
{
	for (int i = 0; i < str.size(); i++)
		str[i] += i + 7;
}
void address_to_file(string&str, int a)
{
	if (a == 1)        //Вместо пробела подчеркивание для записи
	{
		for (int i = 0; i < str.size(); i++)
			if (str[i] == ' ')
				str[i] = '_';
	}
	else if (a == 2)   //Для чтения наоборот
	{
		for (int i = 0; i < str.size(); i++)
			if (str[i] == '_')
				str[i] = ' ';
	}
}
int are_you_sure(console &cons)
{
	int item = 1;
	int user_input;
	do
	{
		system("cls");
		if (item == 0)
		{
			item = 2;
		}
		if (item == 3)
		{
			item = 1;
		}
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t    ";
		if (item == 1)
		{
			
			
			cout << "Are you sure to exit?\n";
			cons.item_color();
			cout << "\t\t\t\t  Yes";
			cons.main_color();
			cout << "    No\n";
			for (int i = 0; i < 14; i++)
					cout << "\n";
				

		}
		else if (item == 2)
		{
			cout << "Are you sure to exit?\n";
			cout << "\t\t\t\t  Yes";
			cons.item_color();
			cout << "    No\n";
			cons.main_color();
			for (int i = 0; i < 14; i++)
				cout << "\n";
		}
		user_input = _getch();
		if (user_input == 224)
			user_input = _getch();
		if (user_input == 75)
		{
			item--;
		}
		else if (user_input == 77)
		{
			item++;
		}
		else if (user_input == 13)
		{
			if (item == 1)
				return 1;
			else if(item == 2)
				return 0;
		}
		else if (user_input == 105)
			system("start www.instagram.com/ch_.il");
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}
		else if (user_input == 27)
			return 0;
	} while (true);
}
int are_you_sure_to_del(console &cons)
{
	int item = 1;
	int user_input;
	do
	{
		system("cls");
		if (item == 0)
		{
			item = 2;
		}
		if (item == 3)
		{
			item = 1;
		}
		if (item == 1)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  ";

			cout << "Are you sure?\n";
			cons.item_color();
			cout << "\t\t\t\t  Yes";
			cons.main_color();
			cout << "    No\n";
			for (int i = 0; i < 14; i++)
				cout << "\n";
		}
		else if (item == 2)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  ";

			cout << "Are you sure?\n";

			cout << "\t\t\t\t  Yes";
			cons.item_color();
			cout << "    No\n";
			cons.main_color();
			for (int i = 0; i < 14; i++)
				cout << "\n";
		}
		user_input = _getch();
		if (user_input == 224)
			user_input = _getch();
		if (user_input == 75)
		{
			item--;
		}
		else if (user_input == 77)
		{
			item++;
		}
		else if (user_input == 13)
		{
			if (item == 1)
				return 1;
			else if (item == 2)
				return 0;
		}
		else if (user_input == 105)
			system("start www.instagram.com/ch_.il");
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}
		else if (user_input == 27)
			return 0;
	} while (true);
}
bool real_user_check(vector<string> data_)
{
	hashing(data_[1]);
	string str;
	string flogin;
	string fpassword;
	ifstream f;
	f.open("data\\file_info\\user.chv", ofstream::binary);
	f >> flogin >> fpassword;
	if (flogin == data_[0] &&fpassword == data_[1])
	{
		return true;
	}
	while (!f.eof())
	{
		f >> flogin >> fpassword >> str >> str >> str >> str >> str;
		if (flogin == data_[0] &&fpassword == data_[1])
		{
			return true;
			break;
		}
	}
	f.close();
	return false;
}
bool user_check_for_sign(vector<string> data_)
{
	hashing(data_[1]);
	string str;
	string flogin;
	ifstream f;
	f.open("data\\file_info\\user.chv", ofstream::binary);
	f >> flogin >> str;
	while (!f.eof())
	{
		f >> flogin >> str >> str >> str >> str >> str >> str;
		if (flogin == data_[0])
		{
			return true;
			break;
		}
	}
	f.close();
	return false;
}

void file_check(console cons)
{
	system("cls");
	vector<string> v;
	ifstream f;
	ofstream of;
	int i = 0;
	f.open("data\\file_info\\categories.chv");
	if (!f)
	{
		v.push_back("categories.chv");
		of.open("data\\file_info\\categories.chv");
		of.close();
		of.open("data\\file_info\\tests_info.chv");
		of.close();
		i++;
	}
	f.close();
	f.open("data\\file_info\\user.chv");
	if (!f)
	{
		v.push_back("user.chv");
		of.open("data\\file_info\\user.chv"); 
		of << "admin hlvsy";
		of.close();
		i++;
	}
	f.close();
	f.open("data\\file_info\\tests_info.chv");
	if (!f)
	{
		v.push_back("tests_info.chv");
		of.open("data\\file_info\\tests_info.chv");
		of.close();
		of.open("data\\file_info\\categories.chv");
		of.close();
		i++;
	}
	f.close();
	if (i != 0)
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\tWe can`t find:\n";
		cons.item_color();
		while (v.size() != 0)
		{
			cout <<"\t\t\t\t"<< v.back() << "\n";
			v.pop_back();
		}
		cons.main_color();
		cout << "\n\t\t\t\tSo we created empty files\n\n\t\t\t\t";
		cons.back_color();
		system("pause");
		cons.main_color();
	}
}
void copy_statistic_node(users_statistic &vs, users_statistic s)
{
	vs.category.resize(s.category.size());

	for (int i = 0; i < vs.category.size(); i++)
		vs.category[i] = s.category[i];

	vs.denominator = s.denominator;
	vs.numerator = s.numerator;
}
void copy_node(node &n,node m)
{

	n.login.resize(m.login.size());
	n.password.resize(m.password.size());
	n.name.resize(m.name.size());
	n.surname.resize(m.surname.size());
	n.patronymic.resize(m.patronymic.size());
	n.address.resize(m.address.size());
	n.phone_number.resize(m.phone_number.size());
	for (int i = 0; i < n.login.size(); i++)
	{
		n.login[i] = m.login[i];
	}
	for (int i = 0; i < n.password.size(); i++)
	{
		n.password[i] = m.password[i];
	}
	for (int i = 0; i < n.name.size(); i++)
	{
		n.name[i] = m.name[i];
	}
	for (int i = 0; i < n.surname.size(); i++)
	{
		n.surname[i] = m.surname[i];
	}
	for (int i = 0; i < n.patronymic.size(); i++)
	{
		n.patronymic[i] = m.patronymic[i];
	}
	for (int i = 0; i < n.address.size(); i++)
	{
		n.address[i] = m.address[i];
	}
	for (int i = 0; i < n.phone_number.size(); i++)
	{
		n.phone_number[i] = m.phone_number[i];
	}

}
void copy_test_node(test_node &n, test_node m)
{
	n.address.resize(m.address.size());
	n.category.resize(m.category.size());
	n.name.resize(m.name.size());


	for (int i = 0; i < n.address.size(); i++)
	{
		n.address[i] = m.address[i];
	}
	for (int i = 0; i < n.category.size(); i++)
	{
		n.category[i] = m.category[i];
	}
	for (int i = 0; i < n.name.size(); i++)
	{
		n.name[i] = m.name[i];
	}

}
void start_preview(console cons)
{
	char c_223 = 223;    // Верхняя
	char c_219 = 219;    // Фул
	char c_220 = 220;    // Нижняя
	char c_254 = 254;    // Среднее
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	cout << c_223 << c_219 << c_223 << " " << c_219 << c_223 << " " << c_219 << c_223 << " " << c_223 << c_219 << c_223 << "\n\t\t\t\t";
	cout << " " << c_219 << "  " << c_219 << c_254 << " " << c_219 << c_220 << "  " << c_219 << "\n\t\t\t\t";
	cout << " " << c_219 << "  " << c_219 << c_220 << " " << c_220 << c_219 << "  " << c_219 << "\n";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(300);
	cons.back_color();
	system("pause");
	cons.main_color();
}
void student_choise(console &cons, bool & is_mute, vector<vector<node>> &data_, input_data id,int page,int num,int &sound)
{
	int exit = 0;
	int item = 1;
	int user_input;
	do
	{
		system("cls");
		if (item == 0)
		{
			item = 3;
		}
		if (item == 4)
		{
			item = 1;
		}
		mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);

		if (item == 1)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
			cons.item_color();
			cout << "Statistic\n";
			cons.main_color();
			cout << "\t\t\t\tEdit\n";
			cout << "\t\t\t\tDelete\n";
			for (int i = 0; i < 51; i++)
			{
				if (i < 22)
					cout << "\n";
				else
					cout << "\t";
			}
			cout << "      ";
		}
		else if (item == 2)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
			cout << "Statistic\n";
			cons.item_color();
			cout << "\t\t\t\tEdit\n";
			cons.main_color();
			cout << "\t\t\t\tDelete\n";
			for (int i = 0; i < 51; i++)
			{
				if (i < 22)
					cout << "\n";
				else
					cout << "\t";
			}
			cout << "      ";
		}
		else if (item == 3)
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
			cout << "Statistic\n";
			cout << "\t\t\t\tEdit\n";
			cons.item_color();
			cout << "\t\t\t\tDelete\n";
			cons.main_color();
			for (int i = 0; i < 51; i++)
			{
				if (i < 22)
					cout << "\n";
				else
					cout << "\t";
			}
			cout << "      ";
		}

		if (sound != 0 && !is_mute)
			mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
		sound++;
		user_input = _getch();
		if (user_input == 224)
			user_input = _getch();
		if (user_input == 72)
		{
			item--;
		}
		else if (user_input == 80)
		{
		item++;
		}
		else if (user_input == 13)

		{
			if (!is_mute)
				mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
			if (item == 1)
			{
				vector<vector<users_statistic>> statistics;
				id.restart_statistic(statistics, data_[page][num - 1].login);
			
				{
					int item = 1;
					int last_item = 1;
					int page = 0;
					int user_input;

					do
					{
						if (statistics.size() == 0)
						{
							system("cls");
							cout << "No results!";
							system("pause");
							break;
						}
						system("cls");
						if (item == 0)
						{
							last_item = 1;

							if (page == 0)
								page = statistics.size() - 1;
							else
								page--;
							item = statistics[page].size();

						}
						if (item == statistics[page].size() + 1)
						{
							item = 1;
							last_item = statistics[page].size();
							if (page<statistics.size())
								page++;
							if (page == statistics.size())
								page = 0;
						}
						cons.menu_statistic(item, sound, is_mute, cons, statistics, page);
						user_input = _getch();
						if (user_input == 224)
							user_input = _getch();
						if (user_input == 72)
						{
							item--;
						}
						else if (user_input == 80)
						{
							item++;
						}
						else if (user_input == 100)
						{
							cons.dark_mode();
							cons.main_color();
						}
						else if (user_input == 105)
							system("start www.instagram.com/ch_.il");
						else if (user_input == 27)
							break;
					} while (true);
					break;
				}
			
			}
			else if (item == 2)
			{
				id.edit_student(is_mute, data_[page][num - 1], cons);
				id.students_to_nodes(data_);
				exit = 1;
			}
			else if (item == 3)
			{
				if (!is_mute)
					mciSendString("play data\\file_sounds\\astalavistababy.mp3  ", NULL, 0, NULL);
				id.del_student(is_mute, data_[page][num - 1], cons);
				id.students_to_nodes(data_);
				exit = 1;
			}
			id.students_to_nodes(data_);
		}
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}
		else if (user_input == 105)
			system("start www.instagram.com/ch_.il");
		else if (user_input == 27)
			exit = 1;
	} while (exit!=1);
}
bool isf(string a)
{
	ifstream f(a);
	if (f)
		return true;
	else return false;
}
bool emp_f(string a)
{
	ifstream ifs;
	ifs.open(a);
	if (!ifs)
	{
		ofstream of(a);
		of.open(a);
		of.close();
		return true;

	}
	int o = 0;
	string str;
	while (!ifs.eof())
	{
		ifs >> str;
		o++;
	}
	if (str.size() == 0 && o == 1)
		return true;

	ifs.close();
	return false;
}
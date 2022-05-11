#include "class.h"
#include "lib.h"
#include "function.h"
#include "struct.h"

void admin::add(vector<string> data_)
{
	this->data_.resize(2);
	this->data_.push_back(data_[0]);
	this->data_.push_back(data_[1]);
}



void student::add(vector<string> data_)
{
	this->data_.clear();
	this->data_.resize(7);
	for (int i = 0; i < 7; i++)
		this->data_[i] = data_[i];
}

void student::show_all(console cons)
{
	preview_input_str("all", data_,  cons, 15 );
}



void to_file::sign_in(vector<string> data_)
{
	ofstream f;
	f.open("data\\file_info\\user.chv", ofstream::app | ofstream::binary);
	f << "\n"; 
	for (vector<string>::iterator it = data_.begin(); it != data_.end(); ++it)
		f << *it << " ";
	f.close();
}



void input_data::restart_statistic(vector<vector<users_statistic>> &vvs,string login)
{
	vvs.resize(0);
	vector<users_statistic> vs;
	users_statistic v_s;
	ifstream f;
	int count = 0;
	string address = "data\\users_statistic\\";
	address += login;
	address += ".chv";
	f.open(address);
	string a;
	if (!emp_f(address))
	{
		while (!f.eof())
		{
			f >> a >> a >> a;
			vs.push_back(v_s);
			count++;
		}
		f.close();
		f.open(address);
		if (count <= 15)
		{
			vvs.resize(1);
			vvs[0].resize(count);
			for (int j = 0; j < count; j++)
			{
				f >> v_s.category >> v_s.numerator >> v_s.denominator;
				copy_statistic_node(vvs[0][j], v_s);
			}

		}

		else if (count > 15)
		{

			vvs.resize((count / 15) + 1);

			for (int i = 0; i < vvs.size() - 1; i++)
			{
				vvs[i].resize(15);
				for (int j = 0; j < 15; j++)
				{
					f >> v_s.category >> v_s.numerator >> v_s.denominator;
					copy_statistic_node(vvs[i][j], v_s);
				}

			}
			while (count >= 15)
			{
				count -= 15;
			}
			vvs[vvs.size() - 1].resize(count);
			for (int j = 0; j < count; j++)
			{
				f >> v_s.category >> v_s.numerator >> v_s.denominator;
				copy_statistic_node(vvs[vvs.size() - 1][j], v_s);
			}
		}
		f.close();
	}
}

void input_data::edit_test(console &cons, string name, string category,input_data id,int &sound,bool&is_mute)
{
	vector<question> questions;
	vector<vector<question>> vquestion;
	string address = "data\\file_tests\\";
	address += category;
	address += "\\";
	address += name;
	address += ".chv";
	ifstream ifs;
	ifs.open(address, ifstream::binary);
	ifs >> count;
	questions.resize(count);
	for (int i = 0; i < count; i++)
	{
		ifs >> questions[i].Question;
		ifs >> questions[i].answ_true;
		ifs >> questions[i].answ1;
		ifs >> questions[i].answ2;
		address_to_file(questions[i].Question, 2);
		address_to_file(questions[i].answ_true, 2);
		address_to_file(questions[i].answ1, 2);
		address_to_file(questions[i].answ2, 2);
	}
	ifs.close();
	output out(new to_file);
	string a;
	int user_input = 0;
	int exit = 0;
	int item = 1;
	int page = 0;
	int last_item = 1;
	int num_of_end_question = 0;
	int true_questions_pass = 0;
	int true_ = 0;
	id.tests_to_nodes_edit(vquestion, questions);
	do
	{
		system("cls");
		if (item == 0)
		{
			last_item = 1;

			if (page == 0)
				page = vquestion.size() - 1;
			else
				page--;
			item = vquestion[page].size();

		}
		if (item == vquestion[page].size() + 1)
		{
			item = 1;
			last_item = vquestion[page].size();
			if (page < vquestion.size())
				page++;
			if (page == vquestion.size())
				page = 0;
		}
		if (last_item == item)
			sound = 0;
		cons.menu_tests_edit(item, sound, is_mute, cons,page,vquestion);
		user_input = _getch();
		last_item = item;
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
			int quest = item;
			item = 1;
			do
			{
				system("cls");

				if (item == 0)
				{
					last_item = 1;
					item = 4;

				}
				if (item == 5)
				{
					item = 1;
					last_item = 4;
				}
				if (last_item == item)
					sound = 0;
				///////////////////////
				if (item == 1)
				{
					cons.item_color();
					cout << vquestion[page][quest - 1].Question << "\n";
					cons.main_color();
					cout << vquestion[page][quest - 1].answ_true << " (true)\n";
					cout << vquestion[page][quest - 1].answ1 << "\n";
					cout << vquestion[page][quest - 1].answ2 << "\n";
				}
				if (item == 2)
				{
					cout << vquestion[page][quest - 1].Question << "\n";
					cons.item_color();
					cout << vquestion[page][quest - 1].answ_true << " (true)\n";
					cons.main_color();
					cout << vquestion[page][quest - 1].answ1 << "\n";
					cout << vquestion[page][quest - 1].answ2 << "\n";
				}
				if (item == 3)
				{
					cout << vquestion[page][quest - 1].Question << "\n";
					cout << vquestion[page][quest - 1].answ_true << " (true)\n";
					cons.item_color();
					cout << vquestion[page][quest - 1].answ1 << "\n";
					cons.main_color();
					cout << vquestion[page][quest - 1].answ2 << "\n";
				}
				if (item == 4)
				{
					cout << vquestion[page][quest - 1].Question << "\n";
					cout << vquestion[page][quest - 1].answ_true << " (true)\n";
					cout << vquestion[page][quest - 1].answ1 << "\n";
					cons.item_color();
					cout << vquestion[page][quest - 1].answ2 << "\n";
					cons.main_color();
				}
				///////////////////////
				user_input = _getch();
				last_item = item;
				if (user_input == 224)
					user_input = _getch();
				if (user_input == 72)
				{
					item--;
				}
				if (user_input == 13)
				{
					int g = 0;
					
					for (int i = 0; i < vquestion.size(); i++)
						for (int j = 0; j < vquestion[i].size(); j++, g++)
						{
							questions[g].Question.resize(vquestion[i][j].Question.size());
							questions[g].answ_true.resize(vquestion[i][j].answ_true.size());
							questions[g].answ1.resize(vquestion[i][j].answ1.size());
							questions[g].answ2.resize(vquestion[i][j].answ2.size());
							for (int k = 0; k<vquestion[i][j].Question.size(); k++)
								questions[g].Question[k] = vquestion[i][j].Question[k];

							for (int k = 0; k<vquestion[i][j].answ1.size(); k++)
								questions[g].answ1[k] = vquestion[i][j].answ1[k];

							for (int k = 0; k<vquestion[i][j].answ2.size(); k++)
								questions[g].answ2[k] = vquestion[i][j].answ2[k];

							for (int k = 0; k<vquestion[i][j].answ_true.size(); k++)
								questions[g].answ_true[k] = vquestion[i][j].answ_true[k];

						}
					break;
				}
				
				else if (user_input == 80)
				{
					item++;
				}
				else if (user_input == 27)
				{

					exit = 1;
					true_ = 1;
					
				}
				else if (user_input == 8)
				{
					if (item == 1)
					{
						if (vquestion[page][quest - 1].Question.size() != 0)
						{
							vquestion[page][quest - 1].Question.pop_back();
							system("cls");
						}
					}
					if (item == 2)
					{
						if (vquestion[page][quest - 1].answ_true.size() != 0)
						{
							vquestion[page][quest - 1].answ_true.pop_back();
							system("cls");
						}
					}
					if (item == 3)
					{
						if (vquestion[page][quest - 1].answ1.size() != 0)
						{
							vquestion[page][quest - 1].answ1.pop_back();
							system("cls");
						}
					}
					if (item == 4)
					{
						if (vquestion[page][quest - 1].answ2.size() != 0)
						{
							vquestion[page][quest - 1].answ2.pop_back();
							system("cls");
						}
					}
					
				}
				else
				{
					if (item == 1)
					{
							vquestion[page][quest - 1].Question.push_back(user_input);
					}
					if (item == 2)
					{
							vquestion[page][quest - 1].answ_true.push_back(user_input);
					}
					if (item == 3)
					{
							vquestion[page][quest - 1].answ1.push_back(user_input);
					}
					if (item == 4)
					{
							vquestion[page][quest - 1].answ2.push_back(user_input);
					}
				}

			} while (exit != 1);
		}
		else if (user_input == 115)
		{
			true_ = 1;
			exit = 1;
			break;
		}
		else if (user_input == 109 && is_mute == true)
			is_mute = false;
		else if (user_input == 109 && is_mute == false)
			is_mute = true;
		else if (user_input == 27)
		{
			exit = 1;
		}
		else if (last_item = item)
		{
			sound = 0;
		}
		else if (user_input == 105)
			system("start www.instagram.com/ch_.il");
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}
		
		else
			true_ = 0;
 
	} while (exit != 1);
	



	if (true_ == 1)
	{
		ofstream ofs;
		ofs.open(address);
		ofs << count;
		for (int i = 0; i <count; i++)
		{
			address_to_file(questions[i].Question, 1);
			address_to_file(questions[i].answ_true, 1);
			address_to_file(questions[i].answ1, 1);
			address_to_file(questions[i].answ1, 1);
			ofs << "\n" << questions[i].Question;
			ofs << "\n" << questions[i].answ_true;
			ofs << "\n" << questions[i].answ1;
			ofs << "\n" << questions[i].answ2;
		}
		ofs.close();
	}
}

void input_data::sign_in(console &cons)
{
	data_.clear();
	data_.resize(9);

	count = 1;
	
	while (count == 1)
	{
		system("cls");
		preview_input_str("login", data_, cons,15);
		is_error_in_str = 0;
		while (c = _getch())
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == '\r')
			{
				preview_input_str("login", data_, cons, 15);
				cout << data_[0];
				is_end = 0;
				is_error_in_str = check_string(data_[0], "login");
				bool real_user = user_check_for_sign(data_);
				if (real_user)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can`t use this login) ";
					cons.main_color();
					is_error_in_str = 0;
				}
				else if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters, \n\t\tunderlines, numbers(more then 8 digits) ";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}
			}
			else if (c == 8)
			{
				if (data_[0].size() != 0)
				{
					data_[0].pop_back();
					system("cls");
					preview_input_str("login", data_, cons, 15);
					cout << data_[0];
				}
				else
					break;
			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				data_[0].push_back(c);
				preview_input_str("login", data_, cons, 15);
				cout << data_[0];
			}
		}
	}

	while (count == 2)
	{
		system("cls");
		preview_input_str("password", data_, cons, 15);

		while ((c = _getch()))
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == 8)
			{
				if (data_[1].size() != 0)
				{
					data_[1].pop_back();
					preview_input_str("password", data_, cons, 15);
					for (int i = 0; i < data_[1].size(); i++)
						cout << '*';
				}
				else
					break;
			}
			else if (c == '\r')
			{
				preview_input_str("password", data_, cons, 15);

				for (int i = 0; i < data_[1].size(); i++)
					cout << '*';

				is_error_in_str = check_string(data_[1], "password");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters, \n\t\t numbers(more then 8 digits) ";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}

			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				preview_input_str("password", data_, cons, 15);
				for (int i = 0; i < data_[1].size(); i++)
					cout << '*';

				data_[1].push_back(c);
				_putch('*');
			}
		}
	}

	while (count == 3)
	{
		system("cls");
		preview_input_str("name", data_, cons, 15);

		while ((c = _getch()))
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == 8)
			{
				if (data_[2].size() != 0)
				{
					data_[2].pop_back();
					preview_input_str("name", data_, cons, 15);
					cout << data_[2];
				}
				else
					break;
			}
			else if (c == '\r')
			{
				preview_input_str("name", data_, cons, 15);
				cout << data_[2];

				is_error_in_str = check_string(data_[2], "name");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters\n\t(more then 2 digits)";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}

			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				data_[2].push_back(c);
				preview_input_str("name", data_, cons, 15);
				cout << data_[2];
			}
		}
	}

	while (count == 4)
	{
		system("cls");
		preview_input_str("surname", data_, cons, 15);

		while ((c = _getch()))
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == 8)
			{
				if (data_[3].size() != 0)
				{
					data_[3].pop_back();
					preview_input_str("surname", data_, cons, 15);
					cout << data_[3];
				}
				else
					break;
			}
			else if (c == '\r')
			{
				preview_input_str("surname", data_, cons, 15);
				cout << data_[3];
				is_error_in_str = check_string(data_[3], "name");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters\n\t(more then 2 digits)";
					cons.main_color();
					is_error_in_str = 0;
				}
				else
				{
					count++;
					break;
				}

			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				data_[3].push_back(c);
				preview_input_str("surname", data_, cons, 15);
				cout << data_[3];
			}
		}
	}

	while (count == 5)
	{
		system("cls");
		preview_input_str("patronymic", data_, cons, 15);

		while ((c = _getch()))
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == 8)
			{
				if (data_[4].size() != 0)
				{
					data_[4].pop_back();
					preview_input_str("patronymic", data_, cons, 15);
					cout << data_[4];
				}
				else
					break;
			}
			else if (c == '\r')
			{
				preview_input_str("patronymic", data_, cons, 15);
				cout << data_[4];
				is_error_in_str = check_string(data_[4], "name");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters, (more then 2 digits)";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}

			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				data_[4].push_back(c);
				preview_input_str("patronymic", data_, cons, 15);
				cout << data_[4];
			}
		}
	}

	while (count == 6)
	{
		system("cls");
		preview_input_str("address", data_, cons, 15);

		while ((c = _getch()))
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == 8)
			{
				if (data_[5].size() != 0)
				{
					data_[5].pop_back();
					preview_input_str("address", data_, cons, 15);
					cout << data_[5];
				}
				else
					break;
			}
			else if (c == '\r')
			{
				preview_input_str("address", data_, cons, 15);
				cout << data_[5];

				is_error_in_str = check_string(data_[5], "address");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters,\n\t\tnumbers and /,.-";
					cons.main_color();
					is_error_in_str = 0;
				}
				else
				{
					count++;
					break;
				}

			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				data_[5].push_back(c);
				preview_input_str("address", data_, cons, 15);
				cout << data_[5];
			}
		}
	}

	while (count == 7)
	{
		system("cls");
		preview_input_str("phone number", data_, cons, 15);

		while ((c = _getch()))
		{
			system("cls");

			if (c == 224)
				c = _getch();
			if (c == 8)
			{
				if (data_[6].size() != 0)
				{
					data_[6].pop_back();
					preview_input_str("phone number", data_, cons, 15);
					cout << data_[6];
				}
				else
					break;
			}
			else if (c == '\r')
			{

				preview_input_str("phone number", data_, cons, 15);

				cout << data_[6];

				is_error_in_str = check_string(data_[6], "telephone");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only numbers\n\tand it must be 10 digits";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}

			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				data_[6].push_back(c);
				preview_input_str("phone number", data_, cons, 15);
				cout << data_[6];
			}
		}


	}

	if (count == 8)
	{
		mciSendString("play data\\file_sounds\\magic.mp3  ", NULL, 0, NULL);
		system("cls");
		preview_input_str("all", data_, cons, 15);
		cout << "\n\t\t\t       ";
		system("pause");

		address_to_file(data_[5], 1);
		hashing(data_[1]);

		to_file tf;
		tf.sign_in(data_);

	}

}

void input_data::log_in(bool &login_successful, vector<string> &data_,console &cons)
{
	is_end = 0;
	while (!is_end)
	{
		
		{
			system("cls");
			data_[1].clear();
			data_[0].clear();
		}
		{
			preview_input_str("login", data_, cons, 15);
			while (c = _getch())
			{
				if (c == 224)
					c = _getch();
				if (c == '\r')
				{
					system("cls");
					preview_input_str("login", data_, cons, 15);
					cout << data_[0];
					is_end = 0;
					break;
				}
				else if (c == 8)
				{
					if (data_[0].size() != 0)
					{
						data_[0].pop_back();
						system("cls");
						preview_input_str("login", data_, cons, 15);
						cout << data_[0];
					}
				}
				else if (c == 27)
				{
					is_end = 1;
					break;
				}
				else
				{
					system("cls");
					data_[0].push_back(c);
					preview_input_str("login", data_, cons, 15);
					cout << data_[0];
				}
			}
		}

		if (!is_end&&data_[0].size()>0)
		{
			preview_input_str("password", data_,  cons, 1);

			while ((c = _getch()))
			{
				if (c == 224)
					c = _getch();
				if (c == 8)
				{
					if (data_[1].size() != 0)
					{
						data_[1].pop_back();
						system("cls");
						preview_input_str("login", data_, cons, 15);
						cout << data_[0];
						preview_input_str("password", data_, cons, 1);
						for (int i = 0; i < data_[1].size(); i++)
							cout << '*';
					}
				}
				else if (c == '\r')
				{
					system("cls");

					preview_input_str("login", data_, cons, 15);
					cout << data_[0];
					preview_input_str("password", data_, cons, 1);

					for (int i = 0; i < data_[1].size(); i++)
						cout << '*';

					is_it_real_user = real_user_check(data_);
					if (is_it_real_user)
					{
						is_end = true;
						login_successful = 1;
					}
					else
					{
						mciSendString("play data\\file_sounds\\vi_kto_takie.mp3", NULL, 0, NULL);
						cons.error_color();
						cout << "\n\n\t\t\t    We can`t find you, \n\t\t\t\tplease sing in";
						cons.main_color();
						is_it_real_user = 0;
						c = _getch();
					}

					break;
				}
				else if (c == 27)
				{
					is_end = true;
					break;
				}
				else
				{
					system("cls");

					preview_input_str("login", data_, cons, 15);
					cout << data_[0];
					preview_input_str("password", data_, cons, 1);
					for (int i = 0; i < data_[1].size(); i++)
						cout << '*';

					data_[1].push_back(c);
					_putch('*');
				}
			}
		}
	}
}    

void input_data::students_to_nodes(vector<vector <node>> &vn)
{
	vn.resize(0);
	string str;
	int count_of_students = -1;
	ifstream f;
	f.open("data\\file_info\\user.chv", ifstream::binary);
	while (getline(f, str))
		count_of_students++;
    f.close();
	node n1;
	if (!emp_f("data\\file_info\\categories.chv"))
	{
		f.open("data\\file_info\\user.chv", ofstream::binary);
		f >> str >> str;


		if (count_of_students <= 15)
		{
			vn.resize(1);
			vn[0].resize(count_of_students);
			for (int j = 0; j < count_of_students; j++)
			{
				f >> n1.login >> n1.password >> n1.name >> n1.surname >> n1.patronymic >> n1.address >> n1.phone_number;
				copy_node(vn[0][j], n1);
			}

		}

		else if (count_of_students > 15)
		{

			vn.resize((count_of_students / 15) + 1);

			for (int i = 0; i < vn.size() - 1; i++)
			{
				vn[i].resize(15);
				for (int j = 0; j < 15; j++)
				{
					f >> n1.login >> n1.password >> n1.name >> n1.surname >> n1.patronymic >> n1.address >> n1.phone_number;
					copy_node(vn[i][j], n1);
				}

			}
			while (count_of_students >= 15)
			{
				count_of_students -= 15;
			}
			vn[vn.size() - 1].resize(count_of_students);
			for (int j = 0; j < count_of_students; j++)
			{
				f >> n1.login >> n1.password >> n1.name >> n1.surname >> n1.patronymic >> n1.address >> n1.phone_number;
				copy_node(vn[vn.size() - 1][j], n1);
			}
		}
		f.close();
	}
}

void input_data::tests_to_nodes(vector<vector <test_node>> &vn)
{
	string str;
	test_node n1;
	vector<string> categ;
	int count_of_tests = 0;
	int count_of_categories = 0;
	ifstream f;
	f.open("data\\file_info\\tests_info.chv", ifstream::binary);
	bool have_this_categ = 0;
	while (getline(f, str))
	{
		count_of_tests++;
	}
	f.close();
	vn.resize(0);
	if (!emp_f("data\\file_info\\categories.chv"))
	{
		f.open("data\\file_info\\tests_info.chv", ofstream::binary);


		if (count_of_tests <= 15)
		{
			vn.resize(1);
			vn[0].resize(count_of_tests);
			for (int j = 0; j < count_of_tests; j++)
			{
				f >> n1.address >> n1.category >> n1.name;
				copy_test_node(vn[0][j], n1);
			}

		}

		else if (count_of_tests > 15)
		{

			vn.resize((count_of_tests / 15) + 1);

			for (int i = 0; i < vn.size() - 1; i++)
			{
				vn[i].resize(15);
				for (int j = 0; j < 15; j++)
				{
					f >> n1.address >> n1.category >> n1.name;
					copy_test_node(vn[i][j], n1);
				}

			}
			while (count_of_tests >= 15)
			{
				count_of_tests -= 15;
			}
			vn[vn.size() - 1].resize(count_of_tests);
			for (int j = 0; j < count_of_tests; j++)
			{
				f >> n1.address >> n1.category >> n1.name;
				copy_test_node(vn[vn.size() - 1][j], n1);
			}
		}
		f.close();
	}
}

void input_data::tests_to_nodes_stud(vector<vector <test_node>> &vn, string login)
{
	string str;
	test_node n1;
	vector<string> categ;
	vector <test_node> tn;
	 test_node t_n;
	int count_of_tests = 0;
	int count_of_categories = 0;
	vn.resize(0);
	if (!emp_f("data\\file_info\\categories.chv"))
	{
		ifstream f;
		f.open("data\\file_info\\tests_info.chv", ifstream::binary);
		bool have_this_categ = 0;
		while (getline(f, str))
		{
			count_of_tests++;
		}
		f.close();
		string address = "data\\passed_tests\\";
		address += login;
		address += ".chv";
		int is_passed = 0;

		f.open(address);
		while (!f.eof())
		{
			f >> t_n.category >> t_n.name;
			tn.push_back(t_n);
			is_passed = 1;
		}
		f.close();

		int is_to_copy = 1 + 0;
		f.open("data\\file_info\\tests_info.chv", ofstream::binary);

		if (count_of_tests <= 15)
		{
			vn.resize(1);
			vn[0].resize(count_of_tests);
			for (int j = 0; j < count_of_tests; j++)
			{
				f >> n1.address >> n1.category >> n1.name;
				if (is_passed == 1)
				{
					for (int i = 0; i < tn.size(); i++)
						if (n1.category == tn[i].category&&n1.name == tn[i].name)
						{
							is_to_copy = 0;
							break;
						}
						else
							is_to_copy = 1;
					if (is_to_copy)
						copy_test_node(vn[0][j], n1);
				}
				else
					copy_test_node(vn[0][j], n1);
			}

		}

		else if (count_of_tests > 15)
		{

			vn.resize((count_of_tests / 15) + 1);

			for (int i = 0; i < vn.size() - 1; i++)
			{
				vn[i].resize(15);
				for (int j = 0; j < 15; j++)
				{
					f >> n1.address >> n1.category >> n1.name;
					if (is_passed == 1)
					{
						for (int i = 0; i < tn.size(); i++)
							if (n1.category == tn[i].category&&n1.name == tn[i].name)
							{
								is_to_copy = 0;
								break;
							}
						if (is_to_copy)
							copy_test_node(vn[0][j], n1);
					}
					else
						copy_test_node(vn[0][j], n1);
				}

			}
			while (count_of_tests >= 15)
			{
				count_of_tests -= 15;
			}
			vn[vn.size() - 1].resize(count_of_tests);
			for (int j = 0; j < count_of_tests; j++)
			{
				f >> n1.address >> n1.category >> n1.name;
				if (is_passed == 1)
				{
					for (int i = 0; i < tn.size(); i++)
						if (n1.category == tn[i].category&&n1.name == tn[i].name)
						{
							is_to_copy = 0;
							break;
						}
					if (is_to_copy)
						copy_test_node(vn[0][j], n1);
				}
				else
					copy_test_node(vn[0][j], n1);
			}
		}
		f.close();
	}
}

void input_data::new_test(console cons)
{
	count = 1;
	test_node tn;
	string quantity;
	vector<question> question;
	
	int quan;
	while (count == 1)
	{
		system("cls");
		cout<<"Name of test: ";
		is_error_in_str = 0;
		while (c = _getch())
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == '\r')
			{
				cout << "Name of test: ";
				cout << tn.name;

				is_error_in_str = check_string(tn.name, "name");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters\n\t(more then 2 digits)";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}
			}
			else if (c == 8)
			{
				if (tn.name.size() != 0)
				{
					tn.name.pop_back();
					system("cls");
					cout << "Name of test: ";
					cout << tn.name;
				}
				else
					break;
			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				tn.name.push_back(c);
				cout << "Name of test: ";
				cout << tn.name;
			}
		}
	}
	while (count == 2)
	{
		system("cls");
		cout << "Name of test: " << tn.name << endl;
		cout << "Categoty of test: ";
		is_error_in_str = 0;
		while (c = _getch())
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == '\r')
			{
				cout << "Name of test: " << tn.name << endl;
				cout << "Categoty of test: "<<tn.category;

				is_error_in_str = check_string(tn.category, "name");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters\n\t(more then 2 digits)";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}
			}
			else if (c == 8)
			{
				if (tn.category.size() != 0)
				{
					tn.category.pop_back();
					system("cls");
					cout << "Name of test: " << tn.name << endl;
					cout << "Categoty of test: " << tn.category;
				}
				else
					break;
			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				tn.category.push_back(c);
				cout << "Name of test: " << tn.name << endl;
				cout << "Categoty of test: " << tn.category;
			}
		}
	}
	while (count == 3)
	{
		system("cls");
		cout << "Name of test: " << tn.name << endl;
		cout << "Categoty of test: " << tn.category << endl;
		cout << "Quantity of tests: ";
		is_error_in_str = 0;
		while (c = _getch())
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == '\r')
			{
				cout << "Name of test: " << tn.name << endl;
				cout << "Categoty of test: " << tn.category << endl;
				cout << "Quantity of tests: " << quantity ;

				is_error_in_str = check_string(quantity, "Quantity");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can input only numbers\n\t(more of 5 less then 100)";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					quan = atoi(quantity.c_str());
					if (quan > 5 && quan < 100)
					{
						count++;
						break;
					}
					else
					{
						cons.error_color();
						cout << "\n\n\t\t\t    You can input only numbers\n\t(more of 5 less then 100)";
						cons.main_color();
						is_error_in_str = 0;
					}
				}
			}
			else if (c == 8)
			{
				if (quantity.size() != 0)
				{
					quantity.pop_back();
					system("cls");
					cout << "Name of test: " << tn.name << endl;
					cout << "Categoty of test: " << tn.category << endl;
					cout << "Quantity of tests: " << quantity;
				}
				else
					break;
			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				quantity.push_back(c);
				cout << "Name of test: " << tn.name << endl;
				cout << "Categoty of test: " << tn.category << endl;
				cout << "Quantity of tests: " << quantity;
			}
		}
	}
	
	if (count == 4)
	{
		question.resize(quan);
		for (int i = 0; i < quan; i++)
		{
			count = 1;
           while (count == 1)
			{
				system("cls");
				cout << "Input " << i +1<< " question :";
					while ((c = _getch()))
					{
						system("cls");
						if (c == 224)
							c = _getch();
						if (c == 8)
						{
							if (question[i].Question.size() != 0)
							{
								question[i].Question.pop_back();
								cout << "Input " << i+1 << " question :"<< question[i].Question;
							}
						}
						else if (c == '\r')
						{
							cout << "Input " << i+1 << " question :" << question[i].Question;

							is_error_in_str = check_string(question[i].Question, "address");
							if (is_error_in_str)
							{
								cons.error_color();
								cout << "\n\n\t\t\t    You can use only English letters,\n\t\tnumbers and /,.-";
								cons.main_color();
								is_error_in_str = 0;
							}
							else
							{
								count++;
								break;
							}

						}
						else if (c == 27)
						{
							count = -1;
							i = quan;
							break;
						}
						else
						{
							question[i].Question.push_back(c);
							cout << "Input " << i+1 << " question :" << question[i].Question;
						}
					}
			}
			while (count == 2)
			{
				system("cls");
				cout << "Input 1 true answer :";
				while ((c = _getch()))
				{
					system("cls");
					if (c == 224)
						c = _getch();
					if (c == 8)
					{
						if (question[i].answ_true.size() != 0)
						{
							question[i].answ_true.pop_back();
							cout << "Input 1 true answer :" <<question[i].answ_true;
						}
					}
					else if (c == '\r')
					{
						cout << "Input 1 true answer :" << question[i].answ_true;

						is_error_in_str = check_string(question[i].answ_true, "address");
						if (is_error_in_str)
						{
							cons.error_color();
							cout << "\n\n\t\t\t    You can use only English letters,\n\t\tnumbers and /,.-";
							cons.main_color();
							is_error_in_str = 0;
						}
						else
						{
							count++;
							break;
						}

					}
					else if (c == 27)
					{
						i = quan;
						count = -1;
						break;
					}
					else
					{
						question[i].answ_true.push_back(c);
						cout << "Input 1 true answer :" << question[i].answ_true;
					}
				}
			}
			while (count == 3)
			{
				system("cls");
				cout << "Input 2 false answer :";

				while ((c = _getch()))
				{
					system("cls");
					if (c == 224)
						c = _getch();
					if (c == 8)
					{
						if (question[i].answ1.size() != 0)
						{
							question[i].answ1.pop_back();
							cout << "Input 2 false answer :"<<question[i].answ1;
						}
					}
					else if (c == '\r')
					{
						cout << "Input 2 false answer :" << question[i].answ1;

						is_error_in_str = check_string(question[i].answ1, "address");
						if (is_error_in_str)
						{
							cons.error_color();
							cout << "\n\n\t\t\t    You can use only English letters,\n\t\tnumbers and /,.-";
							cons.main_color();
							is_error_in_str = 0;
						}
						else
						{
							count++;
							break;
						}

					}
					else if (c == 27)
					{
						count = -1;
						i = quan;
						break;
					}
					else
					{
						question[i].answ1.push_back(c);
						cout << "Input 2 false answer :" << question[i].answ1;
					}
				}
			}
			while (count == 4)
			{
				system("cls");
				cout << "Input 3 false answer :";

				while ((c = _getch()))
				{
					system("cls");
					if (c == 224)
						c = _getch();
					if (c == 8)
					{
						if (question[i].answ2.size() != 0)
						{
							question[i].answ2.pop_back();
							cout << "Input 3 false answer :" << question[i].answ2;
						}
					}
					else if (c == '\r')
					{
						cout << "Input 3 false answer :" << question[i].answ2;

						is_error_in_str = check_string(question[i].answ2, "address");
						if (is_error_in_str)
						{
							cons.error_color();
							cout << "\n\n\t\t\t    You can use only English letters,\n\t\tnumbers and /,.-";
							cons.main_color();
							is_error_in_str = 0;
						}
						else
						{
							count++;
							break;
						}

					}
					else if (c == 27)
					{
						count = -1;
						i = quan;
						break;
					}
					else
					{
						question[i].answ2.push_back(c);
						cout << "Input 3 false answer :" << question[i].answ2;
					}
				}
			}
		}
		if (count == 5)
			output::write_new_test(tn, question, quan);
	
		
	}

	count = 0;
}

void input_data::delete_test(string category, string name)
{
	
	output out(new to_file);
	ifstream f;
	string address = "data\\file_tests\\";
	address += category;
	address += "\\";
	address += name;
	address += ".chv";
	out.del_file(address);           //      удаление файла
	vector <string> s;
	vector <test_node> tn;
	vector <int> intt;
	test_node t_n;
	string str;
	ofstream of;

	f.open("data\\file_info\\tests_info.chv",ofstream::binary);

	int count_of_test = 0;

	while (!f.eof())//                                                 запись в вектор инфо о тестах кроме удаляемого             
	{
		f >> t_n.address >> t_n.category >> t_n.name;
		if (t_n.name == name&&t_n.category == category)
		{
		}
		else
		{
			tn.push_back(t_n);
			count_of_test++;
		}

	}
	f.close();
	
	
	of.open("data\\file_info\\tests_info.chv", ofstream::binary);//       запись в файл инфо о тестах кроме удаляемого       
	if (tn.size() != 0)
	{
		of << tn.back().address << " " << tn.back().category << " " << tn.back().name;
		tn.pop_back();
	}

		while (tn.size() != 0)
		{
			of << "\n" << tn.back().address << " " << tn.back().category << " " << tn.back().name;
			tn.pop_back();
		}
	
	of.close();
	



	int count_of_categ = 0;


	f.open("data\\file_info\\categories.chv", ofstream::binary);
	vector <file_category> fc;
	file_category fl;
	bool nulcateg = 0;
	while (!f.eof()) //       запись в вектор инфо о категориях и колва тестов (если 0 то удалить папку)
	{
		f >> fl.cat >> fl.num;
		if (fl.cat == category) fl.num--;

		if (fl.cat == category&&fl.num==0){nulcateg = 1;}
		else
		{
			fc.push_back(fl);
			count_of_categ++;
		}
	}

	f.close();

	if (nulcateg)
	{
		address.clear();
		string address = "data\\file_tests\\";
		address += category;
		out.del_dir(address);
	}



	of.open("data\\file_info\\categories.chv", ofstream::binary);

	if (fc.size() != 0)
	{
		of << fc.back().cat << " " << fc.back().num;
		fc.pop_back();
	}
	while (fc.size() != 0)
	{
		of << "\n" << fc.back().cat << " " << fc.back().num;
		fc.pop_back();
	}
	

	of.close();
}

void input_data::tests_to_nodes_categories(vector <vector <test_node>> &vn, vector <vector <test_node>> v,string category)
{
	vector <test_node > tests;
	tests.resize(1);
	int count_of_tests = 0;
	vn.resize(0);
	if (!emp_f("data\\file_info\\categories.chv"))
	{
		for (int i = 0; i < v.size(); i++)
			for (int j = 0; j < v[i].size(); j++)
				if (v[i][j].category == category)
				{
					tests.push_back(v[i][j]);
					count_of_tests++;
				}

		if (count_of_tests <= 15)
		{
			vn.resize(1);
			vn[0].reserve(count_of_tests);
			for (int l = 0; l < count_of_tests; l++)
			{
				vn[0].push_back(tests.back());
				tests.pop_back();
			}

		}

		else if (count_of_tests > 15)
		{

			vn.reserve((count_of_tests / 15) + 1);

			for (int i = 0; i < vn.size() - 1; i++)
			{
				vn[i].reserve(15);
				for (int j = 0; j < 15; j++)
				{
					vn[i].push_back(tests.back());
					tests.pop_back();
				}

			}
			while (count_of_tests >= 15)
			{
				count_of_tests -= 15;
			}
			vn[vn.size() - 1].reserve(count_of_tests);
			for (int j = 0; j < count_of_tests; j++)
			{
				vn[vn.size() - 1].push_back(tests.back());
				tests.pop_back();
			}
		}
	}
}

void input_data::tests_to_nodes_edit(vector <vector <question>> &vn, vector <question> v)
{
	vn.resize(1);
	int count_of_tests = v.size();
	
			

	if (count_of_tests <= 15)
	{
		vn.resize(1);
		vn[0].reserve(count_of_tests);
		for (int l = 0; l < count_of_tests; l++)
		{
			vn[0].push_back(v.back());
			v.pop_back();
		}

	}

	else if (count_of_tests > 15)
	{

		vn.reserve((count_of_tests / 15) + 1);

		for (int i = 0; i < vn.size() - 1; i++)
		{
			vn[i].reserve(15);
			for (int j = 0; j < 15; j++)
			{
				vn[i].push_back(v.back());
				v.pop_back();
			}

		}
		while (count_of_tests >= 15)
		{
			count_of_tests -= 15;
		}
		vn[vn.size() - 1].reserve(count_of_tests);
		for (int j = 0; j < count_of_tests; j++)
		{
			vn[vn.size() - 1].push_back(v.back());
			v.pop_back();
		}
	}

}

void input_data::edit_admin(string &passw, console &cons)
{
	int count = 0;
	bool is_error_in_str;
	string password;
	char c;

	while (count==0)
	{
		system("cls");

		for (int j = 0; j < 15; j++)
			cout << "\n";
		cons.item_color();
		cout << "\t\t\t    Input password: ";
		cons.main_color();

		while ((c = _getch()))
		{
			system("cls");
			if (c == 224)
				c = _getch();
			if (c == 8)
			{
				if (password.size() != 0)
				{
					password.pop_back();
					for (int j = 0; j < 15; j++)
						cout << "\n";
					cons.item_color();
					cout << "\t\t\t    Input password: ";
					cons.main_color();
					for (int i = 0; i < password.size(); i++)
						cout << '*';
				}
				else
					break;
			}
			else if (c == '\r')
			{
				for (int j = 0; j < 15; j++)
					cout << "\n";
				cons.item_color();
				cout << "\t\t\t    Input password: ";
				cons.main_color();
				for (int i = 0; i < password.size(); i++)
					cout << '*';
				

				is_error_in_str = check_string(password, "admin password");
				if (is_error_in_str)
				{
					cons.error_color();
					cout << "\n\n\t\t\t    You can use only English letters, \n\t\t numbers(more then 5 digits) ";
					cons.main_color();
					is_error_in_str = 0;

				}
				else
				{
					count++;
					break;
				}

			}
			else if (c == 27)
			{
				count = -1;
				break;
			}
			else
			{
				for (int j = 0; j < 15; j++)
					cout << "\n";
				cons.item_color();
				cout << "\t\t\t    Input password: ";
				cons.main_color();
				for (int i = 0; i < password.size(); i++)
					cout << '*';

				password.push_back(c);
				_putch('*');
			}
		}

		}
	if (count == 1)
	{
		passw.resize(password.size());
		for (int i = 0; i < password.size(); i++)
		{
			passw[i] = password[i];
		}
		list<node> students;
		node n;
		string str;
		ifstream f;
		f.open("data\\file_info\\user.chv", ofstream::binary);
		f >> str >> str;
		int i = 0;
		while (!f.eof())
		{
			f >> n.login >> n.password >> n.name >> n.surname >> n.patronymic >> n.address >> n.phone_number ;
			students.push_back(n);
			i++;
		}
		f.close();
		ofstream f1;
		f1.open("data\\file_info\\user.chv", ofstream::binary);
		hashing(passw);
		f1 << "admin" << " " << passw;
		for (; i != 0; i--)
		{
			copy_node(n, students.front());
			students.pop_front();
            f1 << "\n" << n.login << " "<<n.password << " "<<n.name << " "<<n.surname << " "<<n.patronymic << " "<<n.address << " "<<n.phone_number ;
		}
		f.close();
	}
}

void input_data::edit_student(bool &is_mute, node &data_,console &cons)
{
	int item = 1;
	int user_input;
	int exit = 0;
	int sound = 0;
	int last_item = 1;

	do
	{
		system("cls");
		if (item == 0)
		{
			last_item = 1;
			item = 7;
		}
		if (item == 8)
		{
			item = 1;
			last_item = 7;
		}
		if (last_item == item)
			sound = 0;
		cons.menu_edit_stud(item, sound, is_mute, cons);
		user_input = _getch();
		last_item = item;
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
			cons.action_edit_student(item, is_mute, data_);
		else if (user_input == 27)
		{
			exit = 1;
		}
		else if (item==last_item)
		{
			sound =0;
		}
		else if (user_input == 109 && is_mute == true)
			is_mute = false;
		else if (user_input == 109 && is_mute == false)
			is_mute = true;

		else if (user_input == 105)
			system("start www.instagram.com/ch_.il");
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}
	} while (exit != 1);
}

void input_data::del_student(bool &is_mute, node &data_, console &cons)
{
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
	
	list<node> students;
	students.resize(0);
	string str;
	string str1;
	node n;
	ifstream f;
	f.open("data\\file_info\\user.chv", ofstream::binary);
	f >> str >> str1;
	int i = 0;
	while (!f.eof())
	{
		f >> n.login >> n.password >> n.name >> n.surname >> n.patronymic >> n.address >> n.phone_number;
		if (data_.login != n.login)
		{
			students.push_back(n);
			i++;
		}
	}
	f.close();
	ofstream f1;
	f1.open("data\\file_info\\user.chv", ofstream::binary);
	f1 << str << " " << str1;
	while (students.size() != 0)
	{
		f1 << "\n" << students.front().login << " " << students.front().password << " " << students.front().name << " " << students.front().surname << " " << students.front().patronymic << " " << students.front().address << " " << students.front().phone_number;
		students.pop_front();
	}
	f1.close();
}

void input_data::categories_to_nodes(vector<vector <string>> &v, vector<vector <test_node>> tn)
{
	vector <string> c;
	ifstream f;
	string str;
	v.resize(0);
	int a;
	int count_of_categories = 0;
	f.open("data\\file_info\\categories.chv", ofstream::binary);
	if (!emp_f("data\\file_info\\categories.chv"))
	{
		while (!f.eof())
		{
			f >> str >> a;
			c.push_back(str);
			count_of_categories++;
		}
		f.close();

		v.resize(0);

		f.open("data\\file_info\\user.chv", ofstream::binary);
		f >> str >> str;


		if (count_of_categories <= 15)
		{
			v.resize(1);
			v[0].resize(count_of_categories);
			for (int j = 0; j < count_of_categories; j++)
			{
				v[0][j] = c[j];
			}

		}

		else if (count_of_categories > 15)
		{
			int g = 0;
			v.resize((count_of_categories / 15) + 1);

			for (int i = 0; i < v.size() - 1; i++)
			{
				v[i].resize(15);
				for (int j = 0; j < 15; j++, g++)
				{
					v[i][j] = c[g];
				}

			}
			while (count_of_categories >= 15)
			{
				count_of_categories -= 15;
			}
			v[v.size() - 1].resize(count_of_categories);
			for (int j = 0; j < count_of_categories; j++, g++)
			{
				v[v.size() - 1][j] = c[g];
			}
		}
		f.close();
	}
}



void console::size(int XSize, int YSize)
{
    system("mode con cols=80 lines=30");
}

void console::menu_start(int item, int & sound, bool &is_mute, console &cons)

{
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     "; 
	if (item == 1)
	{

		cons.item_color();
		cout << ">    Log in     <\n";
		cons.main_color();
		cout << "\t\t\t         Sign  in \n\t\t\t\t\t";
		for (int i = 0; i < 14; i++)
			cout << "\n";
	}
	else if (item == 2)
	{

		
		cout << "     Log in\n";
		cons.item_color();
		cout << "\t\t\t     >   Sign  in    <\n";
		cons.main_color();
		for (int i = 0; i < 14; i++)
			cout << "\n";
	}
	cons.back_color();
	cout << "           M - mute  |  D - DarkMode (on\\off)  |  I - dev instagram\n                            In all menu`s";
	cons.main_color();
	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	sound++;
}

void console::menu_admin(int item, int & sound, bool &is_mute, console &cons)

{
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	if (item == 1)
	{
		
		cons.item_color();
		cout << "Tests\n";
		cons.main_color();
		cout << "\t\t\t\tStudents";
		cout << "\n\t\t\t\tEdit password";

		for (int i = 0; i < 14; i++)
				cout << "\n";
		cons.back_color();
		cout << "           M - mute  |  D - DarkMode (on\\off)  |  I - dev instagram\n                            In all menu`s";
		cons.main_color();
	}
	if (item == 2)
	{
		cout << "Tests\n";
		cons.item_color();
		cout << "\t\t\t\tStudents";
		cons.main_color();
		cout << "\n\t\t\t\tEdit password";

		for (int i = 0; i < 14; i++)
			cout << "\n";
		cons.back_color();
		cout << "           M - mute  |  D - DarkMode (on\\off)  |  I - dev instagram\n                            In all menu`s";
		cons.main_color();
	}
	if (item == 3)
	{
		cout << "Tests\n";
		cout << "\t\t\t\tStudents";
		cons.item_color();
		cout << "\n\t\t\t\tEdit password";
		cons.main_color();
		for (int i = 0; i < 14; i++)
			cout << "\n";
		cons.back_color();
		cout << "           M - mute  |  D - DarkMode (on\\off)  |  I - dev instagram\n                            In all menu`s";
		cons.main_color();
	}

	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
	sound++;
}

void console::menu_student(int item, int & sound, bool &is_mute, console &cons)

{

	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	if (item == 1)
	{
		cons.item_color();
		cout << "Tests\n";
		cons.main_color();
		cout << "\t\t\t\tStatistic";
		for (int i = 0; i < 15; i++)
			cout << "\n";
	}
	if (item == 2)
	{
		cout << "Tests\n";
		cons.item_color();
		cout << "\t\t\t\tStatistic";
		cons.main_color();
		for (int i = 0; i < 15; i++)
			cout << "\n";
	}
	cons.back_color();
	cout << "           M - mute  |  D - DarkMode (on\\off)  |  I - dev instagram\n                            In all menu`s";
	cons.main_color();
	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	sound++;
}

void console::menu_edit_stud(int item, int & sound, bool &is_mute, console &cons)
{
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
	if (item == 1)
	{
		
		cons.item_color();
		cout << "Login\n";
		cons.main_color();
		cout << "\t\t\t\tPassword";
		cout << "\n\t\t\t\tName";
		cout << "\n\t\t\t\tSurname";
		cout << "\n\t\t\t\tPatronymic";
		cout << "\n\t\t\t\tAddress";
		cout << "\n\t\t\t\tPhone number";

		for (int i = 0; i < 12; i++)
			cout << "\n";
		
	}
	if (item == 2)
	{
		cout << "Login\n";
		cons.item_color();
		cout << "\t\t\t\tPassword";
		cons.main_color();
		cout << "\n\t\t\t\tName";
		cout << "\n\t\t\t\tSurname";
		cout << "\n\t\t\t\tPatronymic";
		cout << "\n\t\t\t\tAddress";
		cout << "\n\t\t\t\tPhone number";

		for (int i = 0; i < 12; i++)
			cout << "\n";
	}
	if (item == 3)
	{
		cout << "Login\n";		
		cout << "\t\t\t\tPassword";
		cons.item_color();
		cout << "\n\t\t\t\tName";
		cons.main_color();
		cout << "\n\t\t\t\tSurname";
		cout << "\n\t\t\t\tPatronymic";
		cout << "\n\t\t\t\tAddress";
		cout << "\n\t\t\t\tPhone number";

		for (int i = 0; i < 12; i++)
			cout << "\n";
		
	}
	if (item == 4)
	{
		cout << "Login\n";
		cout << "\t\t\t\tPassword";
		cout << "\n\t\t\t\tName";
		cons.item_color();
		cout << "\n\t\t\t\tSurname";
		cons.main_color();
		cout << "\n\t\t\t\tPatronymic";
		cout << "\n\t\t\t\tAddress";
		cout << "\n\t\t\t\tPhone number";

		for (int i = 0; i < 12; i++)
			cout << "\n";
	}
	if (item == 5)
	{
		cout << "Login\n";		
		cout << "\t\t\t\tPassword";
		cout << "\n\t\t\t\tName";
		cout << "\n\t\t\t\tSurname";
		cons.item_color();
		cout << "\n\t\t\t\tPatronymic";
		cons.main_color();
		cout << "\n\t\t\t\tAddress";
		cout << "\n\t\t\t\tPhone number";

		for (int i = 0; i < 12; i++)
			cout << "\n";
		
	}
	if (item == 6)
	{
		cout << "Login\n";		
		cout << "\t\t\t\tPassword";
		cout << "\n\t\t\t\tName";
		cout << "\n\t\t\t\tSurname";
		cout << "\n\t\t\t\tPatronymic";
		cons.item_color();
		cout << "\n\t\t\t\tAddress";
		cons.main_color();
		cout << "\n\t\t\t\tPhone number";

		for (int i = 0; i < 12; i++)
			cout << "\n";
		
	}
	if (item == 7)
	{
		cout << "Login\n";		
		cout << "\t\t\t\tPassword";
		cout << "\n\t\t\t\tName";
		cout << "\n\t\t\t\tSurname";
		cout << "\n\t\t\t\tPatronymic";
		cout << "\n\t\t\t\tAddress";
		cons.item_color();
		cout << "\n\t\t\t\tPhone number";
		cons.main_color();

		for (int i = 0; i < 12; i++)
			cout << "\n";
		
	}


	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	sound++;

}

void console::menu_student_list(int item, int & sound, bool & is_mute, vector<vector<node>> &data_,int page, console &cons)
{
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	cout << "\n\n\n\n\n\n\n\n\n";
	
	for (int i = 0; i < item-1; i++)
	{
		cout << "\t\t\t\t" << data_[page][i].name << " " << data_[page][i].surname << endl;
	}
	cons.item_color();
	cout << "\t\t\t\t" << data_[page][item-1].name << " " << data_[page][item-1].surname << endl;
	cons.main_color();
	for (int i = item; i < data_[page].size(); i++)
	{
		cout << "\t\t\t\t" << data_[page][i].name << " " << data_[page][i].surname << endl;
	}
	
	for (int i = 0; i < 5+15-data_[page].size(); i++)
		cout << "\n";
	
	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
	sound++;
}

void console::menu_test_categories_list(int item, int & sound, bool & is_mute, console &cons, vector<string> &categ)
{
	cout << "\n\n\n\n\n\n\n\n\n";
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	for (int i = 0; i < item - 1; i++)
	{
		cout << "\t\t\t\t" << categ[i] << endl;
	}
	cons.item_color();
	cout << "\t\t\t\t" << categ[item-1] << endl;
	cons.main_color();
	for (int i = item; i < categ.size(); i++)
	{
		cout << "\t\t\t\t" << categ[i] << endl;
	}
	for (int i = 0; i < 5 + 15 - categ.size(); i++)
	{
		cout << "\n";
	}
	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
	sound++;
}

void console::menu_statistic(int item, int & sound, bool & is_mute, console &cons, vector<vector<users_statistic>> statistics, int page)
{
	cout << "\n\n\n\n\n\n\n\n\n";
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	for (int i = 0; i < item - 1; i++)
	{
		cout << "\t\t\t" << statistics[page][i].category << " " << statistics[page][i].numerator/statistics[page][i].denominator << endl;
	}
	cons.item_color();
	cout << "\t\t\t" << statistics[page][item - 1].category << " " << statistics[page][item - 1].numerator / statistics[page][item - 1].denominator << endl;
	cons.main_color();
	for (int i = item; i < statistics[page].size(); i++)
	{
		cout << "\t\t\t" << statistics[page][i].category << " " << statistics[page][i].numerator/statistics[page][i].denominator << endl;
	}
	for (int i = 0; i < 5 + 15 - statistics[page].size(); i++)
		cout << "\n";
	
	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
	sound++;
}

void console::menu_tests_edit(int item, int & sound, bool & is_mute, console & cons, int page, vector<vector<question>> q)
{
	cout << "\n\n\n\n\n\n\n\n\n";
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	for (int i = 0; i < item - 1; i++)
	{
		cout << "\t\t\t\t" << q[page][i].Question << endl;
	}
	cons.item_color();
	cout << "\t\t\t\t" << q[page][item - 1].Question << endl;
	cons.main_color();
	for (int i = item; i < q[page].size(); i++)
	{
		cout << "\t\t\t\t" << q[page][i].Question << endl;
	}
	for (int i = 0; i < 5 + 15 - q[page].size(); i++)
		cout << "\n";
	cons.back_color();
	cout << "                                S - to save";
	cons.main_color();
	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
	sound++;
}

void console::menu_tests_in_categories(int item, int & sound, bool & is_mute, console &cons, string &categ, vector<vector<test_node>> data_,int page, input_data id, vector<vector<test_node>> vtn)
{
	cout << "\n\n\n\n\n\n\n\n\n";
	mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
	for (int i = 0; i < item - 1; i++)
	{
		  cout << "\t\t\t\t" << vtn[page][i].name << endl;
	}
	cons.item_color();
	cout << "\t\t\t\t" << vtn[page][item - 1].name << endl;
	cons.main_color();
	for (int i = item; i < vtn[page].size(); i++)
	{
		cout << "\t\t\t\t" << vtn[page][i].name << endl;
	}
	for (int i = 0; i < 5 + 15 - vtn[page].size(); i++)
		cout << "\n";
	if (sound != 0 && !is_mute)
		mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
	sound++;
}


void console::action_start(int item, bool & login_successful, bool &is_mute, vector<string>& data_,  input_data id, console &cons)
{
	system("cls");
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
	switch (item)
	{
	case 1:
	{
		id.log_in( login_successful, data_,  cons);
		break;
	}
	case 2:
	{
		id.sign_in(cons);
		break;
	}
	}
}

void console::action_admin(int item, bool &is_mute, vector<string>& data_,  input_data id, console &cons, vector<vector<node>> data, vector<vector<test_node>> &_data_, vector<vector<string>> &categ)

{
	system("cls");
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
	switch (item)
	{
	case 1:
	{
		int item = 1;
		int user_input;
		int page = 0;
		int sound = 0;
		int et = 0;
		int last_item = 0;
		do
		{
			system("cls");
			if (item == 0)
			{
				item = 3;
				last_item = 1;
			}
			if (item == 4)
			{
				item = 1;
				last_item = 3;
			}
			mciSendString("close data\\file_sounds\\item.mp3  ", NULL, 0, NULL);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
			if (item == 1)
			{
			
				cons.item_color();
				cout << "New\n";
				cons.main_color();
				cout << "\t\t\t\tEdit\n";
				cout << "\t\t\t\tDelete\n";
				for (int i = 0; i < 14; i++)
						cout << "\n";
					
			}
			else if (item == 2)
			{
				cout << "New\n";
				cons.item_color();
				cout << "\t\t\t\tEdit\n";
				cons.main_color();
				cout << "\t\t\t\tDelete\n";
				for (int i = 0; i < 14; i++)
					cout << "\n";
			}
			else if (item == 3)
			{
				cout << "New\n";
				cout << "\t\t\t\tEdit\n";
				cons.item_color();
				cout << "\t\t\t\tDelete\n";
				cons.main_color();
				for (int i = 0; i < 14; i++)
					cout << "\n";
			}

			if (sound != 0 && !is_mute)
				mciSendString("play data\\file_sounds\\item.mp3 ", NULL, 0, NULL);
			sound++;
			user_input = _getch();
			last_item = item;
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
					id.new_test(cons);
					_data_.resize(0);
					id.tests_to_nodes(_data_);
					categ.resize(0);
					id.categories_to_nodes(categ,_data_);
				}
				else if (item == 2)
				{

					int item = 1;
					last_item = 1;
					page = 0;
					sound = 0;
					int ext = 0;
					do
					{
						system("cls");
						if (categ.size() == 0)
						{
							cout << "Create tests";
							system("pause");
							break;
						}
						if (categ[page].size() == 0)
						{
							ext = 1;
							break;
						}
						if (item == 0)
						{
							last_item = 1;

							if (page == 0)
								page = categ.size() - 1;
							else
								page--;
							item = categ[page].size();

						}
						if (item == categ[page].size() + 1)
						{
							item = 1;
							last_item = categ[page].size();
							if (page < categ.size())
								page++;
							if (page == categ.size())
								page = 0;
						}
						cons.menu_test_categories_list(item, sound, is_mute, cons, categ[page]);
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
							cons.action_test_categories_list(2, sound, is_mute, _data_, cons, categ[page], item - 1, id, categ[page][item - 1], categ);
							if (categ[page].size() == 0)
							{
								cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNo categories\n";
								system("pause");
								break;
							}
						}
						else if (user_input == 100)
						{
							cons.dark_mode();
							cons.main_color();
						}
						else if (user_input == 27)
							ext++;
						else if (user_input == 109 && is_mute == true)
							is_mute = false;
						else if (user_input == 109 && is_mute == false)
							is_mute = true;
						if (last_item == item)
							sound = 0;
						else if (user_input == 105)
							system("start www.instagram.com/ch_.il");
						
					} while (ext!=1);


				}
				else if (item == 3)
				{
					
						int item = 1;
						last_item = 1;
						page = 0;
						int ext = 0;
						do
						{
							system("cls");
							if (categ.size() == 0)
							{
								cout << "Create tests";
								system("pause");
								break;
							}
							if (categ[page].size() == 0)
							{
								ext = 1;
								break;
							}
							if (item == 0)
							{
								last_item = 1;

								if (page == 0)
									page = categ.size() - 1;
								else
									page--;
								item = categ[page].size();

							}
							if (item == categ[page].size() + 1)
							{
								item = 1;
								last_item = categ[page].size();
								if (page < categ.size())
									page++;
								if (page == categ.size())
									page = 0;
							}
							cons.menu_test_categories_list(item, sound, is_mute, cons, categ[page]);
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
								cons.action_test_categories_list(3, sound, is_mute, _data_, cons, categ[page], item - 1, id, categ[page][item - 1], categ);
								if (categ[page].size() == 0)
								{
									cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNo categories\n";
									system("pause");
									break;
								}
							}
							else if (user_input == 100)
							{
								cons.dark_mode();
								cons.main_color();
							}
							else if (user_input == 105)
								system("start www.instagram.com/ch_.il");
							else if (user_input == 27)
								ext++;
							else if (user_input == 109 && is_mute == true)
								is_mute = false;
							else if (user_input == 109 && is_mute == false)
								is_mute = true;
							else if (user_input == 27)
								et = 1;
						} while (ext!=1);
					}
					sound = 0;
			}
			else if (user_input == 100)
			{
				cons.dark_mode();
				cons.main_color();
			}
			else if (user_input == 109 && is_mute == true)
				is_mute = false;
			else if (user_input == 109 && is_mute == false)
				is_mute = true;
			else if (user_input == 27)
				et = 1;
			if (last_item == item)
					sound = 0;

			else if (user_input == 105)
				system("start www.instagram.com/ch_.il");
			
		} while (et!=1);
		sound = 0;
		break;
	}
	case 2:
	{
		if(data[0].size()!=0)
		action_student_list( item,   is_mute,  data,  id,  cons);
		else
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tNo students!\n";
				for (int i = 0; i < 51; i++)
				{
					if (i < 22)
						cout << "\n";
				}
			cons.back_color();
			system("pause");
			cons.main_color();
		}
		break;
	}
	case 3:
	{
		id.edit_admin(data_[1], cons);
		break;
	}
	}
}

void console::action_student(int item, bool &is_mute, vector<string>& data_,  input_data id, console &cons, vector<vector<test_node>> &_data_, vector<vector<string>> &categ,int &sound, vector<vector<users_statistic>> &statistics)

{
	system("cls");
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
	switch (item)
	{
	case 1:
	{

		int item = 1;
		int last_item = 1;
		int page = 0;
		int user_input;
		sound = 0;
		int exit = 0;
		do
		{
			system("cls");
			if (categ.size() == 0)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
				cout << "No tests\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cons.back_color();
				system("pause");
				cons.main_color();
				break;
			}
			if (item == 0)
			{
				last_item = 1;

				if (page == 0)
					page = categ.size() - 1;
				else
					page--;
				item = categ[page].size();

			}
			if (item == categ[page].size() + 1)
			{
				item = 1;
				last_item = categ[page].size();
				if (page<categ.size())
					page++;
				if (page == categ.size())
					page = 0;
			}

			cons.menu_test_categories_list(item, sound, is_mute, cons, categ[page]);
			last_item = item;
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
				cons.action_test_categories_list_student(3, sound, is_mute, _data_, cons, categ[page], item - 1, id, categ[page][item - 1], categ,data_, statistics);
			}
			else if (user_input == 100)
			{
				cons.dark_mode();
				cons.main_color();
			}
			else if (user_input == 27)
				exit++;
			else if (user_input == 109 && is_mute == true)
				is_mute = false;
			else if (user_input == 109 && is_mute == false)
				is_mute = true;
			if (last_item == item)
				sound = 0;
			else if (user_input == 105)
				system("start www.instagram.com/ch_.il");
			
		} while (exit!=1);
		break;
	}
	case 2:
	{
		int item = 1;
		int last_item = 1;
		int page = 0;
		int user_input;
		int exit = 0;
		do
		{
			if (statistics.size() == 0)
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
				cout << "No results!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				cons.back_color();
				system("pause");
				cons.main_color();
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
			cons.menu_statistic(item, sound, is_mute, cons, statistics,page);
			last_item = item;
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
				exit = 1;
			else if (user_input == 109 && is_mute == true)
				is_mute = false;
			else if (user_input == 109 && is_mute == false)
				is_mute = true;
			if (last_item == item)
				sound = 0;
		} while (exit!=1);
		break;
	}
	}
}

void console::action_student_list(int item, bool & is_mute, vector<vector<node>> &data_,  input_data id, console &cons)
{
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
	int user_input;
	int exit = 0;
	int sound = 0;
	item = 1;
	int last_item = 1;
	int page = 0;
	do
	{
		system("cls");
		if (item == 0)
		{
			last_item = 1;

			if(page==0)
			 page = data_.size()-1;
			else
				page--;
			item = data_[page].size();

		}
		if (item == data_[page].size()+1)
		{
			item = 1;
			last_item = data_[page].size();
			if(page<data_.size())
			page++;
			if (page == data_.size())
				page = 0;
		}
		if (last_item == item)
			sound = 0;
		menu_student_list(item, sound, is_mute,data_,page,cons);
		user_input = _getch();
		last_item = item;
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
			student_choise(cons, is_mute, data_, id, page,item,sound);
		}
		else if (user_input == 27)
		{
			exit = 1;
		}

		else if (user_input == 109 && is_mute == true)
			is_mute = false;
		else if (user_input == 109 && is_mute == false)
			is_mute = true;
		else if (last_item == item)
			sound = 0;
		else if (user_input == 105)
			system("start www.instagram.com/ch_.il");
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}

	} while (exit != 1);
}

void console::action_edit_student(int item, bool & is_mute, node & data)
{
	system("cls");
	vector<string> data_;
	data_.resize(9);
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
	bool is_error_in_str = 0; 
	bool is_end = 0;

	char c;
	system("cls");
	int count = 0;
	string oldlogin = data.login;
	switch (item)
	{
	case 1:
	{
			cout<<"Login :"<< data_[0];
			is_error_in_str = 0;
			while (c = _getch())
			{
				system("cls");
				if (c == 224)
					c = _getch();
				if (c == '\r')
				{
					cout << "Login :" << data_[0];
					is_end = 0;
					is_error_in_str = check_string(data_[0], "login");
					bool real_user = user_check_for_sign(data_);
					if (real_user)
					{
						error_color();
						cout << "\n\n\t\t\t    You can`t use this login) ";
						main_color();
						is_error_in_str = 0;
					}
					else if (is_error_in_str)
					{
						error_color();
						cout << "\n\n\t\t\t    You can use only English letters, \n\t\tunderlines, numbers(more then 8 digits) ";
						main_color();
						is_error_in_str = 0;

					}
					else
					{

						count++;
						break;
					}
				}
				else if (c == 8)
				{
					if (data_[0].size() != 0)
					{
						data_[0].pop_back();
						system("cls");
						cout << "Login :" << data_[0];
					}
					else
						break;
				}
				else if (c == 27)
				{

					count=-1;
					break;
				}
				else
				{
					data_[0].push_back(c);
					cout << "Login :" << data_[0];
				}
			}
		
		break;
	}

	case 2:
	{
			cout << "Password :" << data_[1];
			while ((c = _getch()))
			{
				system("cls");
				if (c == 224)
					c = _getch();
				if (c == 8)
				{
					if (data_[1].size() != 0)
					{
						data_[1].pop_back();
						cout << "Password :";
						for (int i = 0; i < data_[1].size(); i++)
							cout << '*';
					}
					else
						break;
				}
				else if (c == '\r')
				{
					cout << "Password :";

					for (int i = 0; i < data_[1].size(); i++)
						cout << '*';

					is_error_in_str = check_string(data_[1], "password");
					if (is_error_in_str)
					{
						error_color();
						cout << "\n\n\t\t\t    You can use only English letters, \n\t\t numbers(more then 8 digits) ";
						main_color();
						is_error_in_str = 0;

					}
					else
					{
						count++;
						break;
					}

				}
				else if (c == 27)
				{
					count = -1;
					break;
				}
				else
				{
					cout << "Password :";
					for (int i = 0; i < data_[1].size(); i++)
						cout << '*';

					data_[1].push_back(c);
					_putch('*');
				}

			}
		break;
	}

	case 3:
	{
			cout << "Name :" << data_[2];
			while ((c = _getch()))
			{
				system("cls");
				if (c == 224)
					c = _getch();
				if (c == 8)
				{
					if (data_[2].size() != 0)
					{
						data_[2].pop_back();
						cout << "Name :" << data_[2];
					}
					else
						break;
				}
				else if (c == '\r')
				{
					cout << "Name :" << data_[2];

					is_error_in_str = check_string(data_[2], "name");
					if (is_error_in_str)
					{
						error_color();
						cout << "\n\n\t\t\t    You can use only English letters\n\t(more then 2 digits)";
						main_color();
						is_error_in_str = 0;

					}
					else
					{
						count++;
						break;
					}

				}
				else if (c == 27)
				{
					count = -1;
					break;
				}
				else
				{
					data_[2].push_back(c);
					cout << "Name :" << data_[2];
				}
			}
		
		break;
	}

	case 4:
	{
            cout << "Surame :" << data_[3];
			while ((c = _getch()))
			{
				system("cls");
				if (c == 224)
					c = _getch();
				if (c == 8)
				{
					if (data_[3].size() != 0)
					{
						data_[3].pop_back();
						cout << "Surame :" << data_[3];
					}
					else
						break;
				}
				else if (c == '\r')
				{
					cout << "Surame :" << data_[3];
					is_error_in_str = check_string(data_[3], "name");
					if (is_error_in_str)
					{
						error_color();
						cout << "\n\n\t\t\t    You can use only English letters\n\t(more then 2 digits)";
						main_color();
						is_error_in_str = 0;
					}
					else
					{
						count++;
						break;
					}

				}
				else if (c == 27)
				{
					count = -1;
					break;
				}
				else
				{
					data_[3].push_back(c);
					cout << "Surame :" << data_[3];
				}
			}
		
		break;
	}

	case 5:
	{
			cout << "Patronymic :" << data_[4];
			while ((c = _getch()))
			{
				system("cls");
				if (c == 224)
					c = _getch();
				if (c == 8)
				{
					if (data_[4].size() != 0)
					{
						data_[4].pop_back();
						cout << "Patronymic :" << data_[4];
					}
					else
						break;
				}
				else if (c == '\r')
				{
					cout << "Patronymic :" << data_[4];
					is_error_in_str = check_string(data_[4], "name");
					if (is_error_in_str)
					{
						error_color();
						cout << "\n\n\t\t\t    You can use only English letters, (more then 2 digits)";
						main_color();
						is_error_in_str = 0;

					}
					else
					{
						count++;
						break;
					}

				}
				else if (c == 27)
				{
					count = -1;
					break;
				}
				else
				{
					data_[4].push_back(c);
					cout << "Patronymic :" << data_[4];
				}
			}
		
		break;
	}

	case 6:
	{

			cout << "Address :" << data_[5];
			while ((c = _getch()))
			{
				system("cls");
				if (c == 224)
					c = _getch();
				if (c == 8)
				{
					if (data_[5].size() != 0)
					{
						data_[5].pop_back();
						cout << "Address :" << data_[5];
					}
					else
						break;
				}
				else if (c == '\r')
				{
					cout << "Address :" << data_[5];

					is_error_in_str = check_string(data_[5], "address");
					if (is_error_in_str)
					{
						error_color();
						cout << "\n\n\t\t\t    You can use only English letters,\n\t\tnumbers and /,.-";
						main_color();
						is_error_in_str = 0;
					}
					else
					{
						count++;
						break;
					}

				}
				else if (c == 27)
				{
					count = -1;
					break;
				}
				else
				{
					data_[5].push_back(c);
					cout << "Address :" << data_[5];
				}
			}
		
		break;
	}

	case 7:
	{
			cout << "Phone number :" << data_[6];
			while ((c = _getch()))
			{
				system("cls");

				if (c == 224)
					c = _getch();
				if (c == 8)
				{
					if (data_[6].size() != 0)
					{
						data_[6].pop_back();
						cout << "Phone number :" << data_[6];
					}
					else
						break;
				}
				else if (c == '\r')
				{

					cout << "Phone number :" << data_[6];
					
					is_error_in_str = check_string(data_[6], "telephone");
					if (is_error_in_str)
					{
						error_color();
						cout << "\n\n\t\t\t    You can use only numbers\n\tand it must be 10 digits";
						main_color();
						is_error_in_str = 0;

					}
					else
					{
						count++;
						break;
					}

				}
				else if (c == 27)
				{
					count = -1;
					break;
				}
				else
				{
					data_[6].push_back(c);
					cout << "Phone number :" << data_[6];
				}
			}
		break;
	}

	}
	if (count != -1)
	{
		address_to_file(data_[5], 1);
		string last_login = data.login;
		switch (item)
		{
		case 1:
		{
			data.login = data_[item - 1];
			break;
		}
		case 2:
		{
			data.password = data_[item - 1];
			break;
		}
		case 3:
		{
			data.name = data_[item - 1];
			break;
		}
		case 4:
		{
			data.surname = data_[item - 1];
			break;
		}
		case 5:
		{
			data.patronymic = data_[item - 1];
			break;
		}
		case 6:
		{
			data.address = data_[item - 1];
			break;
		}
		case 7:
		{
			data.phone_number = data_[item - 1];
			break;
		}
		}

		list<node> students;
		node n;
		string str;
		string str1;

		ifstream f;
		f.open("data\\file_info\\user.chv", ofstream::binary);
		f >> str >> str1;
		int i = 0;
		while (!f.eof())
		{
			f >> n.login >> n.password >> n.name >> n.surname >> n.patronymic >> n.address >> n.phone_number;
			if (last_login != n.login)
			{
				students.push_back(n);
				i++;
			}

			
		}
		f.close();

		ofstream f1;
		f1.open("data\\file_info\\user.chv", ofstream::binary);
		hashing(data_[1]);
		address_to_file(data_[5],1);
		f1 << str << " " << str1;
		f1 << "\n" << data.login << " " << data.password << " " << data.name << " " << data.surname << " " << data.patronymic << " " << data.address << " " << data.phone_number;
		
		while(students.size()!=0)
		{   
	     
		    f1 << "\n" << students.front().login << " " << students.front().password << " " << students.front().name << " " << students.front().surname << " " << students.front().patronymic << " " << students.front().address << " " << students.front().phone_number;
			students.pop_front();
		}
		f.close();
		////////////////////////////////////////////////////////////////////////////////////////////////////



		//изменение в названии файлов студента в папках
		string on = "data\\passed_tests\\";
		on += oldlogin;
		on += ".chv";

		string nn= "data\\passed_tests\\";
		nn += data.login;
		nn += ".chv";
		rename(on.c_str(), nn.c_str());


		on.clear();
		nn.clear();


		on = "data\\tests_in_process\\";
		on += oldlogin;
		on += ".chv";

		nn = "data\\tests_in_process\\";
		nn += data.login;
		nn += ".chv";
		rename(on.c_str(), nn.c_str());


		on.clear();
		nn.clear();


		on = "data\\users_statistic\\";
		on += oldlogin;
		on += ".chv";
		nn = "data\\users_statistic\\";
		nn += data.login;
		nn += ".chv";
		rename(on.c_str(), nn.c_str());
		////////////////////////////////////////////////////////////////////////////////////////////////////
	}

}

void console::action_test_categories_list(int iitem, int & sound, bool & is_mute, vector<vector<test_node>> &data_, console &cons, vector<string> &categ,int categ_item, input_data id,string category, vector<vector<string>> &categg)
{
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
		output out(new to_file);
		int user_input;
		int exit = 0;
		int item = 1;
		int last_item = 1;
		int page = 0;
		sound = 0;
		vector<vector<test_node>> vtn;
		id.tests_to_nodes_categories(vtn, data_, categ[categ_item]);
		do
		{
			system("cls");
			if (vtn.size() == 0)
			{
				exit = 1;
				break;
			}
			if (vtn[page].size() == 0)
			{
				exit = 1;
				break;
			}
			if (item == 0)
			{
				last_item = 1;

				if (page == 0)
					page = vtn.size() - 1;
				else
					page--;
				item = vtn[page].size();

			}
			if (item == vtn[page].size() + 1)
			{
				item = 1;
				last_item = vtn[page].size();
				if (page < vtn.size())
					page++;
				if (page == vtn.size())
					page = 0;
			}
			menu_tests_in_categories(item, sound, is_mute, cons, categ[categ_item], data_, page, id, vtn);
			user_input = _getch();
			last_item = item;
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
				if(!is_mute)
				mciSendString("play data\\file_sounds\\enter.mp3  ", NULL, 0, NULL);
				if (iitem == 3)
				{
					if (!is_mute)
						mciSendString("play data\\file_sounds\\astalavistababy.mp3  ", NULL, 0, NULL);
					id.delete_test(category, vtn[page][item-1].name);
					data_.resize(0);
					id.tests_to_nodes(data_);
					categg.resize(0);
					id.categories_to_nodes(categg, data_);
					exit = 1;
					if (categ.size() == 0)
					{
						exit = 1;
						break;
					}
				}
				else 
				{
					id.edit_test(cons, vtn[page][item - 1].name, vtn[page][item - 1].category,id,sound,is_mute);
					if (categ.size() == 0)
					{
						exit = 1;
						break;
					}
				}
			}

			else if (user_input == 27)
			{
				exit = 1;
			}
			else if (user_input == 109 && is_mute == true)
				is_mute = false;
			else if (user_input == 109 && is_mute == false)
				is_mute = true;
			if (last_item == item)
				sound = 0;
			
			else if (user_input == 105)
				system("start www.instagram.com/ch_.il");
			else if (user_input == 100)
			{
				cons.dark_mode();
				cons.main_color();
			}

		} while (exit != 1);
}

void console::action_test_categories_list_student(int iitem, int & sound, bool & is_mute, vector<vector<test_node>> &data_, console &cons, vector<string> &categ, int categ_item, input_data id, string category, vector<vector<string>> &categg,vector<string> data_st, vector<vector<users_statistic>> &statistics)
{
	if (!is_mute)
		mciSendString("play data\\file_sounds\\enter.wav ", NULL, 0, NULL);
	output out(new to_file);
	int user_input;
	int exit = 0;
	bool is_was = 0;
	int item = 1;
	int last_item = 1;
	int page = 0;
	vector<vector<test_node>> vtn;
	id.tests_to_nodes_categories(vtn, data_, categ[categ_item]);
	do
	{
		system("cls");
		if (vtn[page].size() == 0)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
			cout << "category passed!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cons.back_color();
			system("pause");
			cons.main_color();
			break;
		}
		if (item == 0)
		{
			last_item = 1;

			if (page == 0)
				page = vtn.size() - 1;
			else
				page--;
			item = vtn[page].size();

		}
		if (item == vtn[page].size() + 1)
		{
			item = 1;
			last_item = vtn[page].size();
			if (page < vtn.size())
				page++;
			if (page == vtn.size())
				page = 0;
		}
		if (last_item == item)
			sound = 0;
		menu_tests_in_categories(item, sound, is_mute, cons, categ[categ_item], data_, page, id, vtn);
	
		user_input = _getch();
		last_item = item;
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
				mciSendString("play data\\file_sounds\\just-do-it.mp3 ", NULL, 0, NULL);
			time_t start, end;
			time(&start);
			int count = 0;
			vector<question> question;
			string address = "data\\file_tests\\";
			address += vtn[page][item - 1].category;
			address += "\\";
			address += vtn[page][item - 1].name;
			address += ".chv";
			ifstream ifs;
			ifs.open(address, ifstream::binary);
			ifs >> count;
			question.resize(count);
			for (int i = 0; i < count; i++)
			{
				ifs >> question[i].Question;
				ifs >> question[i].answ_true;
				ifs >> question[i].answ1;
				ifs >> question[i].answ2;
				address_to_file(question[i].Question, 2);
				address_to_file(question[i].answ_true, 2);
				address_to_file(question[i].answ1, 2);
				address_to_file(question[i].answ2, 2);
			}
			ifs.close();

			int i = 0;
			user_input = 0;
			exit = 0;
			int Iitem = 1;
			last_item = 1;
			int num_of_end_question = 0;
			int true_questions_pass = 0;

			string addr = "data\\tests_in_process\\";
			addr += data_st[0];
			addr += ".chv";
			ifstream fs;
			fs.open(addr);
			if (!fs)
			{
				ofstream fo(addr);
				fo.open(addr);
				fo.close();
				fs.close();
				fs.open(addr);
			}
			int seconds = 0;
			vector<in_process> ip;
			in_process i_p;
			while (!fs.eof())
			{
				fs >> i_p.category >> i_p.name >> i_p.num_of_true_answs >> i_p.num_of_end_quest >> i_p.seconds;
				if (i_p.category == vtn[page][item - 1].category&&i_p.name == vtn[page][item - 1].name)
				{
					i = i_p.num_of_end_quest - 1;
					true_questions_pass = i_p.num_of_true_answs;
					seconds = i_p.seconds;
				}
			}
			fs.close();
			int last = 1;
			for (; i < count; i++)
			{
				srand(time(NULL));

				int randnum = rand() % 3;
				while (last == randnum)
					randnum = rand() % 3;
				last = randnum;

				do
				{
					system("cls");
					if (Iitem == 0)
					{
						last_item = 1;
						Iitem = 3;
					}
					if (Iitem == 4)
					{
						Iitem = 1;
						last_item = 3;
					}
					if (last_item == Iitem)
						sound = 0;
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t" << question[i].Question;
					switch (randnum)
					{

					case 0:
					{

						if (Iitem == 1)
						{
							cons.item_color();
							cout << "\n\t\t\t" << question[i].answ_true << "\n";
							cons.main_color();
							cout << "\t\t\t" << question[i].answ1 << "\n";
							cout << "\t\t\t" << question[i].answ2 << "\n";
						}
						if (Iitem == 2)
						{
							cout << "\n\t\t\t" << question[i].answ_true << "\n";
							cons.item_color();
							cout << "\t\t\t" << question[i].answ1 << "\n";
							cons.main_color();
							cout << "\t\t\t" << question[i].answ2 << "\n";
						}
						if (Iitem == 3)
						{
							cout << "\n\t\t\t" << question[i].answ_true << "\n";
							cout << "\t\t\t" << question[i].answ1 << "\n";
							cons.item_color();
							cout << "\t\t\t" << question[i].answ2 << "\n";
							cons.main_color();
						}
						break;
					}

					case 1:
					{
						if (Iitem == 1)
						{
							cons.item_color();
							cout << "\n\t\t\t" << question[i].answ1 << "\n";
							cons.main_color();
							cout << "\t\t\t" << question[i].answ_true << "\n";
							cout << "\t\t\t" << question[i].answ2 << "\n";
						}
						if (Iitem == 2)
						{
							cout << "\n\t\t\t" << question[i].answ1 << "\n";
							cons.item_color();
							cout << "\t\t\t" << question[i].answ_true << "\n";
							cons.main_color();
							cout << "v" << question[i].answ2 << "\n";
						}
						if (Iitem == 3)
						{
							cout << "\n\t\t\t" << question[i].answ1 << "\n";
							cout << "\t\t\t" << question[i].answ_true << "\n";
							cons.item_color();
							cout << "\t\t\t" << question[i].answ2 << "\n";
							cons.main_color();
						}
						break;
					}

					case 2:
					{
						if (Iitem == 1)
						{
							cons.item_color();
							cout << "\n\t\t\t" << question[i].answ2 << "\n";
							cons.main_color();
							cout << "\t\t\t" << question[i].answ1 << "\n";
							cout << "\t\t\t" << question[i].answ_true << "\n";
						}
						if (Iitem == 2)
						{
							cout << "\n\t\t\t" << question[i].answ2 << "\n";
							cons.item_color();
							cout << "\t\t\t" << question[i].answ1 << "\n";
							cons.main_color();
							cout << "\t\t\t" << question[i].answ_true << "\n";
						}
						if (Iitem == 3)
						{
							cout << "\n\t\t\t" << question[i].answ2 << "\n";
							cout << "\t\t\t" << question[i].answ1 << "\n";
							cons.item_color();
							cout << "\t\t\t" << question[i].answ_true << "\n";
							cons.main_color();
						}
						break;
					}

					}

					user_input = _getch();
					last_item = Iitem;
					if (user_input == 224)
						user_input = _getch();
					if (user_input == 72)
					{
						Iitem--;
					}
					else if (user_input == 80)
					{
						Iitem++;
					}
					else if (user_input == 13)
					{
						switch (randnum)
						{
						case 0:
						{
							if (Iitem == 1)
								true_questions_pass++;
							break;
						}
						case 1:
						{
							if (Iitem == 2)
								true_questions_pass++;
							break;
						}
						case 2:
						{
							if (Iitem == 3)
								true_questions_pass++;

							break;
						}
						}
						break;
					}
					else if (user_input == 27)
					{
						exit = 1;
						string address = "data\\tests_in_process\\";
						address += data_st[0];
						address += ".chv";
						ifstream ifs;
						ifs.open(address);
						if (!ifs)
						{
							ofstream of(address);
							of.open(address);
							of.close();
							ifs.close();
							ifs.open(address);
						}
						int o = 0;
						string str;
						while (!ifs.eof())
						{
							ifs >> str;
							o++;
						}
						ifs.close();


						ofstream of(address, ofstream::app | ofstream::binary);

						if (str.size() == 0 && o == 1)
						{
							time(&end);
							seconds += difftime(end, start);
							of << vtn[page][item - 1].category << " " << vtn[page][item - 1].name << " " << true_questions_pass << " " << i + 1 << " " << seconds;
							of.close();
						}
						else
						{

							ifs.open(address);
							vector<in_process> ip;
							in_process i_p;
							while (!ifs.eof())
							{
								ifs >> i_p.category >> i_p.name >> i_p.num_of_true_answs >> i_p.num_of_end_quest >> i_p.seconds;
								if (i_p.category == vtn[page][item - 1].category&&i_p.name == vtn[page][item - 1].name)
								{
									i_p.num_of_end_quest = i + 1;
									i_p.num_of_true_answs = true_questions_pass;
									is_was = 1;
								}
								ip.push_back(i_p);
							}
							ifs.close();
							of.close();
							ofstream of(address, ofstream::binary);
							of << ip.back().category << " " << ip.back().name << " " << ip.back().num_of_true_answs << " " << ip.back().num_of_end_quest << " " << ip.back().seconds;
							ip.pop_back();
							while (ip.size() != 0)
							{
								of << "\n" << ip.back().category << " " << ip.back().name << " " << ip.back().num_of_true_answs << " " << ip.back().num_of_end_quest << " " << ip.back().seconds;
								ip.pop_back();
							}
							if (!is_was)
								of << "\n" << vtn[page][item - 1].category << " " << vtn[page][item - 1].name << " " << true_questions_pass << " " << i + 1<<" "<<seconds;
							of.close();
						}
						is_was = 0;
						i = count;
						break;
					}

					else if (user_input == 109 && is_mute == true)
						is_mute = false;
					else if (user_input == 109 && is_mute == false)
						is_mute = true;
					if (last_item == Iitem)
						sound = 0;
					else if (user_input == 105)
						system("start www.instagram.com/ch_.il");
					else if (user_input == 100)
					{
						cons.dark_mode();
						cons.main_color();
					}
				} while (exit != 1);
				user_input = 0;
				Iitem = 1;
				last_item = 1;
			}

			system("cls");
			if (exit != 1)
			{
				time(&end);
				seconds += difftime(end, start);
				if (seconds <= 60)
					printf("\n\n\n\n\n\n\n\n\n\n\n\nThe time: %i seconds\n", seconds);
				else
				{
					int mins = 0;
					while (seconds >= 60)
					{
						mins++;
						seconds -= 60;
					}
					printf("\n\n\n\n\n\n\n\n\n\n\n\nThe time: %i min, %i seconds\n", mins, seconds);
				}

				double mark = (12 * true_questions_pass) / count;
				cout << mark << " balov\n";
				if (!is_mute)
					mciSendString("play data\\file_sounds\\missioncomplete.mp3 ", NULL, 0, NULL);
				Sleep(3000);
				cons.back_color();
				system("pause");
				cons.main_color();
				//удаление с незаконченных
				string addressf = "data\\tests_in_process\\";
				addressf += data_st[0];
				addressf += ".chv";
				ifstream ifsf;
				ifsf.open(addressf);
				ofstream ofst;
				if (ifsf)
				{


					vector<in_process> ipi;
					in_process i_pi;

					while (!ifsf.eof())
					{
						ifsf >> i_pi.category >> i_pi.name >> i_pi.num_of_true_answs >> i_pi.num_of_end_quest >> i_pi.seconds;
						if (i_pi.category == vtn[page][item - 1].category&&i_pi.name == vtn[page][item - 1].name) { is_was = 1; }
						else ipi.push_back(i_pi);
					}
					ifsf.close();
					if (is_was)
					{
						ofst.open(addressf, ofstream::binary);
						if (ipi.size() != 0)
						{
							ofst << ipi.back().category << " " << ipi.back().name << " " << ipi.back().num_of_true_answs << " " << ipi.back().num_of_end_quest << " " << ipi.back().seconds;
							ipi.pop_back();
						}
						while (ipi.size() != 0)
						{
							ofst << "\n" << ipi.back().category << " " << ipi.back().name << " " << ipi.back().num_of_true_answs << " " << ipi.back().num_of_end_quest << " " << ipi.back().seconds;
							ipi.pop_back();
						}
						ofst.close();
					}
				}
				/////////////////////////////
				//запись в статистику
				addressf.clear();
				addressf += "data\\users_statistic\\";
				addressf += data_st[0];
				addressf += ".chv";

				if (emp_f(addressf))
				{
					ofst.open(addressf);
					ofst << vtn[page][item - 1].category << " " << mark << " 1";
					ofst.close();
				}
				else
				{
					int a = 0;
					ifsf.open(addressf);
					users_statistic us;
					vector<users_statistic> u_s;
					while (!ifsf.eof())
					{
						ifsf >> us.category >> us.numerator >> us.denominator;
						if (us.category == vtn[page][item - 1].category)
						{
							us.numerator += mark;
							us.denominator++;
							a++;
						}
						u_s.push_back(us);
					}
					ifsf.close();
					ofst.close();
					ofst.open(addressf);
					ofst << u_s.back().category << " " << u_s.back().numerator << " " << u_s.back().denominator;
					u_s.pop_back();
					while (u_s.size() != 0)
					{
						ofst << "\n" << u_s.back().category << " " << u_s.back().numerator << " " << u_s.back().denominator;
						u_s.pop_back();
					}
					if (a == 0)
						ofst << "\n" << vtn[page][item - 1].category << " " << mark << " 1";
					ofst.close();
				}
				/////////////////////////////

				//запись в сданые тесты
				addressf.clear();
				addressf += "data\\passed_tests\\";
				addressf += data_st[0];
				addressf += ".chv";

				if (emp_f(addressf))
				{
					ofst.open(addressf);
					ofst << vtn[page][item - 1].category << " " << vtn[page][item - 1].name;
					ofst.close();
				}
				else
				{
					ifsf.open(addressf);
					in_process ins;
					vector<in_process> in_s;
					while (!ifsf.eof())
					{
						ifsf >> ins.category >> ins.name;
						in_s.push_back(ins);
					}
					ifsf.close();
					ofst.open(addressf);
					ofst << vtn[page][item - 1].category << " " << vtn[page][item - 1].name;
					while (in_s.size() != 0)
					{
						ofst << "\n" << in_s.back().category << " " << in_s.back().name;
						in_s.pop_back();
					}
					ofst.close();
				}
			
			/////////////////////////////
			string categor = categ[categ_item];
			data_.resize(0);
			id.tests_to_nodes_stud(data_, data_st[0]);
			categ.resize(0);
			categg.resize(0);
			id.categories_to_nodes(categg, data_);
			vtn.resize(0);
			id.tests_to_nodes_categories(vtn, data_, categor);
			id.restart_statistic(statistics, data_st[0]);
		}
			user_input = 0;
			exit = 0;
			item = 1;
			last_item = 1;
		}
		else if (user_input == 27)
			exit = 1;
		else if (user_input == 109 && is_mute == true)
			is_mute = false;
		else if (user_input == 109 && is_mute == false)
			is_mute = true;
		
		else if (user_input == 105)
			system("start www.instagram.com/ch_.il");
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}

	} while (exit != 1);
}



void output::write_new_test(test_node tn,vector<question> question,int quan)
{
	string address;
	string str1;
	int a = 0;
	string dir_part = "data\\file_tests\\";
	string chv = ".chv";
	address += dir_part;
	address += tn.category;
	output out(new to_file);
	out.cr_dir(address);
	address.clear();
	address += dir_part;
	address += tn.category;
	address += "\\";
	address += tn.name;
	address += chv;
	out.cr_file(address);
	ofstream f;
	f.open(address, ofstream::binary);
	f << quan ;

	for (int i = 0; i < quan; i++)
	{
		address_to_file(question[i].Question, 1);
		address_to_file(question[i].answ_true, 1);
		address_to_file(question[i].answ1, 1);
		address_to_file(question[i].answ2, 1);
		f <<"\n" << question[i].Question  ;
		f << "\n" << question[i].answ_true;
		f << "\n" << question[i].answ1;
		f << "\n" << question[i].answ2;
	}
	f.close();

	f.open("data\\file_info\\categories.chv", ofstream::binary | ofstream::app);
	ifstream ifs;
	ifs.open("data\\file_info\\categories.chv", ofstream::binary);//проверка на существуещую категорию
	if (!emp_f("data\\file_info\\categories.chv"))
	{
		while (!ifs.eof())
		{
			ifs >> str1;
			if (str1 == tn.category)
			{
				a = 1;
				break;
			}
			ifs >> str1;
		}
	}
		if (a != 1)
		{
			if (!emp_f("data\\file_info\\categories.chv"))
			{
				f << "\n" << tn.category << " 1";
			}
			else
				f << tn.category << " 1";
			f.close();
			ifs.close();
		}
	
	else
	{
		ifs.close();
		ifs.open("data\\file_info\\categories.chv", ofstream::binary);
	    vector <file_category> fc; 
		file_category node;
		if (!emp_f("data\\file_info\\categories.chv"))
		{
			while (!ifs.eof())
			{
				ifs >> node.cat >> node.num;
				if (tn.category == node.cat)
				{
					node.num++;
				}
				fc.push_back(node);
			}
			ifs.close();
			f.close();
			f.open("data\\file_info\\categories.chv", ofstream::binary);
			f << fc.back().cat << " " << fc.back().num;
			fc.pop_back();
			while (fc.size() != 0)
			{
				f << "\n" << fc.back().cat << " " << fc.back().num;
				fc.pop_back();
			}

			f.close();
		}

	}
	
	f.open("data\\file_info\\tests_info.chv", ofstream::binary | ofstream::app);
	tn.address.clear();
	tn.address += "data\\\\file_tests\\\\";
	tn.address += tn.category;
	tn.address += "\\\\";
	tn.address += tn.name;
	tn.address += ".chv";
	if (emp_f("data\\file_info\\tests_info.chv"))
		f << tn.address << " " << tn.category << " " << tn.name;
	else
		f << "\n" << tn.address << " " << tn.category << " " << tn.name;
	f.close();
	  
}

void output::cr_dir(string str)
{
	fs::create_directories(str);
}

void output::del_dir(string str)
{
	fs::remove_all(str);
}

void output::cr_file(string str)
{
	ofstream f(str); 
	f.close();
}

void output::del_file(string str)
{
	fs::remove(str);
}
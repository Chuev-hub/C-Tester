#include "lib.h"
#include "function.h"
#include "class.h"
#include "struct.h"



void main()
{
	output out(new to_file);
	vector<string> data_(9);
	console cons;
	cons.size(700, 600);
	input_data id;
	cons.main_color();
	file_check(cons);
	start_preview(cons);

	int item = 1;
	int user_input;
	int exit = 0;
	int sound = 0;
	int last_item = 1;
	bool is_mute = false;
	bool login_successful = 0;

	do
	{
		system("cls");
		
		if (item == 0)
		{
			last_item = 1;
			item = 2;
		}
		if (item == 3)
		{
			item = 1;
			last_item = 2;
		}
		if (last_item == item)
			sound = 0;
		cons.menu_start(item, sound, is_mute, cons);
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
			cons.action_start(item, login_successful, is_mute, data_,id,cons);
			if (login_successful)
			{
				exit == 0;
				admin admin;
				student human;
				char type;
				hashing(data_[1]);
				string flogin;
				string fpassword;
				ifstream f;
				f.open("data\\file_info\\user.chv", ofstream::binary);
				f >> flogin >> fpassword;
				if (data_[0] == "admin" &&fpassword == data_[1])
				{
					admin.add(data_);
					type = 'a';
				}
				else
					while (!f.eof())
					{
						f >> flogin >> fpassword;
						if (flogin == data_[0] && fpassword == data_[1])
						{
							f >> data_[2] >> data_[3] >> data_[4] >> data_[5] >> data_[6] ;
							human.add(data_);
							type = 's';
							break;
						}
						else
							f >> flogin >> flogin >> flogin >> flogin >> flogin;
					}
				f.close();
				system("cls");
				if(!is_mute)
				mciSendString("play data\\file_sounds\\magic.mp3  ", NULL, 0, NULL);
				for (int j = 0; j < 15; j++)
					cout << "\n";
				cout << "\t\t\t       Welcome, ";
				cons.item_color();
				cout << data_[0] << "\n";
				cons.main_color();
				for (int j = 0; j < 15; j++)
					cout << "\n";
				cons.back_color();

				system("pause");
				cons.main_color();
				exit = 0;

				if (type == 'a')
				{
					system("cls");
					vector <vector<node>> students;
					vector <vector <test_node>> tests;
					id.students_to_nodes(students);
					id.tests_to_nodes(tests);
					vector<vector<string>> categ;
					id.categories_to_nodes(categ, tests);

					do
					{
						system("cls");
						if (item == 0)
						{
							last_item = 1;
							item = 3;
						}
						if (item == 4)
						{
							item = 1;
							last_item = 3;
						}
						if (last_item == item)
							sound = 0;
						cons.menu_admin(item, sound, is_mute, cons);
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
							cons.action_admin(item, is_mute, data_, id,cons, students,tests, categ);
						else if (user_input == 109 && is_mute == true)
							is_mute = false;
						else if (user_input == 109 && is_mute == false)
							is_mute = true;
						else if (user_input == 27)
						{
							exit = are_you_sure(cons);
						}
						else if (user_input == 105)
							system("start www.instagram.com/ch_.il");
						else if (user_input == 100)
						{
							cons.dark_mode();
							cons.main_color();
						}
					} while (exit != 1);
				}
				else if (type == 's')
				{

					vector <vector <test_node>> tests;
					id.tests_to_nodes_stud(tests,data_[0]);
					vector<vector<string>> categ;
					id.categories_to_nodes(categ, tests);
					vector<vector<users_statistic>> statistics;
					id.restart_statistic(statistics,data_[0]);

					
					do
					{
						system("cls");
						if (item == 0)
						{
							last_item = 1;
							item = 2;
						}
						if (item == 3)
						{
							item = 1;
							last_item = 2;
						}
						if (last_item == item)
							sound = 0;
						cons.menu_student(item, sound, is_mute, cons);
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
							cons.action_student(item, is_mute, data_, id, cons, tests, categ,sound,statistics);
						else if (user_input == 109 && is_mute == true)
							is_mute = false;
						else if (user_input == 109 && is_mute == false)
							is_mute = true;
						else if (user_input == 27)
						{
							exit = are_you_sure(cons);
						}
						else if (user_input == 105)
							system("start www.instagram.com/ch_.il");
						else if (user_input == 100)
						{
							cons.dark_mode();
							cons.main_color();
						}
					} while (exit != 1);
				}
				exit = 0;
				login_successful = 0;
				item = 1;
				sound = 0;
			}
		}
		else if (user_input == 109 && is_mute == true)
			is_mute = false;
		else if (user_input == 109 && is_mute == false)
			is_mute = true;
		else if (user_input == 27)
			exit = 1;
		else if (user_input == 105)
		    system("start www.instagram.com/ch_.il");
		else if (user_input == 100)
		{
			cons.dark_mode();
			cons.main_color();
		}

	} while (exit != 1);
}
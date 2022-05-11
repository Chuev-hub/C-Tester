#pragma once
#include "lib.h"
#include "function.h"
#include "struct.h"

class console;
class input_data;

class console
{
	bool d_mode;

public:
	console()
	{
		d_mode = 0;
	}
	void size(int XSize, int YSize);

	void dark_mode()
	{
		if (d_mode == 0)
			d_mode = 1;
		else
			d_mode = 0;
	}

	void item_color()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (d_mode == 0)
			SetConsoleTextAttribute(hConsole, 250);
		else
			SetConsoleTextAttribute(hConsole, 10);
	}

	void back_color()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (d_mode == 0)
			SetConsoleTextAttribute(hConsole, 248);
		else
			SetConsoleTextAttribute(hConsole, 8);
	}

	void main_color()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (d_mode == 0)
			SetConsoleTextAttribute(hConsole, 249);
		else
			SetConsoleTextAttribute(hConsole, 15);
	}

	void error_color()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (d_mode == 0)
			SetConsoleTextAttribute(hConsole, 252);
		else
			SetConsoleTextAttribute(hConsole, 12);
	}


	void menu_start(int item, int &sound, bool &is_mute, console &cons);

	void menu_admin(int item, int &sound, bool &is_mute, console &cons);

	void menu_student(int item, int &sound, bool &is_mute, console &cons);

	void menu_edit_stud(int item, int &sound, bool &is_mute, console &cons);

	void menu_student_list(int item, int &sound, bool &is_mute, vector<vector<node>> &data_, int page, console &cons);

	void menu_tests_in_categories(int item, int & sound, bool & is_mute, console &cons, string &categ, vector<vector<test_node>> data_, int page, input_data id, vector<vector<test_node>> vtn);

	void menu_test_categories_list(int item, int & sound, bool & is_mute, console &cons, vector<string> &categ);
	
	void menu_statistic(int item, int & sound, bool & is_mute, console &cons, vector<vector<users_statistic>> statistics, int page);

	void menu_tests_edit(int item, int & sound, bool & is_mute, console &cons, int page,vector<vector<question>>q);


	void action_start(int item, bool &login_successful, bool &is_mute, vector<string> &data_, input_data id, console &cons);

	void action_admin(int item, bool &is_mute, vector<string> &data_, input_data id, console &cons, vector<vector<node>> data, vector<vector<test_node>> &_data_, vector<vector<string>> &categ);

	void action_student(int item, bool &is_mute, vector<string> &data_, input_data id, console &cons, vector<vector<test_node>> &_data_, vector<vector<string>> &categ,int&sound,vector<vector<users_statistic>> &statistics);

	void action_student_list(int item, bool &is_mute, vector<vector<node>> &data_, input_data id, console &cons);

	void action_edit_student(int item, bool &is_mute,node &data_);

	void action_test_categories_list(int item, int & sound, bool & is_mute, vector<vector<test_node>> &data_,  console &cons, vector<string> &categ, int categ_item, input_data id, string category, vector<vector<string>> &categg);
	
	void action_test_categories_list_student(int item, int & sound, bool & is_mute, vector<vector<test_node>> &data_, console &cons, vector<string> &categ, int categ_item, input_data id, string category, vector<vector<string>> &categg, vector<string> data_st, vector<vector<users_statistic>> &statistics);

};

class input_data
{

	vector<string> data_;
	bool is_error_in_str = 0;            //Для проверки правильности строки
	bool is_it_real_user = 0;            //Для проверки пользователя
	bool is_end = 0;                     //Для выхода
	char c;
	int count = 1;

public:

	void log_in( bool &login_successful, vector<string> &data_, console &cons);
	void sign_in(console &cons);
	void edit_admin(string &passw, console &cons);
	void edit_student(bool &is_mute, node &data_, console &cons);
	void students_to_nodes(vector<vector <node>> &vn);
	void tests_to_nodes(vector<vector <test_node>> &vn);
	void tests_to_nodes_categories(vector <vector <test_node>> &vn, vector <vector <test_node>> v, string category);
	void del_student(bool &is_mute, node &data_, console &cons);
	void categories_to_nodes(vector<vector <string>> &v, vector<vector <test_node>> tn);
	void new_test(console cons);
	void tests_to_nodes_stud(vector<vector <test_node>> &vn,string login);
	void delete_test(string category, string name);
	void restart_statistic(vector<vector<users_statistic>> &vvs, string login);
	void edit_test(console &cons, string name, string category, input_data id, int & sound, bool & is_mute);
	void tests_to_nodes_edit(vector <vector <question>> &vn, vector <question> v);
};




class user
{

protected:
	vector<string> data_;

public:

	virtual void add(vector<string> data_) = 0;

};

class admin : user
{

public:

	virtual void add(vector<string> data_);

};

class student : user
{
	vector<vector<users_statistic>> statistic;
protected:
	
public:

	virtual void add(vector<string> data_);

	vector<string> get_data() { return data_; }

	void show_all(console cons);

};



class write
{

public:

	virtual void sign_in(vector<string> data_) = 0;

};

class to_file : public write
{

public:
   virtual void sign_in(vector<string> data_);

};

class output
{
	write*w;
public:
	output(write*ww)
	{
		w = ww;
	}
	void write_new_user(student st)
	{
		w->sign_in(st.get_data());
	}
	void static write_new_test(test_node tn, vector<question> question, int quan);



	void cr_dir(string str);
	void del_dir(string str);
	void cr_file(string str);
	void del_file(string str);

};
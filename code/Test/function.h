#pragma once
#include "lib.h"
#include "class.h"
#include "struct.h"

class console;
class input_data;

void preview_input_str(string str, vector<string> data_, console &cons, int i);
void start_preview(console cons);

void copy_node(node &n, node m);
void copy_test_node(test_node &n, test_node m);
bool check_string(string str, string ver);
void hashing(string&str);
void address_to_file(string&str, int a);
bool real_user_check(vector<string> data_);
bool user_check_for_sign(vector<string> data_);
bool isf(string a);
void file_check(console cons);
void copy_statistic_node(users_statistic &vs, users_statistic s);
int are_you_sure_to_del(console &cons);

bool emp_f(string a);
int are_you_sure(console &cons);
void student_choise(console &cons, bool & is_mute, vector<vector<node>> &data_, input_data id, int page,int num, int &sound);
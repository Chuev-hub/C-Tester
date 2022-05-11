#pragma once
#include "lib.h"
#include "function.h"
#include "class.h"
struct node
{
	string login;
	string password;
	string name;
	string surname;
	string patronymic;
	string address;
	string phone_number;
};
struct test_node
{
	string address;
	string category;
	string name;
};
struct question
{
	string Question;
	string answ_true;
	string answ1;
    string answ2;
};
struct file_category
{
	string cat;
	int num;
};
struct in_process
{
	string category;
	string name;
	int num_of_true_answs;
	int num_of_end_quest;
	int seconds;
};
struct users_statistic
{
	string category;
	int numerator;
	int denominator;
};
#pragma once
#include <iostream>

using namespace std;

struct Employee
{
    Employee(string employee_num_, string name_, string cl_, string phone_num_, string birthday_, string certi_)
        : employee_num(employee_num_), name(name_), cl(cl_), phone_num(phone_num_), birthday(birthday_), certi(certi_) {}
    string employee_num;
    string name;
    string cl;
    string phone_num;
    string birthday;
    string certi;
};

struct Command
{
    string cmd_name;
};
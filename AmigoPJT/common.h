#pragma once
#include <iostream>
#include <vector>

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
    enum
    {
        param_start = 0,
        cmd_type = param_start,
        op1,
        op2,
        op3,
        value1,
        value2,
        value3,
        value4,
        value5,
        value6,
        param_end,
        param_count = param_end - param_start
    };
    string param[param_count];
};

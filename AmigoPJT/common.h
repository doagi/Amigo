#pragma once
#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

struct Employee
{
 //   Employee(string employee_num_, string name_, string cl_, string phone_num_, string birthday_, string certi_)
 //       : str_employee_num(employee_num_), full_name(name_), cl(cl_), full_phone_number(phone_num_), full_birthday(birthday_), certi(certi_){}
    unsigned int employee_num;           // 앞 2자리 년도 포함
    string str_employee_num;    // 앞 2자리 년도 불포함.
    string full_name;
    string full_phone_number;
    string full_birthday;
    string cl;
    string first_name;
    string last_name;
    int middle_phone_num;
    int last_phone_num;
    int year_birthday;
    int month_birthday;
    int day_birthday;
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

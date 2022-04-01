#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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

struct Employee2
{
    Employee2() {}
    Employee2(string employee_num_, string name_, string cl_, string phone_num_, string birthday_, string certi_)
    {
        str_employee_num = employee_num_;
        full_name = name_;
        full_phone_number = phone_num_;
        full_birthday = birthday_;
        cl = cl_;
        certi = certi_;

        int year_in_employee_num = stoi(employee_num_.substr(0, 2));
        string first_year;

        // make employee_num
        if (69 <= year_in_employee_num
            && 99 >= year_in_employee_num)
        {
            employee_num = stoi("19" + str_employee_num);
        }
        else if (00 <= year_in_employee_num
            && 68 >= year_in_employee_num)
        {
            employee_num = stoi("20" + str_employee_num);
        }
        else
        {
            // exception
        }


        // make first / last name
        int pos_space = name_.find(" ");
        first_name = name_.substr(0, pos_space);
        last_name = name_.substr(pos_space + 1, name_.length());

        // make phone num
        middle_phone_num = stoi(full_phone_number.substr(4, 4));
        last_phone_num = stoi(full_phone_number.substr(9, 4));

        // make birthday
        year_birthday = stoi(full_birthday.substr(0, 4));
        month_birthday = stoi(full_birthday.substr(4, 2));
        day_birthday = stoi(full_birthday.substr(6, 2));
    }

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

    Command()
    {
        for (auto entry : param)
        {
            entry = "";
        }
    }

    bool IsValid()
    {
        return param[0] != "";
    }

    string param[param_count];
};

enum class Column : unsigned int
{
    EMPLOYEENUM,
    NAME,
    CL,
    PHONENUM,
    BIRTHDAY,
    CERTI,
    SIZE
};

struct ModificationInfo
{
    Column column;
    string value;
};

static string GenerateRecord(const std::string& cmd, Employee2& employee)
{
    string result = cmd + ",";
    result += employee.str_employee_num + ",";
    result += employee.full_name + ",";
    result += employee.cl + ",";
    result += employee.full_phone_number + ",";
    result += employee.full_birthday + ",";
    result += employee.certi;
    return result;
}

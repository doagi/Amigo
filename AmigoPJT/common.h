#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

static vector<string> split(const string& input, char delimiter)
{
    vector<string> result;
    result.reserve(3);
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter))
    {
        result.push_back(temp);
    }
    return result;
}

static vector<unsigned int> split_date(const string& input)
{
    vector<unsigned int> result;
    if (input.size() == 8)
    {
        result.reserve(3);
        result.emplace_back(stoi(input.substr(0, 4)));
        result.emplace_back(stoi(input.substr(4, 2)));
        result.emplace_back(stoi(input.substr(6, 2)));
    }
    return result;
}

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
        SetEmployeeNumber(employee_num_);
        SetName(name_);
        SetCareerLevel(cl_);
        SetPhoneNumber(phone_num_);
        SetBirthDay(birthday_);
        SetCerti(certi_);
    }

    void SetEmployeeNumber(const string& employee_num_)
    {
        str_employee_num = employee_num_;

        int YY = stoi(str_employee_num.substr(0, 2));

        if (69 <= YY && YY <= 99)
        {
            employee_num = stoi("19" + str_employee_num);
        }
        else if (00 <= YY && YY <= 68)
        {
            employee_num = stoi("20" + str_employee_num);
        }
    }

    void SetName(const string& name)
    {
        full_name = name;

        auto split_name = split(full_name, ' ');
        if (split_name.size() == 2)
        {
            first_name = split_name[0];
            last_name = split_name[1];
        }
    }

    void SetCareerLevel(const string& cl_)
    {
        cl = cl_;
    }

    void SetPhoneNumber(const string& phone_num)
    {
        full_phone_number = phone_num;

        auto split_phone_number = split(full_phone_number, '-');
        if (split_phone_number.size() == 3)
        {
            middle_phone_num = stoi(split_phone_number[1]);
            last_phone_num = stoi(split_phone_number[2]);
        }
    }

    void SetBirthDay(const string& birthday)
    {
        full_birthday = birthday;

        auto split_birthday = split_date(full_birthday);
        if (split_birthday.size() == 3)
        {
            year_birthday = split_birthday[0];
            month_birthday = split_birthday[1];
            day_birthday = split_birthday[2];
        }
    }

    void SetCerti(const string& certi_)
    {
        certi = certi_;
    }

    unsigned int employee_num;  // 앞 2자리 년도 포함
    string str_employee_num;    // 앞 2자리 년도 불포함
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

#if _DEBUG
static int Compare(string reference, string result)
{
    cout << "\x1b[33m" << endl;
    string command = "fc.exe " + reference + " " + result;
    int error_level = system(command.c_str());
    cout << "\x1b[0m";

    if (error_level)
    {
        cout << "\x1b[31m[FAILED]\x1b[0m" << endl;
    }
    else
    {
        cout << "\x1b[32m[PASSED]\x1b[0m" << endl;
    }

    return error_level;
}
#endif

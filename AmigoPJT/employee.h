#pragma once
#include "common.h"
#include <sstream>
#include <string>
#include "util.h"

using namespace std;

class Employee
{
public:
    Employee() {}
    Employee(string employee_num_, string name_, string cl_, string phone_num_, string birthday_, string certi_)
    {
        SetEmployeeNumber(employee_num_);
        SetName(name_);
        SetCareerLevel(cl_);
        SetPhoneNumber(phone_num_);
        SetBirthDay(birthday_);
        SetCerti(certi_);
    }

    void SetFieldValue(SearchType field, string value)
    {
        switch (field)
        {
        case EMPLOYEE_NUM:
            SetEmployeeNumber(value);
        case NAME:
            SetName(value);
        case PHONE_NUMBER:
            SetPhoneNumber(value);
        case BIRTHDAY:
            SetBirthDay(value);
        case CL:
            SetCareerLevel(value);
        case CERTI:
            SetCerti(value);
        }
    }
    string GetFieldValue(SearchType field)
    {
        return data[field];
    }

    void SetEmployeeNumber(const string & employee_num_)
    {
        data[EMPLOYEE_NUM] = employee_num_;

        int YY = stoi(data[EMPLOYEE_NUM].substr(0, 2));

        if (69 <= YY && YY <= 99)
        {
            employee_num = stoi("19" + data[EMPLOYEE_NUM]);
        }
        else if (00 <= YY && YY <= 68)
        {
            employee_num = stoi("20" + data[EMPLOYEE_NUM]);
        }
    }

    void SetName(const string & name)
    {
        data[NAME] = name;

        auto split_name = Util::split(data[NAME], ' ');
        if (split_name.size() == 2)
        {
            data[FIRST_NAME] = split_name[0];
            data[LAST_NAME] = split_name[1];
        }
    }

    void SetCareerLevel(const string & cl_)
    {
        data[CL] = cl_;
    }

    void SetPhoneNumber(const string & phone_num)
    {
        data[PHONE_NUMBER] = phone_num;

        auto split_phone_number = Util::split(data[PHONE_NUMBER], '-');
        if (split_phone_number.size() == 3)
        {
            data[MIDDLE_PHONE_NUMBER] = split_phone_number[1];
            data[LAST_PHONE_NUMBER] = split_phone_number[2];
        }
    }

    void SetBirthDay(const string & birthday)
    {
        data[BIRTHDAY] = birthday;

        auto split_birthday = Util::split_date(data[BIRTHDAY]);
        if (split_birthday.size() == 3)
        {
            data[BIRTHDAY_YEAR] = split_birthday[0];
            data[BIRTHDAY_MONTH] = split_birthday[1];
            data[BIRTHDAY_DAY] = split_birthday[2];
        }
    }

    void SetCerti(const string & certi_)
    {
        data[CERTI] = certi_;
    }

    string ToString(const char& delimiter)
    {
        stringstream sstream;

        sstream << data[EMPLOYEE_NUM] << delimiter << data[NAME] << delimiter << data[CL] << delimiter
            << data[PHONE_NUMBER] << delimiter << data[BIRTHDAY] << delimiter << data[CERTI];

        return sstream.str();
    }

    unsigned int employee_num;  // 앞 2자리 년도 포함

    string data[SearchType_end];
};

//struct Employee_BU
//{
//    Employee_BU() {}
//
//    Employee_BU(string employee_num_, string name_, string cl_, string phone_num_, string birthday_, string certi_)
//    {
//        SetEmployeeNumber(employee_num_);
//        SetName(name_);
//        SetCareerLevel(cl_);
//        SetPhoneNumber(phone_num_);
//        SetBirthDay(birthday_);
//        SetCerti(certi_);
//    }
//
//    void SetEmployeeNumber(const string& employee_num_)
//    {
//        str_employee_num = employee_num_;
//
//        int YY = stoi(str_employee_num.substr(0, 2));
//
//        if (69 <= YY && YY <= 99)
//        {
//            employee_num = stoi("19" + str_employee_num);
//        }
//        else if (00 <= YY && YY <= 68)
//        {
//            employee_num = stoi("20" + str_employee_num);
//        }
//    }
//
//    void SetName(const string& name)
//    {
//        full_name = name;
//
//        auto split_name = Util::split(full_name, ' ');
//        if (split_name.size() == 2)
//        {
//            first_name = split_name[0];
//            last_name = split_name[1];
//        }
//    }
//
//    void SetCareerLevel(const string& cl_)
//    {
//        cl = cl_;
//    }
//
//    void SetPhoneNumber(const string& phone_num)
//    {
//        full_phone_number = phone_num;
//
//        auto split_phone_number = Util::split(full_phone_number, '-');
//        if (split_phone_number.size() == 3)
//        {
//            middle_phone_num = stoi(split_phone_number[1]);
//            last_phone_num = stoi(split_phone_number[2]);
//        }
//    }
//
//    void SetBirthDay(const string& birthday)
//    {
//        full_birthday = birthday;
//
//        auto split_birthday = Util::split_date(full_birthday);
//        if (split_birthday.size() == 3)
//        {
//            year_birthday = split_birthday[0];
//            month_birthday = split_birthday[1];
//            day_birthday = split_birthday[2];
//        }
//    }
//
//    void SetCerti(const string& certi_)
//    {
//        certi = certi_;
//    }
//
//    unsigned int GetEmployeeNumber()
//    {
//        return employee_num;
//    }
//
//    string ToString(const char& delimiter)
//    {
//        stringstream sstream;
//
//        sstream << str_employee_num << delimiter << full_name << delimiter << cl << delimiter
//            << full_phone_number << delimiter << full_birthday << delimiter << certi;
//
//        return sstream.str();
//    }
//
//    unsigned int employee_num;  // 앞 2자리 년도 포함
//    string str_employee_num;    // 앞 2자리 년도 불포함
//    string full_name;
//    string full_phone_number;
//    string full_birthday;
//    string cl;
//    string first_name;
//    string last_name;
//    int middle_phone_num;
//    int last_phone_num;
//    int year_birthday;
//    int month_birthday;
//    int day_birthday;
//    string certi;
//};

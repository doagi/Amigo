#pragma once
#include <iostream>

using namespace std;

struct Employee
{
    Employee(string employeeNum_, string name_, string cl_, string phoneNum_, string birthday_, string certi_)
        : employeeNum(employeeNum_), name(name_), cl(cl_), phoneNum(phoneNum_), birthday(birthday_), certi(certi_) {}
    string employeeNum;
    string name;
    string cl;
    string phoneNum;
    string birthday;
    string certi;
};
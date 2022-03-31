#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee
{
    string employee_num;
    string first_name;
    string last_name;
    string cl;
    string phone_num;
    string birthday;
    string certi;
};

vector<struct Employee> employees;

vector<struct Employee> SearchByYear(string target)
{
    vector<struct Employee> result;
    for (struct Employee an_employee : employees)
    {
        if (an_employee.birthday.substr(0,4) == target)
        {
            result.push_back(an_employee);
        }
    }
    return result;
}

vector<struct Employee> SearchByMonth(string target)
{
    vector<struct Employee> result;
    for (struct Employee an_employee : employees)
    {
        if (an_employee.birthday.substr (4, 2) == target)
        {
            result.push_back(an_employee);
        }
    }
    return result;
}
vector<struct Employee> SearchByDate(string target)
{
    vector<struct Employee> result;
    for (struct Employee an_employee : employees)
    {
        if (an_employee.birthday.substr (6, 2) == target)
        {
            result.push_back(an_employee);
        }
    }
    return result;
}

int SearchByBirthday(string option, string target)
{
    vector<struct Employee> result;

    switch(option[0])
    {
    case 'y':
        result = SearchByYear(target);
        break;

    case 'm':
        result = SearchByMonth(target);
        break;

    case 'd':
        result = SearchByDate(target);
        break;
    }

    return result.size();

}
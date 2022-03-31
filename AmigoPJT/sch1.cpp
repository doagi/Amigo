#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct employee
{
    string employee_id;

    string last_name;
    string first_name;

    string cl;

    string phone_number;

    string birthday;

    string certi;

};

vector<struct employee> employees;

vector<struct employee> SearchByYear (string target)
{
    vector<struct employee> result;
    for (struct employee an_employee : employees)
    {
        if (an_employee.birthday.substr(0,4) == target)
        {
            result.push_back (an_employee);
        }
    }
    return result;
}

vector<struct employee> SearchByMonth (string target)
{
    vector<struct employee> result;
    for (struct employee an_employee : employees)
    {
        if (an_employee.birthday.substr (4, 2) == target)
        {
            result.push_back (an_employee);
        }
    }
    return result;
}
vector<struct employee> SearchByDate (string target)
{
    vector<struct employee> result;
    for (struct employee an_employee : employees)
    {
        if (an_employee.birthday.substr (6, 2) == target)
        {
            result.push_back (an_employee);
        }
    }
    return result;
}

int SearchByBirthday (string option, string target)
{
    vector<struct employee> result;

    employees.push_back ({ "15123099","VXIHXOTH","JHOP","CL3","010 - 3112 - 2609","19771211","ADV" });

    switch (option[0])
    {
    case 'y':
        result = SearchByYear (target);
        break;

    case 'm':
        result = SearchByMonth (target);
        break;

    case 'd':
        result = SearchByDate (target);
        break;
    }

    return result.size ();

}
#include "search1.h"

vector<Employee> SearchByYear(string target)
{
    vector<Employee> result;
    for (Employee an_employee : employees)
    {
        if (an_employee.birthday.substr(0,4) == target)
        {
            result.push_back(an_employee);
        }
    }
    return result;
}

vector<Employee> SearchByMonth(string target)
{
    vector<Employee> result;
    for (Employee an_employee : employees)
    {
        if (an_employee.birthday.substr (4, 2) == target)
        {
            result.push_back(an_employee);
        }
    }
    return result;
}
vector<Employee> SearchByDate(string target)
{
    vector<Employee> result;
    for (Employee an_employee : employees)
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
    vector<Employee> result;

    switch(option[1])
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
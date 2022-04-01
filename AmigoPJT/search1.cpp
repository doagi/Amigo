#include "search1.h"

vector<unsigned int> SearchByYear(string target, unordered_map<unsigned int, Employee> employees)
{
    vector<unsigned int> result;
    for (const auto& an_employee : employees)
    {
        if (an_employee.second.year_birthday == stoi(target))
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}

vector<unsigned int> SearchByMonth(string target, unordered_map<unsigned int, Employee> employees)
{
    vector<unsigned int> result;

    for (const auto& an_employee : employees)
    {
        if (an_employee.second.month_birthday == stoi(target))
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}
vector<unsigned int> SearchByDate(string target, unordered_map<unsigned int, Employee> employees)
{
    vector<unsigned int> result;
    for (const auto& an_employee : employees)
    {
        if (an_employee.second.day_birthday == stoi(target))
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}

vector<unsigned int> SearchByFullBirthday(string target, unordered_map<unsigned int, Employee> employees)
{
    vector<unsigned int> result;
    for (const auto& an_employee : employees)
    {
        if (an_employee.second.full_birthday == target)
        {
            result.push_back(an_employee.second.employee_num);
        }
    }
    return result;
}

vector<unsigned int> SearchByBirthday(string op2, string target, unordered_map<unsigned int, Employee> employees)
{
    if (op2 == "-y")
    {
        return SearchByYear(target, employees);
    }
    else if (op2 == "-m")
    {
        return SearchByMonth(target, employees);
    }
    else if (op2 == "-d")
    {
        return SearchByDate(target, employees);
    }
    else
    {
        return SearchByFullBirthday(target, employees);
    }
}
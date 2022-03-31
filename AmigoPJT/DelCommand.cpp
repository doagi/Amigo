#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;

bool employeeNum(string a, Employee b)
{
    return a == b.employee_num;
}

bool name(string a, Employee b)
{
    return a == b.name;
}

bool cl(string a, Employee b)
{
    return a == b.cl;
}

bool phoneNum(string a, Employee b)
{
    return a == b.phone_num;
}

bool birthday(string a, Employee b)
{
    return a == b.birthday;
}

bool certi(string a, Employee b)
{
    return a == b.certi;
}

string Del(vector<Employee>& employee, bool (*compare)(string, Employee), string targetValue)
{

    int numTarget = 0;
    for (int i = 0; i < employee.size();)
    {
        if (compare(targetValue, employee[i]))
        {
            numTarget++;
            employee.erase(employee.begin() + i);
        }
        else
        {
            i++;
        }
    }

    if (numTarget == 0)
    {
        return "DEL,NONE";
    }
    else
    {
        return "DEL," + to_string(numTarget);
    }
}

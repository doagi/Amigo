#include <iostream>
#include <vector>
#include "common.h"

using namespace std;

vector<Employee> employees;


int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi)
{
    Employee newEmployee = Employee(employee_num, name, cl, phoneNum, birthday, certi);
    employees.push_back(newEmployee);

    return employees.size();
}

int Mod(int op1, int op2, int op3, string targetColumn, string targetValue, string srcColumn, string srcValue)
{
    return 0;
}

int Del(int op1, int op2, int op3, string column, string value)
{
    return 0;
}

int Sch(int op1, int op2, int op3, string column, string value)
{
    return 0;
}
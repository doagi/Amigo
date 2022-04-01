#pragma once
#include <iostream>
#include "common.h"
#include "search1.h"

using namespace std;


int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
int Mod(string op1, string op2, string targetColumn, string targetValue, string srcColumn, string srcValue);
vector<unsigned int> Sch(string op1, string op2, string column, string value, unordered_map<unsigned int, Employee> employees);
int Del(string op1, string op2, string column, string value);

void CommandRun(vector<Command> commands, unordered_map<unsigned int, Employee> employees);

// from DelCommand.cpp
bool employeeNum(string a, Employee b);
bool name(string a, Employee b);
bool cl(string a, Employee b);
bool phoneNum(string a, Employee b);
bool birthday(string a, Employee b);
bool certi(string a, Employee b);
string Del(vector<Employee>& employee, bool (*compare)(string, Employee), string targetValue);


#pragma once
#include <iostream>
#include <unordered_map>
#include "common.h"
#include "search1.h"
#include "searchByName.h"
#include "searchByPhoneNumber.h"

using namespace std;

//extern vector<Employee> employees;
extern unordered_map<unsigned int, Employee2> map_employees;


int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
int Mod(string op1, string op2, string targetColumn, string targetValue, string srcColumn, string srcValue);
vector<unsigned int> Sch(string op1, string op2, string column, string value);
int Del(string op1, string op2, string column, string value);

void CommandRun(vector<Command> commands);

// from DelCommand.cpp
bool employeeNum(string a, Employee2 b);
bool name(string a, Employee2 b);
bool cl(string a, Employee2 b);
bool phoneNum(string a, Employee2 b);
bool birthday(string a, Employee2 b);
bool certi(string a, Employee2 b);
string Del(vector<Employee2>& employee, bool (*compare)(string, Employee2), string targetValue);


#pragma once
#include <iostream>
#include "common.h"
#include "search1.h"

using namespace std;


int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
int Mod(string op1, string op2, string targetColumn, string targetValue, string srcColumn, string srcValue);
int Sch(string op1, string op2, string column, string value);
string Del(vector<Employee>& employee, bool (*compare)(string, Employee), string targetValue);
void CommandRun(vector<Command> commands);
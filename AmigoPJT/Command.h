#pragma once
#include <iostream>
#include <unordered_map>
#include "common.h"
#include "search1.h"
#include "command/mod.h"
#include "searchByName.h"
#include "searchByPhoneNumber.h"
#include "searchEtc.h"

using namespace std;

//extern vector<Employee> employees;
extern unordered_map<unsigned int, Employee2> map_employees;


int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
vector<unsigned int> Sch(string op1, string op2, string column, string value, unordered_map<unsigned int, Employee2> employees);
int Del(string op2, string column, string value);
int Mod(const vector<unsigned int>& founds, string column, string value);

string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);
string GenerateSimpleRecord(const std::string& command, const size_t count);

void CommandRun(vector<Command> commands);

// from DelCommand.cpp
bool employeeNum(string a, Employee2 b);
bool name(string a, Employee2 b);
bool cl(string a, Employee2 b);
bool phoneNum(string a, Employee2 b);
bool birthday(string a, Employee2 b);
bool certi(string a, Employee2 b);
string Del(vector<Employee2>& employee, bool (*compare)(string, Employee2), string targetValue);

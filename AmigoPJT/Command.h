#pragma once
#include <iostream>
#include <unordered_map>
#include "common.h"
#include "searchByBirthday.h"
#include "command/mod.h"
#include "searchByName.h"
#include "searchByPhoneNumber.h"
#include "searchEtc.h"

using namespace std;

//extern vector<Employee> employees;
extern unordered_map<unsigned int, Employee2> map_employees;


int Add(string employee_num, string name, string cl, string phoneNum, string birthday, string certi);
vector<unsigned int> Sch(string op1, string op2, string column, string value);
int Mod(const vector<unsigned int>& founds, string column, string value);

string GenerateCommandRecord(const std::string& command, const bool& detail_print, const vector<unsigned int>& targets);
string GenerateDetailRecord(const std::string& command, const vector<unsigned int>& result);

vector<string> CommandRun(vector<Command> commands);
string Del(vector<unsigned int> deleteList);

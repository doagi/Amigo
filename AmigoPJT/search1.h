#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using namespace std;
extern vector<Employee> employees;
extern vector<Command> commands;

int SearchByBirthday(string option, string target);

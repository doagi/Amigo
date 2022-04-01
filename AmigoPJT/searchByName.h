#pragma once
#include <iostream>
#include <vector>
#include "common.h"

using std::string;
using std::vector;

vector<int> searchByName(string target, vector<Employee> data);
vector<int> searchByFirstName(string target, vector<Employee> data);
vector<int> searchByLastName(string target, vector<Employee> data);
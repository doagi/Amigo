#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "common.h"

using std::string;
using std::vector;

vector<int> searchByPhoneNumber(int target, vector<Employee> data);
vector<int> searchByMiddlePhoneNumber(int target, vector<Employee> data);
vector<int> searchByLastPhoneNumber(int target, vector<Employee> data);
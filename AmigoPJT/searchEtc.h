#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "common.h"

vector<unsigned int> searchByEmployeeNumber(string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByCerti(string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByCl(string target, unordered_map<unsigned int, Employee> data);

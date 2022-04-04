#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "common.h"

using std::string;
using std::vector;
using std::unordered_map;

vector<unsigned int> searchByName(string op2, string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByFullName(string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByFirstName(string target, unordered_map<unsigned int, Employee> data);
vector<unsigned int> searchByLastName(string target, unordered_map<unsigned int, Employee> data);
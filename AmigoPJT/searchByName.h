#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "common.h"

using std::string;
using std::vector;
using std::unordered_map;

vector<int> searchByName(string target, unordered_map<int, Employee2> data);
vector<int> searchByFirstName(string target, unordered_map<int, Employee2> data);
vector<int> searchByLastName(string target, unordered_map<int, Employee2> data);
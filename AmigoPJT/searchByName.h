#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "common.h"

using std::string;
using std::vector;
using std::unordered_map;

vector<unsigned int> searchByName(string target, unordered_map<unsigned int, Employee2> data);
vector<unsigned int> searchByFirstName(string target, unordered_map<unsigned int, Employee2> data);
vector<unsigned int> searchByLastName(string target, unordered_map<unsigned int, Employee2> data);
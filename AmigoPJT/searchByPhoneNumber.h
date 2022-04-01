#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "common.h"

using std::string;
using std::vector;
using std::unordered_map;

vector<unsigned int> searchByPhoneNumber(unsigned int target, unordered_map<unsigned int, Employee2> data);
vector<unsigned int> searchByMiddlePhoneNumber(unsigned int target, unordered_map<unsigned int, Employee2> data);
vector<unsigned int> searchByLastPhoneNumber(unsigned int target, unordered_map<unsigned int, Employee2> data);